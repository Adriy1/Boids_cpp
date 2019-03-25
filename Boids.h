#ifndef DEF_BOIDS
#define DEF_BOIDS

#include "Boid.h"
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
// #include "BoidSimulator.h" //Pourquoi la classe Boid doit etre au courant de la simulation ??

class Boids {
protected:
  /* data */
  // list<Boid> listeBoid; // OLD WAY
  // Grid<list<Boid>> grid;// trouver une solution pour floor + global const TODO
  list<Boid>grid[17][9] ;
public:
  Boids (int nbBoid);
  virtual ~Boids ();

  void nextBoids();

  sf::VertexArray afficheBoids() ;
};



#endif
