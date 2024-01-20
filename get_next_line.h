#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 12
#endif

#ifndef GETNL
#define GETNL
char *get_next_line(int fd);
size_t ft_strlen(char *s);
char *ft_bzero(char *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char    *ft_strchr(const char *s, int c);
#endif
