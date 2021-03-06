#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoidSimulator.h"
// #include "Vecteur.h"
// #include "Boid.h"
// #include "Boids.h"

using namespace std;


int main(int argc, char const *argv[]) {
  /* code */

  sf::RenderWindow windowSimu(sf::VideoMode(GLOBAL_CONST_WIDTH, GLOBAL_CONST_HEIGHT), "SFML Boids!");
  // windowSimu.setVerticalSyncEnabled(true); // un appel suffit, après la création de la fenêtre
  // windowSimu.setFramerateLimit(30); // call it once, after creating the window
  // Boid b = Boid(Vecteur(0,0),Vecteur(1,1)); // Test uniquement -> a placer dans Boid Simulator //DEBUG
  Boids listBoid = Boids(2000);
  BoidSimulator gui = BoidSimulator(windowSimu,listBoid);
  // BoidSimulator::LOOP_COUNTER =0;

  while (windowSimu.isOpen()){
      sf::Event event;
      while (windowSimu.pollEvent(event)){
          if (event.type == sf::Event::Closed)
              windowSimu.close();
      }
          if (event.type == sf::Event::Resized){
            gui.resize(event.size.width,event.size.height);
          }
      gui.affiche();
      gui.next();
      BoidSimulator::LOOP_COUNTER++;
  }
  return 0;
}
