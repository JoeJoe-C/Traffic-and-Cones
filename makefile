CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = main.o rules.o board.o cars.o player.o random.o terminal.o
EXEC = traffic
VAL = valgrind
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=debug.out
DEBUG = gdb
DFLAGS = --args
ARGS = 3 5


$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

main.o : main.c rules.h terminal.h
	$(CC) -c main.c $(CFLAGS)

rules.o : rules.c rules.h board.h player.h cars.h
	$(CC) -c rules.c $(CFLAGS)

board.o: board.c board.h random.h
	$(CC) -c board.c $(CFLAGS)

cars.o: cars.c cars.h random.h
	$(CC) -c cars.c $(CFLAGS)

player.o: player.c player.h
	$(CC) -c player.c $(CFLAGS)

random.o: random.c random.h
	$(CC) -c random.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

clean :
	rm -f $(EXEC) $(OBJ)	

val : $(EXEC)
	$(VAL) $(VFLAGS) ./$(EXEC) $(ARGS) 

debug : $(EXEC)
	$(DEBUG) $(DFLAGS) ./$(EXEC) $(ARGS)