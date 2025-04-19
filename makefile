#configuração para LINUX
lcomp:
#compilação - gera objetos
	g++ -c ./src/main.cpp -o ./build/main.o
	g++ -c ./src/Cliente.cpp -o ./build/Cliente.o
	g++ -c ./src/Conta.cpp -o ./build/Conta.o
	g++ -c ./src/ContaPf.cpp -o ./build/ContaPf.o
	g++ -c ./src/ContaPj.cpp -o ./build/ContaPj.o
#linkagem e geração do executável
	g++ ./build/main.o ./build/Cliente.o ./build/Conta.o ./build/ContaPf.o ./build/ContaPj.o -o ./bin/main-app
lrun: lcomp
	./bin/main-app

#configuração para WINDOWS
wcomp:
#compilação - gera objetos
	g++ -c src\\main.cpp -o build\\main.o
	g++ -c src\\Cliente.cpp -o build\\Cliente.o
	g++ -c .\\src\\Conta.cpp -o .\\build\\Conta.o
	g++ -c .\\src\\ContaPf.cpp -o .\\build\\ContaPf.o
	g++ -c .\\src\\ContaPj.cpp -o .\\build\\ContaPj.o
#linkagem e geração do executável
	g++ .\\build\\main.o .\\build\\Cliente.o .\\build\\Conta.o .\\build\\ContaPf.o .\\build\\ContaPj.o -o .\\bin\\main.exe
wrun: wcomp
	.\\bin\\main.exe