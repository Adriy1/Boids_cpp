#ifndef DEF_BOIDSIMULATOR
#define DEF_BOIDSIMULATOR

#include <iostream>
#include "Boids.h"




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
