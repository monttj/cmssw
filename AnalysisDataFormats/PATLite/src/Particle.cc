#include "AnalysisDataFormats/PATLite/interface/Particle.h"

using namespace lite;

/// default constructor
Particle::Particle(){
}

Particle::Particle(const LorentzVector & aParticle) : LorentzVector(aParticle) {
}

/// destructor
Particle::~Particle() {
}

