#include "Partie.hpp"
#include "Puissance4.hpp"
#include "Dames.hpp"
#include "Othello.hpp"
int main(int argc, char **argv){
  if(argc != 2){
    return 0;
  }
  if(argv[1][0] == '-' && argv[1][1] == 'd' && argv[1][2] == '\0'){
  new Dames();
  } else if(argv[1][0] == '-' && argv[1][1] == 'p' && argv[1][2] == '\0'){
    new Puissance4();
  } else if(argv[1][0] == '-' && argv[1][1] == 'o' && argv[1][2] == '\0'){
    new Othello();
  } else {
    cout << "Jeu non reconnu" << endl;
  }
  return 0;
}
