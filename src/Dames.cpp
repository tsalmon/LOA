#include "Dames.h"
#include "Partie.hpp"
#include "Plateau.hpp"

Dames::Dames()
{
    nbJoueur=2;
    nbLignes=10;
    nbColonnes=10;
    PionFactory &factory=PionFactory::getInstance();
    blanc = factory->getPion("blanc");
    noir = factory->getPion("noir");

}

Dames::newPartie(){
    Plateau *p = Partie::getPlateau();
    for (int i=0;i<p->get_sizeX();i++){
        for (int j=0;j<p->get_sizeY();j++){
            if(j%2!=i%2)
        }
    }
}

Dames::~Dames()
{
}
