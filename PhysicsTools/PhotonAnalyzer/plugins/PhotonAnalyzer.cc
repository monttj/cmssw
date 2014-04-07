// -*- C++ -*-
//
// Package:    PhysicsTools/PhotonAnalyzer
// Class:      PhotonAnalyzer
// 
/**\class PhotonAnalyzer PhotonAnalyzer.cc PhysicsTools/PhotonAnalyzer/plugins/PhotonAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Tae Jeong Kim
//         Created:  Fri, 14 Feb 2014 12:36:54 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/PatCandidates/interface/Photon.h"
#include "AnalysisDataFormats/PATLite/interface/Photon.h"
//
// class declaration
//

class PhotonAnalyzer : public edm::EDAnalyzer {
   public:
      explicit PhotonAnalyzer(const edm::ParameterSet&);
      ~PhotonAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      //typedef pat::LitePhotonCollection::const_iterator PI;
      typedef lite::PhotonCollection::const_iterator PI;

      //typedef std::vector<pat::LitePhoton>::const_iterator PI;

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
PhotonAnalyzer::PhotonAnalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed

}


PhotonAnalyzer::~PhotonAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
PhotonAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

  // Get the vector of Photon's from the event
  //edm::Handle<edm::View<pat::LitePhoton> > photons;
  //edm::Handle<pat::PhotonCollection> photons;
  edm::Handle<lite::PhotonCollection> photons;

  //iEvent.getByLabel("selectedPatPhotons", photons);
  iEvent.getByLabel("patLitePhotons", photons);

  for(PI ph = photons->begin(); ph!=photons->end(); ++ph)  {  
  //for(unsigned int i = 0; i < photons->size() ; ++i)  {  
    //const pat::LitePhoton & ph = photons->at(i);
    std::cout << "chargedhadron= " << ph->chargedHadronIso() << std::endl;
    std::cout << "puChargedhadron= " << ph->puChargedHadronIso() << std::endl;
    std::cout << "neutralHadron= " << ph->neutralHadronIso() << std::endl;
    std::cout << "photon= " << ph->photonIso() << std::endl;
    /*
    std::cout << "super cluster size = " << ph->superCluster()->clustersSize() << std::endl; 
    std::cout << "super cluster eta = " << ph->superCluster()->eta() << std::endl; 
    std::cout << "super cluster etaWidth = " << ph->superCluster()->etaWidth() << std::endl; 
    std::cout << "super cluster phi = " << ph->superCluster()->phi() << std::endl; 
    std::cout << "super cluster phiWidth = " << ph->superCluster()->phiWidth() << std::endl; 
    std::cout << "super cluster rawEnergy = " << ph->superCluster()->rawEnergy() << std::endl; 
    std::cout << "super cluster calibEnergy = " << ph->superCluster()->correctedEnergy() << std::endl; 
    std::cout << "super cluster seedEnergy = " << ph->seedEnergy() << std::endl; 
    std::cout << "has pixel seed = " << ph->hasPixelSeed() << std::endl; 
    std::cout << "see = " << ph->see() << std::endl; 
    std::cout << "spp = " << ph->spp() << std::endl; 
    std::cout << "sep = " << ph->sep() << std::endl; 
    std::cout << "sigmaEtaEta= " << ph->sigmaEtaEta() << std::endl;
    std::cout << "sigmaIetaIeta= " << ph->sigmaIetaIeta() << std::endl;
    std::cout << "eMax = " << ph->eMax() << std::endl; 
    std::cout << "e2nd = " << ph->e2nd() << std::endl; 
    std::cout << "e3x3 = " << ph->e3x3() << std::endl; 
    std::cout << "maxDR = " << ph->maxDR() << std::endl; 
    std::cout << "maxDRDPhi = " << ph->maxDRDPhi() << std::endl; 
    std::cout << "maxDRDEta = " << ph->maxDRDEta() << std::endl; 
    std::cout << "maxDRRawEnergy = " << ph->maxDRRawEnergy() << std::endl; 
    std::cout << "subClusRawE[0]= " << ph->subClusRawE1() << std::endl;
    std::cout << "subClusRawE[1]= " << ph->subClusRawE2() << std::endl;
    std::cout << "subClusRawE[2]= " << ph->subClusRawE3() << std::endl;
    std::cout << "subClusDPhi[0]= " << ph->subClusDPhi1() << std::endl;
    std::cout << "subClusDPhi[1]= " << ph->subClusDPhi2() << std::endl;
    std::cout << "subClusDPhi[2]= " << ph->subClusDPhi3() << std::endl;
    std::cout << "subClusDEta[0]= " << ph->subClusDEta1() << std::endl;
    std::cout << "subClusDEta[1]= " << ph->subClusDEta2() << std::endl;
    std::cout << "subClusDEta[2]= " << ph->subClusDEta3() << std::endl;
    std::cout << "cryEta= " << ph->cryEta() << std::endl;
    std::cout << "cryPhi= " << ph->cryPhi() << std::endl;
    std::cout << "iEta= " << ph->iEta() << std::endl;
    std::cout << "iPhi= " << ph->iPhi() << std::endl;
    */
  }
 
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
PhotonAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
PhotonAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
PhotonAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
PhotonAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
PhotonAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
PhotonAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
PhotonAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(PhotonAnalyzer);
