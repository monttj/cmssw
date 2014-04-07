#ifndef PATLite_Particle_H
#define PATLite_Particle_H 

#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/PatCandidates/interface/Particle.h"


// Define typedefs for convenience
namespace lite {
  class Particle;
  typedef std::vector<Particle>              ParticleCollection;
  typedef edm::Ref<ParticleCollection>       ParticleRef;
  typedef edm::RefVector<ParticleCollection> ParticleRefVector;
}

namespace lite {

  typedef reco::Candidate::LorentzVector LorentzVector;

  class Particle : public LorentzVector{
  public:
    Particle();
    Particle(const LorentzVector & aParticle); 
    virtual ~Particle();
    
  private:

  };
}

#endif
