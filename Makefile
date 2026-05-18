CC=gcc
LDFLAGS=``
FILES=src/*

ticket: $(FILES)
	$(CC) $(LDFLAGS) -o ticket $(FILES)
