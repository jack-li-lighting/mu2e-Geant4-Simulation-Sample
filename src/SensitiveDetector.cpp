#include "SensitiveDetector.hh"

SensitiveDetector::SensitiveDetector(G4String name):G4VSensitiveDetector(name){}
SensitiveDetector::~SensitiveDetector(){}

G4bool SensitiveDetector::ProcessHits (G4Step *aStep, G4TouchableHistory *ROhist){
	G4Track* Track = aStep->GetTrack();
	G4int EventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
	
	G4StepPoint* prestep = aStep->GetPreStepPoint();
	G4StepPoint* poststep = aStep->GetPostStepPoint();
	G4ThreeVector photon_position = prestep->GetPosition();
	//G4cout << "Photon hit position is:" << photon_position << G4endl;
	
	const G4VTouchable* touchable = prestep -> GetTouchable();
	G4VPhysicalVolume* physic_hit = touchable -> GetVolume();
	G4ThreeVector hit_position = physic_hit->GetTranslation();
	//std::cout << "Photon hit position is:" << hit_position << std::endl;
	
	
	G4RootAnalysisManager* analysis_manager = G4RootAnalysisManager::Instance();
	analysis_manager->FillNtupleIColumn(0,EventID);
	analysis_manager->FillNtupleDColumn(1,hit_position[0]);
	analysis_manager->FillNtupleDColumn(2,hit_position[1]);
	analysis_manager->FillNtupleDColumn(3,hit_position[2]);
	analysis_manager->AddNtupleRow(0);
	
	return true;
}