CC=gcc
LDFLAGS=`pkg-config --cflags --libs gtk4`
FILES=src/*

main.o: $(FILES)
	$(CC) $(LDFLAGS) -o main.o $(FILES)
