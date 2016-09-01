#ifndef _contador_h_
#define _contador_h_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <getopt.h>
#include<sys/wait.h>
#include <sys/mman.h>
#include <semaphore.h>


int *contador (int , char*);

#endif 
