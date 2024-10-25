NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

PREF_SRC = src/
PREF_OBJ = obj/

SRC = $(addprefix $(PREF_SRC), main.c all_check.c push.c swap.c rotate.c rev_rot.c support_func_lib.c func_lib.c \
								support_func_lib2.c sort.c stack.c nods.c free_memory.c median_sort.c fast_sort.c \
								support_fast_sort.c calculation.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	@mkdir -pv $(PREF_OBJ)
	$(CC) -c $< -o $@

clean :
	rm -rf $(PREF_OBJ)
	rm -rf $(PREF_OBJ_BONUS)
	
fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all

NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

PREF_SRC_BONUS = bonus_src/
PREF_OBJ_BONUS = bonus_obj/

SRC_BONUS = $(addprefix $(PREF_SRC_BONUS), main.c all_check.c push.c swap.c rotate.c rev_rot.c support_func_lib.c func_lib.c \
								support_func_lib2.c stack.c free_memory.c checking.c)
OBJ_BONUS = $(patsubst $(PREF_SRC_BONUS)%.c, $(PREF_OBJ_BONUS)%.o, $(SRC_BONUS))

bonus : $(NAME_BONUS) all

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(PREF_OBJ_BONUS)%.o : $(PREF_SRC_BONUS)%.c
	@mkdir -pv $(PREF_OBJ_BONUS)
	$(CC) -c $< -o $@

.PHONY: all clean fclean re
