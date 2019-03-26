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
    grid[(x_pos/SIZE_LEAF)][y_pos/SIZE_LEAF].push_back(Boid(Vecteur(x_pos,y_pos),Vecteur(rand()%10-5,rand()%10-5)));
  }
}

Boids::~Boids(){}

// list<Boid>[][] Boids::getGrid(){
//   return grid;
// }

void Boids::nextBoids(){

  list<Boid>::iterator it;
  for (int i=0; i<NB_ROWS;i++){
    for(int j=0; j<NB_COLS;j++){
      for(it = grid[i][j].begin();it != grid[i][j].end(); ++it){
        // std::cout << "\n--------- \n CASE I: "<< i << " CASE J: "<< j << '\n';
        it->nextBoid(grid);
        int new_X = int(it->getPosition().getX()/SIZE_LEAF);
        int new_Y = int(it->getPosition().getY()/SIZE_LEAF);
        if (i != new_X || j != new_Y){
          Boid b = Boid(it->getPosition(),it->getVitesse());
          it = grid[i][j].erase(it);//(*it);
          grid[new_X][new_Y].push_back(b);
        }
      }
    }
  }
}

void Boids::removeGrid(int x,int y, Boid b){
  grid[x][y].remove(b);
}

void Boids::addGrid(int x,int y, Boid b){
  grid[x][y].push_back(b);
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
