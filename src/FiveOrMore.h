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
    virtual int getNbLignes();
    virtual int getNbJoueur();
    virtual int getNbColonnes();
    virtual bool peutJouer ();
    virtual int fini ();
    
    vector<Pion*> vp;
    
    int **getHorizontalMask(/*Plateau *p,*/ int nbLignes, int nbColonnes);
    int **getVerticalMask(/*Plateau *p,*/ int nbLignes, int nbColonnes);
    int **getDiagonalMask1(/*Plateau *p,*/ int nbLignes, int nbColonnes);
    int **getDiagonalMask2(/*Plateau *p,*/ int nbLignes, int nbColonnes);
    void checkFive(/*Plateau *p*/);
public:
    FiveOrMore(unsigned int dimension, unsigned int nbPions);
    virtual void newPartie ();
};

#endif /* defined(__Projet__FiveOrMore__) */
