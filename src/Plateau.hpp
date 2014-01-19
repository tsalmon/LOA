#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Case.hpp"
class Plateau{
private:
  int m_nbLignes;
  int m_nbColonnes;
  Case*** m_cases;
public:

  Plateau(int,int);
  Case* getCase (int, int);
  bool isEmpty();
  bool isFull();
  int morePions();
  bool hasPion(Pion *);
  void mettrePionDansCase(Pion &checker, unsigned int x, unsigned int y);
  void effacerPionDeCase(unsigned int x, unsigned y);
  Pion *pionDansCase(unsigned int x, unsigned int y);
  friend ostream &operator<<(ostream &,const Plateau &);
};
#endif
