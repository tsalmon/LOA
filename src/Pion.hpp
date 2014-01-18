#ifndef PION_HPP
#define PION_HPP
#include <iostream>
#include <string>
using namespace std;
class Pion{
private:
    string nom;
    Pion(string nom = "Nope");
public:
    virtual void deplacementsPossible (int, int);
    friend class PionFactory;
};

#endif
