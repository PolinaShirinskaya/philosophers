# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adian <adian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 15:18:59 by adian             #+#    #+#              #
#    Updated: 2022/07/09 15:26:33 by adian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = ./srcs/main.c ./srcs/init.c ./srcs/create_n_monitor.c \
        ./srcs/print_messege.c ./srcs/utils.c \
		./srcs/action.c ./srcs/validation.c

HEADER = ./includes/philosophers.h

OBJ = ${SRCS:.c=.o}

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

${NAME} : ${OBJ} Makefile $(HEADER)
		$(CC) $(OBJ) -lpthread -o $(NAME)
		@echo "\033[32mProject Compiled"

%.o : %.c Makefile ${HEADER}
		$(CC) ${CFLAGS} -I./include -O3 -c $< -o $@

clean :
		@${RM} $(OBJ)

fclean : clean
		@$(RM) $(NAME)
		@clear
		@echo "\033[32mFclean"

re : fclean all

.PHONY : all clean fclean re
