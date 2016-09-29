#ifndef _puerto_h_
#define _puerto_h_

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <assert.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int puerto(char *argv );

#endif 
