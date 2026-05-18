CC=gcc
LDFLAGS=``
FILES=src/*

main.o: $(FILES)
	$(CC) $(LDFLAGS) -o main.o $(FILES)
