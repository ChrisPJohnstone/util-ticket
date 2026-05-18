PREFIX	?= /usr/local
BINDIR	?= $(PREFIX)/bin
CC			?= gcc
FILES		?= src/main.c

ticket: $(FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f ticket

install: ticket
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 ticket $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/ticket

.PHONY: clean install uninstall
