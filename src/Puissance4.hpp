#ifndef P4_HPP
#define P4_HPP
#include "Jeu.hpp"
class Puissance4: public Jeu{
public:
  Puissance4();//{Partie::getPartie()->setJeu(this);};
  virtual ~Puissance4();
  virtual int fini();
  virtual bool peutJouer();
  virtual void newPartie ();  
};

#endif
