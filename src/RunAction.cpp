#include "RunAction.hh"
#include "G4Run.hh"
#include <iostream>

void RunAction::BeginOfRunAction(const G4Run* run){
	G4RootAnalysisManager* analysis_manager = G4RootAnalysisManager::Instance();
	G4int run_id = run->GetRunID();
	std::stringstream string_run_id;
	string_run_id << run_id;
	
	analysis_manager->OpenFile("Hits" + string_run_id.str() + ".root");
	
	analysis_manager->CreateNtuple("Hits","Photon Hits counter");
	analysis_manager->CreateNtupleIColumn("EventID");
	analysis_manager->CreateNtupleDColumn("Hitxposition");
	analysis_manager->CreateNtupleDColumn("Hityposition");
	analysis_manager->CreateNtupleDColumn("Hitzposition");
	analysis_manager->FinishNtuple(0);
	
	analysis_manager->CreateNtuple("TotalScoring","Energy deposition");
	analysis_manager->CreateNtupleDColumn("EnergyDeposition");
	analysis_manager->FinishNtuple(1);
	
	analysis_manager->CreateNtuple("PositronScoring","Energy deposition");
	analysis_manager->CreateNtupleDColumn("PositronEnergySpectrum");
	analysis_manager->FinishNtuple(2);
	
	analysis_manager->CreateNtuple("SourcePhotonScoring","Source photon energy spectrum");
	analysis_manager->CreateNtupleDColumn("EnergySpectrum");
	analysis_manager->FinishNtuple(3);
	
	analysis_manager->CreateNtuple("PairProductionInTargetCounter","Count the number of pair production events in target");
	analysis_manager->CreateNtupleIColumn("Count");
	analysis_manager->FinishNtuple(4);
	
	analysis_manager->CreateNtuple("PairProductionCounter","Count the number of total pair production events");
	analysis_manager->CreateNtupleIColumn("Count");
	analysis_manager->FinishNtuple(5);
	
	analysis_manager->CreateNtuple("HighEnergyPairProductionInTargetCounter","Count the number of pair production events in target with gamma energy > 90 MeV");
	analysis_manager->CreateNtupleIColumn("Count");
	analysis_manager->FinishNtuple(6);
	
	analysis_manager->CreateNtuple("HighEnergyPairProductionCounter","Count the number of total pair production events with gamma energy > 90 MeV");
	analysis_manager->CreateNtupleIColumn("Count");
	analysis_manager->FinishNtuple(7);
}

void RunAction::EndOfRunAction(const G4Run* run){
	G4RootAnalysisManager* analysis_manager = G4RootAnalysisManager::Instance();
	analysis_manager->Write();
	analysis_manager->CloseFile();
}