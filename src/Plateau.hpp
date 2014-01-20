#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Case.hpp"
#include <vector>
class Plateau{
private:
  int m_nbLignes;
  int m_nbColonnes;
  vector< std::vector<Case> > m_cases;
public:
  vector<Case> m_casesLibres;
  int get_sizeX();
  int get_sizeY();
  Plateau(int,int);
  Case* getCase (int, int);
  bool isEmpty();
  bool isFull();
  int morePions();
  bool hasPion(Pion *);
  bool hasPion(int x, int y);
  void mettrePionDansCase(Pion *pion, unsigned int x, unsigned int y);
  void effacerPionDeCase(unsigned int x, unsigned y);
  Pion *pionDansCase(unsigned int x, unsigned int y);
  friend ostream &operator<<(ostream &,const Plateau &);
};
#endif
