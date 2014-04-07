#include "AnalysisDataFormats/PATLite/interface/Muon.h"

using namespace lite;

/// default constructor
Muon::Muon() {
}

Muon::Muon(const pat::Muon & aMuon) : Lepton( aMuon.p4() ) {

  chargedHadronIso_ = aMuon.chargedHadronIso();
  puChargedHadronIso_ = aMuon.puChargedHadronIso();
  neutralHadronIso_ = aMuon.neutralHadronIso();
  photonIso_ =  aMuon.photonIso();

  isLooseMuon_ = aMuon.isLooseMuon();

}

/// destructor
Muon::~Muon() {
}
