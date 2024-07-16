#ifndef Action_h
#define Action_h

#include "G4VUserActionInitialization.hh"
#include "ParticleGunAction.hh"
#include "ParticleSourceAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

class ActionInitialization: public G4VUserActionInitialization{
public:
     ActionInitialization();
	 ~ActionInitialization() override;
	 
	 void Build() const override;
};

#endif