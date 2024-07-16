#include "EventAction.hh"

EventAction::EventAction(RunAction* run){
	AccuEnergyDep = 0;
}

EventAction::~EventAction(){}

void EventAction::BeginOfEventAction(const G4Event* event){
	AccuEnergyDep = 0;
	PairProInTargetCounter = 0;
	PairProCounter = 0;
}

void EventAction::EndOfEventAction(const G4Event* event){
	G4RootAnalysisManager* analysis_manager = G4RootAnalysisManager::Instance();
	analysis_manager->FillNtupleDColumn (1,0,AccuEnergyDep);
	analysis_manager->AddNtupleRow(1);
	
	std::cout << "Energy deposited is:" << AccuEnergyDep << " MeV" << std::endl;
	
	analysis_manager->FillNtupleIColumn (4,0,PairProInTargetCounter);
	analysis_manager->AddNtupleRow(4);
	
	analysis_manager->FillNtupleIColumn (5,0,PairProCounter);
	analysis_manager->AddNtupleRow(5);
}

void EventAction::AddEnergy(G4double edep){
	AccuEnergyDep = AccuEnergyDep + edep;
}

void EventAction::AddInTargetCounter(){
	PairProInTargetCounter += 1;
}

void EventAction::AddCounter(){
	PairProCounter += 1;
}

void EventAction::HighEnergyCounter(){
	HighEnePairProCounter += 1;
}

void EventAction::HighEnergyInTargetCounter(){
	HighEnePairProInTargetCounter += 1;
}