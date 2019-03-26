#ifndef DEF_BOIDSIMULATOR
#define DEF_BOIDSIMULATOR

const int GLOBAL_CONST_WIDTH = 1900;
const int GLOBAL_CONST_HEIGHT = 1000;
const int RANGE_BOID = 100;
const int SIZE_LEAF = RANGE_BOID*(1.+1./10.);
const int NB_ROWS = (GLOBAL_CONST_WIDTH/SIZE_LEAF)+1;
const int NB_COLS = (GLOBAL_CONST_HEIGHT/SIZE_LEAF)+1;

#include <iostream>
#include "Boids.h"
#include "Boid.h"

class BoidSimulator {
private:
  /* data */
  sf::RenderWindow& window;
  Boids& boids;

public:
  BoidSimulator (sf::RenderWindow& window,Boids& b);
  // BoidSimulator (arguments);
  virtual ~BoidSimulator ();
  void affiche();
  void drawBoids();
  void resize(int width,int height);
  void box();
  void next();
};

#endif
