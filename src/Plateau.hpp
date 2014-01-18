#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Cases.hpp"
class Plateau{
private:
  int m_nbLignes;
  int m_nbColonnes;
  Cases **m_cases;
public:
  Plateau(int,int);
  Cases *getCase (int, int);
  bool isEmpty();
  bool isFull();
  Pion* morePions();
  bool hasPion(Pion &);
};
#endif
