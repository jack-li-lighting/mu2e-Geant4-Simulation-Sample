#ifndef DetectorConstruction_h
#define DetectorConstruction_h

#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"





class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction() = default;
    ~DetectorConstruction() override = default;

    G4VPhysicalVolume* Construct() override;
	G4LogicalVolume* GetTargetVolume() const {return logic_target_volume;}
	G4LogicalVolume* GetSensitiveVolume() const {return logic_sensitive;}
	G4LogicalVolume* GetWorldVolume() const {return logic_world_vacuum;}
  private:
    G4LogicalVolume* logic_sensitive;
	G4LogicalVolume* logic_target_volume;
	G4LogicalVolume* logic_world_vacuum;
    void ConstructSDandField() override;
};

#endif