
CC = cc 
CFLAGS = -Wall -Wextra -Werror	
CFILES = strjoin.c push_swap_main.c sort_five_and_less.c push_moves__.c push_moves_.c push_moves.c normal_sort_and_index.c push_it_back_to_b.c push_swap_sort.c arg_checks.c p_list_funcs.c atoi_to_stack.c
OFILES = $(CFILES:.c=.o)
CBFILES = strjoin.c get_next_instruction.c push_moves__.c push_moves_.c push_moves.c arg_checks.c p_list_funcs.c atoi_to_stack.c instruc_bonus.c check_execute_bonus.c
OBFILES = $(CBFILES:.c=.o)
PROG_NAME = push_swap
BONUS = checker
all : $(PROG_NAME)
$(PROG_NAME) : $(OFILES) 
	$(CC) $(CFLAGS) $(OFILES) -o $(PROG_NAME)
bonus: $(BONUS)
$(BONUS):$(OBFILES)
	$(CC) $(CFLAGS) $(OBFILES) -o $(BONUS)
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
clean: 
	rm -f $(OFILES) $(OBFILES) 
	
fclean: clean 
	 rm -f $(OFILES) $(OBFILES) $(PROG_NAME) $(BONUS)
	 
re: fclean all







