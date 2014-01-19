#ifndef JEU_HPP
#define JEU_HPP
#include <iostream>
using namespace std;
class Jeu{
protected:
  int nbLignes;
  int nbColonnes;
  int nbJoueur;
public:
  //Jeu(){}
  virtual int fini () =0;
  virtual bool peutJouer () =0;
  virtual void newPartie () =0;
  virtual int getNbLignes();
  virtual int getNbJoueur();
  virtual int getNbColonnes();
};
#endif
