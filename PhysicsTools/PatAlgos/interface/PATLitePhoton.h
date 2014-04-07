#ifndef PHOTONFACTORY_H_
#define PHOTONFACTORY_H_

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "AnalysisDataFormats/CMGTools/interface/Photon.h"
#include "AnalysisDataFormats/CMGTools/interface/PatTypes.h"
#include "CMGTools/Common/interface/Factory.h"

namespace pat {

  class PhotonFactory : public Factory<pat::Photon> {
  public:
    PhotonFactory(const edm::ParameterSet& ps):
      photonLabel_(ps.getParameter<edm::InputTag>("inputCollection")),
{
}

    virtual event_ptr create(const edm::Event&, const edm::EventSetup&);
    virtual void set(const pat::PhotonPtr& input, pat::Photon* const output) const;

  private:
    const edm::InputTag photonLabel_;
   
  };

} // namespace cmg

#endif /*PHOTONFACTORY_H_*/
