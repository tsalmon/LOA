#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Cases.hpp"
class Plateau{
private:
  int m_nbLignes;
  int m_nbColonnes;
  Cases **m_cases;
public:
  Plateau(){};
  Cases *getCase (int, int);
};
#endif
