# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 11:00:40 by aljigmon          #+#    #+#              #
#    Updated: 2019/10/27 17:14:52 by aljigmon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = aljigmon.filler

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/

HEADERS_DIR = headers/

SRC_NAMES =  main.c \
			 get_infos.c \
			 get_who_am_i.c \
			 algo_filling.c \
			 cut_piece.c \
			 cut_map.c \
			 init_struct.c \
			 offset.c \
			 free.c \
			 print_coor.c \
			 get_directions.c \
			 to_int_tab.c \
			 match_piece.c \
			 check_top_bottom.c \
			 check_right_left.c \
			 check_read.c \
			 check_piece.c

HEADERS_NAMES = struct.h \
				algo_filling.h \
				get_infos.h \
				get_who_am_i.h \
				cut_piece.h \
				cut_map.h \
				defines.h \
				init_struct.h \
				offset.h \
				free.h \
				print_coor.h \
				get_directions.h \
				to_int_tab.h \
				match_piece.h \
				check_top_bottom.h \
				check_right_left.h \
				check_read.h \
				check_piece.h

SRC = $(addprefix $(SRC_DIR), $(SRC_NAMES))

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_NAMES))

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

LIBFT_DIR = libft/

LIBFT_HEADERS_DIR = libft/includes

LIBFT_SRC_NAMES = ft_strdel.c \
				  ft_putnbr.c \
				  ft_putchar.c \
				  ft_strstr.c \
				  ft_strdup.c \
				  ft_bzero.c \
				  ft_atoi.c \
				  ft_strsplit.c \
				  ft_strlen.c

LIBFT_SRC = $(addprefix $(LIBFT_DIR), $(LIBFT_SRC_NAMES))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32mPlayer $(NAME) ready to fight\033[0m"

$(LIBFT): $(LIBFT_SRC)
	@make -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR)

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)
	
re: fclean all
