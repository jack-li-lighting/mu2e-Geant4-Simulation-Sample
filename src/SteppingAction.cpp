#include "SteppingAction.hh"

SteppingAction::SteppingAction(EventAction* event) {
	fEventAction = event;
}

SteppingAction::~SteppingAction(){}

void SteppingAction::UserSteppingAction(const G4Step* step){
	G4double edep = step->GetTotalEnergyDeposit();
	//std::cout << "the current step energy deposit:" << edep << std::endl;
	
	G4LogicalVolume* logic_prestep_volume = step->GetPreStepPoint ()->GetTouchable ()->GetVolume ()->GetLogicalVolume ();
	G4LogicalVolume* logic_poststep_volume = step->GetPostStepPoint ()->GetTouchable ()->GetVolume ()->GetLogicalVolume ();
	
	const DetectorConstruction* current_detector_construction = static_cast <const DetectorConstruction*>
	(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
	G4LogicalVolume* logic_sensitive_volume = current_detector_construction -> GetSensitiveVolume();
	G4LogicalVolume* logic_target_volume = current_detector_construction -> GetTargetVolume();
	
	//add total energy deposition to accumulator
	if (logic_prestep_volume == logic_target_volume){
	fEventAction->AddEnergy(edep);
	}
	
	//define particle type to be identified
	G4Track* track = step -> GetTrack();
	G4ParticleTable* ParticleTable = G4ParticleTable::GetParticleTable();
	G4String ParticleName = "e+";
	G4String ParticleNameGamma = "gamma";
	G4ParticleDefinition* positron = ParticleTable -> FindParticle(ParticleName);
	G4ParticleDefinition* gamma = ParticleTable -> FindParticle(ParticleNameGamma);
	
	//define process name
	G4String conv = "conv";

    //particle process identification	
	if (track -> GetCreatorProcess()!= nullptr){
		if (track -> GetCreatorProcess()-> GetProcessName()!= nullptr){
			if(track-> GetParticleDefinition()== positron && logic_prestep_volume == logic_target_volume){
				G4String proc = track -> GetCreatorProcess() -> GetProcessName();
				//G4cout << "Positron generation process identified: " << proc << G4endl;
			}
		}
	}
	
	//count # of pair production vertex (in total & in target)
	if (track -> GetCreatorProcess()!= nullptr){
		if (track -> GetCreatorProcess()-> GetProcessName()!= nullptr){
			if (track-> GetParticleDefinition()== positron){
				fEventAction->AddCounter();
				if(logic_prestep_volume == logic_target_volume)
					fEventAction->AddInTargetCounter();
			}
		}
	}
	
	//Starts recording data to file
	G4RootAnalysisManager* analysis_manager = G4RootAnalysisManager::Instance();
	
	
	//Store positron energy spectrum to file (at sensitive detector)
	if (track-> GetParticleDefinition()== positron && 
	logic_prestep_volume == logic_sensitive_volume){
		G4double positron_energy = track->GetTotalEnergy();
	    analysis_manager->FillNtupleDColumn (2,0,positron_energy);
		analysis_manager->AddNtupleRow(2);
	    //std::cout << "Positron deposited with energy: " << positron_energy << " MeV" << std::endl;
	}
	
	//Store gamma energy spectrum to file (at sensitive detector)
	if (track-> GetParticleDefinition()== gamma && 
	logic_prestep_volume == logic_sensitive_volume){
		G4double gamma_energy = track->GetTotalEnergy();
		analysis_manager->FillNtupleDColumn (3,0,gamma_energy);
		analysis_manager->AddNtupleRow(3);
	}
}