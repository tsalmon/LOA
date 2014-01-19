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
  virtual int fini () =0;
  virtual bool peutJouer () =0;
  virtual void newPartie () =0;
  virtual int getNbLignes()=0;
  virtual int getNbJoueur()=0;
  virtual int getNbColonnes()=0;
  virtual string* getListePions () =0;
};
#endif
