#ifndef steppingaction_hh
#define steppingaction_hh

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4RootAnalysisManager.hh"


class SteppingAction:public G4UserSteppingAction{
	public:
	SteppingAction(EventAction* event);
	~SteppingAction();
	
	void UserSteppingAction (const G4Step* step) override;
	
	private:
	EventAction* fEventAction;
};
#endif