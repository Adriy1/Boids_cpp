#include "Boids.h"
#include "Boid.h"
#include <cmath>
#include <stdlib.h>
#include "BoidSimulator.h"

Boids::Boids(int nbBoid){
  for(int i=0;i<nbBoid;i++){
    // listeBoid.push_back(Boid(Vecteur(rand()%GLOBAL_CONST_WIDTH,rand()%GLOBAL_CONST_HEIGHT),Vecteur(1,0)));
    listeBoid.push_back(Boid(Vecteur(rand()%GLOBAL_CONST_WIDTH,rand()%GLOBAL_CONST_HEIGHT),Vecteur(rand()%10-5,rand()%10-5)));
  }
}

Boids::~Boids(){}

void Boids::nextBoids(){
  list<Boid>::iterator it;
  for(it = listeBoid.begin();it != listeBoid.end(); ++it){
      it->nextBoid();
  }
}

sf::VertexArray Boids::afficheBoids(){
  sf::VertexArray listTriangleBoids = sf::VertexArray(sf::Triangles);
  list<Boid>::iterator it;
  for(it = listeBoid.begin();it != listeBoid.end(); ++it){
    listTriangleBoids.append(it->afficheBoid()[0]);
    listTriangleBoids.append(it->afficheBoid()[1]);
    listTriangleBoids.append(it->afficheBoid()[2]);
  }
  return listTriangleBoids;
}
