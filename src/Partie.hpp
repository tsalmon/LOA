#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp"
class Partie{
private:
    Jeu &jeu;
    Joueur *joueurs;
    Plateau *plateau;
    static Partie laPartie;
    Partie() {}
    Partie(Partie &l) {}
    void operator=(Partie &l) {}
    ~Partie() {}
public:
    int joueTour ();
    void setJeu(Jeu const &j);
    Plateau& getPlateau ();
    static Partie* getPartie();
    Joueur getJoueurs();
};

#endif
