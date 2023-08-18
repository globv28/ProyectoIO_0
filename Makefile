CC := gcc
CFLAGS := -Wall `pkg-config --cflags gtk+-3.0` -export-dynamic -rdynamic
LIBS := `pkg-config --libs gtk+-3.0`

all: menu pending

menu: menuController.c
	$(CC) -o menu menuController.c $(CFLAGS) $(LIBS)

pending: pendingController.c
	$(CC) -o pending pendingController.c $(CFLAGS) $(LIBS)

clean:
	rm -f menu pending
