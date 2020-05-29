#include "CurvyWall.h"

CurvyWall :: CurvyWall(float l, float r) : Wall(l) {
  length = l;
  radius = r;
}

CurvyWall :: CurvyWall(const Particle& start, const Particle& end, const Particle& mid) : Wall(start, end) {
  Wall* fstDiag = new Wall(mid, start);
  Wall* secDiag = new Wall(mid, end);
  float angle = fstDiag->FindAngleBetween(*secDiag);
  if (!(angle) && !(start == end)) {
    angle = PI;
  }
  else if (!(angle) && start == end) {
    angle = 2*PI;
  }
  radius = mid.FindDistance(start);
  length = radius*angle;
  startPoint = new Particle(start);
  endPoint = new Particle(end);
  centre = new Particle(mid);
  delete fstDiag;
  delete secDiag;
}

CurvyWall :: CurvyWall(const CurvyWall& rhs) : Wall(rhs) {
  length = rhs.length;
  radius = rhs.radius;
  if (rhs.startPoint) {
    startPoint = rhs.startPoint;
  }
  if (rhs.endPoint) {
    endPoint = rhs.endPoint;
  }
  if (rhs.centre) {
    centre = rhs.centre;
  }
}

float CurvyWall :: GetRadius() const {
  return radius;
}

const Particle& CurvyWall :: GetCenter() const {
  return *centre;
}

void CurvyWall :: ComputeLength() {
  Wall* fstDiag = new Wall(*centre, *startPoint);
  Wall* secDiag = new Wall(*centre, *endPoint);
  float angle = fstDiag->FindAngleBetween(*secDiag);
  if (!(angle) && !(startPoint == endPoint)) {
    angle = PI;
  }
  else if (!(angle) && startPoint == endPoint) {
    angle = 2*PI;
  }
  length = radius*angle;
  delete fstDiag;
  delete secDiag;
}

Wall* CurvyWall :: Clone() const {
  return new CurvyWall(*this);
}

bool CurvyWall :: IsContinuousLinear(const Wall& rhs) const {
  return false;
}

const Wall& CurvyWall :: operator+(const Wall& rhs) const {
  if (dynamic_cast<const CurvyWall*>(this) && dynamic_cast<const CurvyWall*>(&rhs)) {
    if (*(this->centre) == *(rhs.centre)) {
      if (*(this->startPoint) == *(rhs.endPoint)) {
        Wall* newWall = new CurvyWall(*(rhs.startPoint), *(this->endPoint), *(rhs.centre));
        return *newWall;
      }
      else if (*(this->endPoint) == *(rhs.startPoint)) {
        Wall* newWall = new CurvyWall(*(this->startPoint), *(rhs.endPoint), *(rhs.centre));
        return *newWall;
      }
      else {
        throw ApplePearException();
      }
    }
    else {
      throw ApplePearException();
    }
  }
  else {
    throw ApplePearException();
  }
}

CurvyWall :: ~CurvyWall() {
  length = 0.0;
  radius = 0.0;
  delete startPoint;
  delete endPoint;
  delete centre;
}