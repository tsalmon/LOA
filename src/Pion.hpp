#ifndef PION_HPP
#define PION_HPP
#include <iostream>
#include <string>
using namespace std;
class Pion{
private:
    string nom;
    int jouer;
    char symbole;
    Pion(string nom = "Nope");
public:
    virtual void deplacementsPossible (int, int);
    void setJouer(int);
    int getJouer();
    void setSymbole(char);
    char getSymbole();
    friend class PionFactory;
};

#endif
