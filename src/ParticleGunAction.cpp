#include "ParticleGunAction.hh"

ParticleGunAction::ParticleGunAction(){
	main_ParticleGun = new G4ParticleGun();
	
	G4ParticleTable* ParticleTable = G4ParticleTable::GetParticleTable();
	G4String ParticleName = "mu-";
	G4ParticleDefinition* Particle = ParticleTable -> FindParticle("mu-");//create particle
	
	G4ThreeVector position(0.,0.,-2.5); //create where the particle gun initiates
	G4ThreeVector momentum(0.,0.,1.);
	
	main_ParticleGun->SetParticlePosition(position*m);
	main_ParticleGun->SetParticleMomentumDirection(momentum);
	main_ParticleGun->SetParticleMomentum(100*GeV);
	main_ParticleGun->SetParticleDefinition(Particle);
	
}

ParticleGunAction::~ParticleGunAction(){
	delete main_ParticleGun;
}

void ParticleGunAction::GeneratePrimaries(G4Event* Event){
	main_ParticleGun->GeneratePrimaryVertex(Event);
}