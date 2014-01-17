#ifndef PLATEAU_HPP
#define PLATEAU_HPP
class Plateau{
private:
  int m_nbLignes;
  int m_nbColonnes;
  Case **m_cases;
  static Plateau m_lePlateau;  
public:
  static Plateau getInstance ();
  Case getCase (int, int);
};
#endif
