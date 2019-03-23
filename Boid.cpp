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

void Boid::nextBoid(list<Boid>& listBoid) {
  vitesse += this->flock(listBoid);
  vitesse += this->boundingPosition();
  this->limitVelocity();
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

Vecteur Boid::flock(list<Boid>& listBoid){
    Vecteur v_cohesion = Vecteur();
    Vecteur v_aligmenent = Vecteur();
    Vecteur v_separation = Vecteur();
    int nb_vu =0.,nb_separation=0.;
    double dist;
    list<Boid>::iterator it;
    for(it = listBoid.begin();it != listBoid.end();++it){
      if (*this != *it){ //on check les autres boids uniquement
        dist = position.distance(it->position)
        if(dist<200. && vitesse.getAngle(it->position-position)<90.){
          v_cohesion += (it->position-position); //cohesion
          v_aligmenent += it->vitesse; // alignement
          nb_vu++;
        }
        if(dist <30.){ //OPTI possible ?
          v_separation -= (it->position-position);
          v_separation *= v_separation.norm()/dist; //plus la norm est petite plus la force est grande
          nb_separation ++;
        }
      }
    }
    if(nb_vu > 0){
      v_cohesion *= 1./nb_vu/1.7;
      v_aligmenent *= 1./nb_vu/1.7;
    }
    if(nb_separation>0){
      v_separation *= 1./nb_separation;
    }
    return v_cohesion + v_aligmenent + v_separation;
}

Vecteur Boid::cohesion(list<Boid>& listBoid){

}

Vecteur Boid::alignement(list<Boid>& listBoid){

}

Vecteur Boid::separation(list<Boid>& listBoid){

}

Vecteur Boid::boundingPosition(){
  double x_position = position.getX(); // performance
  double y_position = position.getY(); // performance
  Vecteur v = Vecteur();
  // test si proche des 4 bords
    if(x_position<= GLOBAL_CONST_WIDTH/10 || x_position >= GLOBAL_CONST_WIDTH * (1.-1./10.) || y_position <= GLOBAL_CONST_HEIGHT/10 || y_position >= GLOBAL_CONST_HEIGHT * (1.-1./10.)){
      // double norme = vitesse.norm();
      v -= Vecteur(x_position-GLOBAL_CONST_WIDTH/2,y_position-GLOBAL_CONST_HEIGHT/2); // force centrale
      v *= vitesse.norm()/v.norm()/2;
      // // v.afficher();
      // vitesse.afficher();
    }
  // TODO norme ?

  return v;

}

void Boid::limitVelocity(){
  double vlim =5.f,n = vitesse.norm();
  if (n>vlim){
    vitesse *= vlim/n;
    // std::cout << "vitesse limitVelocity " << vitesse.norm() << '\n';
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
  double a = vitesse.getOrientation()/180*3.1416;
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

bool operator==(const Boid& lhs, const Boid& rhs){ if(lhs.getPosition() == rhs.getPosition() && lhs.getVitesse() == rhs.getVitesse()) return true; }
bool operator!=(const Boid& lhs, const Boid& rhs){ return !(lhs == rhs); }

Boid::~Boid(){}
