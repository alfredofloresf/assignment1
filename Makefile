default: prog

get-deps:
	# Assuming Debian or Ubuntu here
	sudo apt-get install -y build-essential check


test:
	gcc -Wall -o test_main test_main.c spell.c dictionary.c -lcheck -lm -lrt -lpthread -lsubunit
	./test_main

prog:
	gcc -Wall -o spell_check dictionary.c spell.c main.c dictionary.h

clean:


cleanall:clean
	rm spell_check