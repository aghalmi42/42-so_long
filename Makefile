# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 19:58:54 by aghalmi           #+#    #+#              #
#    Updated: 2025/12/09 16:57:54 by aghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wpadded -g3
INCLUDES =  -I./include -I./ft_printf -I./libft

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

LIBS = -L$(LIBFT_DIR) -lft \
	   -L$(FT_PRINTF_DIR) -lftprintf

SRCS =  main.c \
		mandatory/map/parsing_map.c \
		mandatory/map/parsing_map_utils.c \
		mandatory/map/init_map.c \
		mandatory/map/valid_map.c \
		mandatory/map/valid_track.c \
		mandatory/map/valid_track_utils.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re