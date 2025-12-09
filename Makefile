# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 19:58:54 by aghalmi           #+#    #+#              #
#    Updated: 2025/12/09 19:45:27 by aghalmi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
INCLUDES    = -I./include -I./minilibx-linux
LIBS        = -L./minilibx-linux -lmlx -lXext -lX11 -lm

# ==========================================
# DIRECTORIES
# ==========================================

MAND_DIR    = mandatory
MAP_DIR     = $(MAND_DIR)/map
GRAPH_DIR   = $(MAND_DIR)/graphics
UTILS_DIR   = $(MAND_DIR)/utils
GAME_DIR    = $(MAND_DIR)/gameplay

# ==========================================
# SOURCES
# ==========================================

SRCS        = $(MAND_DIR)/main.c \
              $(MAP_DIR)/parsing_map.c \
              $(MAP_DIR)/parsing_map_utils.c \
              $(MAP_DIR)/init_map.c \
              $(MAP_DIR)/valid_map.c \
              $(MAP_DIR)/valid_track.c \
              $(MAP_DIR)/valid_track_utils.c \
              $(GRAPH_DIR)/display_map.c \
              $(GRAPH_DIR)/init_mlx.c \
              $(GRAPH_DIR)/load_texture.c \
			  $(UTILS_DIR)/utils.c \
			  $(UTILS_DIR)/ft_printf.c \
              get_next_line.c \
              get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)

# ==========================================
# MINILIBX
# ==========================================

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a

# ==========================================
# COLORS
# ==========================================

