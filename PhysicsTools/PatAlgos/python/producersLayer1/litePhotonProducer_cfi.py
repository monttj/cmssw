import FWCore.ParameterSet.Config as cms

patLitePhotons = cms.EDProducer("PATLitePhotonProducer",
    # input collection
    photonSource = cms.InputTag("patPhotons"),
)
