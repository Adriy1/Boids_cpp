#include <SFML/Graphics.hpp>
#include "BoidSimulator.h"

BoidSimulator::BoidSimulator(sf::RenderWindow& wd,Boid b): window(wd),boid(b){
}

BoidSimulator::~BoidSimulator(){}

void BoidSimulator::next(){
  boid.nextBoid();
}

void BoidSimulator::affiche(){
  window.clear();
  this->box();
  this->afficheBoid();
  window.display();
}

void BoidSimulator::afficheBoid(){
  sf::CircleShape triangle(8.f, 3);
  triangle.setPosition(boid.getPosition().getX(),boid.getPosition().getY());
  double signe = (boid.getVitesse().getX() * boid.getVitesse().getY() >= 0);
  if (signe) {
    triangle.setRotation(boid.getVitesse().getAngle()-30);
  }
  else{
    triangle.setRotation((boid.getVitesse().getAngle())-360+30);
  }
  window.draw(triangle);
}

void BoidSimulator::resize(int width, int height){
  // A DEBUG
  window.setSize(sf::Vector2u(width,height));
}

void BoidSimulator::box(){ // defini une box dans l'affichage
  sf::VertexArray borders (sf::LinesStrip,5);
  borders[0].position = sf::Vector2f(1.f,1.f);
  borders[1].position = sf::Vector2f(1.f, window.getSize().y);
  borders[2].position = sf::Vector2f(window.getSize().x, window.getSize().y);
  borders[3].position = sf::Vector2f(window.getSize().x, 1.f);
  borders[4].position = sf::Vector2f(1.f,1.f);
  borders[0].color = sf::Color::Red;
  borders[1].color = sf::Color::Red;
  borders[2].color = sf::Color::Red;
  borders[3].color = sf::Color::Red;
  borders[4].color = sf::Color::Red;
  window.draw(borders);
}
