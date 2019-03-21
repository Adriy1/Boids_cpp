#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
using namespace std;

class Vecteur
{
public:
  // Constructeurs
  Vecteur();
  Vecteur(double x, double y);

  //Accesseurs et mutateurs
  void setX(double x);
  void setY(double y);
  double getX() const;
  double getY() const;

  // Autres méthodes
  void move(double dx,double dy);
  double distance(const Vecteur &V) const;
  Vecteur milieu(const Vecteur &V) const;

  void saisir();
  void afficher() const;

  //operateurs
  Vecteur &operator+=(const Vecteur&);

private:
  double x,y;
};

#endif
