#ifndef PARTIE_HPP
#define PARTIE_HPP

class Partie{
private:
  Joueur joueurs;
  //Plateau plateau;
  Jeu jeu;
public:
  void joueTour ();
  void victory (int);
  void defaite ();
  void egalite ();
  Partie (Jeu);
  static Jeu getJeu ();
  Plateau& getPlateau ();
};

#endif
