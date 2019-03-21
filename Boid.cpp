#include "Boid.h"
#include "Vecteur.h"
#include "BoidSimulator.h"

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
  this->checkPosition();

}

void Boid::checkPosition(){
  if(position.getX() >= GLOBAL_CONST_WIDTH) {
    position.setX(2*GLOBAL_CONST_WIDTH-position.getX());
    vitesse.setX(-vitesse.getX());
  }
  if(position.getX() < 0) {
    position.setX(-position.getX());
    vitesse.setX(-vitesse.getX());
  }
  if(position.getY() >= GLOBAL_CONST_HEIGHT) {
    position.setY(2*GLOBAL_CONST_HEIGHT-position.getY());
    vitesse.setY(-vitesse.getY());
  }
  if(position.getY() < 0) {
    position.setY(-position.getY());
    vitesse.setY(-vitesse.getY());
  }
}

void Boid::afficherPosition()const{
  position.afficher();
}

void Boid::afficherVitesse()const{
  vitesse.afficher();
}

Boid::~Boid(){}
