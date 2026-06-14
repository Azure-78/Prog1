# ******************************************************************
# Programación I. Curso 2025-2026
# Compilación del proyecto Televote
# ******************************************************************
CC = gcc -Wall

all: televote

access.o: access.c access.h
	$(CC) -c access.c

database.o: database.c database.h
	$(CC) -c database.c

televote: televote.c access.o database.o
	$(CC) access.o database.o televote.c -o televote

clean:
	rm -f televote *.o *.bak *~
