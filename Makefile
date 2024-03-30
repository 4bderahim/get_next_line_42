
CC = cc
CFLAGS = -Wall -Wextra -Werror	
CFILES = push_swap_main.c push_moves.c push_swap_sort.c sort_five_and_less.c
OFILES = $(CFILES:.c=.o)
CBFILES = get_next_instruction.c push_moves.c
OBFILES = $(CBFILES:.c=.o)
NAME = push_swap.a
PROG_NAME = push_swap
BONUS = checker

$(PROG_NAME) : $(OFILES) 
	$(CC) $(OFILES) -o $(PROG_NAME)

$(BONUS):$(OBFILES)
	$(CC) $(OBFILES) -o $(BONUS)

%.o: %.c push_swap.h
	$(CC) -c $< -o $@

clean: 
	rm -f $(OFILES) $(OBFILES)
	
fclean: clean 
	 rm -f $(OFILES) $(OBFILES)
re: fclean $(PROG_NAME) $(BONUS)

