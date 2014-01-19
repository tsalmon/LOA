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
    blancR = factory.getPion("blancR");
    noirR = factory.getPion("noirR");
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

int Dames::fini(){
    Plateau *p=Partie::getPartie()->getPlateau();
    if (!p->hasPion(noir) and !p->hasPion(noirR)){return 0;}
    else if (!p->hasPion(blanc) and !p->hasPion(blancR)){return 1;}
    else{return -1;}
}


bool Dames::peutJouer(){
    int joueur=Partie::getPartie()->getJoueurs()->getCourrant();
    vector<Case> peuventPrendre= peuventRafler();
    if (peuventPrendre.size()!=0){
        choixPionPourRafle(peuventPrendre);
    }
    else{
        choixPionDeplacement();
    }
    return true;
}

Dames::~Dames()
{
}

void Dames::choixPionPourRafle(vector<Case>){
}

void Dames::choixPionDeplacement(){
}

vector<Case> Dames::peuventRafler(){
}
