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

namespace cond {
  
  template<class C>
//   class CondDBDumper {
    class CondDBDumper : public cond::Utilities {
      
  public:
    
//     CondDBDumper(std::string tag) : Utilities("conddb_dumper"), _tag(tag)
    CondDBDumper(std::string tag)  : Utilities("")
//       CondDBDumper(std::string tag)  
        {
     _tag = tag;
     
//       addAuthenticationOptions();
//       addOption<bool>("join", "j", "produce one single output file, where IOVs are separated by double line break and a comment line starting with `#'");
//       addOption<bool>("verbose","v","verbose");
//       addOption<cond::Time_t>("beginTime","b","begin time (first since) (optional)");
//       addOption<cond::Time_t>("endTime","e","end time (last till) (optional)");
//       addOption<int>("niov","n","number of IOVs to be dumped");
//       addOption<int>("prescale","s","prescale factor, i.e. dump 1 in N IOVs");
//       addOption<std::string>("object","O","object to be dumped (required)");
//       addOption<std::string>("output","o","output file");
//       addOption<std::string>("tag","t","tag to be dumped (required)");
//       addOption<std::string>("db","d","database to run the command on;"
//       " arg can be an explicit db connection, e.g. for sqlite files,"
//       " or one of the following aliases:\n"
//       "     dev -> FrontierPrep\n"
//       "     pro -> PromptProd\n"
//       "     arc -> FrontierArc\n"
//       "     int -> FrontierInt\n"
//       );
      
     
      _ids.resize(EBDetId::MAX_HASH + 1 + EEDetId::kSizeForDenseIndexing);      
      for (int hi = EBDetId::MIN_HASH; hi <= EBDetId::MAX_HASH; ++hi ) {
        EBDetId ebId = EBDetId::unhashIndex(hi);
        if (ebId != EBDetId()) {
          _ids[hi] = ebId;
        }
      }
      for ( int hi = 0; hi < EEDetId::kSizeForDenseIndexing; ++hi ) {
        EEDetId eeId = EEDetId::unhashIndex(hi);
        if (eeId != EEDetId()) {
          int idx = EBDetId::MAX_HASH + 1 + hi;
          _ids[idx] = eeId;
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
      std::string tag = _tag;
      
      
      
      session.transaction().start( true );
      cond::persistency::IOVProxy iov = session.readIov(tag, true);
      std::string obj_type = iov.payloadObjectType();
      
      
      auto first_iov = iov.begin();
      auto last_iov  = iov.begin();
      for (int i = 0; i < iov.loadedSize() - 1; ++i) ++last_iov;

      
      std::cout << (*first_iov).since << " " << (*last_iov).since << std::endl;
      
      int cnt_iov = 0;
      //---- loop over all the intervals of validity
      for (auto i : iov) {
        cnt_iov++;
        std::shared_ptr<C> pa = session.fetchPayload<C>(i.payloadId);
        //---- loop over the crystals
        for (size_t i = 0; i < _ids.size(); ++i) {
          DetId id(_ids[i]);
          EcalPulseShapes::const_iterator it = pa->find(id);
          if (it == pa->end()) {
            std::cout << "Cannot find value for DetId " << id.rawId() << std::endl;
          }
          coord(_ids[i]);
          std::cout <<  _c.ix_ << " " <<  _c.iy_ << " " <<  _c.iz_ << " ::: " ;
          //---- loop over the N-samples of the pulse shape
          for (int is = 0; is < EcalPulseShape::TEMPLATESAMPLES; ++is) {
            std::cout << it->val(is) << " : " ;
          }
          std::cout << std::endl;
        }
      }
      
      
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
    std::string _tag;
    std::vector<DetId> _ids;
  };
  
}

#endif
