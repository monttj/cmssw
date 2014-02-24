#include "AnalysisDataFormats/PATLite/interface/Photon.h"

/// default constructor
lite::Photon::Photon() {
}

lite::Photon::Photon(const pat::Photon & aPhoton) {
  chargedHadronIso_ = aPhoton.chargedHadronIso();
  puChargedHadronIso_ = aPhoton.puChargedHadronIso();
  neutralHadronIso_ = aPhoton.neutralHadronIso();
  photonIso_ =  aPhoton.photonIso();
  hadronicOverEm_ = aPhoton.hadronicOverEm();
  sigmaIetaIeta_ = aPhoton.sigmaIetaIeta();

  passElectronVeto_ = aPhoton.passElectronVeto();
  hasPixelSeed_ = aPhoton.hasPixelSeed();
}

/// destructor
lite::Photon::~Photon() {
}

