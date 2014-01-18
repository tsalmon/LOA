#ifndef JEU_HPP
#define JEU_HPP
#include <iostream>
using namespace std;
class Jeu{
private:
  string* listePions;
public:
  virtual bool jouetour () =0;
  virtual void newPartie () =0;
  virtual int **deplacementPossible (int x, int Y, string Nom) =0;
  virtual string* getListePions () =0;
};
#endif
