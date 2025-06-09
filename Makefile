NAME = so_long

SRCS_DIR = ./srcs

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

SRC = ./so_long.c \
	$(SRCS_DIR)/errors.c \
	$(SRCS_DIR)/flood.c \
	$(SRCS_DIR)/free.c \
	$(SRCS_DIR)/game.c \
	$(SRCS_DIR)/handling.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/movement.c \
	$(SRCS_DIR)/parsing_utils.c \
	$(SRCS_DIR)/rendering.c \
	$(SRCS_DIR)/validations.c \
	$(SRCS_DIR)/del.c # DELETE NAO TE ESQUECAS CARALHO

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Confirmar importância desta rule: faz com que qualquer verificação no so_long.h se verifique após a compilação
## %.o: %.c [...]

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean
	$(MAKE) all