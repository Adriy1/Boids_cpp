#include "Vecteur.h"
#include <cmath>
#include <iostream>
using namespace std;

Vecteur::Vecteur() : x(0), y(0) {}

Vecteur::Vecteur(double x, double y) : x(x), y(y) {}

void Vecteur::setX(double x){
    this->x = x;
}

void Vecteur::setY(double y){
    this->y = y;
}

void Vecteur::move(double dx,double dy){
  this->x = x + dx;
  this->y = y + dy;
}

double Vecteur::getX() const{
    return this->x;
}

double Vecteur::getY() const{
    return this->y;
}

double Vecteur::getOrientation()const{
    return atan2(x, y)*180/3.1416;
}

double Vecteur::scalaire(const Vecteur&V)const{
  return x*V.x+y*V.y;
}

double Vecteur::getAngle(const Vecteur&V)const{
  return 180/3.1416*acos(this->scalaire(V)/(this->norm()*V.norm()));
}

double Vecteur::norm()const{
    return sqrt(x*x+y*y);
}

double Vecteur::normCompare()const{
    return (x*x+y*y);
}

double Vecteur::distance(const Vecteur &V) const{
    double dx = this->x - V.x;
    double dy = this->y - V.y;
    return sqrt(dx*dx + dy*dy);
}

double Vecteur::distanceCompare(const Vecteur &V) const{
    double dx = this->x - V.x;
    double dy = this->y - V.y;
    return (dx*dx + dy*dy);
}

Vecteur Vecteur::milieu(const Vecteur &V) const{
    Vecteur result;
    result.x = (V.x + this->x) / 2;
    result.y = (V.y + this->y) / 2;
    return result;
}

void Vecteur::saisir(){
    cout << "Tapez l'abscisse : ";  cin >> this->x;
    cout << "Tapez l'ordonnée : ";  cin >> this->y;
}

void Vecteur::afficher() const{
    cout << "L'abscisse vaut " << this->x << endl;
    cout << "L'ordonnée vaut " << this->y << endl;
}

Vecteur &Vecteur::operator+=(const Vecteur &v){
    x += v.x;
    y += v.y;
    return *this;
}

Vecteur &Vecteur::operator-=(const Vecteur &v){
    x -= v.x;
    y -= v.y;
    return *this;
}

Vecteur operator+(Vecteur lhs,const Vecteur& rhs){
  lhs += rhs;
  return lhs;
}

Vecteur operator-(Vecteur lhs,const Vecteur& rhs){
  lhs -= rhs;
  return lhs;
}

Vecteur &Vecteur::operator*=(const double &k){
    x *= k;
    y *= k;
    return *this;
}

bool operator==(const Vecteur& lhs, const Vecteur& rhs){ if(lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY()) return true; }
bool operator!=(const Vecteur& lhs, const Vecteur& rhs){ return !(lhs == rhs); }
