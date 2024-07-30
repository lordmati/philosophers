# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 17:50:34 by misaguir          #+#    #+#              #
#    Updated: 2024/07/30 13:59:58 by misaguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = 	main.c \
		utils.c \
		routine.c \
		creating.c \
		one_philo.c \
		utils_two.c \
		
CFLAGS = -Wall -Werror -Wextra -pthread #-fsanitize=thread
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
