# -*- Makefile -*-
NAME := fdf

# ifndef DEBUG
# CFLAGS := -Wall -Wextra -Werror
# else
# CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g
# endif

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRCS :=	gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			src/main.c \
			src/array_size.c \
			src/make_input_array.c \
			src/rotate.c \
			src/make_square.c \
			src/plot.c \
			src/events.c \
			src/increase_z.c \
			src/add_angle.c
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