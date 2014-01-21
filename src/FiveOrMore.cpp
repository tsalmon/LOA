//
//  FiveOrMore.cpp
//  Projet
//
//  Created by Владислав Фиц on 20.01.14.
//  Copyright (c) 2014 Vladislav Fitc. All rights reserved.
//

#include "FiveOrMore.h"

char getRandomSymbole(vector<Pion*> vp){
    char c;
    while (true) {
        c = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
        for (unsigned int i = 0; i<vp.size(); ++i) {
            if(c == vp[i]->getSymbole())
                continue;
        }
        break;
    }
    return c;
}

unsigned int calculPoints(unsigned int pionsSupprimes){
    unsigned int points = 50;
    for (unsigned int i = 6; i<=pionsSupprimes; ++i) {
        points += (i-5)*30;
    }
    return points;
}

int **matrix(Plateau *p, int nbLignes, int nbColonnes, int srcX, int srcY, int dstX, int dstY){
    int **matrix = new int*[nbLignes];
    
    for(int i = 0; i < nbLignes; ++i)
        matrix[i] = new int[nbColonnes];
    
    for (int i = 0; i<nbLignes; ++i) {
        for (int j = 0; j<nbColonnes; ++j) {
            if (p->hasPion(i,j)) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    
    matrix[srcX][srcY] = 2;
    matrix[dstX][dstY] = 0;
    
    return matrix;
}

int **updateMatrix(int **m, int nbLignes, int nbColonnes){
    bool changed = false;
    for (int i = 0; i<nbLignes; ++i) {
        for (int j = 0; j<nbColonnes; ++j) {
            if (m[i][j] == 2) {
                
                if (i-1 >= 0)
                    if (m[i-1][j] != 2 && m[i-1][j] != 1){
                        m[i-1][j] = 2;
                        changed = true;
                    }
                
                if (i+1 < nbLignes)
                    if(m[i+1][j] != 2 && m[i+1][j] != 1){
                        m[i+1][j] = 2;
                        changed = true;
                    }
                
                if (j-1 >= 0)
                    if (m[i][j-1] != 2 && m[i][j-1] != 1){
                        m[i][j-1] = 2;
                        changed = true;
                    }
                
                if (j+1 < nbColonnes)
                    if(m[i][j+1] != 2 && m[i][j+1] != 1){
                        m[i][j+1] = 2;
                        changed = true;
                    }
                
            }
        }
    }
    if (changed) {
        return m;
    } else {
        return NULL;
    }
}


bool possibleRoute(Plateau *p, int srcX, int srcY, int dstX, int dstY){
    int nbLignes = p->get_sizeX();
    int nbColonnes = p->get_sizeY();
    int **m = matrix(p, nbLignes, nbColonnes, srcX, srcY, dstX, dstY);
    //showMatrix(m, nbLignes, nbColonnes);
    while (m != NULL && m[dstX][dstY]!=2) {
        m = updateMatrix(m, nbLignes, nbColonnes);
        //showMatrix(m, nbLignes, nbColonnes);
    }
    if (m == NULL) {
        return false;
    } else {
        return true;
    }
}



int **FiveOrMore::getHorizontalMask(){
    Plateau *p = Partie::getPartie()->getPlateau();
    int nbLignes = p->get_sizeX();
    int nbColonnes = p->get_sizeY();
    int **matrix = new int*[nbLignes];
    
    for(int i = 0; i < nbLignes; ++i)
        matrix[i] = new int[nbColonnes];
    
    for (int i = 0; i<nbLignes; ++i) {
        for (int j = 0; j<nbColonnes; ++j) {
            matrix[i][j]=1;
        }
    }
    
    int counter = 1;
    for (int i = 0; i<nbLignes; ++i) {
        for (int j = 0; j<nbColonnes-1; ++j) {
            if(p->getCase(i, j)->hasPion()&&p->getCase(i, j+1)->hasPion() &&(*p->getCase(i, j)->getPion()).getSymbole() == (*p->getCase(i, j+1)->getPion()).getSymbole())
            {
                ++counter;
            } else {
                if (counter >= 5) {
                    for (int k = j-counter+1; k<=j; ++k) {
                        matrix[i][k]=0;
                    }
                    points += calculPoints(counter);
                }
                counter = 1;
            }
        }
        if (counter >= 5) {
            for (int k = nbColonnes-counter; k<nbColonnes; ++k) {
                matrix[i][k]=0;
            }
            points += calculPoints(counter);
        }
        counter = 1;
    }
    return matrix;
}

int **FiveOrMore::getVerticalMask(){
    Plateau *p = Partie::getPartie()->getPlateau();
    int nbLignes = p->get_sizeX();
    int nbColonnes = p->get_sizeY();
    int **matrix = new int*[nbLignes];
    for(int i = 0; i < nbLignes; ++i)
        matrix[i] = new int[nbColonnes];
    for (int i = 0; i<nbLignes; ++i) {
        for (int j = 0; j<nbColonnes; ++j) {
            matrix[i][j]=1;
        }
    }
    
    int counter = 1;
    for (int j = 0; j<nbLignes; ++j) {
        for (int i = 0; i<nbColonnes-1; ++i) {
            if(p->getCase(i, j)->hasPion()&&p->getCase(i+1, j)->hasPion() &&(*p->getCase(i, j)->getPion()).getSymbole() == (*p->getCase(i+1, j)->getPion()).getSymbole())
            {
                ++counter;
            } else {
                if (counter >= 5) {
                    for (int k = i-counter+1; k<=i; ++k) {
                        matrix[k][j] = 0;
                    }
                    points += calculPoints(counter);
                }
                counter = 1;
            }
        }
        if (counter >= 5) {
            for (int k = nbLignes-counter; k<nbLignes; ++k) {
                matrix[k][j] = 0;
            }
            points += calculPoints(counter);
        }
        counter = 1;
    }
    return matrix;
}

int **FiveOrMore::getDiagonalMask1(){
    Plateau *p = Partie::getPartie()->getPlateau();
    int nbLignes = p->get_sizeX();
    int nbColonnes = p->get_sizeY();
    int **matrix = new int*[nbLignes];
    for(int i = 0; i < nbLignes; ++i)
        matrix[i] = new int[nbColonnes];
    for (int i = 0; i<nbLignes; ++i) {
        for (int j = 0; j<nbColonnes; ++j) {
            matrix[i][j]=1;
        }
    }
    
    int counter = 1;
    
    for(int i = 0; i<nbLignes; ++i){
        int ki = i;
        int kj = 0;
        while (ki>=0) {
            //cout<<ki<<","<<kj<<endl;
            if(ki>0 && p->getCase(ki, kj)->hasPion()&&p->getCase(ki-1, kj+1)->hasPion() && (*p->getCase(ki, kj)->getPion()).getSymbole() == (*p->getCase(ki-1, kj+1)->getPion()).getSymbole())
            {
                ++counter;
            } else {
                if (counter >= 5) {
                    int b = kj-counter+1;
                    for(int a = ki+counter-1; a>=ki; --a,++b){
                        matrix[a][b] = 0;
                    }
                    points += calculPoints(counter);
                }
                counter = 1;
            }
            --ki;
            ++kj;
        }
        //cout<<"----"<<endl;
        if (counter >= 5) {
            int b = kj-counter+1;
            for(int a = ki+counter-1; a>=ki; --a,++b){
                matrix[a][b] = 0;
            }
            points += calculPoints(counter);
        }
        counter = 1;
    }
    for (int j = 1; j<nbColonnes; ++j) {
        int kj = j;
        int ki = nbLignes-1;
        while (kj<nbColonnes) {
            //cout<<ki<<","<<kj<<endl;
            if(kj+1<nbColonnes && p->getCase(ki, kj)->hasPion()&&p->getCase(ki-1, kj+1)->hasPion() &&(*p->getCase(ki, kj)->getPion()).getSymbole() == (*p->getCase(ki-1, kj+1)->getPion()).getSymbole())
            {
                ++counter;
            } else {
                if (counter >= 5) {
                    int b = kj-counter+1;
                    for(int a = ki+counter-1; a>=ki; --a,++b){
                        matrix[a][b] = 0;
                    }
                    points += calculPoints(counter);
                }
                counter = 1;
            }
            --ki;
            ++kj;
        }
        //cout<<"----"<<endl;
        if (counter >= 5) {
            int b = kj-counter+1;
            for(int a = ki+counter-1; a>=ki; --a,++b){
                matrix[a][b] = 0;
            }
            points += calculPoints(counter);
        }
        counter = 1;
    }
    return matrix;
}

int **FiveOrMore::getDiagonalMask2(){
    Plateau *p = Partie::getPartie()->getPlateau();
    int nbLignes = p->get_sizeX();
    int nbColonnes = p->get_sizeY();
    int **matrix = new int*[nbLignes];
    
    for(int i = 0; i < nbLignes; ++i)
        matrix[i] = new int[nbColonnes];
    
    for (int i = 0; i<nbLignes; ++i) {
        for (int j = 0; j<nbColonnes; ++j) {
            matrix[i][j]=1;
        }
    }
    
    int counter = 1;
    for(int i = nbLignes-1; i>=0; --i){
        int ki = i;
        int kj = 0;
        while (ki<nbLignes) {
            //cout<<ki<<","<<kj<<endl;
            if(ki+1<nbLignes && kj+1<nbColonnes&& p->getCase(ki, kj)->hasPion() && p->getCase(ki+1, kj+1)->hasPion() && (*p->getCase(ki, kj)->getPion()).getSymbole() == (*p->getCase(ki+1, kj+1)->getPion()).getSymbole())
            {
                ++counter;
            } else {
                if (counter >= 5) {
                    int b = kj-counter+1;
                    for(int a = ki-counter+1; a<=ki; ++a,++b){
                        matrix[a][b] = 0;
                    }
                    points += calculPoints(counter);
                }
                counter = 1;
            }
            ++ki;
            ++kj;
        }
        //cout<<"----"<<endl;
        if (counter >= 5) {
            int b = kj-counter+1;
            for(int a = ki-counter+1; a<=ki; ++a,++b){
                matrix[a][b] = 0;
            }
            points += calculPoints(counter);
        }
        counter = 1;
    }
    for (int j = 1; j<nbColonnes; ++j) {
        int kj = j;
        int ki = 0;
        while (kj<nbColonnes) {
            //cout<<ki<<","<<kj<<endl;
            if(ki+1<nbLignes && kj+1<nbColonnes && p->getCase(ki, kj)->hasPion() && p->getCase(ki+1, kj+1)->hasPion() &&(*p->getCase(ki, kj)->getPion()).getSymbole() == (*p->getCase(ki+1, kj+1)->getPion()).getSymbole())
            {
                ++counter;
            } else {
                if (counter >= 5) {
                    int b = kj-counter+1;
                    for(int a = ki-counter+1; a<=ki; ++a,++b){
                        matrix[a][b] = 0;
                    }
                    points += calculPoints(counter);
                }
                counter = 1;
            }
            ++kj;
            ++ki;
        }
        //cout<<"----"<<endl;
        if (counter >= 5) {
            int b = kj-counter+1;
            for(int a = ki-counter+1; a<=ki; ++a,++b){
                matrix[a][b] = 0;
            }
            points += calculPoints(counter);
        }
        counter = 1;
    }
    return matrix;
}

int **fusionMatrix(int **m1, int **m2, int nbLignes, int nbColonnes){
    int **matrix = new int*[nbLignes];
    
    for(int i = 0; i < nbLignes; ++i)
        matrix[i] = new int[nbColonnes];
    
    for (int i = 0; i<nbLignes; ++i) {
        for(int j = 0; j<nbColonnes; ++j){
            matrix[i][j] = m1[i][j]*m2[i][j];
        }
    }
    return matrix;
}

void applyMask(Plateau *p, int **mask,int nbLignes, int nbColonnes){
    for (int i = 0; i<nbLignes; ++i) {
        for(int j = 0; j<nbColonnes; ++j){
            if (mask[i][j] == 0) {
                p->getCase(i, j)->retirePion();
            }
        }
    }
}


void FiveOrMore::checkFive(){
    Plateau *p = Partie::getPartie()->getPlateau();
    int nbLignes = p->get_sizeX();
    int nbColonnes = p->get_sizeY();
    int **hm = this->getHorizontalMask();
    int **vm = this->getVerticalMask();
    int **dm1 = this->getDiagonalMask1();
    int **dm2 = this->getDiagonalMask2();
    int **fm1 = fusionMatrix(hm, vm, nbLignes, nbColonnes);
    int **fm2 = fusionMatrix(dm1, fm1, nbLignes, nbColonnes);
    int **fm3 = fusionMatrix(dm2, fm2, nbLignes, nbColonnes);
    applyMask(p, fm3, nbLignes, nbColonnes);
    delete hm;
    delete vm;
    delete dm1;
    delete dm2;
    delete fm1;
    delete fm2;
    delete fm3;
    
}

FiveOrMore::FiveOrMore(unsigned int dimension, unsigned int nbPions){
    nbLignes = dimension;
    nbColonnes = dimension;
    nbJoueur = 1;
    points = 0;
    this->nbPions = nbPions;
    char s;
    PionFactory *factory = &PionFactory::getInstance();

    for(unsigned int i = 0; i<nbPions; ++i){
        s=getRandomSymbole(vp);
        Pion *r = factory->getPion(string(1,s));
        r->setSymbole(s);
        vp.push_back(new Pion(*r));
    }
    
    Partie::getPartie()->setJeu(this);
}
FiveOrMore::~FiveOrMore(){
    vp.clear();
    vector<Pion*>(vp).swap(vp);
}

int FiveOrMore::fini (){
    if (!peutJouer()) {
        return 0;
    } else{
        return -1;
    }
}

bool FiveOrMore::peutJouer (){
    Plateau *p = Partie::getPartie()->getPlateau();
    return (p->m_casesLibres.size()>=3);
}

void FiveOrMore::mettreTroisPions(/*Plateau *p,*/ vector<Pion*> vp){
    Plateau *p = Partie::getPartie()->getPlateau();
    unsigned long cp = vp.size();
    unsigned long ccl = p->m_casesLibres.size();

    std::vector<Case>::iterator it;
    
    for (int i = 0; i<3; ++i) {
        it = p->m_casesLibres.begin();
        it+= rand()%ccl;
        
        p->mettrePionDansCase(vp[rand()%cp], (*it).getX(), (*it).getY());
        --ccl;
    }
}

void FiveOrMore::newPartie (){
    int srcX, srcY, dstX, dstY;
    Plateau *p = Partie::getPartie()->getPlateau();
    mettreTroisPions(vp);
    while(!p->isFull()){
        Partie::getPartie()->affiche();
        cout<<"Please, input source X: ";
        cin>>srcX;
        cout<<endl<<"Source Y: ";
        cin>>srcY;
        cout<<endl<<"Destination X: ";
        cin>>dstX;
        cout<<endl<<"Destination Y: ";
        cin>>dstY;
        
        
        if (srcX < 0 || srcX >= p->get_sizeX() || srcY < 0 || srcY >= p->get_sizeY()) {
            cout << "Cell coordinates out of range. Try again." << endl;
            continue;
        }
        if (!p->hasPion(srcX, srcY)) {
            cout << "You have selected empty cell. Try again." << endl;
            continue;
        }
        if (p->hasPion(dstX, dstY)) {
            cout << "Destination cell has a checker. Try again." << endl;
            continue;
        }
        
        if (possibleRoute(p, srcX, srcY, dstX, dstY)) {
            Pion *pBouge = p->pionDansCase(srcX, srcY);
            p->mettrePionDansCase(pBouge, dstX, dstY);
            p->effacerPionDeCase(srcX, srcY);
            checkFive();
            
            if (!peutJouer())
                break;
            
            mettreTroisPions(vp);
            checkFive();
            cout << "Points: " << points << endl;
        } else {
            cout << "Impossible to move this checker to this position. Try again" <<endl;
            continue;
        }
    }
    
    cout<< "Game over!" <<endl;
    cout<< "Total points: "<<points<<endl;
}

int FiveOrMore::getNbLignes(){
    return this->nbLignes;
}

int FiveOrMore::getNbColonnes(){
    return this->nbColonnes;
}

int FiveOrMore::getNbJoueur(){
    return 1;
}


