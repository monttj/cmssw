import FWCore.ParameterSet.Config as cms

patLiteElectrons = cms.EDProducer("PATLiteElectronProducer",
    # input collection
    electronSource = cms.InputTag("patElectrons"),
)
