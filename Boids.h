#ifndef DEF_BOIDS
#define DEF_BOIDS

#include "Boid.h"
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
// #include "BoidSimulator.h" //Pourquoi la classe Boids doit etre au courant de la simulation ??

class Boids {
protected:
  /* data */
  // list<Boid> listeBoid; // OLD WAY
  // trouver une solution pour taille de la grille  + global const TODO
  list<Boid>grid[NB_ROWS][NB_COLS];

public:
  Boids (int nbBoid);
  virtual ~Boids ();
  // list<Boid>[][] getGrid();
  void nextBoids();
  void removeGrid(int x,int y,Boid b);
  void addGrid(int x,int y,Boid b);

  sf::VertexArray afficheBoids() ;
};



#endif
