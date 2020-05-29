#include "Triangular.h"

Triangular :: Triangular(int id, const vector<Wall*>& edges, const NucleoBase& nucBase) : MicroOrganism(id, edges) {
	ID = id;
	nucleoBase = new NucleoBase(nucBase);	
	for (int i = 0; i < edges.size(); i++) {
    microEdges.push_back(new Wall(*edges[i]));
  }
}

Triangular :: ~Triangular() {
	ID = 0;
	delete nucleoBase;
  for (int i = 0; i < microEdges.size(); i++) {
    delete microEdges[i];
  }
}

void Triangular :: ConnectToCell(Cell* const cell) {
	int id = ID;
	this->~Triangular();
	ID = id;
  for (int i = 0; i < cell->GetCellWall().size(); i++) {
    microEdges.push_back(new Wall(*cell->GetCellWall()[i]));
  }
	connectedCell = cell;
}

bool Triangular :: DoesFitInto(const Cell& cell) const {
	bool fits, curvy;
	int i, j;
	vector<Wall*> cellWalls;
	if (cell.GetCellWall().size() > 3) {
		Cell* cellptr = new Cell(cell);
  	cellptr->StrengthenCellWall();
		cellWalls = cellptr->GetCellWall();
	}
	else {
		cellWalls = cell.GetCellWall();
	}
	for (i = 0; i < cellWalls.size(); i++) {
		if (dynamic_cast<CurvyWall*>(cellWalls[i])) {
			curvy = true;
			break;
		}
		else {
			curvy = false;
		}
	}
	//cout << !curvy << " curvy\n";
	//cout << cell.GetCellWall()[0]->GetLength() << cell.GetCellWall()[1]->GetLength() << "\n";
	if (!curvy && cellWalls.size() == 3) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
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

	return fits;
}

void Triangular :: React() {
	if (connectedCell) {
		connectedCell->GetTissue()->RemoveCell(*connectedCell);
	}
}

const NucleoBase& Triangular :: GetRNA() const {
	return *nucleoBase;
}

void Triangular :: Mutate(Triangular& rhs) {
	int i = 0, j = 0, startIndex, endIndex;
	string midPart1, midPart2, temp, thisString, rhsString;
	while (i < this->nucleoBase->RNA.size()) {
		startIndex = i;
		if (this->nucleoBase->RNA[i] == rhs.nucleoBase->RNA[i]) {
			i++;
		}
		else {
			break;
		}
	}
	i = 0;
	while (i < rhs.nucleoBase->RNA.size()) {
		endIndex = rhs.nucleoBase->RNA.size() - 1 - i;
		if (this->nucleoBase->RNA[rhs.nucleoBase->RNA.size() - 1 - i] == rhs.nucleoBase->RNA[rhs.nucleoBase->RNA.size() - 1 - i]) {
			i++;
		}
		else {
			break;
		}
	}
	midPart1 = this->nucleoBase->RNA.substr(startIndex,endIndex-startIndex);
	midPart2 = rhs.nucleoBase->RNA.substr(startIndex,endIndex-startIndex);
	for (i = 0; i <= midPart1.size(); i++) {
		if ((midPart1[i] == 'S' && midPart2[i] == 'G') || (midPart1[i] == 'G' && midPart2[i] == 'S') || (midPart1[i] == 'A' && midPart2[i] == 'U') || (midPart1[i] == 'U' && midPart2[i] == 'A')) {
			temp = midPart1;
			midPart1.replace(i, 1, midPart2.substr(i, 1));
			midPart2.replace(i, 1, temp.substr(i, 1));
		}
		else {
			midPart1.replace(i, 1, "#");
			midPart2.replace(i, 1, "#");
		}
		for (i = 0; i <= midPart1.size(); i++) {
			if (midPart1[i] == '#' && midPart2[i] == '#') {
				midPart1.erase(midPart1.begin()+i);
				midPart2.erase(midPart2.begin()+i);
			}
		}
		thisString = this->nucleoBase->RNA.substr(0, startIndex) + midPart1 + this->nucleoBase->RNA.substr(0, startIndex + midPart1.size());
		rhsString = rhs.nucleoBase->RNA.substr(0, startIndex) + midPart2 + rhs.nucleoBase->RNA.substr(0, startIndex + midPart2.size());
		this->nucleoBase->RNA = thisString;
		rhs.nucleoBase->RNA = rhsString;
	}
}