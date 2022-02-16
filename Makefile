# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 08:23:59 by dvan-der          #+#    #+#              #
#    Updated: 2022/02/09 11:16:45 by dvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME := pipex

SRCS := \
main.c \
pipex.c \
ft_split_pipex.c \
pipex_utils.c \
execute_cmd.c \
conv_info.c

OBJS :=			*.o
LIBFT := 		libft/libft.a

ifdef debug
	CFLAGS := -Wall -Wextra -fsanitize=address -g
else
	CFLAGS := -Wall -Werror -Wextra
endif

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) bonus -C libft CFLAGS="$(CFLAGS)"

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME) $^

re:	fclean all

.PHONY: all, clean, fclean, re