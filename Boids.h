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
public:
  list<Boid>grid[18][10] ;
  Boids (int nbBoid);
  virtual ~Boids ();
  // list<Boid>[][] getGrid();
  void nextBoids();
  void removeGrid(int x,int y,Boid b);
  void addGrid(int x,int y,Boid b);

  sf::VertexArray afficheBoids() ;
};



#endif
