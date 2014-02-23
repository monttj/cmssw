#ifndef PATLite_Photon_H
#define PATLite_Photon_H 

#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/PatCandidates/interface/Photon.h"


// Define typedefs for convenience
namespace patlite {
  class Photon;
  typedef std::vector<patlite::Photon>              PhotonCollection;
  typedef edm::Ref<PhotonCollection>       PhotonRef;
  typedef edm::RefVector<PhotonCollection> PhotonRefVector;
}

namespace patlite{

  typedef reco::Candidate::LorentzVector LorentzVector;

  class Photon : public LorentzVector{
  public:
    Photon();
    Photon(const pat::Photon & aPhoton); 
    virtual ~Photon();

    double test() const { return test_; }
    
  private:
    double test_;
  };
}

#endif
