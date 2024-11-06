CC = gcc
CFLAGS = -g -ansi -pedantic -Wall -Wextra
FILES = printMap.o main.o checkEOF.o
OUT_EXE = Assignment1

build: $(OUT_EXE)

$(OUT_EXE): $(FILES)
	$(CC) $(CFLAGS) -o $(OUT_EXE) $(FILES)

printMap.o: printMap.c printMap.h
	$(CC) $(CFLAGS) -c printMap.c

checkEOF.o: checkEOF.c checkEOF.h
	$(CC) $(CFLAGS) -c checkEOF.c

main.o: main.c printMap.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(OUT_EXE)

rebuild: clean build

run:
	./$(OUT_EXE)