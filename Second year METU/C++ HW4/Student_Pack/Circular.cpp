#include "Circular.h"

Circular :: Circular(int id, float rad) : MicroOrganism() {
	ID = id;
	radius = rad;
}

Circular :: ~Circular() {
	ID = 0;
	radius = 0;
  for (int i = 0; i < microEdges.size(); i++) {
    delete microEdges[i];
  }
}

void Circular :: ConnectToCell(Cell* const cell) {
	int id = ID;
	this->~Circular();
	ID = id;
  microEdges.push_back(new Wall(*cell->GetCellWall()[0]));
	connectedCell = cell;
}

bool Circular :: DoesFitInto(const Cell& cell) const {
	bool fits, curvy;
	int i, curvyCount;
	vector<Wall*> cellWalls;
	Cell* cellptr = NULL;
	if (cell.GetCellWall().size() > 1) {
		cellptr = new Cell(cell);
  	cellptr->StrengthenCellWall();
		cellWalls = cellptr->GetCellWall();
	}
	else {
		cellWalls = cell.GetCellWall();
	}
	if (dynamic_cast<CurvyWall*>(cellWalls[0])) {
		curvy = true;
	}
	else {
		curvy = false;
	}
	if (cellptr){
		if (curvy && cellptr->GetCellWall().size() == 1) {
			if (dynamic_cast<CurvyWall*>(cellWalls[0])->GetRadius() == radius) {
				fits = true;
			}
			else {
				fits = false;
			}
		}
		else {
			fits = false;
		}
	}
	else {
		if (curvy && cell.GetCellWall().size() == 1) {
			if (dynamic_cast<CurvyWall*>(cellWalls[0])->GetRadius() == radius) {
				fits = true;
			}
			else {
				fits = false;
			}
		}
		else {
			fits = false;
		}
	}
	return fits;
}

void Circular :: React() {
	vector<Wall*>tempWall;
	float x1, y1, x2, y2;
	x1 = dynamic_cast<CurvyWall*>(this->connectedCell->GetCellWall()[0])->GetInitialParticle().X() * 2;
	y1 = dynamic_cast<CurvyWall*>(this->connectedCell->GetCellWall()[0])->GetInitialParticle().Y() * 2;
	x1 = dynamic_cast<CurvyWall*>(this->connectedCell->GetCellWall()[0])->GetFinalParticle().X() * 2;
	y1 = dynamic_cast<CurvyWall*>(this->connectedCell->GetCellWall()[0])->GetFinalParticle().Y() * 2;
	Particle* tempStartParticle = new Particle(x1, y1);
	Particle* tempEndParticle = new Particle(x2, y2);
	Particle* tempCenter = new Particle(dynamic_cast<CurvyWall*>(this->connectedCell->GetCellWall()[0])->GetCenter());
	tempWall.push_back(new CurvyWall(*tempStartParticle, *tempEndParticle, *tempCenter));
	this->connectedCell->RenewCellWall(tempWall);
}

bool Circular :: DoesContain(const Particle& particle) const {
	CurvyWall* particleCircle = new CurvyWall(particle, particle, dynamic_cast<CurvyWall*>(this->connectedCell->GetCellWall()[0])->GetCenter());
	if (particleCircle->GetRadius() <= dynamic_cast<CurvyWall*>(this->connectedCell->GetCellWall()[0])->GetRadius()) {
		return true;
	}
	return false;
}