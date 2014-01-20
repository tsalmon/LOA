#include "Dames.hpp"
#include "Partie.hpp"

Dames::Dames()
{
    nbJoueur=2;
    nbLignes=10;
    nbColonnes=10;
    PionFactory &factory=PionFactory::getInstance();
    blanc = factory.getPion("blanc");
    blanc->setSymbole('b');
    noir = factory.getPion("noir");
    noir->setSymbole('n');
    blancR = factory.getPion("blancR");
    blancR->setSymbole('B');
    noirR = factory.getPion("noirR");
    noirR->setSymbole('N');
    Partie::getPartie()->setJeu(this);
}

void Dames::newPartie(){
    Plateau *p = Partie::getPartie()->getPlateau();
#include <iostream>
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
    vector<Case> result;
    for (int i=0;i<p->get_sizeX();i++){
        for (int j=0;j<p->get_sizeY();j++){
            if(p->hasPion(i,j)){
                Pion *pion =p->getCase(i,j)->getPion();
                if (peutRafler(i,j,pion)){
                    result.push_back(*p->getCase(i,j));
                }
            }
        }
    }
    return result;
}

bool Dames::peutRafler(int i, int j, Pion *pion){
    int joueur;
    if(pion==noir or pion==noirR){
        joueur=1;
    }
    else{
        joueur=0;
    }
    int adj; int next;
    Plateau *p=Partie::getPartie()->getPlateau();
    if(pion==noir or pion==blanc){
         adj=joueurAt(i-1,j-1,p); next=joueurAt(i-2,j-2,p);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        adj=joueurAt(i-1,j+1,p); next=joueurAt(i-2,j+2,p);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        adj=joueurAt(i+1,j-1,p); next=joueurAt(i+2,j-2,p);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        adj=joueurAt(i+1,j+1,p); next=joueurAt(i+2,j+2,p);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}
    }
    else if(pion==noirR or pion==blancR){
        int x=0; int y=0;
        do{
        x--;y--;
        adj=joueurAt(i+x,y,p); next=joueurAt(i+x-1,j+y-1,p);
        }
        while(next>-1 and adj==-1);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        x=0; y=0;
        do{
        x--;y++;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x-1,j+y+1,p);
        }
        while(next>-1 and adj==-1);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        x=0; y=0;
        do{
        x++;y--;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x+1,j+y-1,p);
        }
        while(next>-1 and adj==-1);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        x=0; y=0;
        do{
        x++;y++;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x+1,j+y+1,p);
        }
        while(next>-1 and adj==-1);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}
    }


}


int Dames::joueurAt(int x,int y, Plateau* p){
    if(x<0 or y <0 or x>9 or y>9){return -2;}
    else{
        if(p->hasPion(x,y)){
            return p->getCase(x,y)->getPion()->getJoueur();}
        else{return -1;}
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
    int joueur;
    if(c.getPion()==noir or c.getPion()==noirR){
        joueur=1;
    }
    else{
        joueur=0;
    }
    Plateau *p=Partie::getPartie()->getPlateau();
    int i=c.getX();int j=c.getY();
    vector<Case> case_arrivee;
    int adj; int next;
    if(c.getPion()==noir or c.getPion()==blanc){
         adj=joueurAt(-1,-1,p); next=joueurAt(-2,-2,p);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){
            case_arrivee.pop_back(p->getCase()}

        adj=joueurAt(-1,1,p); next=joueurAt(-2,2,p);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){
            rec.getPion()turn true;}

        adj=joueurAt(1,-1,p); next=joueurAt(2,-2,p);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

      if(pion==noir or pion==blanc){
      adj=joueurAt(1,1,p); next=joueurAt(2,2,p);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}
    }
    if(c.getPion()==noirR or c.getPion()==blancR){
        int x=0; int y=0;
        do{
        x--;y--;
        adj=joueurAt(x,y,p); next=joueurAt(x-1,y-1,p);
        }
        while(next>-1 and adj==-1);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        x=0; y=0;
        do{
        x--;y++;
        adj=joueurAt(x,y,p); next=joueurAt(x-1,y+1,p);
        }
        while(next>-1 and adj==-1);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        x=0; y=0;
        do{
        x++;y--;
        adj=joueurAt(x,y,p); next=joueurAt(x+1,y-1,p);
        }
        while(next>-1 and adj==-1);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}

        x=0; y=0;
        do{
        x++;y++;
        adj=joueurAt(x,y,p); next=joueurAt(x+1,y+1,p);
        }
        while(next>-1 and adj==-1);
        if(adj!=joueur and next==joueur and adj>-1 and next>-1){return true;}
    }*/


}

void Dames::choixPionPourRafle(vector<Case> cases){}
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

