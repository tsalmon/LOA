#ifndef PARTIE_HPP
#define PARTIE_HPP
#include "Joueur.hpp"
#include "Jeu.hpp"
#include "Plateau.hpp"
class Partie{
private:
    Jeu *jeu;
    Joueur *joueurs;
    Plateau *plateau;
    
    Partie();
    Partie(Partie &l);
    void operator=(Partie &l);
    ~Partie();
public:
    static Partie *getPartie();
    int joueTour ();
    void setJeu(Jeu *j);
    Plateau &getPlateau();
    Joueur *getJoueurs();
    int getNbJoueur();
};
#endif
