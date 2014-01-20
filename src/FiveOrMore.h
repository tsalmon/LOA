//
//  FiveOrMore.h
//  Projet
//
//  Created by Владислав Фиц on 20.01.14.
//  Copyright (c) 2014 Vladislav Fitc. All rights reserved.
//

#ifndef __Projet__FiveOrMore__
#define __Projet__FiveOrMore__

#include <iostream>

#include "Plateau.hpp"
#include "Partie.hpp"

class FiveOrMore:public Jeu{
private:
    unsigned int nbPions;
    unsigned int points;
    vector<Pion*> vp;

    virtual int getNbLignes();
    virtual int getNbJoueur();
    virtual int getNbColonnes();
    virtual bool peutJouer ();
    virtual void newPartie ();
    virtual int fini ();
    
    void checkFive();
    int **getHorizontalMask( int nbLignes, int nbColonnes);
    int **getVerticalMask(int nbLignes, int nbColonnes);
    int **getDiagonalMask1(int nbLignes, int nbColonnes);
    int **getDiagonalMask2( int nbLignes, int nbColonnes);
public:
    FiveOrMore(unsigned int dimension, unsigned int nbPions);
};

#endif /* defined(__Projet__FiveOrMore__) */
