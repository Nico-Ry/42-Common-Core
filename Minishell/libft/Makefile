# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ameechan <ameechan@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 11:35:24 by nryser            #+#    #+#              #
#    Updated: 2024/11/06 20:38:09 by ameechan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_BASE =	ft_putchar_fd.c\
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_strmapi.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_striteri.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

SRCS_BONUS = ft_lstnew.c \
            ft_lstadd_front.c \
            ft_lstsize.c \
            ft_lstlast.c \
            ft_lstadd_back.c \
            ft_lstdelone.c \
            ft_lstclear.c \
            ft_lstiter.c \
            ft_lstmap.c \

OBJS_BASE = $(SRCS_BASE:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS = $(OBJS_BASE)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
