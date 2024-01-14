#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>



#ifndef GETNL
#define GETNL
char *get_next_line(int fd);
#endif
