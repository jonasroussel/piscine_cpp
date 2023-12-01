# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 12:05:46 by jroussel          #+#    #+#              #
#    Updated: 2019/10/18 13:48:45 by jroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= polymorph

HDR_DIR	= ./
SRC_DIR	= ./
OBJ_DIR	= bin/

HDR		= Sorcerer.hpp \
		  Victim.hpp \
		  Peon.hpp
HDR		:= $(addprefix $(HDR_DIR),$(HDR))

SRC		= Sorcerer.cpp \
		  Victim.cpp \
		  Peon.cpp \
		  main.cpp
SRC		:= $(addprefix $(SRC_DIR),$(SRC))

OBJ		= $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC:.cpp=.o))

CPPFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

exec: all
	./$(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	clang++ -c $< -o $@
	printf '%s: \033[32m%s\n\033[0m' "$<" "Compiled"

$(NAME): $(OBJ) $(HDR)
	clang++ $(CPPFLAG) $(OBJ) -o $(NAME)
	printf '%s: \033[32m%s\n\033[0m' "$(NAME)" "Created"

clean:
	rm -rf $(OBJ_DIR)
	printf '%s: \033[32m%s\n\033[0m' "clean" "Done"

fclean: clean
	rm -f $(NAME)
	printf '%s: \033[32m%s\n\033[0m' "fclean" "Done"

re: fclean all

.PHONY: all exec clean fclean re
