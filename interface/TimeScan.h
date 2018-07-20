// 
// Shamelessly imported from: https://github.com/ferriff/usercode/blob/master/DBDump/interface/TimeScan.h
//  


#ifndef CONDDB_DUMPER_hh
#define CONDDB_DUMPER_hh

#include "CondCore/CondDB/interface/IOVProxy.h"
#include "CondCore/Utilities/interface/Utilities.h"

#include "CondCore/CondDB/interface/ConnectionPool.h"

#include <boost/program_options.hpp>
#include <iterator>
#include <iostream>

#include "CondFormats/BeamSpotObjects/interface/BeamSpotObjects.h"
#include "CondFormats/EcalObjects/interface/EcalADCToGeVConstant.h"
#include "CondFormats/EcalObjects/interface/EcalChannelStatus.h"
#include "CondFormats/EcalObjects/interface/EcalClusterLocalContCorrParameters.h"
#include "CondFormats/EcalObjects/interface/EcalCondObjectContainer.h"
#include "CondFormats/EcalObjects/interface/EcalGainRatios.h"
#include "CondFormats/EcalObjects/interface/EcalPedestals.h"
#include "CondFormats/EcalObjects/interface/EcalPulseShapes.h"
#include "CondFormats/EcalObjects/interface/EcalTimeOffsetConstant.h"
#include "CondFormats/EcalObjects/interface/EcalTPGLinearizationConst.h"
#include "CondFormats/EcalObjects/interface/EcalTPGLutGroup.h"
#include "CondFormats/EcalObjects/interface/EcalTPGLutIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalTPGPedestals.h"
#include "CondFormats/EcalObjects/interface/EcalTPGWeightIdMap.h"
#include "CondFormats/EcalObjects/interface/EcalTPGWeightGroup.h"
#include "CondFormats/EcalObjects/interface/EcalTPGSlidingWindow.h"
#include "CondFormats/EcalObjects/interface/EcalTPGSpike.h"
#include "CondFormats/ESObjects/interface/ESEEIntercalibConstants.h"
#include "CondFormats/ESObjects/interface/ESGain.h"
#include "CondFormats/ESObjects/interface/ESIntercalibConstants.h"
#include "CondFormats/RunInfo/interface/RunInfo.h"

#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"

//---- for multifit 
#include "RecoLocalCalo/EcalRecAlgos/interface/PulseChiSqSNNLS.h"

#include "CondFormats/DataRecord/interface/EcalPulseShapesRcd.h"
#include "CondFormats/DataRecord/interface/EcalPulseCovariancesRcd.h"

#include "CondFormats/EcalObjects/interface/EcalPulseShapes.h"
#include "CondFormats/EcalObjects/interface/EcalPulseCovariances.h"

#include "CondFormats/DataRecord/interface/EcalSamplesCorrelationRcd.h"
#include "CondFormats/EcalObjects/interface/EcalSamplesCorrelation.h"





//---- ROOT
#include "TFile.h"
#include "TTree.h"



double alphabeta(double* x, double*p){
  
  double fitval;
  
  if( ( 1+(x[0]-p[1]) / (p[2]*p[3]) ) > 0. ){
    fitval = p[0] * pow(1 + (x[0]-p[1]) / (p[2]*p[3]) , p[2] ) * exp ( - (x[0]-p[1]) / p[3]);
  }else{
    fitval = 0;
  }
  
  return fitval;
  
}





namespace cond {
  
  template<class C>
  class TimeScan : public cond::Utilities {
    
  public:
    
