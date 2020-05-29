#include "Squadratic.h"

Squadratic :: Squadratic(int id, float edgeLen) : MicroOrganism() {
	ID = id;
	edgeLength = edgeLen;
	for (int i = 0; i < 4; i++) {
		microEdges.push_back(new Wall(edgeLen));
	}
}

Squadratic :: Squadratic(const Squadratic& rhs) : MicroOrganism() {
	ID = rhs.ID;
	edgeLength = rhs.edgeLength;
	for (int i = 0; i < rhs.microEdges.size(); i++) {
    microEdges.push_back(new Wall(*rhs.microEdges[i]));
  }
}

Squadratic :: ~Squadratic() {
	ID = 0;
  for (int i = 0; i < microEdges.size(); i++) {
    delete microEdges[i];
  }
}

void Squadratic :: ConnectToCell(Cell* const cell) {
	int id = ID;
	this->~Squadratic();
	ID = id;
  for (int i = 0; i < cell->GetCellWall().size(); i++) {
    microEdges.push_back(new Wall(*cell->GetCellWall()[i]));
  }
	connectedCell = cell;
}

bool Squadratic :: DoesFitInto(const Cell& cell) const {
	bool fits, curvy;
	int i, j, curvyCount;
	vector<Wall*> cellWalls;
	Cell* cellptr = NULL;
	if (cell.GetCellWall().size() > 3) {
		cellptr = new Cell(cell);
  	cellptr->StrengthenCellWall();
		cellWalls = cellptr->GetCellWall();
	}
	else {
		cellWalls = cell.GetCellWall();
	}
	for (i = 0; i < cellWalls.size(); i++) {
		if (dynamic_cast<CurvyWall*>(cellWalls[i])) {
			curvy = true;
		}
		else {
			curvy = false;
			break;
		}
	}
	if (!curvy && !cellptr) {
		if (cell.GetCellWall()[0]->FindAngleBetween(*cell.GetCellWall()[2]) == PI/2 && cell.GetCellWall()[1]->FindAngleBetween(*cell.GetCellWall()[3]) == PI/2 && cellWalls.size() == 4) {
			for (i = 0; i < 4; i++) {
				if (cellWalls[j]->GetLength() != microEdges[i]->GetLength()) {
					fits = false;
				}
				else {
					fits = true;
					cellWalls.erase(cellWalls.begin()+j);
					break;
				}
			}
		}
		else {
			fits = false;
		}
	}
	else if (!curvy && cellptr) {
		if (cellptr->GetCellWall()[0]->FindAngleBetween(*cellptr->GetCellWall()[2]) == PI/2 && cellptr->GetCellWall()[1]->FindAngleBetween(*cellptr->GetCellWall()[3]) == PI/2 && cellWalls.size() == 4) {
			for (i = 0; i < 4; i++) {
				if (cellWalls[j]->GetLength() != microEdges[i]->GetLength()) {
					fits = false;
				}
				else {
					fits = true;
					cellWalls.erase(cellWalls.begin()+j);
					break;
				}
			}
		}
		else {
			fits = false;
		}
	}
	else {
		fits = false;
	}
	return fits;
}

