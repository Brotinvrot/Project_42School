NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

PREF_SRC = src/
PREF_OBJ = obj/

SRC = $(addprefix $(PREF_SRC), all_check.c command_1.c command_2.c support_code2.c command.c re_test.c \
								support_code.c support_code1.c func_lib.c sort_g.c)
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
