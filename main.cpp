#include <iostream>
#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "BoidSimulator.h"
#include "Vecteur.h"

using namespace std;


int main(int argc, char const *argv[]) {
  /* code */

  sf::RenderWindow windowSimu(sf::VideoMode(800, 600), "SFML Boids!");
  Boid b = Boid(Vecteur(0,0),Vecteur(1,1));
  BoidSimulator gui = BoidSimulator(windowSimu,b);

  while (windowSimu.isOpen())
  {
      sf::Event event;
      while (windowSimu.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              windowSimu.close();
      }

      windowSimu.clear();
      sf::CircleShape triangle(8.f, 3);
      triangle.setPosition(b.getPosition().getX(),b.getPosition().getY());
      windowSimu.draw(triangle);
      gui.box();
      windowSimu.display();

      // Add calculation -> next()
      b.nextBoid();
  }

  // b.afficherPosition();
  // b.nextBoid();
  // b.afficherPosition();
  // b.nextBoid();
  // b.afficherPosition();
  // b.nextBoid();
  // b.afficherPosition();
  return 0;
}
