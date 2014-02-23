#include "DataFormats/Common/interface/Wrapper.h"

#include "AnalysisDataFormats/PATLite/interface/Photon.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include <vector>

#include <TMatrixD.h>

namespace {
  struct PATLite_AnalysisDataFormats {

    lite::Photon p_;
    std::vector<lite::Photon> pv;
    edm::Wrapper<lite::Photon> pe;
    edm::Wrapper<std::vector<lite::Photon> > ppv;
    edm::Ptr<lite::Photon> pPtr;

  };
  

}
