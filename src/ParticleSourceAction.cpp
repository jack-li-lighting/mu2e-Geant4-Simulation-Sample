#include "ParticleSourceAction.hh"

ParticleSourceAction::ParticleSourceAction(){
	main_ParticleSource = new G4GeneralParticleSource();
	
	G4ParticleTable* ParticleTable = G4ParticleTable::GetParticleTable();
	G4String ParticleName = "mu-";
	G4ParticleDefinition* Particle = ParticleTable -> FindParticle("mu-");//create particle
	
	main_ParticleSource->SetParticleDefinition(Particle);
}

ParticleSourceAction::~ParticleSourceAction(){
	delete main_ParticleSource;
}

void ParticleSourceAction::GeneratePrimaries(G4Event* Event){
	main_ParticleSource->GeneratePrimaryVertex(Event);
}