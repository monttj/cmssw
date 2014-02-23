#include "AnalysisDataFormats/PATLite/interface/Photon.h"

/// default constructor
patlite::Photon::Photon() {
}

patlite::Photon::Photon(const pat::Photon & aPhoton) {
  test_ = aPhoton.chargedHadronIso();
}

/// destructor
patlite::Photon::~Photon() {
}

