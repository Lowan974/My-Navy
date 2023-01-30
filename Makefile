##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-pushswap-lowan.ferraro
## File description:
## Makefile
##

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
SRC = $(call rwildcard,src/,*.c)

OBJ = $(SRC:.c=.o)

NAME = navy
CFLAGS := -I./includes

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ) -g3 $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
