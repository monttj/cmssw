#ifndef PATLite_Lepton_H
#define PATLite_Lepton_H 

#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "AnalysisDataFormats/PATLite/interface/Particle.h"
#include "DataFormats/PatCandidates/interface/Lepton.h"


// Define typedefs for convenience
namespace lite {
  class Lepton;
  typedef std::vector<Lepton>              LeptonCollection;
  typedef edm::Ref<LeptonCollection>       LeptonRef;
  typedef edm::RefVector<LeptonCollection> LeptonRefVector;
}

namespace lite {

  class Lepton : public Particle{
  public:
    Lepton() {}
    Lepton(const LorentzVector & aLepton) : Particle ( aLepton ){} 
    virtual ~Lepton(){}

    double chargedHadronIso() const { return chargedHadronIso_;  } 
    double puChargedHadronIso() const { return puChargedHadronIso_; }
    double neutralHadronIso() const { return neutralHadronIso_; }
    double photonIso() const { return photonIso_; }
  
  
  protected:

    double chargedHadronIso_;
    double puChargedHadronIso_;
    double neutralHadronIso_;
    double photonIso_;
  
  };
}

#endif
