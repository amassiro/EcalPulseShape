// 
// Shamelessly imported from: https://github.com/ferriff/usercode/blob/master/DBDump/interface/CondDBDumper.h
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


namespace cond {
  
  template<class C>
//   class CondDBDumper {
    class CondDBDumper : public cond::Utilities {
      
  public:
    
    CondDBDumper(std::string tag_production, std::string tag_fit)  : Utilities("") {
      _tag_production = tag_production;
      _tag_fit        = tag_fit;
      
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
      
    }
    
    ~CondDBDumper()
    {
    }
    
        
    // main loop
    int execute()
    {
      std::string connect = "frontier://FrontierProd/CMS_CONDITIONS";
      std::string db = "";
//       if (hasOptionValue("db")) {
//         if      (db == "dev") connect = "frontier://FrontierPrep/CMS_CONDITIONS";
//           else if (db == "pro") connect = "frontier://PromptProd/CMS_CONDITIONS";
//             else if (db == "arc") connect = "frontier://FrontierArc/CMS_CONDITIONS";
//               else if (db == "int") connect = "frontier://FrontierInt/CMS_CONDITIONS";
//                 else {
//                   connect = getOptionValue<std::string>("db" );
//                 }
//       }
//       
      cond::persistency::ConnectionPool connPool;

      int niov = -1;

      cond::Time_t since = std::numeric_limits<cond::Time_t>::min();
      cond::Time_t till = std::numeric_limits<cond::Time_t>::max();

      connPool.configure();
      cond::persistency::Session session = connPool.createSession(connect);

//       std::string tag = "EcalPulseShapes_hlt";
//       std::string tag = _tag_production;
      
      
      
      session.transaction().start( true );
      
      cond::persistency::IOVProxy iovs_EcalPulseCovariances = session.readIov("EcalPulseCovariances_mc", true);
//       EcalPulseCovariancesRcd       EcalPulseCovariances_mc 
      
      std::shared_ptr<EcalPulseCovariances> pulsecovariances;
      for (auto iov : iovs_EcalPulseCovariances) {
        pulsecovariances = session.fetchPayload<EcalPulseCovariances>(iov.payloadId);
      }
      
      
      cond::persistency::IOVProxy iovs_production = session.readIov(_tag_production, true);
      std::string obj_type = iovs_production.payloadObjectType();
      
      
      
      auto first_iov = iovs_production.begin();
      auto last_iov  = iovs_production.begin();
      for (int i = 0; i < iovs_production.loadedSize() - 1; ++i) ++last_iov;

      
      std::cout << (*first_iov).since << " " << (*last_iov).since << std::endl;
      
      int cnt_iov = 0;
      //---- loop over all the intervals of validity
      for (auto iov : iovs_production) {
        cnt_iov++;
        std::shared_ptr<C> pa = session.fetchPayload<C>(iov.payloadId);
        //---- loop over the crystals
        for (size_t i = 0; i < _ids.size(); ++i) {
          DetId id(_ids[i]);
          EcalPulseShapes::const_iterator it_pulseShape = pa->find(id);
          
          if (it_pulseShape == pa->end()) {
            std::cout << "Cannot find value for DetId " << id.rawId() << std::endl;
          }
          
          coord(_ids[i]);
          
//           std::vector < float > production_samples;
//           production_samples.push_back(0, 0, 0);     

          SampleVector amplitudes;
          amplitudes[0] = 0.;
          amplitudes[1] = 0.;
          amplitudes[2] = 0.;

          for (int iSample = 0; iSample < EcalPulseShape::TEMPLATESAMPLES; iSample++) {
            //                       std::cout << it_pulseShape->val(iSample) << " : " ;
            //---- only the first 7 samples, the rest is extrapolation
            if (iSample<7) {
              //---- 100 = 100 ADC counts [random number]
              //               production_samples.push_back( 100* it_pulseShape->val(iSample) );
              amplitudes[iSample+3] = 100* it_pulseShape->val(iSample);
            }
          }
          
                    
          SampleMatrix noisecov;
          BXVector activeBX;
          FullSampleVector fullpulse(FullSampleVector::Zero());
          FullSampleMatrix fullpulsecov(FullSampleMatrix::Zero());

          const EcalPulseCovariances::Item * aPulseCov = nullptr;
          unsigned int hashedIndex = EBDetId(_ids[i]).hashedIndex();
          aPulseCov  = &(pulsecovariances)->barrel(hashedIndex);
          
          
          SampleGainVector gainsPedestal;
          SampleGainVector badSamples = SampleGainVector::Zero();
          

          
          for (int iSample=0; i<EcalPulseShape::TEMPLATESAMPLES; ++iSample) {
            fullpulse(iSample+7) = it_pulseShape->val(iSample);
          }
          
          for(int iSample=0; iSample<EcalPulseShape::TEMPLATESAMPLES;iSample++) {
            for(int jSample=0; jSample<EcalPulseShape::TEMPLATESAMPLES;jSample++) {
              fullpulsecov(iSample+7,jSample+7) = aPulseCov->covval[iSample][jSample];
            }
          }
            
            
            
//           noisecov = aped->rms_x12*aped->rms_x12*noisecors[0];
          //---- 1.2 ADC: https://github.com/kpedro88/cmssw/blob/master/CondFormats/EcalObjects/interface/EcalPedestals.h ---> it's a float
          SampleMatrixGainArray noisecors;
          noisecov = 1.2 * 1.2 * noisecors[0];
          
          for (int iSample = 0; iSample < EcalPulseShape::TEMPLATESAMPLES; iSample++) {
            gainsPedestal[iSample] = -1;  //-1 for static pedestal
          }
          
          bool status = _pulsefunc.DoFit(amplitudes,noisecov,activeBX,fullpulse,fullpulsecov,gainsPedestal,badSamples);
          float chisq = _pulsefunc.ChiSq();
          
//           if (!status) {
//             edm::LogWarning("EcalUncalibRecHitMultiFitAlgo::makeRecHit") << "Failed Fit" << std::endl;
//           }
//           
          unsigned int ipulseintime = 0;
          for (unsigned int ipulse=0; ipulse<_pulsefunc.BXs().rows(); ++ipulse) {
            if (_pulsefunc.BXs().coeff(ipulse)==0) {
              ipulseintime = ipulse;
              break;
            }
          }
          
          _bias [i] = ( status ? _pulsefunc.X()[ipulseintime] : 0.) / 100.;
          
//           
//           amplitude = status ? _pulsefunc.X()[ipulseintime] : 0.;
//           amperr = status ? _pulsefunc.Errors()[ipulseintime] : 0.;
//           
//           
          
          
          
          
          
          
//           std::cout <<  _c.ix_ << " " <<  _c.iy_ << " " <<  _c.iz_ << " ::: " ;
//           //---- loop over the N-samples of the pulse shape
//           for (int is = 0; is < EcalPulseShape::TEMPLATESAMPLES; ++is) {
          //             std::cout << it_pulseShape->val(is) << " : " ;
//           }
//           std::cout << std::endl;
        }
      }
      
      std::cout << " cnt_iov = " << cnt_iov << std::endl;
      
      
      session.transaction().commit();

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
    std::string _tag_production;
    std::string _tag_fit;
    std::vector<DetId> _ids;
    std::vector<float> _bias;
    
    PulseChiSqSNNLS _pulsefunc;
    
    
  };
  
}

#endif
