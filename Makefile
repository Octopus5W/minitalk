SERVER_NAME = server
CLIENT_NAME = client
CC = cc
CFLAGS = -Wall -Werror -Wextra
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/printf.a
INC_DIR = include
INC = -I$(INC_DIR) -I$(PRINTF_DIR)
SRC_DIR = sources
OBJ_DIR = obj
RM = rm -rf

SERVER_SRCS = \
	server.c

CLIENT_SRCS = \
	client.c

SERVER_SRC = $(addprefix $(SRC_DIR)/, $(SERVER_SRCS))
CLIENT_SRC = $(addprefix $(SRC_DIR)/, $(CLIENT_SRCS))

SERVER_OBJ = $(SERVER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLIENT_OBJ = $(CLIENT_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(SERVER_NAME) $(CLIENT_NAME) 

$(PRINTF): | $(PRINTF_DIR)
			@$(MAKE) -C $(PRINTF_DIR)

$(SERVER_NAME): $(SERVER_OBJ) $(PRINTF)
			@$(CC) $(CFLAGS) -o $@ $(SERVER_OBJ) $(PRINTF) $(INC)

$(CLIENT_NAME): $(CLIENT_OBJ) $(PRINTF)
			@$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJ) $(PRINTF) $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) $(OBJ_DIR)
			@$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
		@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
		@$(MAKE) fclean -C $(PRINTF_DIR)

re:        fclean all

.PHONY:    fclean re all clean