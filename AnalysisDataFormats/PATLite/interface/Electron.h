#ifndef PATLite_Electron_H
#define PATLite_Electron_H 

#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "AnalysisDataFormats/PATLite/interface/Particle.h"
#include "AnalysisDataFormats/PATLite/interface/Lepton.h"
#include "DataFormats/PatCandidates/interface/Electron.h"


// Define typedefs for convenience
namespace lite {
  class Electron;
  typedef std::vector<Electron>              ElectronCollection;
  typedef edm::Ref<ElectronCollection>       ElectronRef;
  typedef edm::RefVector<ElectronCollection> ElectronRefVector;
}

namespace lite {

  class Electron : public Lepton{
  public:
    Electron();
    Electron(const pat::Electron & aElectron); 
    virtual ~Electron();

    double mvaTrigV0() const { return mvaTrigV0_; } 
    double mvaNoTrigV0() const { return mvaNoTrigV0_; } 
  
  private:
   
    double mvaTrigV0_;
    double mvaNoTrigV0_;
  
  };
}

#endif
