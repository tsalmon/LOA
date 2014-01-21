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
#include <stdlib.h>

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
    void mettreTroisPions(vector<Pion*>);
    int **getHorizontalMask();
    int **getVerticalMask();
    int **getDiagonalMask1();
    int **getDiagonalMask2();
public:
    FiveOrMore(unsigned int dimension, unsigned int nbPions);
    virtual ~FiveOrMore();
};

#endif /* defined(__Projet__FiveOrMore__) */
