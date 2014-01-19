#ifndef DAMES_H
#define DAMES_H

#include "Jeu.hpp"
#include "PionFactory.hpp"


class Dames : public Jeu{
    public:
        Dames();
        virtual ~Dames();
    protected:
        Pion noir;
        Pion blanc;
    private:
};

#endif // DAMES_H
