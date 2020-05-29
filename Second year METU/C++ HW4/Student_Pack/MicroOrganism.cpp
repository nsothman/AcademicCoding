#include "MicroOrganism.h"

MicroOrganism :: MicroOrganism() {
}

MicroOrganism :: MicroOrganism(int id, const vector<Wall*>& edges) {
  ID = id;
  for (int i = 0; i < edges.size(); i++) {
    microEdges.push_back(new Wall(*edges[i]));
  }
	connectedCell = NULL;
}

std :: ostream& operator<<(ostream& os, const MicroOrganism& microOrganism) {
	if (microOrganism.connectedCell) {
		os << "The microorganism " << microOrganism.ID << " was successfully placed into the cell" << microOrganism.connectedCell->GetCellID() << ".";
	}
	else {
		os << "The microorganism" << microOrganism.ID << "could not be placed into any cell!";
	}
	return os;
}

bool MicroOrganism :: DoesFitInto(const Cell& cell) const {
	return false;

	/*const MicroOrganism* thisOrganism = this;
	bool fits, curvy;
	int i, j, curvyCount;
	vector<Wall*> cellWalls;
	Cell* cellptr = new Cell(cell);
  cellptr->StrengthenCellWall();
	cellWalls = cellptr->GetCellWall();
	for (i = 0; i < 4; i++) {
		if (dynamic_cast<CurvyWall*>(cellWalls[i]) && dynamic_cast<CurvyWall*>(microEdges[i])) {
			curvy = true;
		}
		else {
			curvy = false;
			break;
		}
	}
	if (!curvy && i == 0) {
		for (i = 0; i < 4; i++) {
			if (dynamic_cast<CurvyWall*>(cellWalls[i]) && dynamic_cast<CurvyWall*>(microEdges[i])) {
				curvy = true;
				break;
			}
		}
	}
	if (i == 3 && cellptr->GetCellWall().size() == microEdges.size()) {
		if (!curvy) {
			if ((microEdges.size() == 4 && cellptr->GetCellWall()[0]->FindAngleBetween(*cellptr->GetCellWall()[2]) == PI/2 && cellptr->GetCellWall()[1]->FindAngleBetween(*cellptr->GetCellWall()[3]) == PI/2) || (microEdges.size() == 3 && !curvy)) {
				for (i = 0; i < microEdges.size(); i++) {
					for (j = 0; j < microEdges.size(); j++) {
						if (cellWalls[j]->GetLength() != microEdges[i]->GetLength()) {
							fits = false;
						}
						else {
							fits = true;
							cellWalls.erase(cellWalls.begin()+j);
							break;
						}
					}
					if (!fits) {
						break;
					}
				}
			}
			else {
				fits = false;
			}
		}
		else if (curvy && microEdges.size() == 1) {
			if (cellWalls[0]->GetLength() == microEdges[0]->GetLength() && dynamic_cast<CurvyWall*>(cellWalls[0])->GetRadius() == dynamic_cast<CurvyWall*>(microEdges[i])->GetRadius()) {
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
		fits = false;
	}
	return fits;*/
}

void MicroOrganism :: ConnectToCell(Cell* const cell) {
	/*int id = ID;
	this->~MicroOrganism();
	ID = id;
  for (int i = 0; i < cell->GetCellWall().size(); i++) {
    microEdges.push_back(new Wall(*cell->GetCellWall()[i]));
  }
	connectedCell = cell;*/
}

MicroOrganism :: ~MicroOrganism() {
	ID = 0;
  for (int i = 0; i < microEdges.size(); i++) {
    delete microEdges[i];
  }
}

