#ifndef PATLite_Muon_H
#define PATLite_Muon_H 

#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "AnalysisDataFormats/PATLite/interface/Particle.h"
#include "AnalysisDataFormats/PATLite/interface/Lepton.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

// Define typedefs for convenience
namespace lite {
  class Muon;
  typedef std::vector<Muon>              MuonCollection;
  typedef edm::Ref<MuonCollection>       MuonRef;
  typedef edm::RefVector<MuonCollection> MuonRefVector;
}

namespace lite {

  class Muon : public Lepton{
  public:
    Muon();
    Muon(const pat::Muon & aMuon); 
    virtual ~Muon();

    bool isTightMuon() const { return isTightMuon_; }
    bool isLooseMuon() const { return isLooseMuon_; } 
    bool isSoftMuon() const { return isSoftMuon_; } 
  
  private:

    bool isTightMuon_; 
    bool isLooseMuon_; 
    bool isSoftMuon_;

  };
}

#endif
