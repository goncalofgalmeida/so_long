NAME = so_long

SRCS_DIR = ./srcs

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

SRC =	$(SRCS_DIR)/so_long.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

all: $(S_NAME) $(C_NAME)

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