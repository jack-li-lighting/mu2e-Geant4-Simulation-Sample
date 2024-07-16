#ifndef RunAction_h
#define RunAction_h

#include "G4UserRunAction.hh"
#include "G4RootAnalysisManager.hh"

class RunAction: public G4UserRunAction{
public:
	RunAction(){};
	~RunAction(){};
	
	void BeginOfRunAction(const G4Run* run) override;
	void EndOfRunAction(const G4Run* run) override;
};

#endif