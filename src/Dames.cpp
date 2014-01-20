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
    blancR = factory.getPion("blancR");
    blancR->setSymbole('B');
    blancR->setJoueur(0);
    noirR = factory.getPion("noirR");
    noirR->setSymbole('N');
    noirR->setJoueur(1);
    noir->setSymbole('n');
    noir->setJoueur(1);
    blanc->setJoueur(0);
    Partie::getPartie()->setJeu(this);
}

void Dames::newPartie(){
    Plateau *p = Partie::getPartie()->getPlateau();
    for (int i=0;i<p->get_sizeX();i++){
        for (int j=0;j<p->get_sizeY();j++){
            if(j%2!=i%2){
                if(i<4){p->mettrePionDansCase(noir,i,j);}
                if(i>=6){p->mettrePionDansCase(blanc,i,j);}
            }
        }
    }
    Partie::getPartie()->joueTour();
}

int Dames::fini(){
    Plateau *p=Partie::getPartie()->getPlateau();
    if (!p->hasPion(noir) and !p->hasPion(noirR)){return 0;}
    else if (!p->hasPion(blanc) and !p->hasPion(blancR)){return 1;}
    else{return -1;}
}

vector<Case*> Dames::peuventRafler(int joueur){
    Plateau *p=Partie::getPartie()->getPlateau();
    vector<Case*> result;
    for (int i=0;i<p->get_sizeX();i++){
        for (int j=0;j<p->get_sizeY();j++){
            if(p->hasPion(i,j)){
                Pion *pion =p->getCase(i,j)->getPion();
                if (peutRafler(i,j,pion) and pion->getJoueur()==joueur){
                    result.push_back(p->getCase(i,j));
                }
            }
        }
    }
    return result;
}

bool Dames::peutRafler(int i, int j, Pion *pion){
    int joueur=pion->getJoueur();
    int adj; int next;
    Plateau *p=Partie::getPartie()->getPlateau();
    if(pion==noir or pion==blanc){
         adj=joueurAt(i-1,j-1,p); next=joueurAt(i-2,j-2,p);
        if(adj!=joueur and next==-1 and adj>-1){return true;}

        adj=joueurAt(i-1,j+1,p); next=joueurAt(i-2,j+2,p);
        if(adj!=joueur and next==-1 and adj>-1){return true;}

        adj=joueurAt(i+1,j-1,p); next=joueurAt(i+2,j-2,p);
        if(adj!=joueur and next==-1 and adj>-1){return true;}

        adj=joueurAt(i+1,j+1,p); next=joueurAt(i+2,j+2,p);
        if(adj!=joueur and next==-1 and adj>-1){return true;}
    }
    else if(pion==noirR or pion==blancR){
        int x=0; int y=0;
        do{
        x--;y--;
        adj=joueurAt(i+x,y,p); next=joueurAt(i+x-1,j+y-1,p);
        }
        while(next!=-2 and adj==-1);
        if(adj!=joueur and next==-1 and adj>-1 ){return true;}

        x=0; y=0;
        do{
        x--;y++;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x-1,j+y+1,p);
        }
        while(next!=-2 and adj==-1);
        if(adj!=joueur and next==-1 and adj>-1){return true;}

        x=0; y=0;
        do{
        x++;y--;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x+1,j+y-1,p);
        }
        while(next!=-2 and adj==-1);
        if(adj!=joueur and next==-1 and adj>-1){return true;}

        x=0; y=0;
        do{
        x++;y++;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x+1,j+y+1,p);
        }
        while(next!=-2 and adj==-1);
        if(adj!=joueur and next==-1 and adj>-1){return true;}
    }
    return false;


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
    std::cout <<"Au tour du joueur "<< joueur<<std::endl<<std::endl;
    vector<Case*> peuventPrendre= peuventRafler(joueur);
    if (peuventPrendre.size()!=0){
        choixPionPourRafle(peuventPrendre);
    }
    else{
        choixPionDeplacement(joueur);
    }
    std::cout <<std::endl<<"------------------------------"
    << std::endl<<std::endl;
    return true;
}

void Dames::vider_buffer()
{
    cin.clear();
    cin.seekg(0, ios::end);
    if(!cin.fail())
    {cin.ignore(numeric_limits<streamsize>::max());}
    else{cin.clear();}
}

