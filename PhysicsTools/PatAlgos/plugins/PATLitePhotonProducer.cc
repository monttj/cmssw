//
//

#include "PhysicsTools/PatAlgos/plugins/PATLitePhotonProducer.h"
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

#include "AnalysisDataFormats/PATLite/interface/Photon.h"

#include <memory>

using namespace lite;

PATLitePhotonProducer::PATLitePhotonProducer(const edm::ParameterSet & iConfig) {
  // initialize the configurables
  photonToken_ = consumes<edm::View<pat::Photon> >(iConfig.getParameter<edm::InputTag>("photonSource"));

  // produces vector of photons
  produces<std::vector<lite::Photon> >();

}

PATLitePhotonProducer::~PATLitePhotonProducer() {
}

void PATLitePhotonProducer::produce(edm::Event & iEvent, const edm::EventSetup & iSetup)
{
  // Get the vector of Photon's from the event
  edm::Handle<edm::View<pat::Photon> > photons;
  iEvent.getByToken(photonToken_, photons);

  // loop over photons
  std::vector<lite::Photon> * PATLitePhotons = new std::vector<lite::Photon>();
  for (edm::View<pat::Photon>::const_iterator itPhoton = photons->begin(); itPhoton != photons->end(); itPhoton++) {
    // construct the Photon from the ref -> save ref to original object
    unsigned int idx = itPhoton - photons->begin();
    const pat::Photon & aPhoton = photons->at(idx);
    lite::Photon aLitePhoton(aPhoton);
    PATLitePhotons->push_back(aLitePhoton);
  }

  // put genEvt object in Event
  std::auto_ptr<std::vector<lite::Photon> > myLitePhotons(PATLitePhotons);
  iEvent.put(myLitePhotons);

}

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE(PATLitePhotonProducer);
