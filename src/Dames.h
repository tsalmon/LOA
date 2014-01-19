#ifndef DAMES_H
#define DAMES_H

#include "Jeu.hpp"
#include "PionFactory.hpp"


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
    private:
};

#endif // DAMES_H
