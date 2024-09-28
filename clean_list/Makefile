NAME = Push_Swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	@mkdir -pv $(PREF_OBJ)
	$(CC) -c $< -o $@

clean :
	rm -f $(PREF_OBJ)*.o

fclean :
	rm -f $(NAME) $(PREF_OBJ)*.o

re : fclean all
	
.PHONY: all clean fclean re
