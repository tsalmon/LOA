#ifndef JEU_HPP
#define JEU_HPP

class Jeu{
private:
  string* listePions;
public:
  virtual bool jouetour ();
  virtual void newPartie ();
  virtual int **deplacementPossible (int x, int Y, string Nom);
  virtual string* getListePions ();
};
#endif
