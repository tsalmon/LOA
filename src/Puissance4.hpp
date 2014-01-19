#ifndef P_4
#define P_4

#include "Jeu.hpp"
class Puissance4: public Jeu{
  //private:
  /*string* listePions;
  int nbLignes;
  int nbColonnes;
  int nbJoueur;  */
public:
  Puissance4(int);
  virtual int fini();
  virtual bool peutJouer();
  virtual void newPartie ();
  virtual int getNbLignes();
  virtual int getNbColonnes();
  virtual int getNbJoueur();
  virtual int **deplacementPossible (int x, int Y, string Nom);
  virtual string* getListePions ();
};

#endif
