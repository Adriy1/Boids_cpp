#ifndef DEF_BOIDSIMULATOR
#define DEF_BOIDSIMULATOR

const int GLOBAL_CONST_WIDTH = 800;
const int GLOBAL_CONST_HEIGHT = 600;

#include <iostream>
#include "Boid.h"

class BoidSimulator {
private:
  /* data */
  sf::RenderWindow& window;
  Boid boid;

public:
  BoidSimulator (sf::RenderWindow& window,Boid b);
  // BoidSimulator (arguments);
  virtual ~BoidSimulator ();
  void affiche();
  void afficheBoid();
  void box();
  void next();
};

#endif
