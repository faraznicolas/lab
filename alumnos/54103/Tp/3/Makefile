GETS=memoria
FLAGS= -Wall -g -pthread -lrt
CC= gcc
TARGETS=memoria

memoria: partes.h partes.c contador.h contador.c main.c
	$(CC) $(FLAGS) -o $@ $^

clean:
	rm -fv $(TARGETS) *.o *~
