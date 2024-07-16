# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 17:50:34 by misaguir          #+#    #+#              #
#    Updated: 2024/07/16 17:52:54 by misaguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = main.c utils.c
		
CFLAGS = -Wall -Werror -Wextra
OBJS_SRCS = $(SRCS:.c=.o)

RM = rm -rf
CC = gcc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS_SRCS)
	$(CC) $(CFLAGS) $(OBJS_SRCS) -o $(NAME)

clean:
	@$(RM) $(OBJS_SRCS)

fclean: clean
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
