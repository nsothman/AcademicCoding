#include "Cell.h"

Cell :: Cell(int id, const vector<Wall*>& wall, Tissue* tissuePtr) {
  ID = id;
  for (int i = 0; i < wall.size() - 1; i++) {
    cellWall.push_back(new Wall(*wall[i]));
  }
  cellWall.push_back(new Wall(cellWall[cellWall.size()-1]->GetFinalParticle(), cellWall[0]->GetInitialParticle()));
  tissue = tissuePtr; 
}

Cell :: Cell(const Cell& rhs) {
  ID = rhs.ID;
  for (int i = 0; i < rhs.cellWall.size() - 1; i++) {
    cellWall.push_back(new Wall(*rhs.cellWall[i]));
  }
  tissue = rhs.tissue;
}

int Cell :: GetCellID() const {
  return ID;
}

Tissue* Cell :: GetTissue() const {
  return tissue;
}

const vector<Wall*>& Cell :: GetCellWall() const {
  return cellWall;
}

void Cell :: RenewCellWall(vector<Wall*>& wall) {
  cellWall = wall;
}

void Cell :: StrengthenCellWall() {
  int i = 0, j, k;
  while (i < cellWall.size()) {
    for (j = i+1; j < cellWall.size() - 1; j++) {
      if (cellWall[i]->IsContinuousLinear(*cellWall[j])) {
        try {
		      *cellWall[i] = *cellWall[i] + *cellWall[j];
          cellWall.erase(cellWall.begin()+j);
        } catch (ApplePearException e) {
          i = j;
          break;
        }
      }
      else {}
    }
    i = j;
  }
  try {
	  *cellWall[0] = *cellWall[0] + *cellWall[cellWall.size()-1];
    cellWall.erase(cellWall.begin() + (cellWall.size()-1));
  } catch (ApplePearException e) {}
  if (cellWall.size() > 1 && this->cellWall[this->cellWall.size() - 1]->GetInitialParticle() == this->cellWall[this->cellWall.size() - 1]->GetInitialParticle()) {
    cellWall.erase(cellWall.begin() + (cellWall.size()-1));
  } 
}

Cell :: ~Cell() {
  ID = 0;
  for (int i = 0; i < cellWall.size(); i++) {
    delete cellWall[i];
  }
}

std :: ostream& operator<<(ostream& os, const Cell& cell) {
  for (int i = 0; i < cell.cellWall.size() - 1; i++) {
    os << cell.cellWall[i]->GetInitialParticle() << "-";
  }
  os << cell.cellWall[cell.cellWall.size() - 1]->GetInitialParticle();
  return os;
}