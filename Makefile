CC=g++
CFLAGS=-I "./armadillo/include"
TARGET=target/main
HEADERS=$(wildcard headers/*.h)
HEADERS_ASTYLE=$(wildcard headers/*.h.orig)
SOURCES=$(wildcard src/*.cpp)
SOURCES_ASTYLE=$(wildcard src/*.cpp.orig)
OBJ=$(patsubst src/%.cpp, obj/%.o, $(SOURCES))

all: compile_main

compile_main: $(OBJ) | target #Créer le dossier target s'il n'existe pas
	$(CC) $(CFLAGS) -o $(TARGET) $^

obj/%.o: src/%.cpp $(HEADERS) | obj #Créer le dossier obj s'il n'existe pas
	$(CC) $(CFLAGS) $< -c -o $@

## Création des dossiers obj et target ##
obj:
	mkdir -p $@
target:
	mkdir -p $@

## Target&Obj clean ##
.PHONY: clean
clean:
	rm -f $(OBJ)
	rm -f $(TARGET)
	rm -f $(SOURCES_ASTYLE) $(HEADERS_ASTYLE)

compile_source: $(OBJ)

format: $(SOURCES) $(HEADERS)
	./astyle --style=allman $^