void Dames::choixPionDeplacement(int joueur){
    std::cout <<
    "Entrez le numero de ligne de la piece a deplacer : ";
    unsigned int x;
    while(!(std::cin>>x and x<10)){
        vider_buffer();
        std::cout <<"Erreur ! Entrez le numero de LIGNE de la piece a deplacer : ";
    }
    std::cout <<
    "Entrez le numero de colonne de la piece a deplacer : ";
    unsigned int y;
    while(!(std::cin>>y and y<10)){
        vider_buffer();
        std::cout <<"Erreur ! Entrez le numero de COLONNE de la piece a deplacer : ";
    }
    Plateau *p=Partie::getPartie()->getPlateau();
    if (p->hasPion(x,y)){
        Case *choix=p->getCase(x,y);
        if(choix->getPion()->getJoueur()==joueur){
            deplace(choix);
        }else{
            std::cout <<
            "Erreur ! vous devez selectionner une case ayant un de vos pions"
            <<std::endl;
            choixPionDeplacement(joueur);
        }
    }else {
        std::cout <<
        "Erreur ! vous devez selectionner une case ayant un de vos pions"
        <<std::endl;
        choixPionDeplacement(joueur);
    }


}



void Dames::deplace(Case *c){
    Plateau *p=Partie::getPartie()->getPlateau();
    int i=c->getX();int j=c->getY();
    vector<Case*> case_arrivee;
    if(c->getPion()==noir){
            if(joueurAt(i+1,j-1,p)==-1){
                 case_arrivee.push_back(p->getCase(i+1,j-1));
            }
            if(joueurAt(i+1,j+1,p)==-1){
                 case_arrivee.push_back(p->getCase(i+1,j+1));
            }
    }else if(c->getPion()==blanc){
            if(joueurAt(i-1,j-1,p)==-1){
                 case_arrivee.push_back(p->getCase(i-1,j-1)); std::cout<<"1";
            }
            if(joueurAt(i-1,j+1,p)==-1){
                 case_arrivee.push_back(p->getCase(i-1,j+1));std::cout<<"2";
            }
    }
    else if(c->getPion()==noirR or c->getPion()==blancR){
        int x=-1; int y=-1;
        while(!joueurAt(i+x,j+y,p)>-1){
            case_arrivee.push_back(p->getCase(i+x,j+y));
            x--;y--;
        }
        x=1; y=-1;
        while(!joueurAt(i+x,j+y,p)>-1){
            case_arrivee.push_back(p->getCase(i+x,j+y));
            x++;y--;
        }
        x=-1; y=1;
        while(!joueurAt(i+x,j+y,p)>-1){
            case_arrivee.push_back(p->getCase(i+x,j+y));
            x--;y++;
        }
        x=1; y=1;
        while(!joueurAt(i+x,j+y,p)>-1){
            case_arrivee.push_back(p->getCase(i+x,j+y));
            x++;y++;
        }
    }
    if(case_arrivee.size()==0){
        choixPionDeplacement(Partie::getPartie()->getJoueurs()->getCourrant());
        return;
    }
    std::cout << "Choisissez la case d'arrivee : "<<std::endl;
    for(unsigned int i=0;i<case_arrivee.size();i++){
        std::cout << "[" << i << "] : (" << case_arrivee[i]->getX()<< ","<<
         case_arrivee[i]->getY() << ")" << std::endl;
    }
    std::cout << "Numero du choix : ";
    unsigned int num;
    while(!(cin>>num and num<case_arrivee.size())){
        vider_buffer();
        std::cout << "Erreur ! Entrez le numero de la case cible : ";
    }
    Case *cible=case_arrivee[num];
    cible->addPion(c->getPion());
    c->retirePion();
    if (cible->getX()==0 and cible->getPion()==noir){
        std::cout << "Reine !";
        cible->addPion(noirR);
    }
    else if (cible->getX()==9 and cible->getPion()==blanc){
        std::cout << "Reine !";
        cible->addPion(blancR);
    }
}

