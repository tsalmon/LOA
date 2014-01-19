#ifndef DAMES_H
#define DAMES_H

#include "Jeu.hpp"
#include "PionFactory.hpp"
#include <vector>
#include "Case.hpp"


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
        void rafle(Case);

    private:
};

#endif // DAMES_H
