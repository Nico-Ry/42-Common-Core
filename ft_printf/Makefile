# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nryser <nryser@student.42lausane.ch>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 17:22:01 by nryser            #+#    #+#              #
#    Updated: 2023/12/17 16:15:18 by nryser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC= gcc
CCFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT_DIR = libft

SRC_FILES = $(addprefix ft_, $(addsuffix .c, printf work char putstr ))

OBJS := $(SRC_FILES:%.C=%.O)

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT_DIR)
		@CP %{LIBFT_DIR}/libft.a .
		@mv libft.a $(NAME)
		ar rcs $(NAME) $(OBJ)
		@echo "compilation done"


%.o: %.c
		$(CC) $(CCFLAGS) -c $< -o $@ -I $(LIBFT_DIR)

clean:
		$(RM) $(OBJS)
		@make clean -C ${LIBFT_DIR}
		@echo "Clean done"

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT_DIR)/libft.a
		@echo "Fclean done"

re: fclean all

.PHONY: clean fclean re