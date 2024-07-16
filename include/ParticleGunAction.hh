#ifndef ParticleGunAction_h
#define ParticleGunAction_h

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"


class ParticleGunAction: public G4VUserPrimaryGeneratorAction{
public:
     ParticleGunAction();
	 ~ParticleGunAction();
	 
	 void GeneratePrimaries(G4Event* Event) override;

private:
     G4ParticleGun* main_ParticleGun;
};

#endif