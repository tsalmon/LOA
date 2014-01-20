#ifndef DAMES_H
#define DAMES_H

#include "Jeu.hpp"
#include "PionFactory.hpp"
#include <vector>
#include "Plateau.hpp"


class Dames : public Jeu{
    public:
        Dames();
        virtual ~Dames();
        virtual int fini ();
        virtual bool peutJouer();
        virtual void newPartie();
    protected:
        Pion *noir;
        Pion *blanc;
        Pion *noirR;
        Pion *blancR;
        vector<Case> peuventRafler();
        void choixPionPourRafle(vector<Case>);
        void choixPionDeplacement();
        bool peutRafler(int,int,Pion*);
        void rafle(Case);
        int joueurAt(int,int,Plateau*);
    private:
};

#endif // DAMES_H
