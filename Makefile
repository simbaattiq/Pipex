# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 16:28:44 by mel-atti          #+#    #+#              #
#    Updated: 2023/11/26 16:47:11 by mel-atti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRC =	libft/ft_split.c \
		libft/ft_calloc.c \
		libft/ft_bzero.c \
		libft/ft_strjoin2.c \
		libft/ft_strdup.c \
		libft/ft_putstr_fd.c \
		libft/ft_strlcpy.c \
		libft/ft_strncmp.c \
		libft/ft_strlen.c \
		libft/ft_substr.c \
		pipex.c \
        pipex_excute.c \
		pipex_parser.c \
		pipex_helper_fun.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)
	make clean -C libft

fclean: clean
	@rm -f $(NAME)
	make fclean -C libft

re: fclean $(NAME)

.PHONY: all clean fclean re