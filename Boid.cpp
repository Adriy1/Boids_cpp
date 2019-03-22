#include "Boid.h"
#include "Vecteur.h"
#include "BoidSimulator.h"
#include <SFML/Graphics.hpp>
#include <cmath>


using namespace std;

//inclure les fonctions de la classe Boid en tant qu'invidu

Boid::Boid():position(),vitesse(){}

Boid::Boid(Vecteur pos, Vecteur vit): position(pos),vitesse(vit){}

Vecteur Boid::getPosition()const{
  return position;
}

Vecteur Boid::getVitesse()const{
  return vitesse;
}

void Boid::nextBoid() {
  position += vitesse; // TODO check apres l'affectation bonne idee ?
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

sf::VertexArray Boid::afficheBoid()const{ //creer la figure d'un seul boid
  sf::VertexArray triangle(sf::Triangles, 3);
  double x = position.getX(); //performance
  double y = position.getY();
  double a = vitesse.getAngle()/180*3.1416;
  double px = cos(a);
  double py = sin(a); // TODO opti perf
  triangle[0].position = sf::Vector2f(x+py*12.f,y+px*12.f);
  triangle[1].position = sf::Vector2f(x+px*4.f,y-py*4.f);
  triangle[2].position = sf::Vector2f(x-px*4.f,y+py*4.f);
  triangle[0].color = sf::Color::Red;
  triangle[1].color = sf::Color::Red;
  triangle[2].color = sf::Color::Red;
  return triangle;
}

Boid::~Boid(){}
