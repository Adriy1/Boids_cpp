#include <iostream>
#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "BoidSimulator.h"
#include "Vecteur.h"

using namespace std;


int main(int argc, char const *argv[]) {
  /* code */

  sf::RenderWindow windowSimu(sf::VideoMode(GLOBAL_CONST_WIDTH, GLOBAL_CONST_HEIGHT), "SFML Boids!");
  // windowSimu.setVerticalSyncEnabled(true); // un appel suffit, après la création de la fenêtre
  // Boid b = Boid(Vecteur(0,0),Vecteur(1,1)); // Test uniquement -> a placer dans Boid Simulator
  Boids listBoid = Boids(1000);
  BoidSimulator gui = BoidSimulator(windowSimu,listBoid);
  int i =0 ;
  while (windowSimu.isOpen() && i<100){
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
      i++;
  }
  return 0;
}
