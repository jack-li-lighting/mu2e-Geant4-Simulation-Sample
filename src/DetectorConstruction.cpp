#include "DetectorConstruction.hh"
#include "SensitiveDetector.hh"

G4VPhysicalVolume* DetectorConstruction::Construct(){
	//define constants
	G4double pi  = 3.14159265358979323846;
	G4double universe_mean_density = 1.e-25*g/cm3; 
	//define material
	G4NistManager* nist = G4NistManager::Instance();
	G4Material* world_material = nist->FindOrBuildMaterial("G4_AIR");
	
    G4double pressure = 3.e-18*pascal;
    G4double temperature = 2.73*kelvin;
    G4Material* Vacuum = new G4Material("Vacuum",
    1., 1.01*g/mole, universe_mean_density,
    kStateGas,temperature,pressure);
	
	G4Material* Calcium40 = new G4Material("Calcium40",1.526*g/cm3,1);
	Calcium40->AddElement(nist->FindOrBuildElement("Ca"),1);
	
	G4Material* Lead = nist->FindOrBuildMaterial("G4_Pb");
	
	
	//define solid volume
	G4Box* solid_world = new G4Box("world_geometry",5*m,5*m,5*m);
	G4Box* solid_target = new G4Box("target_geometry",4*m,4*m,0.5*m);
	G4Box* solid_sensitive = new G4Box("sensitive_detector_geometry",0.5*m,0.5*m,0.1*m);
	G4Tubs* solid_target_mu2e = new G4Tubs("target_geometry_mu2e", 0*mm, 100*mm, 100*um, 0, 2*pi);
	
	//define logic volume
	G4LogicalVolume* logic_world = new G4LogicalVolume(solid_world, Vacuum, "world_logic");
	G4LogicalVolume* logic_target = new G4LogicalVolume(solid_target, Calcium40, "target_logic");
	logic_sensitive = new G4LogicalVolume(solid_sensitive, Vacuum, "senstive_logic");
	G4LogicalVolume* logic_target_mu2e = new G4LogicalVolume(solid_target_mu2e, Calcium40, "target_logic_mu2e");
	
	logic_target_volume = logic_target_mu2e;
	logic_world_vacuum = logic_world;

	
	//define physical volume
	G4VPhysicalVolume* physic_world = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.),logic_world,"world_physical",0,false,0,true);
	//G4VPhysicalVolume* physic_target = new G4PVPlacement(0,G4ThreeVector(0.,0.,2*m),logic_target,"target_physical",
	//logic_world,false,0,true);
	
	for (G4int i = 0; i < 17; i++)
	G4VPhysicalVolume* physic_target = new G4PVPlacement(0,G4ThreeVector(0,0,1*m+0.05*i*m),logic_target_mu2e,"targetmu2e_physical",
	            logic_world,false,i,true);

	for (G4int i = 0; i < 20; i++){
		for (G4int j = 0; j < 20; j++){
			G4VPhysicalVolume* physic_sensitive = new G4PVPlacement(0,G4ThreeVector(-5*m+i*0.5*m,-5*m+j*0.5*m,4.9*m),logic_sensitive,"sensitive_physical",
	            logic_world,false,i*10+j,true);
		}
	}
	
	return physic_world;
	
}

void DetectorConstruction::ConstructSDandField(){
	SensitiveDetector* SensDetect = new SensitiveDetector("Sensitive Detector");
	logic_sensitive->SetSensitiveDetector(SensDetect);
}