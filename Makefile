NAME = libftprintf.a

SRC_DIR = ./src/
INC_DIR = ./inc/
OBJ_DIR = ./obj/
SRC = ft_printf.c function_pointers.c modifiers.c specifiers.c ft_lcs_unicode.c ft_atoi.c ft_itoa.c ft_putchar.c \
ft_putstr.c ft_strcpy.c ft_strnew.c nbr_hex.c ft_itoa_base.c ft_itoa_base_l.c ft_output.c ft_strnew.c ft_check.c ft_strlen.c \
ft_check_pers.c field_width.c precision.c ft_toupper.c flags.c ft_atoi_base.c specifiers2.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		$(CC) -c $< -o $@ $(CC_FLAGS) -I $(INC_DIR)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
