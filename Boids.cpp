#include "Boids.h"
#include "Boid.h"
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include "BoidSimulator.h"

Boids::Boids(int nbBoid){
  srand((unsigned)time(0));
  for(int i=0;i<nbBoid;i++){
    // listeBoid.push_back(Boid(Vecteur(rand()%GLOBAL_CONST_WIDTH,rand()%GLOBAL_CONST_HEIGHT),Vecteur(1,0))); //DEBUG
    // listeBoid.push_back(Boid(Vecteur(rand()%GLOBAL_CONST_WIDTH,rand()%GLOBAL_CONST_HEIGHT),Vecteur(rand()%10-5,rand()%10-5))); OLD VERSION
    int x_pos = rand()%GLOBAL_CONST_WIDTH;
    int y_pos = rand()%GLOBAL_CONST_HEIGHT;
    std::cout <<  x_pos/SIZE_LEAF<<'\n';
    std::cout << x_pos/110 << " || "<<y_pos/110 <<'\n';
    grid[(x_pos/SIZE_LEAF)][y_pos/SIZE_LEAF].push_back(Boid(Vecteur(x_pos,y_pos),Vecteur(rand()%10-5,rand()%10-5)));
  }
}

Boids::~Boids(){}

void Boids::nextBoids(){
  // list<Boid>::iterator it;
  // for(it = listeBoid.begin();it != listeBoid.end(); ++it){
  //     it->nextBoid(listeBoid);
  // }
  list<Boid>::iterator it;
  for (int i=0; i<NB_ROWS;i++){
    for(int j=0; j<NB_COLS;j++){
      for(it = grid[i][j].begin();it != grid[i][j].end(); ++it){
          it->nextBoid(grid);
      }
    }
  }
}

sf::VertexArray Boids::afficheBoids(){
  sf::VertexArray listTriangleBoids = sf::VertexArray(sf::Triangles);
  list<Boid>::iterator it;
  for (int i=0; i<NB_ROWS;i++){
    for(int j=0; j<NB_COLS;j++){
      for(it = grid[i][j].begin();it != grid[i][j].end(); ++it){
        listTriangleBoids.append(it->afficheBoid()[0]);
        listTriangleBoids.append(it->afficheBoid()[1]);
        listTriangleBoids.append(it->afficheBoid()[2]);
      }
    }
  }
  return listTriangleBoids;
}
