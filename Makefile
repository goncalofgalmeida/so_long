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
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

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