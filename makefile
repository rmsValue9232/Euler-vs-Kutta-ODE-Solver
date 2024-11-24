AbstractOdeSolver.o: AbstractOdeSolver.hpp AbstractOdeSolver.cpp
	g++ -O2 -c AbstractOdeSolver.cpp
ForwardEulerSolver.o: ForwardEulerSolver.hpp ForwardEulerSolver.cpp
	g++ -O2 -c ForwardEulerSolver.cpp
RungeKuttaSolver.o: RungeKuttaSolver.hpp RungeKuttaSolver.cpp
	g++ -O2 -c RungeKuttaSolver.cpp
Data.o: Data.hpp Data.cpp
	g++ -O2 -c Data.cpp
main.o: main.cpp  AbstractOdeSolver.hpp ForwardEulerSolver.hpp RungeKuttaSolver.hpp Data.hpp
	g++ -O2 -c main.cpp
executable: AbstractOdeSolver.o ForwardEulerSolver.o RungeKuttaSolver.o Data.o main.o
	g++ -O2 -o executable AbstractOdeSolver.o ForwardEulerSolver.o RungeKuttaSolver.o Data.o main.o

all: executable clean
	./executable.exe

plots: clean
	mkdir ./plots
	gnuplot eulerPlot.gp
	gnuplot kuttaPlot.gp
	gnuplot comparisonPlot.gp



clean:
	rm -rf AbstractOdeSolver.o ForwardEulerSolver.o RungeKuttaSolver.o Data.o main.o
	rm -rf ./plots