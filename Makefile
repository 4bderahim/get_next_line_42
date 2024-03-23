
CC = cc
CFLAGS = -Wall -Wextra -Werror	
CFILES = push_swap_main.c push_moves.c push_swap_sort.c sort_five_and_less.c
OFILES = $(CFILES:.c=.o)
NAME = push_swap.a
PROG_NAME = push_swap

all: $(NAME)
$(NAME) : $(OFILES) 
	ar rcs $(NAME) $(OFILES)
	$(CC) $(NAME) -o $(PROG_NAME)
	
bonus:${OBFILES}

${OBFILES}: $(BFILES) push_swap.h
	${CC} ${CFLAGS} -c ${BFILES}
	ar rcs $(NAME) $(OBFILES)

%.o: %.c push_swap.h
	$(CC) -c $< -o $@

clean: 
	rm -f $(OFILES)
	
fclean: clean 
	 rm -f $(NAME)
re: fclean all

