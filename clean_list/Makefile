NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

PREF_SRC = src/
PREF_OBJ = obj/

SRC = $(addprefix $(PREF_SRC), main.c all_check.c push.c swap.c rotate.c rev_rot.c func_lib.c support_code.c support_code1.c \
								support_code2.c strong_sort.c stack.c nods.c free_memory.c median_sort.c fast_sort.c calculation.c file_to_delete.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	@mkdir -pv $(PREF_OBJ)
	$(CC) -c $< -o $@

clean :
	rm -rf $(PREF_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
	
.PHONY: all clean fclean re
