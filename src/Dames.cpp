#include "Dames.h"
#include "Partie.hpp"
#include "Plateau.hpp"
#include <iostream>

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
    Partie::getPartie()->setJeu(this);
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

vector<Case> Dames::peuventRafler(){
    Plateau *p=Partie::getPartie()->getPlateau();
    for (int i=0;i<p->get_sizeX();i++){
        for (int j=0;j<p->get_sizeY();j++){
            Pion *pion =p->getCase(i,j)->getPion();
            if(pion!=NULL){
                if (peutRafler(i,j,pion)){

                }
            }
        }
    }
}

bool Dames::peutRafler(int i, int j, Pion *p){
    Plateau *plateau=Partie::getPartie()->getPlateau();
    int joueur;
    if(p==noir or p==noirR){
        joueur=1;
    }
    else{
        joueur=0;
    }
    if(p==noir or p==blanc){
        if(plateau->getCase(i-1,j-1)->getPion()->getJoueur()!=joueur and
           plateau->getCase(i-2,j-2)->getPion()->getJoueur()==joueur){return true;}
        if(plateau->getCase(i-1,j+1)->getPion()->getJoueur()!=joueur and
           plateau->getCase(i-2,j+2)->getPion()->getJoueur()==joueur){return true;}
        if(plateau->getCase(i+1,j+1)->getPion()->getJoueur()!=joueur and
           plateau->getCase(i+2,j+2)->getPion()->getJoueur()==joueur){return true;}
        if(plateau->getCase(i+1,-1)->getPion()->getJoueur()!=joueur and
           plateau->getCase(i+2,j-2)->getPion()->getJoueur()==joueur){return true;}
    }
    if(p==noirR or p==blancR){
        if(plateau->getCase(i-1,j-1)->getPion()->getJoueur()!=joueur and
           plateau->getCase(i-2,j-2)->getPion()->getJoueur()==joueur){return true;}
        if(plateau->getCase(i-1,j+1)->getPion()->getJoueur()!=joueur and
           plateau->getCase(i-2,j+2)->getPion()->getJoueur()==joueur){return true;}
        if(plateau->getCase(i+1,j+1)->getPion()->getJoueur()!=joueur and
           plateau->getCase(i+2,j+2)->getPion()->getJoueur()==joueur){return true;}
        if(plateau->getCase(i+1,-1)->getPion()->getJoueur()!=joueur and
           plateau->getCase(i+2,j-2)->getPion()->getJoueur()==joueur){return true;}
    }

}


bool Dames::peutJouer(){
    int joueur=Partie::getPartie()->getJoueurs()->getCourrant();
    vector<Case> peuventPrendre= peuventRafler();
    if (peuventPrendre.size()!=0){
        choixPionPourRafle(peuventPrendre);
    }
    else{
        //choixPionDeplacement();
    }

}


void Dames::rafle(Case c){
}

void Dames::choixPionPourRafle(vector<Case> cases){
    std::cout << "Obligation de prendre des pieces adverses. "
     << "Choisissez la pièce avec laquelle rafler : "<<std::endl;
    for(int i=0;i<cases.size();i++){
        std::cout << "[" << i << "] : (" << cases[i].getX()<< ","<<
         cases[i].getY() << ")" << std::endl;
    }
    std::cout << "Numéro du choix : ";
    int num;
    std::cin >> num;
    while(!(cin and num<cases.size())){
        std::cout << "Erreur ! Entrez le numero du pion à jouer : ";
        std::cin.clear();
        std::cin >> num;
    }
    rafle(cases[num]);
}

Dames::~Dames()
{
}

