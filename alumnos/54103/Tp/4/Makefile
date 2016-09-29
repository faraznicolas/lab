GETS=servidor
FLAGS= -Wall -g -pthread -lrt
CC= gcc
TARGETS=servidor

servidor: main.c argumento.h argumento.c puerto.h puerto.c analisis.c analisis.h 
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm -fv $(TARGETS) *.o *~