    TimeScan(std::string input_alpha_beta_file_name, int min_dt, int max_dt, float delta_time)  : Utilities("") {
      
      _input_alpha_beta_file_name = input_alpha_beta_file_name;
      
      //
      //         crystal rawid      A       t_0     alpha   beta 
      //         838861313       0.240841        121.422 1.18845 40.2035
      //         838861314       0.241195        121.533 1.14727 40.8942
      //
      
      //Open txt file with mean fit parameters for eta rings for barrel and endcaps
      unsigned int rawid;
      float A;
      float t_0;
      float alpha;
      float beta;
      
      std::vector<float> v_parameters;
      
      std::ifstream txt_input;
      txt_input.open(_input_alpha_beta_file_name);
      
      while ( kTRUE ) {
        txt_input >> rawid >> A >> t_0 >> alpha >> beta;
        v_parameters.clear();
        v_parameters.push_back(A);
        v_parameters.push_back(t_0);
        v_parameters.push_back(alpha);
        v_parameters.push_back(beta);
        
        _map_parameters[rawid] = v_parameters;
        
        if ( ! txt_input.good() ) break;
      }
      
      
      
      
      _min_dt = min_dt;
      _max_dt = max_dt;
      _delta_time = delta_time;
      
      
      _bias.resize(EBDetId::MAX_HASH + 1 + EEDetId::kSizeForDenseIndexing);
      _ids.resize(EBDetId::MAX_HASH + 1 + EEDetId::kSizeForDenseIndexing);      
      for (int hi = EBDetId::MIN_HASH; hi <= EBDetId::MAX_HASH; ++hi ) {
        EBDetId ebId = EBDetId::unhashIndex(hi);
        if (ebId != EBDetId()) {
          _ids[hi] = ebId;
          _bias[hi] = 1.;
        }
      }
      for ( int hi = 0; hi < EEDetId::kSizeForDenseIndexing; ++hi ) {
        EEDetId eeId = EEDetId::unhashIndex(hi);
        if (eeId != EEDetId()) {
          int idx = EBDetId::MAX_HASH + 1 + hi;
          _ids[idx] = eeId;
          _bias[idx] = -1.;
        }
      }
      assert(_ids.size() == 75848);
      assert(_ids.size() == EBDetId::MAX_HASH + 1 + EEDetId::kSizeForDenseIndexing);
      
      std::cout << " :: min_dt = " << _min_dt << std::endl;
      std::cout << " :: max_dt = " << _max_dt << std::endl;
      std::cout << " :: delta_time = " << _delta_time << std::endl;
      
      
    }
    
    
    
    
    ~TimeScan()
    {
    }
    
     
    
