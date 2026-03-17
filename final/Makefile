NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INC_DIR		= includes
SRC_DIR		= src
PARSE_DIR	= src/parsing
INIT_DIR	= src/init
RAYCAST_DIR	= src/raycasting
RENDER_DIR	= src/rendering
EVENTS_DIR	= src/events

INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

SRC			= $(SRC_DIR)/main.c \
			  $(PARSE_DIR)/cleanup_config.c \
			  $(PARSE_DIR)/parse_file.c \
			  $(PARSE_DIR)/parse_utils.c \
			  $(PARSE_DIR)/parse_textures.c \
			  $(PARSE_DIR)/parse_colors.c \
			  $(PARSE_DIR)/gnl_clean.c \
			  $(PARSE_DIR)/parse_config.c \
			  $(PARSE_DIR)/file_validation.c \
			  $(PARSE_DIR)/flood_fill.c \
			  $(PARSE_DIR)/map_builder.c \
			  $(PARSE_DIR)/map_validation.c \
			  $(PARSE_DIR)/config_validation.c \
			  $(INIT_DIR)/init_game.c \
			  $(INIT_DIR)/init_game_utils.c \
			  $(INIT_DIR)/init_player.c \
			  $(INIT_DIR)/init_mlx.c \
			  $(INIT_DIR)/init_textures.c \
			  $(INIT_DIR)/init_cleanup.c \
			  $(RAYCAST_DIR)/cast_rays.c \
			  $(RAYCAST_DIR)/ray_init.c \
			  $(RAYCAST_DIR)/ray_step.c \
			  $(RAYCAST_DIR)/dda.c \
			  $(RAYCAST_DIR)/ray_projection.c \
			  $(RENDER_DIR)/get_tex_pixel.c \
			  $(RENDER_DIR)/draw_background.c \
			  $(RENDER_DIR)/draw_wall.c \
			  $(RENDER_DIR)/render_frame.c \
			  $(EVENTS_DIR)/key_handler.c \
			  $(EVENTS_DIR)/player_move.c \
			  $(EVENTS_DIR)/player_rotate.c \
			  $(EVENTS_DIR)/events.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

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
