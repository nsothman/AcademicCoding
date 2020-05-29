#include "Wall.h"

Wall :: Wall(float l) {
  length = l;
}

Wall :: Wall(const Particle& particle1, const Particle& particle2) {
  length = particle1.FindDistance(particle2);
  startPoint = new Particle(particle1);
  endPoint = new Particle(particle2);
}

Wall :: Wall(const Wall& rhs) {
  length = rhs.length;

  if (rhs.startPoint) {
    startPoint = rhs.startPoint;
  }
  if (rhs.endPoint) {
    endPoint = rhs.endPoint;
  }
}

const Particle& Wall :: GetInitialParticle() const {
  return *startPoint;
}

const Particle& Wall :: GetFinalParticle() const {
  return *endPoint;
}

float Wall :: FindAngleBetween(const Wall& rhs) const {
  float m1, m2, angle;
  if (abs(startPoint->X() - endPoint->X()) >= EPSILON && abs(rhs.startPoint->X() - rhs.endPoint->X()) >= EPSILON) {
    if (abs(startPoint->Y() - endPoint->Y()) >= EPSILON) {
      m1 = (startPoint->Y() - endPoint->Y()) / (startPoint->X() - endPoint->X());
    }
    else {
      m1 = 0.0;
    }
    if (abs(rhs.startPoint->Y() - rhs.endPoint->Y()) >= EPSILON) {
      m2 = (rhs.startPoint->Y() - rhs.endPoint->Y()) / (rhs.startPoint->X() - rhs.endPoint->X());
    }
    else {
      m2 = 0.0;
    }
    angle = atan((m2-m1) / (1.0 + m1*m2));
  }
  else if (abs(startPoint->X() - endPoint->X()) < EPSILON && abs(rhs.startPoint->X() - rhs.endPoint->X()) < EPSILON) {
    angle = 0.0;
  }
  else if (abs(startPoint->X() - endPoint->X()) < EPSILON) {
    if (abs(rhs.startPoint->Y() - rhs.endPoint->Y()) >= EPSILON) {
      m2 = (rhs.startPoint->Y() - rhs.endPoint->Y()) / (rhs.startPoint->Y() - rhs.endPoint->Y());
    }
    else {
      m2 = 0.0;
    }
    angle = 3.14159265/2 - atan(m2);
  }
  else {
    if (abs(startPoint->Y() - endPoint->Y()) >= EPSILON) {
      m1 = (startPoint->Y() - endPoint->Y()) / (startPoint->Y() - endPoint->Y());
    }
    else {
      m1 = 0.0;
    }
    angle = 3.14159265/2 - atan(-m1);
  }
  return angle;
}

float Wall :: GetLength() const {
  return length;
}

void Wall :: ComputeLength() {
  length = startPoint->FindDistance(*endPoint);
}

Wall* Wall :: Clone() const {
  return new Wall(*this);
}

bool Wall :: IsContinuousLinear(const Wall& rhs) const {
  if (!(dynamic_cast<const Wall*>(&rhs)) || !(dynamic_cast<const Wall*>(&rhs))) {
    return false;
  }
  if (this->FindAngleBetween(rhs) == 0.0 && (*startPoint == *(rhs.endPoint) || *endPoint == *(rhs.startPoint))) {
    return true;
  }
  return false;
}

const Wall& Wall :: operator+(const Wall& rhs) const {
  if (dynamic_cast<const Wall*>(this) && dynamic_cast<const Wall*>(&rhs)) {
    if (*(this->startPoint) == *(rhs.endPoint)) {
      Wall* newWall = new Wall(*(rhs.startPoint), *(this->endPoint));
      return *newWall;
    }
    else if (*(this->endPoint) == *(rhs.startPoint)) {
      Wall* newWall = new Wall(*(this->startPoint), *(rhs.endPoint));
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

Wall :: ~Wall() {
  length = 0.0;
  delete startPoint;
  delete endPoint;
}