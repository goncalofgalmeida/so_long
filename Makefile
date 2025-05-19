NAME = so_long

SRCS_DIR = ./srcs

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

SRC = ./so_long.c \
	$(SRCS_DIR)/errors.c \
	$(SRCS_DIR)/validations.c \
	$(SRCS_DIR)/parsing_utils.c \
	$(SRCS_DIR)/game.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/player.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

# Confirmar importância desta rule: faz com que qualquer verificação no so_long.h se verifique após a compilação
## %.o: %.c [...]

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

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