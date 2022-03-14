all: alunoAVL.o alunoHash.o avl.o hash.o questaoAVL.o questaoHash.o main.cpp
	g++ -o main main.cpp alunoAVL.o alunoHash.o avl.o hash.o questaoAVL.o questaoHash.o
alunoAVL.o: alunoAVL.cpp
	g++ -o alunoAVL.o -c alunoAVL.cpp
alunoHash.o: alunoHash.cpp
	g++ -o alunoHash.o -c alunoHash.cpp
avl.o: avl.cpp
	g++ -o avl.o -c avl.cpp
hash.o: hash.cpp
	g++ -o hash.o -c hash.cpp
questaoAVL.o: questaoAVL.cpp
	g++ -o questaoAVL.o -c questaoAVL.cpp
questaoHash.o: questaoHash.cpp
	g++ -o questaoHash.o -c questaoHash.cpp
clean:
	rm -f *.o main
run:
	./main < input.txt > output.txt