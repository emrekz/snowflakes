all:
	gcc -o run snowflakes.c interface.c -std=c99
	./run.exe