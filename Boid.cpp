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
  vitesse += this->boundingPosition();
  vitesse += this->flock(listBoid);
  this->limitVelocity();
  position += vitesse; // TODO check apres l'affectation bonne idee ?
  this->checkPosition();
}

void Boid::checkPosition(){
  double x_position = position.getX(); //PERF
  double y_position = position.getY();
  if(x_position >= GLOBAL_CONST_WIDTH) {
    position.setX(2*GLOBAL_CONST_WIDTH-x_position);
    // vitesse.setX(-vitesse.getX());
  }
  if(x_position < 0) {
    position.setX(-x_position);
    // vitesse.setX(-vitesse.getX());
  }
  if(y_position >= GLOBAL_CONST_HEIGHT) {
    position.setY(2*GLOBAL_CONST_HEIGHT-y_position);
    // vitesse.setY(-vitesse.getY());
  }
  if(y_position < 0) {
    position.setY(-y_position);
    // vitesse.setY(-vitesse.getY());
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
        // nb++; DEBUG
        dist = position.distance(it->position);
        if(dist<200. && vitesse.getAngle(it->position-position)<90.){
          v_cohesion += (it->position-position); //cohesion
          v_aligmenent += it->vitesse; // alignement
          nb_vu++;
        }
        if(dist <20.){ //OPTI possible ?
          v_separation -= (it->position-position);
          v_separation *= v_separation.norm()/dist; //plus la norm est petite plus la force est grande
          nb_separation ++;
        }
      }
    }
    // std::cout << nb << '\n'; DEBUG
    if(nb_vu > 0){
      v_cohesion *= 1./nb_vu/50.;
      v_aligmenent *= 1./nb_vu/1.;
    }
    if(nb_separation>0){
      v_separation *= 1./nb_separation/2.;
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
  double vx = vitesse.getX();
  double vy = vitesse.getY();
  Vecteur v = Vecteur();
  // // test si proche des 4 bords
  //   if(x_position<= GLOBAL_CONST_WIDTH/20 || x_position >= GLOBAL_CONST_WIDTH * (1.-1./20) || y_position <= GLOBAL_CONST_HEIGHT/20 || y_position >= GLOBAL_CONST_HEIGHT * (1.-1./20)){
  //     // double norme = vitesse.norm();
  //     v -= Vecteur(x_position-GLOBAL_CONST_WIDTH/2,y_position-GLOBAL_CONST_HEIGHT/2); // force centrale
  //     v *= vitesse.norm()/v.norm()/1.3;
  //     // // v.afficher();
  //     // vitesse.afficher();
  //   }
  // TODO norme ?
  if ((x_position < -10*vx && vx <0) || x_position > GLOBAL_CONST_WIDTH-10*vx && vx>0){
    v.setX(-1.1*vx);
  }
  if ((y_position < -10*vy && vy <0)||(y_position > GLOBAL_CONST_HEIGHT-10*vy && vy>0)){
    v.setY(-1.1*vy);
  }
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
