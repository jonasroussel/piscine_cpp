# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 12:05:46 by jroussel          #+#    #+#              #
#    Updated: 2019/10/22 12:32:50 by jroussel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= convert

HDR_DIR	= ./
SRC_DIR	= ./
OBJ_DIR	= bin/

HDR		= 
HDR		:= $(addprefix $(HDR_DIR),$(HDR))

SRC		= main.cpp
SRC		:= $(addprefix $(SRC_DIR),$(SRC))

OBJ		= $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC:.cpp=.o))

CPPFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

exec: all
	./$(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	clang++ $(CPPFLAG) -c $< -o $@
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
