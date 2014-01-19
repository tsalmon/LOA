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

void Dames::newPartie(){
    Plateau *p = Partie::getPlateau();
    for (int i=0;i<p->get_sizeX();i++){
        for (int j=0;j<p->get_sizeY();j++){
            if(j%2!=i%2){
                if(j<4){p->mettrePionDansCase(noir);}
                if(j>=6){p->mettrePionDansCase(blanc);}
            }
        }
    }
}

int Dames::fini(){return 0;}


Dames::~Dames()
{
}
