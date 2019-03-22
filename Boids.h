#ifndef DEF_BOIDS
#define DEF_BOIDS

#include "Boid.h"
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

class Boids {
protected:
  /* data */
  list<Boid> listeBoid;

public:
  Boids (int nbBoid);
  virtual ~Boids ();

  void nextBoids();

  sf::VertexArray afficheBoids() ;
};



#endif