void Dames::rafle(Case *c){
    int joueur=c->getPion()->getJoueur();
    Plateau *p=Partie::getPartie()->getPlateau();
    int i=c->getX();int j=c->getY();
    vector<Case*> case_arrivee;
    vector<Case*> case_a_bouffer;
    int adj; int next;
    if(c->getPion()==noir or c->getPion()==blanc){
         adj=joueurAt(i-1,j-1,p); next=joueurAt(i-2,j-2,p);
        if(adj!=joueur and next==-1 and adj>-1){
            case_arrivee.push_back(p->getCase(i-2,j-2));
            case_a_bouffer.push_back(p->getCase(i-1,j-1));}

        adj=joueurAt(i-1,j+1,p); next=joueurAt(i-2,j+2,p);
        if(adj!=joueur and next==-1 and adj>-1){
            case_arrivee.push_back(p->getCase(i-2,j+2));
            case_a_bouffer.push_back(p->getCase(i-1,j+1));}

        adj=joueurAt(i+1,j-1,p); next=joueurAt(i+2,j-2,p);
        if(adj!=joueur and next==-1 and adj>-1){
            case_arrivee.push_back(p->getCase(i+2,j-2));
            case_a_bouffer.push_back(p->getCase(i+1,j-1));}

        adj=joueurAt(i+1,j+1,p); next=joueurAt(i+2,j+2,p);
        if(adj!=joueur and next==-1 and adj>-1){
            case_arrivee.push_back(p->getCase(i+2,j+2));
            case_a_bouffer.push_back(p->getCase(i+1,j+1));}
    }
    else if(c->getPion()==noirR or c->getPion()==blancR){
        int x=0; int y=0;
        do{
        x--;y--;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x-1,j+y-1,p);
        }
        while(next!=-2 and adj==-1);
        if(adj!=joueur and next==-1 and adj>-1){
            while (next==-1){
                case_arrivee.push_back(p->getCase(i+x-1,j+y-1));
                case_a_bouffer.push_back(p->getCase(i+x,j+y));
                x--;y--; next=joueurAt(i+x-1,j+y-1,p);
            }
        }

        x=0; y=0;
        do{
        x--;y++;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x-1,j+y+1,p);
        }
        while(next!=-2 and adj==-1);
        if(adj!=joueur and next==-1 and adj>-1){
            while (next==-1){
                case_arrivee.push_back(p->getCase(i+x-1,j+y+1));
                case_a_bouffer.push_back(p->getCase(i+x,j+y));
                x--;y++;next=joueurAt(i+x-1,j+y+1,p);
            }
        }

        x=0; y=0;
        do{
        x++;y--;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x-1,j+y+1,p);
        }
        while(next!=-2 and adj==-1);
        if(adj!=joueur and next==-1 and adj>-1){
            while (next==-1){
                case_arrivee.push_back(p->getCase(i+x+1,j+y-1));
                case_a_bouffer.push_back(p->getCase(i+x,j+y));
                x++;y--;next=joueurAt(i+x-1,j+y+1,p);
            }
        }

        x=0; y=0;
        do{
        x++;y++;
        adj=joueurAt(i+x,j+y,p); next=joueurAt(i+x+1,j+y+1,p);
        }
        while(next!=-2 and adj==-1);
        if(adj!=joueur and next==-1 and adj>-1){
            while (next==-1){
                case_a_bouffer.push_back(p->getCase(i+x,j+y));
                case_arrivee.push_back(p->getCase(i+x+1,j+y+1));
                x++;y++;next=joueurAt(i+x+1,j+y+1,p);
            }
        }
    }

    std::cout << "Choisissez la case d'arrivee : "<<std::endl;
    for(unsigned int i=0;i<case_arrivee.size();i++){
        std::cout << "[" << i << "] : (" << case_arrivee[i]->getX()<< ","<<
         case_arrivee[i]->getY() << ")" << std::endl;
    }
    std::cout << "Numero du choix : ";
    unsigned int num;
    while(!(cin>>num and num<case_arrivee.size())){
        vider_buffer();
        std::cout << "Erreur ! Entrez le numero de la case cible : ";
    }
    Case *cible=case_arrivee[num];
    cible->addPion(c->getPion());
    Case *victime=case_a_bouffer[num];
    victime->retirePion();
    c->retirePion();
    if (cible->getX()==0 and cible->getPion()==noir){
        std::cout << "Reine !";
        cible->addPion(noirR);
    }
    else if (cible->getX()==9 and cible->getPion()==blanc){
        std::cout << "Reine !";
        cible->addPion(blancR);
    }
    if(peutRafler(cible->getX(),cible->getY(),cible->getPion())){
        std::cout << "Encore des pieces a prendre : "<<std::endl;
        Partie::getPartie()->affiche();
       rafle(cible);
       }
}

void Dames::choixPionPourRafle(vector<Case*> cases){
    std::cout << "Obligation de prendre des pieces adverses. "<<std::endl;
    std::cout << "Choisissez la piece avec laquelle rafler : "<<std::endl;
    for(unsigned int i=0;i<cases.size();i++){
        std::cout << "[" << i << "] : (" << cases[i]->getX()<< ","<<
         cases[i]->getY() << ")" << std::endl;
    }
    std::cout << "Numero du choix : ";
    unsigned int num;
    while(!(cin>>num and num<cases.size())){
        vider_buffer();
        std::cout << "Erreur ! Entrez le numero du pion a jouer : ";
    }
    rafle(cases[num]);

}

Dames::~Dames()
{
}

