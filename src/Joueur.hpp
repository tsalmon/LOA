#ifndef JOUEUR_HPP
#define JOUEUR_HPP

class Joueur{
private:
  int m_nbJoueurs;
  int m_current;
public:
  static int getCourrant (); 
  static void next ();
  Joueur (int);
};

#endif
