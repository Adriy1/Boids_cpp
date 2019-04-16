#ifndef DEF_BOIDS
#define DEF_BOIDS

#include "Boid.h"
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

class Boids {
protected:
  /* data */
  // list<Boid> listeBoid; // OLD WAY
  // trouver une solution pour taille de la grille  + global const TODO
  list<Boid>grid[NB_ROWS][NB_COLS];

public:
  Boids (int nbBoid);
  virtual ~Boids ();
  void nextBoids();
  void removeGrid(int x,int y,Boid b);
  void addGrid(int x,int y,Boid b);

  sf::VertexArray afficheBoids() ;
};



#endif
