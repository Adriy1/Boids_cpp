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
  this->afficheBoid();
  window.display();
}

void BoidSimulator::afficheBoid(){
  sf::CircleShape triangle(8.f, 3);
  triangle.setPosition(boid.getPosition().getX(),boid.getPosition().getY());
}

void BoidSimulator::box(){
  sf::VertexArray borders (sf::LinesStrip,4);
  borders[0].position = sf::Vector2f(0.f,0.f);
  borders[1].position = sf::Vector2f(0.f, window.getSize().y);
  borders[2].position = sf::Vector2f(window.getSize().x, window.getSize().y);
  borders[3].position = sf::Vector2f(window.getSize().x, 0.f);
  window.draw(borders);
}
