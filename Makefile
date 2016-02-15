all: main

libgtk2.so: test_gtk2.c
	gcc `pkg-config --cflags --libs gtk+-2.0` test_gtk2.c -shared -fPIC -o libgtk2.so

main: test_gtk3.c main.c libgtk2.so
	gcc `pkg-config --cflags --libs gtk+-3.0` test_gtk3.c main.c -o main -L. -lgtk2 

clean:
	rm -f main libgtk2.so
