#include "PionFactory.hpp"

PionFactory::PionFactory(){}
PionFactory::PionFactory(PionFactory &){}
void PionFactory::operator=(PionFactory &){}

PionFactory &PionFactory::getInstance(){
    static PionFactory instance;
    return instance;
}

Pion *PionFactory::getPion(string nom)
{
    for(std::vector<Pion>::iterator it = pions.begin(); it != pions.end(); ++it) {
        if((*it).nom == nom)
            return &(*it);
    }
    Pion *ch = new Pion(nom);
    pions.push_back(*ch);
    return &(*pions.end());
}

