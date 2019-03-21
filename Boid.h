#ifndef DEF_BOID
#define DEF_BOID

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

  Vecteur getPosition();
  Vecteur getVitesse();

  void nextBoid();
  void checkPosition();
  void afficherPosition()const;
  void afficherVitesse()const;
};



#endif
