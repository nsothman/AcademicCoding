#include "Tissue.h"

Tissue :: Tissue() {
	xy = NULL;
}

Tissue :: Tissue(float xMin, float xMax, float yMin, float yMax) {
  xy = new float[4];
  xy[0] = xMin;
  xy[1] = xMax;
  xy[2] = yMin;
  xy[3] = yMax;
}

Tissue :: Tissue(const Tissue& rhs) {
  xy[0] = rhs.xy[0];
  xy[1] = rhs.xy[1];
  xy[2] = rhs.xy[2];
  xy[3] = rhs.xy[3];
	for (int i = 0; i < rhs.cellsInTissue.size(); i++) {
		cellsInTissue.push_back(rhs.cellsInTissue[i]);
	}
}

Tissue :: ~Tissue() {
  delete [] xy;
  for (int i = 0; i < cellsInTissue.size(); i++) {
    delete cellsInTissue[i];
  }
}

float* Tissue :: GetCoordinates() {
  return xy;
}

void Tissue :: AddCell(Cell& cell) {
	cellsInTissue.push_back(&cell);
}

void Tissue :: RemoveCell(Cell& cell) {
	for (int i = 0; i < cellsInTissue.size(); i++) {
		if (cell.GetCellID() == cellsInTissue[i]->GetCellID()) {
			cellsInTissue.erase(cellsInTissue.begin() + i);
		}
	}
}

const Cell& Tissue :: GetCell(int id) const {
  for (int i = 0; i < cellsInTissue.size(); i++) {
    if (cellsInTissue[i]->GetCellID() == id) {
      return *cellsInTissue[i];
    }
  }
  throw DeadCellException();
}

void Tissue :: Interact(const vector<MicroOrganism*>& microOrganisms) {
	for (int i = 0; i < cellsInTissue.size(); i++) {
		for (int j = 0; i < microOrganisms.size(); i++) {
			if (microOrganisms[j]->DoesFitInto(*cellsInTissue[i])) {
				microOrganisms[j]->ConnectToCell(cellsInTissue[i]);
			}
		}
	}
}