#ifndef JOUEUR_HPP
#define JOUEUR_HPP

class Joueur{
private:
  int nb_Joueurs;
  int m_current;
public:
  int getCourrant ();
  int getNbJoueur();
  void next ();
  Joueur (int nbJoueurs);
};

#endif
