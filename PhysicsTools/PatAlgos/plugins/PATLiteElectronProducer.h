//
//

#ifndef PhysicsTools_PatAlgos_PATLiteElectronProducer_h
#define PhysicsTools_PatAlgos_PATLiteElectronProducer_h

/**
  \class    pat::PATLiteElectronProducer PATLiteElectronProducer.h "PhysicsTools/PatAlgos/interface/PATLiteElectronProducer.h"
  \brief    Produces the pat::Electron

   The PATLiteElectronProducer produces the analysis-level pat::Electron starting from
   a collection of objects of ElectronType.

  \author   Steven Lowette
  \version  $Id: PATLiteElectronProducer.h,v 1.19 2009/06/25 23:49:35 gpetrucc Exp $
*/


#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"


#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"

#include "CommonTools/Utils/interface/EtComparator.h"

#include "AnalysisDataFormats/PATLite/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"

#include "PhysicsTools/PatAlgos/interface/MultiIsolator.h"
#include "PhysicsTools/PatAlgos/interface/EfficiencyLoader.h"
#include "PhysicsTools/PatAlgos/interface/KinResolutionsLoader.h"


#include "DataFormats/PatCandidates/interface/UserData.h"
#include "PhysicsTools/PatAlgos/interface/PATUserDataHelper.h"

#include "RecoEgamma/EgammaTools/interface/EcalClusterLocal.h"
#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"

namespace pat {

  class PATLiteElectronProducer : public edm::EDProducer {

    public:

      explicit PATLiteElectronProducer(const edm::ParameterSet & iConfig);
      ~PATLiteElectronProducer();

      virtual void produce(edm::Event & iEvent, const edm::EventSetup& iSetup) override;

    private:

      // configurables
      edm::EDGetTokenT<edm::View<pat::Electron> > electronToken_;
  };

}

using namespace pat;

#endif
