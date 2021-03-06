#include "Case.hpp"

Case::Case(unsigned int x, unsigned int y, Pion *p){
    this->coordonneX = x;
    this->coordonneY = y;
    this->pionImbrique = p;
}

Pion *Case::getPion() const{
    return this->pionImbrique;
}

void Case::addPion(Pion *p){
    this->pionImbrique = p;
}
bool Case::hasPion(){
    return this->pionImbrique != NULL;
}

void Case::retirePion(){
    this->pionImbrique = NULL;
}

unsigned int Case::getX() const{
    return this->coordonneX;
}

unsigned int Case::getY() const{
    return this->coordonneY;
}
