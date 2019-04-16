#ifndef DEF_BOID
#define DEF_BOID

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vecteur.h"
#include <list>

const int GLOBAL_CONST_WIDTH = 1900; // NE DEVRAIT PAS ETRE LA CAR LIE A LA FENETRE DE SIMU OU A LA GRILLE BOIDS
const int GLOBAL_CONST_HEIGHT = 1000; // MAIS PERMET D'ACTUALISER FACILEMENT LA RANGE DES BOIDS
const int RANGE_BOID = 75; // TOUT EN GARDANT LA PERF DES TABLEAUS STATIQUES
const int SIZE_LEAF = RANGE_BOID*(1.+1./10.);
const int NB_ROWS = (GLOBAL_CONST_WIDTH/SIZE_LEAF)+1;
const int NB_COLS = (GLOBAL_CONST_HEIGHT/SIZE_LEAF)+1;

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

  void nextBoid(list<Boid>(&)[NB_ROWS][NB_COLS]);
  void checkPosition();
  Vecteur flock(list<Boid>(&)[NB_ROWS][NB_COLS]);
  bool isInSight(Boid);
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