RESET       = \033[0m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
RED         = \033[31m

# ==========================================
# RULES
# ==========================================

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@echo "$(BLUE)🔧 Compiling MiniLibX...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✅ MiniLibX ready!$(RESET)"

$(NAME): $(OBJS)
	@echo "$(BLUE)🔗 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) created successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)🔨 Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make -C $(MLX_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

# NAME        = so_long
# CC          = cc
# CFLAGS      = -Wall -Wextra -Werror -g3
# INCLUDES    = -I./include -I./ft_printf -I./libft -I./minilibx-linux
# LIBS        = -L./minilibx-linux -lmlx -lXext -lX11 -lm

# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

# FT_PRINTF_DIR = ./ft_printf
# FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# GNL_DIR = ./get_next_line
# # ==========================================
# # DIRECTORIES
# # ==========================================

# MAND_DIR    = mandatory
# MAP_DIR     = $(MAND_DIR)/map
# GRAPH_DIR   = $(MAND_DIR)/graphics
# UTILS_DIR   = $(MAND_DIR)/utils
# GAME_DIR    = $(MAND_DIR)/gameplay

# # ==========================================
# # SOURCES
# # ==========================================

# SRCS        = $(MAND_DIR)/main.c \
#               $(MAP_DIR)/parsing_map.c \
#               $(MAP_DIR)/parsing_map_utils.c \
#               $(MAP_DIR)/init_map.c \
#               $(MAP_DIR)/valid_map.c \
#               $(MAP_DIR)/valid_track.c \
#               $(MAP_DIR)/valid_track_utils.c \
#               $(GRAPH_DIR)/display_map.c \
#               $(GRAPH_DIR)/init_mlx.c \
#               $(GRAPH_DIR)/load_texture.c \
#               $(GNL_DIR)/get_next_line.c \
#               $(GNL_DIR)/get_next_line_utils.c 

# OBJS        = $(SRCS:.c=.o)

# # ==========================================
# # MINILIBX
# # ==========================================

# MLX_DIR     = minilibx-linux
# MLX_LIB     = $(MLX_DIR)/libmlx.a

# # ==========================================
# # COLORS
# # ==========================================

# RESET       = \033[0m
# GREEN       = \033[32m
# YELLOW      = \033[33m
# BLUE        = \033[34m
# RED         = \033[31m

# # ==========================================
# # RULES
# # ==========================================


# $(LIBFT):
# 	@echo "$(BLUE)📚 Compiling libft...$(RESET)"
# 	@make -C $(LIBFT_DIR) > /dev/null 2>&1
# 	@echo "$(GREEN)✅ libft ready!$(RESET)"

# $(FT_PRINTF):
# 	@echo "$(BLUE)🖨️  Compiling ft_printf...$(RESET)"
# 	@make -C $(FT_PRINTF_DIR) > /dev/null 2>&1
# 	@echo "$(GREEN)✅ ft_printf ready!$(RESET)"
	
# $(MLX_LIB):
# 	@echo "$(BLUE)🔧 Compiling MiniLibX...$(RESET)"
# 	@make -C $(MLX_DIR) > /dev/null 2>&1
# 	@echo "$(GREEN)✅ MiniLibX ready!$(RESET)"

# $(NAME): $(OBJS)
# 	@echo "$(BLUE)🔗 Linking $(NAME)...$(RESET)"
# 	@$(CC) $(CFLAGS) $(OBJS) \
# 		-L$(LIBFT_DIR) -lft \
# 		-L$(FT_PRINTF_DIR) -lftprintf \
# 		-L$(MLX_DIR) -lmlx -lXext -lX11 -lm \
# 		-o $(NAME)
# 	@echo "$(GREEN)✅ $(NAME) created successfully!$(RESET)"

# all: $(MLX_LIB) $(LIBFT) $(FT_PRINTF) $(NAME)

# %.o: %.c
# 	@echo "$(YELLOW)🔨 Compiling $<...$(RESET)"
# 	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean:
# 	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
# 	@rm -f $(OBJS)
# 	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
# 	@make -C $(FT_PRINTF_DIR) clean > /dev/null 2>&1
# 	@make -C $(MLX_DIR) clean > /dev/null 2>&1

# fclean: clean
# 	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"
# 	@rm -f $(NAME)
# 	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
# 	@make -C $(FT_PRINTF_DIR) fclean > /dev/null 2>&1

# re: fclean all

# .PHONY: all clean fclean re


# NAME = so_long

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -Wpadded -g3
# INCLUDES =  -I./include -I./ft_printf -I./libft -I./minilibx-linux

# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a

# FT_PRINTF_DIR = ./ft_printf
# FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# LIBS = -L$(LIBFT_DIR) -lft \
# 	   -L$(FT_PRINTF_DIR) -lftprintf

# SRCS =  main.c \
# 		mandatory/map/parsing_map.c \
# 		mandatory/map/parsing_map_utils.c \
# 		mandatory/map/init_map.c \
# 		mandatory/map/valid_map.c \
# 		mandatory/map/valid_track.c \
# 		mandatory/map/valid_track_utils.c \
# 		mandatory/graphics/display_map.c \
# 		mandatory/graphics/init_mlx.c \
# 		mandatory/graphics/load_texture.c \
# 		main.c

# OBJS = $(SRCS:.c=.o)

# MLX_DIR     = minilibx-linux
# MLX_LIB     = $(MLX_DIR)/libmlx.a

# ESET       = \033[0m
# GREEN       = \033[32m
# YELLOW      = \033[33m
# BLUE        = \033[34m
# RED         = \033[31m

# all: $(MLX_LIB) $(NAME)

# $(MLX_LIB):
# 	@echo "$(BLUE)🔧 Compiling MiniLibX...$(RESET)"
# 	@make -C $(MLX_DIR) > /dev/null 2>&1
# 	@echo "$(GREEN)✅ MiniLibX ready!$(RESET)"

# $(NAME): $(OBJS)
# 	@echo "$(BLUE)🔗 Linking $(NAME)...$(RESET)"
# 	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
# 	@echo "$(GREEN)✅ $(NAME) created successfully!$(RESET)"

# %.o: %.c
# 	@echo "$(YELLOW)🔨 Compiling $<...$(RESET)"
# 	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# clean:
# 	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
# 	@rm -f $(OBJS)
# 	@make -C $(MLX_DIR) clean > /dev/null 2>&1

# fclean: clean
# 	@echo "$(RED)🗑️  Removing $(NAME)...$(RESET)"
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

# CFLAGS = -Wall -Wextra -Werror -Wpadded -g3