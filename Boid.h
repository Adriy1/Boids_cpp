#ifndef DEF_BOID
#define DEF_BOID

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vecteur.h"

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

  void nextBoid();
  void checkPosition();
  void afficherVitesse()const;
  void afficherPosition()const;

  sf::VertexArray afficheBoid() const;
};



#endif
