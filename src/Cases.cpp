#include "Cases.hpp"

Case::Case(unsigned int x, unsigned int y, Pion *p){
    this->coordonneX = x;
    this->coordonneX = y;
    this->pionImbrique = p;
}

Pion *Case::getPion() const{
    return this->pionImbrique;
}

void Case::addPion(Pion &p){
    this->pionImbrique = &p;
}

void Case::retirePion(){
    this->pionImbrique = NULL;
}

unsigned int Case::getX(){
    return this->coordonneX;
}

unsigned int Case::getY(){
    return this->coordonneY;
}