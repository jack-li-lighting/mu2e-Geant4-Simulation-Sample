#include "ActionInitialization.hh"

ActionInitialization::ActionInitialization(){}
ActionInitialization::~ActionInitialization(){}

void ActionInitialization::Build() const {
	//ParticleGunAction* Generator = new ParticleGunAction();
	//SetUserAction(Generator);
	
	ParticleSourceAction* Generator = new ParticleSourceAction();
	SetUserAction(Generator);
	
	RunAction* Run = new RunAction();
	SetUserAction(Run);
	
	EventAction* Event = new EventAction(Run);
	SetUserAction(Event);
	
	SteppingAction* Step = new SteppingAction(Event);
	SetUserAction(Step);
	
	
}