#ifndef DAMES_H
#define DAMES_H

#include "Jeu.hpp"
#include "PionFactory.hpp"
#include <vector>
#include "Plateau.hpp"
#include <iostream>
#include <sstream>
#include <limits>


class Dames : public Jeu{
    public:
        Dames();
        virtual ~Dames();
        virtual int fini ();
        virtual bool peutJouer();
        virtual void newPartie();
    protected:
        Pion *blanc;
        Pion *noir;
        Pion *noirR;
        Pion *blancR;
        vector<Case*> peuventRafler(int);
        void choixPionPourRafle(vector<Case*>);
        void choixPionDeplacement(int);
        void deplace(Case*);
        bool peutRafler(int,int,Pion*);
        void rafle(Case*);
        int joueurAt(int,int,Plateau*);
        void vider_buffer();
    private:
};

#endif // DAMES_H
