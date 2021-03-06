#ifndef CASES_HPP
#define CASES_HPP
#include <iostream>
#include <string>
#include "Pion.hpp"
using namespace std;
class Case{
private:
  unsigned int coordonneX;
  unsigned int coordonneY;
  Pion *pionImbrique;
public:
  Case(unsigned int x, unsigned int y, Pion *ch=NULL);
  Pion *getPion () const;
  bool hasPion();
  void addPion (Pion *p);
  void retirePion ();
  unsigned int getX() const;
  unsigned int getY() const;
};
#endif
