platolib: test.o Cases.o Jeu.o Joueur.o Plateau.o
	g++ -o platolib test.o Cases.o Jeu.o Joueur.o Plateau.o

test.o: test.cpp
	@g++ test.cpp -c	

Cases.o: Cases.cpp
	@g++ Cases.cpp -c

Jeu.o: Jeu.cpp
	@g++ Jeu.cpp -c

Plateau.o: Plateau.cpp
	@g++ Plateau.cpp -c