void Squadratic :: React() {
	if (connectedCell) {
		Squadratic *child1, *child2, *child3, *child4;
		Cell *miniCell1, *miniCell2, *miniCell3, *miniCell4;
		float x1, y1, x2, y2, x3, y3, x4, y4;
		vector <Particle*> particles1, particles2, particles3, particles4;
		vector <Wall*> walls1, walls2, walls3, walls4;
		x1 = connectedCell->GetCellWall()[0]->GetInitialParticle().X();
		y1 = connectedCell->GetCellWall()[0]->GetInitialParticle().Y();
		x2 = connectedCell->GetCellWall()[1]->GetInitialParticle().X();
		y2 = connectedCell->GetCellWall()[1]->GetInitialParticle().Y();
		x3 = connectedCell->GetCellWall()[2]->GetInitialParticle().X();
		y3 = connectedCell->GetCellWall()[2]->GetInitialParticle().Y();
		x4 = connectedCell->GetCellWall()[3]->GetInitialParticle().X();
		y4 = connectedCell->GetCellWall()[3]->GetInitialParticle().Y();
		particles1.push_back(new Particle(x1, y1));
		particles1.push_back(new Particle(x1, y1/2));
		particles1.push_back(new Particle(x1/2, y1));
		particles1.push_back(new Particle(x1/2, y1/2));
		particles2.push_back(new Particle(x2, y2));
		particles2.push_back(new Particle(x2, y2/2));
		particles2.push_back(new Particle(x2/2, y2));
		particles2.push_back(new Particle(x2/2, y2/2));
		particles3.push_back(new Particle(x3, y3));
		particles3.push_back(new Particle(x3, y3/2));
		particles3.push_back(new Particle(x3/2, y3));
		particles3.push_back(new Particle(x3/2, y3/2));
		particles4.push_back(new Particle(x4, y4));
		particles4.push_back(new Particle(x4, y4/2));
		particles4.push_back(new Particle(x4/2, y4));
		particles4.push_back(new Particle(x4/2, y4/2));
		walls1.push_back(new Wall(*particles1[0], *particles1[1]));
		walls1.push_back(new Wall(*particles1[1], *particles1[2]));
		walls1.push_back(new Wall(*particles1[2], *particles1[3]));
		walls2.push_back(new Wall(*particles2[0], *particles2[1]));
		walls2.push_back(new Wall(*particles2[1], *particles2[2]));
		walls2.push_back(new Wall(*particles2[2], *particles2[3]));
		walls3.push_back(new Wall(*particles3[0], *particles3[1]));
		walls3.push_back(new Wall(*particles3[1], *particles3[2]));
		walls3.push_back(new Wall(*particles3[2], *particles3[3]));
		walls4.push_back(new Wall(*particles4[0], *particles4[1]));
		walls4.push_back(new Wall(*particles4[1], *particles4[2]));
		walls4.push_back(new Wall(*particles4[2], *particles4[3]));
		miniCell1 = new Cell(ID+1, walls1, NULL);
		miniCell2 = new Cell(ID+2, walls2, NULL);
		miniCell3 = new Cell(ID+3, walls3, NULL);
		miniCell4 = new Cell(ID+4, walls4, NULL);
		child1 = new Squadratic(ID+1, edgeLength/2);
		child2 = new Squadratic(ID+2, edgeLength/2);
		child3 = new Squadratic(ID+3, edgeLength/2);
		child4 = new Squadratic(ID+4, edgeLength/2);
		child1->ConnectToCell(miniCell1);
		child2->ConnectToCell(miniCell2);
		child3->ConnectToCell(miniCell3);
		child4->ConnectToCell(miniCell4);
		children.push_back(child1);
		children.push_back(child2);
		children.push_back(child3);
		children.push_back(child4);
	}
}

Squadratic Squadratic :: GetChild(float minX, float maxX, float minY, float maxY) const {
	if (children[0]) {
		vector <Particle*> particles;
		vector <Wall*> walls;
		particles.push_back(new Particle(minX, minY));
		particles.push_back(new Particle(minX, maxY));
		particles.push_back(new Particle(maxX, maxY));
		particles.push_back(new Particle(maxX, minY));
		walls.push_back(new Wall(*particles[0], *particles[1]));
		walls.push_back(new Wall(*particles[1], *particles[2]));
		walls.push_back(new Wall(*particles[2], *particles[3]));
		Cell* cell = new Cell(-1, walls, NULL);
		for (int i = 0; i < 4; i++) {
			if (children[i]->DoesFitInto(*cell)) {
				return *children[i];
			}
		}
		throw NotBornChildException();
	}
}