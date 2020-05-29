#include "Particle.h"

Particle :: Particle(float X, float Y) {
  x = X;
  y = Y;
}

Particle :: Particle(const Particle& rhs) {
  x = rhs.x;
  y = rhs.y;
}

float Particle :: X() const {
  return x;
}

float Particle :: Y() const {
  return y;
}

float Particle :: FindDistance(const Particle& rhs) const {
  float distance, xDiff = 0.0, yDiff = 0.0;
  if (abs(x - rhs.x) >= EPSILON) {
    xDiff = x - rhs.x;
  }
  if (abs(y - rhs.y) >= EPSILON) {
    yDiff = y - rhs.y;
  }

  distance = sqrt((pow(xDiff,2.0))+(pow(yDiff,2.0)));
  return distance;
}

bool Particle :: operator== (const Particle& rhs) const {
  if (abs(x - rhs.x) >= EPSILON || abs(y - rhs.y) >= EPSILON) {
    return false;
  }
  return true;
}

std :: ostream& operator<<(std::ostream& os, const Particle& particle) {
  os << "(" << particle.x << "," << particle.y << ")";
  return os;
}
