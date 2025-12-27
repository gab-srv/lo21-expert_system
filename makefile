CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
LIBS =

SRC = \
    src/main.c \
    src/liste.c \
    src/regle.c \
    src/bc.c \
    src/moteur.c

OBJ = $(SRC:.c=.o)

systeme_expert: $(OBJ)
	$(CC) $(OBJ) -o systeme_expert $(LIBS)

clean:
	rm -f $(OBJ) systeme_expert