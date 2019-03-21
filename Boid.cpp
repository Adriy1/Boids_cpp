#include "Boid.h"
#include "Vecteur.h"

using namespace std;

//inclure les fonctions de la classe Boid en tant qu'invidu

Boid::Boid():position(),vitesse(){}

Boid::Boid(Vecteur pos, Vecteur vit): position(pos),vitesse(vit){}

Vecteur Boid::getPosition(){
  return position;
}

Vecteur Boid::getVitesse(){
  return vitesse;
}

void Boid::nextBoid() {
  position += vitesse;
}

void Boid::afficherPosition(){
  position.afficher();
}

void Boid::afficherVitesse(){
  vitesse.afficher();
}

Boid::~Boid(){}
