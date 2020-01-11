run:
	gcc -o bin/main src/*.c -Werror
	./bin/main
comp:
	gcc -o bin/main src/*.c -Werror
debug:
	gcc -g -o bin/debug src/*.c -Werror
	gdb --args bin/debug
