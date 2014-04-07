//
//

#include "PhysicsTools/PatAlgos/plugins/PATLiteMuonProducer.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "DataFormats/Common/interface/View.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"

#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterTools.h"

#include "TVector2.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "AnalysisDataFormats/PATLite/interface/Muon.h"

#include <memory>

using namespace lite;

PATLiteMuonProducer::PATLiteMuonProducer(const edm::ParameterSet & iConfig) {
  // initialize the configurables
  std::cout << "initialize PATLiteMuonProducer" << std::endl;
  muonToken_ = consumes<edm::View<pat::Muon> >(iConfig.getParameter<edm::InputTag>("muonSource"));

  // produces vector of muons
  produces<std::vector<lite::Muon> >();
  std::cout << "constructor PATLiteMuonProducer" << std::endl;
}

PATLiteMuonProducer::~PATLiteMuonProducer() {
}

void PATLiteMuonProducer::produce(edm::Event & iEvent, const edm::EventSetup & iSetup)
{
  // Get the vector of Muon's from the event
  edm::Handle<edm::View<pat::Muon> > muons;
  iEvent.getByToken(muonToken_, muons);

  std::cout << "PATLiteMuonProducer ... producing" << std::endl;

  // loop over muons
  std::vector<lite::Muon> * PATLiteMuons = new std::vector<lite::Muon>();
  for (edm::View<pat::Muon>::const_iterator itMuon = muons->begin(); itMuon != muons->end(); itMuon++) {
    // construct the Muon from the ref -> save ref to original object
    unsigned int idx = itMuon - muons->begin();
    const pat::Muon & aMuon = muons->at(idx);
    std::cout << "ici1" << std::endl;
    lite::Muon aLiteMuon(aMuon);
    std::cout << "ici2" << std::endl;
    PATLiteMuons->push_back(aLiteMuon);
  }

  // put genEvt object in Event
  std::auto_ptr<std::vector<lite::Muon> > myLiteMuons(PATLiteMuons);
  iEvent.put(myLiteMuons);

}

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE(PATLiteMuonProducer);
