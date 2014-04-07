#include "DataFormats/Common/interface/Wrapper.h"

#include "AnalysisDataFormats/PATLite/interface/Particle.h"
#include "AnalysisDataFormats/PATLite/interface/Muon.h"
#include "AnalysisDataFormats/PATLite/interface/Electron.h"
#include "AnalysisDataFormats/PATLite/interface/Photon.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include <vector>

#include <TMatrixD.h>

namespace {
  struct PATLite_AnalysisDataFormats {

    lite::Particle a_;
    std::vector<lite::Particle> av;
    edm::Wrapper<lite::Particle> ae;
    edm::Wrapper<std::vector<lite::Particle> > aav;
    edm::Ptr<lite::Particle> aPtr;

    lite::Muon m_;
    std::vector<lite::Muon> mv;
    edm::Wrapper<lite::Muon> me;
    edm::Wrapper<std::vector<lite::Muon> > mmv;
    edm::Ptr<lite::Muon> mPtr;

    lite::Electron e_;
    std::vector<lite::Electron> ev;
    edm::Wrapper<lite::Electron> ee;
    edm::Wrapper<std::vector<lite::Electron> > eev;
    edm::Ptr<lite::Electron> ePtr;

    lite::Photon p_;
    std::vector<lite::Photon> pv;
    edm::Wrapper<lite::Photon> pe;
    edm::Wrapper<std::vector<lite::Photon> > ppv;
    edm::Ptr<lite::Photon> pPtr;

  };
  

}
