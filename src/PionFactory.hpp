#ifndef __Projet__CheckerFactory__
#define __Projet__CheckerFactory__

#include <iostream>
#include <vector>

#include "Pion.hpp"
using namespace std;

class PionFactory{
private:
    PionFactory();
    PionFactory(PionFactory &);
    void operator=(PionFactory &);
    vector<Pion> pions;
public:
    static PionFactory &getInstance();
    Pion getPion(string name);
};
#endif /* defined(__Projet__CheckerFactory__) */
