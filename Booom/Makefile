##
## EPITECH PROJECT, 2018
## 
## File description:
## makefile
##

CC	=	g++ -std=c++11

SRC	=	src/main.cpp	\
		src/game_engine/*.cpp	\
		src/interface/*.cpp

INCLUDE_GAME_ENGINE	=	$(realpath ./include/include_game_engine)

INCLUDE_INTERFACE	=	$(realpath ./include/include_interface)

INCLUDE_IRRLICHT	=	$(realpath ./include/include_interface/include)

IRRLICHT_LOCATION	=	$(realpath ./include/include_interface/lib/Linux)

INCLUDE_DIR	=	$(/usr/X11R6/lib)

CFLAGS	+=	-Wall -Wextra -I$(INCLUDE_GAME_ENGINE) -I$(INCLUDE_INTERFACE) -I$(INCLUDE_IRRLICHT) -L$(IRRLICHT_LOCATION) -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor

OBJ	=	$(SRC:.c=.o)

NAME	=	Booom

%.o:	%.c
	@$(CC) -c -o $@ $< $(CFALGS)
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
