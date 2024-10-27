CC = gcc
CFLAGS = -Wall -Wextra -g3
OBJ = main.o lib/utils.o lib/casos.o lib/sort.o # Adicione lib/casos.o aqui
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Regra para compilar arquivos .c na pasta lib
lib/%.o: lib/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar o main.c
main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar casos.c
lib/casos.o: lib/casos.c lib/casos.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
