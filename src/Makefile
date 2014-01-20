CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS= -g
EXEC=platolib.exe
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o) 

all:$(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ $(CFLAGS)

%.o: %.cpp
	$(CC) $(LDFLAGS) -o $@ -c $< $(CFLAGS) 

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf platolib.exe