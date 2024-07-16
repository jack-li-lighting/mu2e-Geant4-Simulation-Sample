#ifndef eventaction_hh
#define eventaction_hh

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4RootAnalysisManager.hh"
#include "RunAction.hh"

class EventAction:public G4UserEventAction{
	public:
	EventAction(RunAction* run);
	~EventAction();
	
	void BeginOfEventAction(const G4Event* event) override;
	void EndOfEventAction(const G4Event* event) override;
	void AddEnergy(G4double edep);
	void AddInTargetCounter();
	void AddCounter();
	void HighEnergyCounter();
	void HighEnergyInTargetCounter();
	
	private:
	G4double AccuEnergyDep;
	G4int PairProInTargetCounter;
	G4int PairProCounter;
	G4int HighEnePairProInTargetCounter;
	G4int HighEnePairProCounter;
};
#endif