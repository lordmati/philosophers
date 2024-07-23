# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 17:50:34 by misaguir          #+#    #+#              #
#    Updated: 2024/07/23 10:50:32 by misaguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = 	main.c \
		utils.c \
		routine.c \
		creating.c \
		
CFLAGS = -Wall -Werror -Wextra -pthread #-fsanitize=address
OBJS = $(SRCS:.c=.o)

RM = rm -rf
CC = gcc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
