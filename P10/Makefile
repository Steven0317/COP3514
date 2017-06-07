records: dogs.o readline.o records.o
	gcc -o records dogs.c readline.c records.c

dogs.o: dogs.c readline.h dogs.h
	gcc -c dogs.c

readline.o: readline.c readline.h
	gcc -c readline.c

records.o: records.c dogs.h 
	gcc -c records.c
