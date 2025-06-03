
CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRC_DIRS = moves parsing libft utils
SRC = $(wildcard $(addsuffix /*.c, $(SRC_DIRS))) main.c
OBJ_DIR = obj
OBJ_UTILS_DIR = $(OBJ_DIR)/utils
OBJ_MOVES_DIR = $(OBJ_DIR)/moves
OBJ_PARSING_DIR = $(OBJ_DIR)/parsing
OBJ_LIBFT_DIR = $(OBJ_DIR)/libft
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
NAME = push_swap




all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_MOVES_DIR):
	mkdir -p $(OBJ_MOVES_DIR)

$(OBJ_UTILS_DIR):
	mkdir -p $(OBJ_UTILS_DIR)

$(OBJ_PARSING_DIR):
	mkdir -p $(OBJ_PARSING_DIR)

$(OBJ_LIBFT_DIR):
	mkdir -p $(OBJ_LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_MOVES_DIR)/%.o: moves/%.c | $(OBJ_MOVES_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PARSING_DIR)/%.o: parsing/%.c | $(OBJ_PARSING_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_UTILS_DIR)/%.o: utils/%.c | $(OBJ_UTILS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_LIBFT_DIR)/%.o: libft/%.c | $(OBJ_LIBFT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
