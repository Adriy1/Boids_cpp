#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Vecteur
{
public:
  // Constructeurs
  Vecteur();
  Vecteur(double x, double y);

  void setX(double x);
  void setY(double y);
  double getX() const;
  double getY() const;
  double getOrientation() const;
  double norm() const;
  double normCompare() const;
  double getAngle(const Vecteur&) const;
  double scalaire(const Vecteur&) const;
  void move(double dx,double dy);
  double distance(const Vecteur &V) const;
  double distanceCompare(const Vecteur &V) const;
  Vecteur milieu(const Vecteur &V) const;

  void saisir();
  void afficher() const;

  //operateurs
  Vecteur &operator+=(const Vecteur&);
  Vecteur &operator-=(const Vecteur&);
  Vecteur &operator*=(const double&);


private:
  double x,y;
};

Vecteur operator+(Vecteur,const Vecteur&);

Vecteur operator-(Vecteur,const Vecteur&);

bool operator==(const Vecteur&, const Vecteur&);

bool operator!=(const Vecteur&, const Vecteur&);


#endif
