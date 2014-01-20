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
    /*
  bool operator==(const Case c) const;
  bool operator!=(const Case c) const;*/
  Pion *getPion () const;
  bool hasPion();
  void addPion (Pion *p);
  void retirePion ();
  unsigned int getX() const;
  unsigned int getY() const;
    /*
  friend bool operator== (const Case& c1, const Case& c2)
  {
      return
      (c1.getX() == c2.getX() && c1.getY() == c2.getY());
  }*/
};
#endif
