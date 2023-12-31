build :
	g++ -c -fPIC -std=c++20 .\src\ticTacToe.cpp -o ticTacToe.o
	g++ -shared ticTacToe.o -o ticTacToe.dll
	del "ticTacToe.o"
	g++ -L. -lticTacToe -std=c++20 -O3 .\src\main.cpp -o main

run :
	g++ -c -fPIC -std=c++20 .\src\ticTacToe.cpp -o ticTacToe.o
	g++ -shared ticTacToe.o -o ticTacToe.dll
	del "ticTacToe.o"
	.\main

debug :
	g++ .\src\main.cpp .\src\ticTacToe.cpp -g3 -O0 -std=c++20 -o main
	gdb .\main.exe

test :
	g++ .\src\test.cpp .\src\ticTacToe.cpp -std=c++20 -o test
	.\main
	del "test.exe"