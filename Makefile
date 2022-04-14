# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 13:46:03 by ttorbeyn          #+#    #+#              #
#    Updated: 2022/04/09 13:46:08 by ttorbeyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			=	-I include

SRC				=	./pipex.c \
					./libft/ft_split.c \
					./libft/ft_strtrim.c \
					./libft/ft_strlen.c \
					./libft/ft_strdup.c \
					./libft/ft_strncmp.c \
					./libft/ft_strjoin.c \
					./ft_error.c

OBJS			=	$(SRC:.c=.o)

RM				= 	@rm -f

NAME			=	pipex

all: 		$(NAME)

$(NAME):
			@$(CC) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) pipex

re:			fclean all

.PHONY:		all clean fclean re save
