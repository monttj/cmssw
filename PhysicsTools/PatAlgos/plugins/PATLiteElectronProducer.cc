//
//

#include "PhysicsTools/PatAlgos/plugins/PATLiteElectronProducer.h"
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

#include "AnalysisDataFormats/PATLite/interface/Electron.h"

#include <memory>

using namespace lite;

PATLiteElectronProducer::PATLiteElectronProducer(const edm::ParameterSet & iConfig) {
  // initialize the configurables
  electronToken_ = consumes<edm::View<pat::Electron> >(iConfig.getParameter<edm::InputTag>("electronSource"));

  // produces vector of electrons
  produces<std::vector<lite::Electron> >();

}

PATLiteElectronProducer::~PATLiteElectronProducer() {
}

void PATLiteElectronProducer::produce(edm::Event & iEvent, const edm::EventSetup & iSetup)
{
  // Get the vector of Electron's from the event
  edm::Handle<edm::View<pat::Electron> > electrons;
  iEvent.getByToken(electronToken_, electrons);

  // loop over electrons
  std::vector<lite::Electron> * PATLiteElectrons = new std::vector<lite::Electron>();
  for (edm::View<pat::Electron>::const_iterator itElectron = electrons->begin(); itElectron != electrons->end(); itElectron++) {
    // construct the Electron from the ref -> save ref to original object
    unsigned int idx = itElectron - electrons->begin();
    const pat::Electron & aElectron = electrons->at(idx);
    lite::Electron aLiteElectron(aElectron);
    PATLiteElectrons->push_back(aLiteElectron);
  }

  // put genEvt object in Event
  std::auto_ptr<std::vector<lite::Electron> > myLiteElectrons(PATLiteElectrons);
  iEvent.put(myLiteElectrons);

}

#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE(PATLiteElectronProducer);
