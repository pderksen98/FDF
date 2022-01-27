# -*- Makefile -*-
NAME := fdf

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRCS :=	gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			src/main.c \
			src/array_size.c \
			src/input.c \
			src/print.c 
			#hier komt nog meer

HEADERFILES := fdf.h

LIBFT := libft/libft.a

MLX := mlx/libmlx.dylib

all: $(NAME)
	
$(NAME) : $(SRCS) $(LIBFT) $(MLX)
		$(CC) $(CFLAGS) -o $@ $^

$(LIBFT) :
		$(MAKE) -C libft

$(MLX) :
		$(MAKE) -C mlx && (test -e libmlx.dylib || ln -sf mlx/libmlx.dylib libmlx.dylib)

clean :
		$(MAKE) clean -C libft 

fclean:
		$(MAKE) fclean -C libft
		$(MAKE) clean -C mlx
		rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re