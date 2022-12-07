NAME = so_long.out
LIBMLX	:= ~/MLX42/
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = $(LIBMLX)/libmlx42.a
CC = gcc
LIBFT = libft/libft_enhanced.a
HEADERS	:= -I ./include -I $(LIBMLX)/include

SOURCES = 	main.c \
			map.c \
			map_parser.c \
			map_check_data.c \
			map_check_data2.c \
			map_check_data_utils.c \
			map_check_path.c \
			map_check_path_utils.c \
			pos.c \
			t_data.c \
			t_data_utils.c \
			t_data_utils2.c \
			render_frame.c \
			render_characters_sprites.c \
			render_characters_sprites_utils.c \
			input.c \
			display_ui.c \
			ui.c 	\
			end_menu.c \
			player_movement.c \
			player_movement_utils.c \
			handle_collisions.c \
			handle_collision_enemy.c \
			handle_collision_attack.c \
			can_move_to.c \
			file_loader.c \
			file_loader_utils.c \
			handle_animation.c \
			handle_animation_utils.c \
			handle_player_animation.c \
			handle_enemy_animation.c \
			player_attack.c \
			enemies_behavior.c \
			enemies_behavior_utils.c \
			enemies_path.c \
			enemies_path_utils.c \
			enemies_movement.c \
			enemies_movement_utils.c \
			game_state.c \
			queue.c \
			
			

SOURCES_BONUS = 

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)


all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

clean:
	make clean -C libft/
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

bonus: $(NAME)

.c.o: 		
			@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

re: fclean $(NAME)

sanitize: $(LIBFT) $(SOURCES) $(OBJECTS)
	$(CC) $(FLAGS) -fsanitize=address $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

debug: $(LIBFT) $(SOURCES) $(OBJECTS)
	$(CC) $(MLX_FLAGS) -g $(FLAGS) -fsanitize=address $(OBJECTS) $(LIBFT) -lglfw -L "/Users/lloison/.brew/opt/glfw/lib/" -o $(NAME)

$(LIBFT) :
	make -C libft/

$(NAME): $(LIBFT) $(SOURCES) $(OBJECTS)
	$(CC) $(MLX_FLAGS) $(FLAGS) $(OBJECTS) $(LIBFT) -lglfw -L "/Users/lloison/.brew/opt/glfw/lib/" -o $(NAME)