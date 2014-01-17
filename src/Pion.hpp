#ifndef PION_HPP
#define PION_HPP
#include <iostream>
#include <string>
using namespace std;
class Pion{
private:
  string nom;
public:
  virtual void deplacementsPossible (int, int);
};

#endif
