NAME	= ft_retro

SRC_DIR	= src/
OBJ_DIR	= bin/

SRC		= main.cpp \
		  map.cpp \
		  class/IEntity.cpp \
		  class/ArmedEntity.cpp \
		  class/Projectile.cpp \
		  class/Enemy.cpp \
		  class/Player.cpp \
		  class/ProjectileManager.cpp \
		  class/Laser.cpp \
		  class/Rocket.cpp \
		  class/StarFighter.cpp \
		  class/HyenaBomber.cpp
SRC		:= $(addprefix $(SRC_DIR),$(SRC))

OBJ		= $(subst $(SRC_DIR),$(OBJ_DIR),$(SRC:.cpp=.o))

CPPFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

exec: all
	./$(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(dir $@)
	clang++ $(CPPFLAG) -c $< -o $@
	printf '%s: \033[32m%s\n\033[0m' "$<" "Compiled"

$(NAME): $(OBJ)
	clang++ $(CPPFLAG) $(OBJ) -o $(NAME) -lncurses
	printf '%s: \033[32m%s\n\033[0m' "$(NAME)" "Created"

clean:
	rm -rf $(OBJ_DIR)
	printf '%s: \033[32m%s\n\033[0m' "clean" "Done"

fclean: clean
	rm -f $(NAME)
	printf '%s: \033[32m%s\n\033[0m' "fclean" "Done"

re: fclean all

.PHONY: all exec clean fclean re
