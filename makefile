CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = programa
TEST_TARGET = testes

# Diretórios
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
TESTS_DIR = tests
LIB_DIR = lib

# Arquivos objeto principais
MAIN_OBJS = ${BUILD_DIR}/Gerente.o ${BUILD_DIR}/Banco.o ${BUILD_DIR}/ContaPj.o \
             ${BUILD_DIR}/ContaPf.o ${BUILD_DIR}/Conta.o ${BUILD_DIR}/Cliente.o \
             ${BUILD_DIR}/Calendario.o ${BUILD_DIR}/main.o

# Arquivos objeto para testes
TEST_OBJS = ${BUILD_DIR}/TesteGerente.o ${BUILD_DIR}/TesteBanco.o \
			${BUILD_DIR}/TesteContaPj.o ${BUILD_DIR}/TesteContaPf.o \
			${BUILD_DIR}/TesteConta.o ${BUILD_DIR}/TesteCliente.o

#----- Build principal -----
${BIN_DIR}/${TARGET}: ${MAIN_OBJS}
	@mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} ${MAIN_OBJS} -o ${BIN_DIR}/${TARGET}

#----- Build dos testes -----
${BIN_DIR}/${TEST_TARGET}: ${TEST_OBJS}
	@mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} ${TEST_OBJS} -o ${BIN_DIR}/${TEST_TARGET}

#----- Regras de compilação para os arquivos principais -----
${BUILD_DIR}/%.o: ${SRC_DIR}/%.cpp ${INCLUDE_DIR}/%.hpp
	@mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c $< -o $@

#----- Regras de compilação para os testes -----
${BUILD_DIR}/TesteGerente.o: ${TESTS_DIR}/TesteGerente.cpp
	@mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -I${LIB_DIR}/doctest -c $< -o $@

${BUILD_DIR}/TesteBanco.o: ${TESTS_DIR}/TesteBanco.cpp
	@mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -I${LIB_DIR}/doctest -c $< -o $@
${BUILD_DIR}/TesteContaPj.o: ${TESTS_DIR}/TesteContaPj.cpp
	@mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -I${LIB_DIR}/doctest -c $< -o $@

${BUILD_DIR}/TesteContaPf.o: ${TESTS_DIR}/TesteContaPf.cpp
	@mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -I${LIB_DIR}/doctest -c $< -o $@
${BUILD_DIR}/TesteConta.o: ${TESTS_DIR}/TesteConta.cpp
	@mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -I${LIB_DIR}/doctest -c $< -o $@

${BUILD_DIR}/TesteCliente.o: ${TESTS_DIR}/TesteCliente.cpp
	@mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -I${LIB_DIR}/doctest -c $< -o $@

#----- Regras auxiliares -----
all: ${BIN_DIR}/${TARGET}

test: ${BIN_DIR}/${TEST_TARGET}
	./${BIN_DIR}/${TEST_TARGET}

clean:
	rm -f ${BUILD_DIR}/* ${BIN_DIR}/*

.PHONY: all test clean
