import FWCore.ParameterSet.Config as cms

patLiteMuons = cms.EDProducer("PATLiteMuonProducer",
    # input collection
    muonSource = cms.InputTag("patMuons"),
)
