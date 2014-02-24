#ifndef PATLite_Photon_H
#define PATLite_Photon_H 

#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "AnalysisDataFormats/PATLite/interface/Particle.h"
#include "DataFormats/PatCandidates/interface/Photon.h"


// Define typedefs for convenience
namespace lite {
  class Photon;
  typedef std::vector<Photon>              PhotonCollection;
  typedef edm::Ref<PhotonCollection>       PhotonRef;
  typedef edm::RefVector<PhotonCollection> PhotonRefVector;
}

namespace lite {

  class Photon : public Particle{
  public:
    Photon();
    Photon(const pat::Photon & aPhoton); 
    virtual ~Photon();

    double chargedHadronIso() const { return chargedHadronIso_; }
    double puChargedHadronIso() const { return puChargedHadronIso_; }
    double neutralHadronIso() const { return neutralHadronIso_; }
    double photonIso() const { return photonIso_; }
    double hadronicOverEm() const { return hadronicOverEm_; }
    double sigmaIetaIeta() const { return sigmaIetaIeta_; }
  
    bool passElectronVeto() const { return passElectronVeto_; }
    bool hasPixelSeed() const { return hasPixelSeed_; } 
  
  private:
    double chargedHadronIso_;
    double puChargedHadronIso_;
    double neutralHadronIso_;
    double photonIso_;
    double hadronicOverEm_;
    double sigmaIetaIeta_;
  
    bool passElectronVeto_;
    bool hasPixelSeed_;

  };
}

#endif
