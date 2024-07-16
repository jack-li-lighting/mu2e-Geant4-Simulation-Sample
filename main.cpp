#include <iostream>
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh"

int main (int argc, char** argv){
	//Initialize all manager classes
	G4RunManager* run_manager = new G4RunManager();
	
	G4VisManager* vis_manager = new G4VisExecutive();
	
	G4UImanager* UI_manager = G4UImanager::GetUIpointer();
	
	//Manager class initialization and start
	run_manager->SetUserInitialization(new DetectorConstruction());
	run_manager->SetUserInitialization(new PhysicsList());
	run_manager->SetUserInitialization(new ActionInitialization());
	run_manager->Initialize();
	
	vis_manager->Initialize();
	if (argc == 1){
		G4UIExecutive* ui = new G4UIExecutive(argc, argv);
	    ui->SessionStart();
		UI_manager->ApplyCommand("/control/execute vis.mac");

	}
	else if (argc == 2){
		G4UIExecutive* ui = 0;
		G4String command_word = "/control/execute ";
		G4String argument_word = argv[1];
		std::cout << "Your selected argument is:" << argv[1] << std::endl;
		UI_manager->ApplyCommand(command_word+argument_word);
	}
	else{
		G4UIExecutive* ui = 0;
		G4String command_word = "/control/execute ";
		G4String argument_word1 = argv[1];
		std::cout << "Your selected argument is:" << argv[1] << std::endl;
		UI_manager->ApplyCommand(command_word+argument_word1);
		
		G4String argument_word2 = argv[2];
		std::cout << "Your selected argument is:" << argv[2] << std::endl;
		UI_manager->ApplyCommand(command_word+argument_word2);
	}
	
	
	return 0;
}