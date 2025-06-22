#configuração para LINUX
#lcomp:
#compilação - gera objetos
#	g++ -c ./src/main.cpp -o ./build/main.o
#	g++ -c ./src/Cliente.cpp -o ./build/Cliente.o
#	g++ -c ./src/Conta.cpp -o ./build/Conta.o
#	g++ -c ./src/ContaPf.cpp -o ./build/ContaPf.o
#	g++ -c ./src/ContaPj.cpp -o ./build/ContaPj.o
#	g++ -c ./src/Banco.cpp -o ./build/Banco.o
#	g++ -c ./src/Gerente.cpp -o ./build/Gerente.o
#linkagem e geração do executável
#	g++ ./build/main.o ./build/Cliente.o ./build/Conta.o ./build/ContaPf.o ./build/ContaPj.o ./build/Banco.o ./build/Gerente.o -o ./bin/main-app
#lrun: lcomp
#	./bin/main-app

#-----Variáveis-----
CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = programa
#Diretórios
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
#-----Definições-----
#Programa:
${BIN_DIR}/${TARGET}: ${BUILD_DIR}/Gerente.o ${BUILD_DIR}/Banco.o ${BUILD_DIR}/ContaPj.o ${BUILD_DIR}/ContaPf.o ${BUILD_DIR}/Conta.o ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/main.o
	@mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${BIN_DIR}/${TARGET}
#Compilações:
${BUILD_DIR}/Gerente.o : ${INCLUDE_DIR}/Gerente.hpp ${SRC_DIR}/Gerente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Gerente.cpp -o ${BUILD_DIR}/Gerente.o

${BUILD_DIR}/Banco.o : ${INCLUDE_DIR}/Banco.hpp ${SRC_DIR}/Banco.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Banco.cpp -o ${BUILD_DIR}/Banco.o

${BUILD_DIR}/ContaPj.o : ${INCLUDE_DIR}/ContaPj.hpp ${SRC_DIR}/ContaPj.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/ContaPj.cpp -o ${BUILD_DIR}/ContaPj.o

${BUILD_DIR}/ContaPf.o : ${INCLUDE_DIR}/ContaPf.hpp ${SRC_DIR}/ContaPf.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/ContaPf.cpp -o ${BUILD_DIR}/ContaPf.o

${BUILD_DIR}/Conta.o : ${INCLUDE_DIR}/Conta.hpp ${SRC_DIR}/Conta.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Conta.cpp -o ${BUILD_DIR}/Conta.o

${BUILD_DIR}/Cliente.o : ${INCLUDE_DIR}/Cliente.hpp ${SRC_DIR}/Cliente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Cliente.cpp -o ${BUILD_DIR}/Cliente.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Gerente.hpp ${INCLUDE_DIR}/Banco.hpp ${INCLUDE_DIR}/ContaPj.hpp ${INCLUDE_DIR}/ContaPf.hpp ${INCLUDE_DIR}/Conta.hpp ${INCLUDE_DIR}/Cliente.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o
clean:
	rm -f &{BUILD_DIR}/*