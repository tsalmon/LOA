CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=platolib.exe
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o) 

all:$(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -o $@ -c $< 

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf platolib.exe