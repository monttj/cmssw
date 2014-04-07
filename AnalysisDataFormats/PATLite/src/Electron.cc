#include "AnalysisDataFormats/PATLite/interface/Electron.h"

using namespace lite;

/// default constructor
Electron::Electron() {
}

Electron::Electron(const pat::Electron & aElectron) : Lepton ( aElectron.p4() ) {
  chargedHadronIso_ = aElectron.chargedHadronIso();
  puChargedHadronIso_ = aElectron.puChargedHadronIso();
  neutralHadronIso_ = aElectron.neutralHadronIso();
  photonIso_ =  aElectron.photonIso();

  mvaTrigV0_ = aElectron.electronID("mvaTrigV0");
  mvaNoTrigV0_ = aElectron.electronID("mvaNoTrigV0");

}

/// destructor
Electron::~Electron() {
}

