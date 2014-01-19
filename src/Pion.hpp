#ifndef __Projet__Checker__
#define __Projet__Checker__

#include <iostream>
using namespace std;
class Pion{
private:
    string nom;
    int jouer;
    Pion(string nom="nope", char symbole='o');
    char symbole;
    friend class PionFactory;
public:
    void setJouer(int);
    int getJouer();
    void setSymbole(char);
    char getSymbole() const;
    friend ostream &operator<<(ostream &,const Pion &);
};


#endif /* defined(__Projet__Checker__) */