#include "DataFormats/Common/interface/Wrapper.h"

#include "AnalysisDataFormats/PATLite/interface/Photon.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include <vector>

#include <TMatrixD.h>

namespace {
  struct PATLite_AnalysisDataFormats {

    patlite::Photon p_;
    std::vector<patlite::Photon> pv;
    edm::Wrapper<patlite::Photon> pe;
    edm::Wrapper<std::vector<patlite::Photon> > ppv;
    edm::Ptr<patlite::Photon> pPtr;

  };
  

}
