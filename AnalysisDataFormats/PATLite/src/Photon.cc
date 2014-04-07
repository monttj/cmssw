#include "AnalysisDataFormats/PATLite/interface/Photon.h"

using namespace lite;

/// default constructor
Photon::Photon() {
}

Photon::Photon(const pat::Photon & aPhoton) : Particle( aPhoton.p4() ) {
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
Photon::~Photon() {
}

