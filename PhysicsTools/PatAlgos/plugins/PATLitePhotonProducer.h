//
//

#ifndef PhysicsTools_PatAlgos_PATLitePhotonProducer_h
#define PhysicsTools_PatAlgos_PATLitePhotonProducer_h

/**
  \class    pat::PATLitePhotonProducer PATLitePhotonProducer.h "PhysicsTools/PatAlgos/interface/PATLitePhotonProducer.h"
  \brief    Produces the pat::Photon

   The PATLitePhotonProducer produces the analysis-level pat::Photon starting from
   a collection of objects of PhotonType.

  \author   Steven Lowette
  \version  $Id: PATLitePhotonProducer.h,v 1.19 2009/06/25 23:49:35 gpetrucc Exp $
*/


#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"


#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"

#include "CommonTools/Utils/interface/EtComparator.h"

#include "AnalysisDataFormats/PATLite/interface/Muon.h"
#include "AnalysisDataFormats/PATLite/interface/Electron.h"
#include "AnalysisDataFormats/PATLite/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
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

  class PATLitePhotonProducer : public edm::EDProducer {

    public:

      explicit PATLitePhotonProducer(const edm::ParameterSet & iConfig);
      ~PATLitePhotonProducer();

      virtual void produce(edm::Event & iEvent, const edm::EventSetup& iSetup) override;

    private:

      // configurables
      edm::EDGetTokenT<edm::View<pat::Photon> > photonToken_;
  };

}

using namespace pat;

#endif
