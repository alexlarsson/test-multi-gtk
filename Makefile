all: main

libgtk2.so: test_gtk.c
	gcc `pkg-config --cflags --libs gtk+-2.0` test_gtk.c -shared -fPIC -o libgtk2.so -DVERSION=2

main: test_gtk.c main.c libgtk2.so
	gcc `pkg-config --cflags --libs gtk+-3.0` test_gtk.c main.c -o main -L. -lgtk2  -DVERSION=3

clean:
	rm -f main libgtk2.so
