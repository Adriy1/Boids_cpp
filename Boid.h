#ifndef DEF_BOID
#define DEF_BOID

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vecteur.h"
#include <list>
// #include "BoidSimulator.h"

class Boid {
protected:
  /* data */
  Vecteur position;
  Vecteur vitesse;

public:
  Boid();
  Boid (Vecteur position, Vecteur vitesse);
  virtual ~Boid ();

  Vecteur getPosition()const;
  Vecteur getVitesse()const;

  void nextBoid(list<Boid>(&)[17][9]);
  void checkPosition();
  Vecteur flock(list<Boid>(&)[17][9]);
  Vecteur boundingPosition();
  Vecteur cohesion(list<Boid>&);
  Vecteur alignement(list<Boid>&);
  Vecteur separation(list<Boid>&);
  void limitVelocity();
  void afficherVitesse()const;
  void afficherPosition()const;

  sf::VertexArray afficheBoid() const;

  // operateurs


};

bool operator==(const Boid&, const Boid&);

bool operator!=(const Boid&, const Boid&);

#endif
