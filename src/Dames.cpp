#include "Dames.h"
#include "Partie.hpp"
#include "Plateau.hpp"

Dames::Dames()
{
    nbJoueur=2;
    nbLignes=10;
    nbColonnes=10;
    PionFactory &factory=PionFactory::getInstance();
    blanc = factory.getPion("blanc");
    noir = factory.getPion("noir");
}

void Dames::newPartie(){
    Plateau *p = Partie::getPartie()->getPlateau();
    for (int i=0;i<p->get_sizeX();i++){
        for (int j=0;j<p->get_sizeY();j++){
            if(j%2!=i%2){
                if(j<4){p->mettrePionDansCase(*noir,i,j);}
                if(j>=6){p->mettrePionDansCase(*blanc,i,j);}
            }
        }
    }
}

int Dames::fini(){}


Dames::~Dames()
{
}
