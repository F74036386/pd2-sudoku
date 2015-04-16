all:solve.o give.o Sudoku.o
	g++ -o solve solve.o Sudoku.o
	g++ -o give give.o Sudoku.o
solve.o:solve.cpp 
	g++ -c solve.cpp
give.o:give.cpp
	g++ -c give.cpp
Sudoku.o:Sudoku.cpp
	g++ -c Sudoku.cpp
