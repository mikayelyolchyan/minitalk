CLIENT_NAME = client
SERVER_NAME = server

CC = cc

C_FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

CLIENT_SRC_DIR = sources/client
SERVER_SRC_DIR = sources/server
INC_DIR = includes/headers
LIB_DIR = includes/libraries

LIBFT_DIR = $(LIB_DIR)/libft
FT_PRINTF_DIR = $(LIB_DIR)/ft_printf

CLIENT_SRCS = $(CLIENT_SRC_DIR)/main.c
SERVER_SRCS = $(SERVER_SRC_DIR)/main.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

HEADER = $(INC_DIR)/minitalk.h

INC_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR) -lftprintf

all: $(LIBFT) $(FT_PRINTF) $(CLIENT_NAME) $(SERVER_NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR) all

$(CLIENT_NAME): $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(C_FLAGS) $(CLIENT_OBJS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(C_FLAGS) $(SERVER_OBJS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(SERVER_NAME)

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re