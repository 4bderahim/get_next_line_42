
CC = cc 
CFLAGS = -Wall -Wextra -Werror	
CFILES = strjoin.c push_swap_main.c push_moves.c push_swap_sort.c sort_five_and_less.c arg_checks.c p_list_funcs.c atoi_to_stack.c
OFILES = $(CFILES:.c=.o)
CBFILES = strjoin.c get_next_instruction.c push_moves.c arg_checks.c p_list_funcs.c atoi_to_stack.c instruc_bonus.c check_execute_bonus.c
OBFILES = $(CBFILES:.c=.o)
BONUS = checker
PROG_NAME = push_swap
BONUS = checker
all : $(PROG_NAME)
$(PROG_NAME) : $(OFILES) 
	$(CC) $(CFLAGS) $(OFILES) -o $(PROG_NAME)
bonus: $(BONUS)
$(BONUS):$(OBFILES)
	$(CC) $(CFLAGS) $(OBFILES) -o $(BONUS)
%.o: %.c push_swap.h
	$(CC) -c $< -o $@
clean: 
	rm -f $(OFILES) $(OBFILES) $(PROG_NAME) $(BONUS)
	
fclean: clean 
	 rm -f $(OFILES) $(OBFILES)
re: fclean all







