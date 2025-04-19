#configuração para LINUX
lcomp:
#compilação - gera objetos
	g++ -c ./src/main.cpp -o ./build/main.o
#linkagem e geração do executável
	g++ ./build/main.o -o ./bin/main-app
lrun: lcomp
	./bin/main-app

#configuração para WINDOWS
wcomp:
#compilação - gera objetos
	g++ -c src\main.cpp -o build\main.o
#linkagem e geração do executável
	g++ \build\main.o -o \bin\main.exe
wrun: wcomp
	\bin\main.exe