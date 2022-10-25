TESTHEADERS=$(wildcard *.h)
TESTSOURCES=$(patsubst %.h, %.cpp, $(TESTHEADERS))
TESTOBJ=obj/tests.o
TESTCPP=tests.cpp
TARGET=target/test

PROJECTOBJ_A_TEST=../obj/hermite.o ../obj/psiSolution.o ../obj/dataExporter.o
CXX=cxxtestgen
CC=g++
CFLAGS=-I "../armadillo/include" -Wall -Wextra -std=c++11 -O3

###
#  Les tests ont besoin des .obj pour pouvoir se faire, donc on va aller les chercher en les compilant d'abord.
#  On peut ensuite lancer cxxtestgen et compiler notre exécutable de test. Et enfin on le lance.
###
all: compile_project_obj CXX compile_test run_test

## Lancement des tests ##
run_test:
	@echo "Lancement des tests\n-----------------"
	./$(TARGET)

## Compilation de l'exécutable des tests ##
compile_test: $(TESTOBJ) $(PROJECTOBJ_A_TEST)| target #Créer le dossier target s'il n'existe pas
	$(CC) $(CFLAGS) -o $(TARGET) $^

$(TESTOBJ): $(TESTCPP) | obj #Créer le dossier obj s'il n'existe pas
	$(CC) $(CFLAGS) $< -c -o $@

## CXXtest ##
CXX: $(TESTHEADERS)
	$(CXX) --error-printer -o $(TESTCPP) $^

## Compilation des obj du projet ##
compile_project_obj:
	@echo "Démarrage des tests\n-----------------"
	@echo "Préparation des .obj du projet, peut prendre un peu de temps."
	$(MAKE) -C .. compile_source

## Target&Obj clean ##
.PHONY: clean
clean:
	rm -f $(TESTOBJ)
	rm -f $(TARGET)
	rm -f $(TESTSOURCES)
	rm -f tests.cpp

## Création des dossiers obj et target ##
obj:
	mkdir -p $@
target:
	mkdir -p $@