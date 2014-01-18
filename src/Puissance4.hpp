#ifndef P_4
#define P_4

#include "Jeu.hpp"
class Puissance4: public Jeu{
private:
  string* listePions;
public:
  Puissance4(){};
  virtual bool jouetour();
  virtual void newPartie ();
  virtual int **deplacementPossible (int x, int Y, string Nom);
  virtual string* getListePions ();
};

#endif
