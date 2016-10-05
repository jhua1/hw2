strtest: stringy.c
	gcc stringy.c -o strtest

clear:
	rm *~

run: strtest
	./strtest
