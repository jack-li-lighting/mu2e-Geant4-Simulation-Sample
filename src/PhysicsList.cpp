#include "PhysicsList.hh"

PhysicsList::PhysicsList() {
	G4VModularPhysicsList::RegisterPhysics(new G4EmStandardPhysics());
	G4VModularPhysicsList::RegisterPhysics(new G4OpticalPhysics());
}

PhysicsList::~PhysicsList() {}