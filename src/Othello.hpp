#ifndef OTHELLO_HPP
#define OTHELLO_HPP
#include "Jeu.hpp"
#include "Partie.hpp"

#define SIZE_X 8
#define SIZE_Y 8

#define ENTRE(a, b, c) (a < b && b < c) 
#define DANS_JEU(x, y) (ENTRE(-1, x, SIZE_X) && ENTRE(-1, y, SIZE_Y))

class Othello : public Jeu{
  protected:
  Pion *pX; 
  Pion *pO; 
public:
  Othello();
  int get_j();
  virtual ~Othello();
  void affichage();
  void capture(int, int, int);
  int trouverPion(int, int, int, int);
  bool coupValide(int, int);
  virtual int fini();
  virtual bool peutJouer();
  virtual void newPartie ();  
};

#endif
