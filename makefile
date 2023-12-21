build :
	g++ ticTacToe.cpp -c -std=c++20 -o ticTacToe.o
	ar cr ticTacToe.lib ticTacToe.o
	g++ main.cpp ticTacToe.lib -std=c++20 -o main
	del "ticTacToe.o"
	.\main
run :
	g++ main.cpp ticTacToe.cpp -std=c++20 -o main
	.\main
	 
