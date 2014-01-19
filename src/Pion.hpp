#ifndef __Projet__Checker__
#define __Projet__Checker__

#include <iostream>
using namespace std;
class Pion{
private:
    string nom;
    int joueur;
    Pion(string nom);
    char symbole;
    friend class PionFactory;
public:
    void setJoueur(int);
    int getJoueur();
    void setSymbole(char);
    char getSymbole() const;
    friend ostream &operator<<(ostream &,const Pion &);
};


#endif /* defined(__Projet__Checker__) */
