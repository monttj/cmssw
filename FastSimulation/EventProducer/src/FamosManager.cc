// CMSSW Header
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "SimDataFormats/Track/interface/EmbdSimTrackContainer.h"
#include "SimDataFormats/Vertex/interface/EmbdSimVertexContainer.h"

#include "DataFormats/Common/interface/EventID.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "DetectorDescription/Core/interface/DDCompactView.h"
#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"


// CLHEP headers
#include "CLHEP/HepMC/GenEvent.h"

// FAMOS Header
#include "FastSimulation/EventProducer/interface/FamosManager.h"
#include "FastSimulation/TrajectoryManager/interface/TrajectoryManager.h"
#include "FastSimulation/Event/interface/FSimEvent.h"
#include "FastSimulation/ParticlePropagator/interface/MagneticFieldMap.h"
  
#include <iostream>
#include <memory>
#include <vector>

using namespace HepMC;
using namespace std;

FamosManager::FamosManager(edm::ParameterSet const & p)
    : iEvent(0),
      myGenEvent(0),
      mySimEvent(new FSimEvent()),
      myTrajectoryManager(new TrajectoryManager(mySimEvent)),
      m_pUseMagneticField(p.getParameter<bool>("UseMagneticField")),
      m_pRunNumber(p.getUntrackedParameter<int>("RunNumber",1)),
      m_pVerbose(p.getUntrackedParameter<int>("Verbosity",1))
{}

FamosManager::~FamosManager()
{ 
  if (!mySimEvent) delete mySimEvent; 
  if (!myTrajectoryManager) delete myTrajectoryManager; 
}

void FamosManager::setupGeometryAndField(const edm::EventSetup & es)
{
    // geometry
  edm::ESHandle<DDCompactView> pDD;
  es.get<IdealGeometryRecord>().get(pDD);

    // magnetic field
  if (m_pUseMagneticField) {
    edm::ESHandle<MagneticField> pMF;
    es.get<IdealMagneticFieldRecord>().get(pMF);
    const GlobalPoint g(0.,0.,0.);
    std::cout << "B-field(T) at (0,0,0)(cm): " << pMF->inTesla(g) << std::endl;      
    MagneticFieldMap::instance(pMF); 
 }    
  
  // Pass the information to a singleton

}

/*
void FamosManager::initEventReader()
{
    if (inputFile_!=0) delete inputFile_;
    std::cout << "Input file name: " << m_pInputFileName << std::endl;
    inputFile_ = new std::ifstream(m_pInputFileName.c_str(),std::ios::in);
}
*/


void 
FamosManager::reconstruct(const GenEvent* evt) {

  myGenEvent = evt;

  if (evt != 0) {
    iEvent++;
    edm::EventID id(m_pRunNumber,iEvent);


    // Fill the event from the original generated event
    mySimEvent->fill(*evt,id);
    //    mySimEvent->print();

    // And propagate the particles through the detector
    myTrajectoryManager->reconstruct();
    //    mySimEvent->print();

    }
  std::cout << " saved : Event  " << iEvent 
	    << " of weight " << mySimEvent->weight()
	    << " with " << mySimEvent->nTracks() 
	    << " tracks and " << mySimEvent->nVertices()
	    << " vertices, generated by " 
	    << mySimEvent->nGenParts() << " particles " << std::endl;
  
}
