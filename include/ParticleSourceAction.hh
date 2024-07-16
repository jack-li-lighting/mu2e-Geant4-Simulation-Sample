#ifndef ParticleSourceAction_h
#define ParticleSourceAction_h

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"


class ParticleSourceAction: public G4VUserPrimaryGeneratorAction{
public:
     ParticleSourceAction();
	 ~ParticleSourceAction();
	 
	 void GeneratePrimaries(G4Event* Event) override;

private:
     G4GeneralParticleSource* main_ParticleSource;
};

#endif