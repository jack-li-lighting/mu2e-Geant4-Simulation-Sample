#ifndef SensitiveDetector_h
#define SensitiveDetector_h

#include "G4VSensitiveDetector.hh"
#include "RunAction.hh"
#include "G4RunManager.hh"

class SensitiveDetector: public G4VSensitiveDetector{
	public:
	SensitiveDetector(G4String name);
	~SensitiveDetector();
	
	protected:
	G4bool ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist) override;
};

#endif