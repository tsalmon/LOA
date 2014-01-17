#ifndef CASES_HPP
#define CASES_HPP
#include <iostream>
#include <string>
#include "Pion.hpp"
using namespace std;
class Cases{ 
private:
  int m_x;
  int m_y;
  Pion *m_pion;
public:
  Cases (int, int);
  Pion* getPion ();
  void addPion (const Pion &p);
  void retirePion ();
};
#endif
