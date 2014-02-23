#include "AnalysisDataFormats/PATLite/interface/Photon.h"

/// default constructor
lite::Photon::Photon() {
}

lite::Photon::Photon(const pat::Photon & aPhoton) {
  test_ = aPhoton.chargedHadronIso();
}

/// destructor
lite::Photon::~Photon() {
}

