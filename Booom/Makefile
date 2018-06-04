##
## EPITECH PROJECT, 2018
## 
## File description:
## makefile
##

CC	=	g++ -std=c++11

SRC	=	src/main.cpp	\
		src/game/*.cpp

INCLUDE_DIR	=	$(realpath ./include)

CFLAGS	+=	-Wall -Wextra -I$(INCLUDE_DIR)

OBJ	=	$(SRC:.c=.o)

NAME	=	booom

%.o:	%.c
	@$(CC) -c -o $@ $< -I$(INCLUDE_DIR)
	@printf "[\033[0;33mCompiled\033[0m] % 20s\n" $< | tr ' ' '-'

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
	@printf "[\033[0;32mAssembled\033[0m] % 20s\n" $(NAME) | tr ' ' '-'

clean:
		@rm -f *.o
		@rm -f ./src/*.o

fclean:		clean
		@rm -f $(NAME)

re:		fclean $(NAME)