    // main loop
    int execute() {

      
      float Amplitude_ADC = 1000.;
      
      
      
      TF1 *function_alphabeta = new TF1("function_alphabeta", alphabeta, -11, 236, 4);
      
      function_alphabeta->SetParName(0, "A");
      function_alphabeta->SetParName(1, "t_0");
      function_alphabeta->SetParName(2, "alpha");
      function_alphabeta->SetParName(3, "beta");
      
      
      
      std::string connect = "frontier://FrontierProd/CMS_CONDITIONS";
      std::cout << " connect = " << connect << std::endl;
      
      cond::persistency::ConnectionPool* connPool = new cond::persistency::ConnectionPool ;
      
      int niov = -1;
      
      cond::Time_t since = std::numeric_limits<cond::Time_t>::min();
      cond::Time_t till = std::numeric_limits<cond::Time_t>::max();
      
      connPool->configure();
      
      cond::persistency::Session session = connPool->createSession(connect);
      
      session.transaction().start( true );
      
      //---- get pulse covariances 
      cond::persistency::IOVProxy iovs_EcalPulseCovariances = session.readIov("EcalPulseCovariances_mc", true);
      //       EcalPulseCovariancesRcd       EcalPulseCovariances_mc 
      
      std::shared_ptr<EcalPulseCovariances> pulsecovariances;
      for (auto iov : iovs_EcalPulseCovariances) {
        pulsecovariances = session.fetchPayload<EcalPulseCovariances>(iov.payloadId);
      }
      
      
      //---- get samples correlation -> for noise!
      //       EcalSamplesCorrelationRcd EcalSamplesCorrelation_mc
      cond::persistency::IOVProxy iovs_EcalSamplesCorrelation = session.readIov("EcalSamplesCorrelation_mc", true);
      std::shared_ptr<EcalSamplesCorrelation> noisecovariances;
      for (auto iov : iovs_EcalSamplesCorrelation) {
        noisecovariances = session.fetchPayload<EcalSamplesCorrelation>(iov.payloadId);
      }
      
      SampleMatrix noisecovEB;
      noisecovEB = SampleMatrix::Zero();
      int nnoise = SampleVector::RowsAtCompileTime;
      for (int i=0; i<nnoise; ++i) {
        for (int j=0; j<nnoise; ++j) {
          int vidx = std::abs(j-i);
          noisecovEB(i,j) = 2.0 * 2.0 * noisecovariances->EBG12SamplesCorrelation[vidx];
          //           noisecorEBg12(i,j) = noisecovariances->EBG12SamplesCorrelation[vidx];
        }
      }
      
      SampleMatrix noisecovEE;
      noisecovEE = SampleMatrix::Zero();
      for (int i=0; i<nnoise; ++i) {
        for (int j=0; j<nnoise; ++j) {
          int vidx = std::abs(j-i);
          noisecovEE(i,j) = 2.0 * 2.0 * noisecovariances->EEG12SamplesCorrelation[vidx];
        }
      }
      
      
      //       
      //       static const int TEMPLATESAMPLES = 12;
      //       
      
      //---- now get the pulse shape and amplitude tags
      
      for (int itime = _min_dt; itime < _max_dt; itime++) {
        float delta_time_absolute = itime * _delta_time;
        std::cout << " delta_time_absolute [" << itime << " ] = " << delta_time_absolute << std::endl;
        
        std::string name_output_file = "out_time_scan_" + std::to_string(delta_time_absolute) + ".root";
        
        std::cout << " name_output_file = " << name_output_file << std::endl;
        
        TFile* outputFile = new TFile (name_output_file.c_str(), "RECREATE");
        TTree* outputTree = new TTree ("outputTree", "outputTree");
        float bias;
        float EbxM1; //---- energy in BX -1
        int ieta;
        int iphi;
        int iz;
        
        std::vector <float> samplesReco; //---- the reconstructed energy per BX
        std::vector <float> samplesSim; //---- the simulated pulse
        std::vector <float> pulseShapeTemplate; //---- the pulse shape template
        
        
        outputTree->Branch("samplesReco",   &samplesReco);
        outputTree->Branch("samplesSim",    &samplesSim);
        outputTree->Branch("pulseShapeTemplate",    &pulseShapeTemplate);
        outputTree->Branch("bias",  &bias);
        outputTree->Branch("EbxM1", &EbxM1);
        outputTree->Branch("ieta", &ieta);
        outputTree->Branch("iphi", &iphi);
        outputTree->Branch("iz",   &iz);
        
        for (unsigned int ibx=0; ibx<10; ++ibx) {
          samplesReco.push_back(0.);
          samplesSim.push_back(0.);   
        }
        
        for (unsigned int ibx=0; ibx<20; ++ibx) {
          pulseShapeTemplate.push_back(0.);
        }
        
        
        
        
        //---- loop over the crystals
        //       for (size_t i = 0; i < 100; ++i) {
        for (size_t i = 0; i < _ids.size(); ++i) {
          
          
          for (unsigned int ibx=0; ibx<10; ++ibx) {
            samplesReco.at(ibx) = 0.;
            samplesSim.at(ibx) = 0.;
          }
          for (unsigned int ibx=0; ibx<20; ++ibx) {
            pulseShapeTemplate.at(ibx) = 0.;
          }
          
          
          DetId id(_ids[i]);
          coord(_ids[i]);
          
          
          
          //---- the input pulse to be fitted
          SampleVector amplitudes;
          
          //---- bunch crossings that are active
          BXVector activeBX;
          //---- active bunch crossings
          activeBX.resize(10);
          activeBX << -5,-4,-3,-2,-1,0,1,2,3,4;
          
          
          //---- the pulse shape and its parameters used for fitting
          FullSampleVector fullpulse(FullSampleVector::Zero());
          FullSampleMatrix fullpulsecov(FullSampleMatrix::Zero());
          
          
          unsigned int hashedIndex;
          
          const EcalPulseCovariances::Item * aPulseCov = nullptr;
          //---- EB
          if (_c.iz_ == 0 ) {
            hashedIndex = EBDetId(_ids[i]).hashedIndex();
            aPulseCov  = &(pulsecovariances)->barrel(hashedIndex);  
          }
          //---- EE
          else {
            hashedIndex = EEDetId(_ids[i]).hashedIndex();
            aPulseCov  = &(pulsecovariances)->endcap(hashedIndex);
          }
          
          SampleGainVector gainsPedestal;
          SampleGainVector badSamples = SampleGainVector::Zero();
          
          for (int iSample = 0; iSample < EcalPulseShape::TEMPLATESAMPLES; iSample++) {
            gainsPedestal[iSample] = -1;  //-1 for static pedestal
          }
          
          
          //---- ... and the corresponding covariance matrix          
          for(int iSample=0; iSample<EcalPulseShape::TEMPLATESAMPLES;iSample++) {
            for(int jSample=0; jSample<EcalPulseShape::TEMPLATESAMPLES;jSample++) {
              fullpulsecov(iSample+7,jSample+7) = aPulseCov->covval[iSample][jSample];
            }
          }
          
//           std::cout << " hashedIndex = " << hashedIndex << "; _ids[" << i << "].rawId() = " << _ids[i].rawId() << std::endl;
          
          if (_map_parameters.find( _ids[i].rawId() ) != _map_parameters.end()) {
            
            //---- pulse shape to be used as reference ...      
            function_alphabeta->SetParameter(0, _map_parameters[_ids[i].rawId()].at(0));  // A 
            function_alphabeta->SetParameter(1, _map_parameters[_ids[i].rawId()].at(1));  // t_0 
            function_alphabeta->SetParameter(2, _map_parameters[_ids[i].rawId()].at(2));  // alpha 
            function_alphabeta->SetParameter(3, _map_parameters[_ids[i].rawId()].at(3));  // beta
            
            
            for (int iSample=0; iSample<EcalPulseShape::TEMPLATESAMPLES; iSample++) {
              fullpulse(iSample+7) = function_alphabeta->Eval(iSample * 25 + 25*3);
              pulseShapeTemplate.at(iSample+7) = function_alphabeta->Eval(iSample * 25 + 25*3);
            }
            
            
            //
            //---- the input pulse to be fitted
            //
            //           std::vector < float > production_samples;
            //           production_samples.push_back(0, 0, 0);     
            
            amplitudes[0] = 0.;
            amplitudes[1] = 0.;
            amplitudes[2] = 0.;
            
            //---- shift in time
            function_alphabeta->SetParameter(1, _map_parameters[_ids[i].rawId()].at(1) + delta_time_absolute);  // t_0 
            
            for (int iSample = 0; iSample < EcalPulseShape::TEMPLATESAMPLES; iSample++) {
              //---- only the first 7 samples, the rest is extrapolation
              if (iSample<7) {
                //---- 100 = 100 ADC counts [random number]
                amplitudes[iSample+3] = Amplitude_ADC * function_alphabeta->Eval(iSample * 25 + 25*3);
                samplesSim.at(iSample+3) = function_alphabeta->Eval(iSample * 25 + 25*3);
              }
            }
            
            //---- now fit!
            bool status = false;
            
            //---- EB
            if (_c.iz_ == 0 ) {
              status = _pulsefunc.DoFit(amplitudes,noisecovEB,activeBX,fullpulse,fullpulsecov,gainsPedestal,badSamples);
            }
            else {
              status = _pulsefunc.DoFit(amplitudes,noisecovEE,activeBX,fullpulse,fullpulsecov,gainsPedestal,badSamples);
            }
            float chisq = _pulsefunc.ChiSq();
            
            if (!status) {
              std::cout << " warning: bad fit " << std::endl;
            }
            
            unsigned int ipulseintime = 0;
            for (unsigned int ipulse=0; ipulse<_pulsefunc.BXs().rows(); ++ipulse) {
              if (_pulsefunc.BXs().coeff(ipulse) == 0) {
                ipulseintime = ipulse;
                break;
              }
            }
            
            unsigned int ipulseM1 = 0;
            for (unsigned int ipulse=0; ipulse<_pulsefunc.BXs().rows(); ++ipulse) {
              if (_pulsefunc.BXs().coeff(ipulse) == -1) {
                ipulseM1 = ipulse;
                break;
              }
            }
            
            _bias [i] = ( status ? _pulsefunc.X()[ipulseintime] : 0.) / Amplitude_ADC;
            
            bias = _bias [i];
            
            EbxM1 =  ( status ? _pulsefunc.X()[ipulseM1] : -1) / Amplitude_ADC;
            
            int NSAMPLES = 10;
            for (unsigned int ipulse=0; ipulse<_pulsefunc.BXs().rows() ; ++ipulse) {
              if (status) { 
                if ((int(_pulsefunc.BXs().coeff(ipulse))) + 5 < NSAMPLES) samplesReco[ (int(_pulsefunc.BXs().coeff(ipulse))) + 5] = _pulsefunc.X()[ ipulse ];
              }
              else {
                samplesReco[ipulse] = -1;
              }
            }
            
            
            
            if (! (i%10000)) {
              std::cout << " i = " << i;
              std::cout << "     -> " << _pulsefunc.X()[ipulseintime] << std::endl;
            }
            
          }
//           else {
//             std::cout << " Crystal missing: " << _c.ix_ << " , " << _c.iy_ << " , " << _c.iz_ << " : " << _ids[i].rawId() << " MAX = " << _map_parameters.size() << std::endl; 
//           }
          
          ieta = _c.ix_;
          iphi = _c.iy_;
          iz   = _c.iz_;
          
          outputTree->Fill();
          
        } //---- end loop over crystals
        
        outputTree->Write();
        
        outputFile->Close();
        
        delete outputFile;
        
        
      }
      
      
      session.transaction().commit();
      
      session.close();
      
      delete connPool;
      
      return 0;
    }
    
    
    
    
    
    
    
    
    
    //---- additional information and useful tools
    
    struct Coord {
      int ix_;
      int iy_;
      int iz_;
    } _c;
    
    
    void coord(DetId id)
    {
      if (id.subdetId() == EcalBarrel) {
        EBDetId eid(id);
        _c.ix_ = eid.ieta();
        _c.iy_ = eid.iphi();
        _c.iz_ = 0;
      } else if (id.subdetId() == EcalEndcap) {
        EEDetId eid(id);
        _c.ix_ = eid.ix();
        _c.iy_ = eid.iy();
        _c.iz_ = eid.zside();
      } else {
        fprintf(stderr, "[coord] ERROR: invalid DetId %d", id.rawId());
        assert(0);
      }
    }
    
    
    
    
  private:

    std::string _input_alpha_beta_file_name;
    
    int _min_dt;
    int _max_dt;
    float _delta_time;
    
    std::vector<DetId> _ids;
    std::vector<float> _bias;
    
    std::map<unsigned int, std::vector<float> > _map_parameters;
    
    PulseChiSqSNNLS _pulsefunc;
    
  };
  
}

#endif
