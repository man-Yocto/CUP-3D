NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INC_DIR		= includes
SRC_DIR		= src
PARSE_DIR	= src/parsing

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR)

SRC			= $(SRC_DIR)/main.c \
			  $(PARSE_DIR)/cleanup_config.c \
			  $(PARSE_DIR)/parse_file.c \
			  $(PARSE_DIR)/parse_utils.c \
			  $(PARSE_DIR)/parse_textures.c \
			  $(PARSE_DIR)/parse_colors.c \
			  $(PARSE_DIR)/gnl_clean.c \
			  $(PARSE_DIR)/parse_config.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(INC_DIR)/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re