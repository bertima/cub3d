SRC_CUB3D	=	src/main.c \
				$(KEYBOARD)/init_keyhook.c \
				$(MINI)/mini_map.c $(MINI)/print_floor_ceiling.c $(MINI)/fov_mini_map.c \
				$(MINI)/recup_tile.c $(MINI)/enlarge_map.c \
				$(RECUP_DATA)/dispatch.c $(RECUP_DATA)/recup_data.c $(RECUP_DATA)/recup_map.c \
				$(RECUP_DATA)/search_kind_str.c  $(RECUP_DATA)/search_len_map.c \
				$(RECUP_DATA)/position_player_len_map.c $(RECUP_DATA)/recup_floor_ceiling.c \
				$(RECUP_DATA)/delete_useless_space.c \
				$(VERIF_DATA)/verif_color.c $(VERIF_DATA)/verif_map.c $(VERIF_DATA)/verif_wall.c \
				$(VERIF_DATA)/verif_map_split.c \
				$(PARSING)/error_parsing.c $(PARSING)/free.c $(PARSING)/exit_game.c \
				$(PARSING)/add_data.c $(PARSING)/alloc_struct.c  \
				$(DRAWING)/start_draw.c $(DRAWING)/rotation_utils.c $(DRAWING)/movement.c $(DRAWING)/wall.c \
				$(DRAWING)/fps.c

PARSING		= src/parsing
RECUP_DATA	= $(PARSING)/recup_data
VERIF_DATA	= $(PARSING)/verif_data
DRAWING 	= src/drawing
KEYBOARD	= src/keyboard
MINI		= src/mini_map

OBJ_CUB3D 	= $(addprefix $(OBJDIR)/, $(SRC_CUB3D:.c=.o))
NAME   		= cub3D
CC     		= cc
CFLAGS 		= -Wall -Wextra -Werror -g

LIBFT_DIR 	= libft
LIBFT_A 	= $(LIBFT_DIR)/libft.a
PRINTF_DIR	= libft/printf
PRINTF_A	= $(PRINTF_DIR)/libftprintf.a
OBJDIR 		= cub3d_object

MLX_DIR 	= minilibx-linux
MLX_LIB 	= $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/$(PARSING)
	@mkdir -p $(OBJDIR)/$(VERIF_DATA)
	@mkdir -p $(OBJDIR)/$(RECUP_DATA)
	@mkdir -p $(OBJDIR)/$(DRAWING)
	@mkdir -p $(OBJDIR)/$(KEYBOARD)
	@mkdir -p $(OBJDIR)/$(MINI)
	
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ_CUB3D) $(LIBFT_A) $(PRINTF_A) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJ_CUB3D) $(LIBFT_A) $(PRINTF_A) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo -e "\033[32mCUB3D PROGRAM SUCCESSFULLY COMPILED\033[0m"\
"\n\033[38;2;4;95;164m               ╔═══════════════════════════════════════════════════════════════════════════╗\n"\
"\033[38;2;4;95;164m               ║                                   ___________                             ║\n"\
"\033[38;2;4;95;164m               ║                                 /             \                           ║\n"\
"\033[38;2;4;95;164m               ║                                | Meow Meow 🎶  |                          ║\n"\
"\033[38;2;4;95;164m               ║                                 \____    _____/                           ║\n"\
"\033[38;2;4;95;164m               ║                                      \  /                                 ║\n"\
"\033[38;2;4;95;164m               ║                                       |/                                  ║\n"\
"\033[38;2;4;95;164m               ║                       /^--^\     /^--^\     /^--^\                        ║\n"\
"\033[38;2;4;95;164m               ║                       \____/     \____/     \____/                        ║\n"\
"\033[38;2;4;95;164m               ║                      /      \   /      \   /      \                       ║\n"\
"\033[38;2;4;95;164m               ║                     |        | |        | |        |                      ║\n"\
"\033[38;2;4;95;164m               ║                      \__  __/   \__  __/   \__  __/                       ║\n"\
"\033[38;2;4;95;164m               ║ |^|^|^|^|^|^|^|^|^|^|^|^\ \^|^|^|^/ /^|^|^|^|^\ \^|^|^|^|^|^|^|^|^|^|^|^| ║\n"\
"\033[38;2;4;95;164m               ║ | | | | | | | | | | | | |\ \| | |/ /| | | | | |\ \| | | | | | | | | | | | ║\n"\
"\033[38;2;4;95;164m               ║ | | | | | | | | | | | | |/ /| | |\ \| | | | | |/ /| | | | | | | | | | | | ║\n"\
"\033[38;2;4;95;164m               ║ | | | | | | | | | | | | |\/ | | | \/| | | | | |\/ | | | | | | | | | | | | ║\n"\
"\033[38;2;4;95;164m               ║ |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| ║\n"\
"\033[38;2;4;95;164m               ║                                                                           ║\n"\
"\033[38;2;4;95;164m               ╚═══════════════════════════════════════════════════════════════════════════╝\n"\
"\n"\
"\033[38;2;6;213;175m  .----------------.  .----------------.  .----------------.     .----------------.  .----------------.\033[0m\n"\
"\033[38;2;6;208;163m  | .--------------. || .--------------. || .--------------. |   | .--------------. || .--------------. |\033[0m\n"\
"\033[38;2;5;203;151m  | |\033[38;2;6;213;175m     ______  \033[38;2;5;203;151m | || |\033[38;2;5;203;151m _____  _____ \033[38;2;5;203;151m| || |\033[38;2;5;188;115m   ______    \033[38;2;5;203;151m | |   | |\033[38;2;4;178;91m    ______   \033[38;2;5;203;151m | || |\033[38;2;4;164;54m  ________    \033[38;2;5;203;151m| |\033[0m\n"\
"\033[38;2;5;198;139m  | |\033[38;2;6;213;175m   .' ___  | \033[38;2;5;198;139m | || |\033[38;2;5;203;151m|_   _||_   _|\033[38;2;5;198;139m| || |\033[38;2;5;188;115m  |_   _ \   \033[38;2;5;198;139m | |   | |\033[38;2;4;178;91m   / ____ '. \033[38;2;5;198;139m | || |\033[38;2;4;164;54m |_   ___ '.  \033[38;2;5;198;139m| |\033[0m\n"\
"\033[38;2;5;193;127m  | |\033[38;2;6;213;175m  / .'   \_| \033[38;2;5;193;127m | || |\033[38;2;5;203;151m  | |    | |  \033[38;2;5;193;127m| || |\033[38;2;5;188;115m    | |_) |  \033[38;2;5;193;127m | |   | |\033[38;2;4;178;91m   ''  __) | \033[38;2;5;193;127m | || |\033[38;2;4;164;54m   | |   '. \ \033[38;2;5;193;127m| |\033[0m\n"\
"\033[38;2;5;188;115m  | |\033[38;2;6;213;175m  | |        \033[38;2;5;188;115m | || |\033[38;2;5;203;151m  | '    ' |  \033[38;2;5;188;115m| || |\033[38;2;5;188;115m    |  __'.  \033[38;2;5;188;115m | |   | |\033[38;2;4;178;91m   _  |__ '. \033[38;2;5;188;115m | || |\033[38;2;4;164;54m   | |    | | \033[38;2;5;188;115m| |\033[0m\n"\
"\033[38;2;5;183;103m  | |\033[38;2;6;213;175m  \ '.___.'\ \033[38;2;5;183;103m | || |\033[38;2;5;203;151m   \ '--' /   \033[38;2;5;183;103m| || |\033[38;2;5;188;115m   _| |__) | \033[38;2;5;183;103m | |   | |\033[38;2;4;178;91m  | \____) | \033[38;2;5;183;103m | || |\033[38;2;4;164;54m  _| |___.' / \033[38;2;5;183;103m| |\033[0m\n"\
"\033[38;2;4;178;91m  | |\033[38;2;6;213;175m   '._____.'  \033[38;2;4;178;91m| || |\033[38;2;5;203;151m    '.__.'    \033[38;2;4;178;91m| || |\033[38;2;5;188;115m  |_______/   \033[38;2;4;178;91m| |   | |\033[38;2;4;178;91m   \______.'  \033[38;2;4;178;91m| || |\033[38;2;4;164;54m |________.'  \033[38;2;4;178;91m| |\033[0m\n"\
"\033[38;2;4;173;79m  | |\033[38;2;6;213;175m             \033[38;2;4;173;79m | || |\033[38;2;5;203;151m              \033[38;2;4;173;79m| || |\033[38;2;5;188;115m             \033[38;2;4;173;79m | |   | |\033[38;2;4;178;91m             \033[38;2;4;173;79m | || |\033[38;2;4;164;54m              \033[38;2;4;173;79m| |\033[0m\n"\
"\033[38;2;4;168;67m  | '--------------' || '--------------' || '--------------' |   | '--------------' || '--------------' |\033[0m\n"\
"\033[38;2;4;164;54m   '----------------'  '----------------'  '----------------'     '----------------'  '----------------' \033[0m\n"

clean:
	@clear
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo -e "\033[34mALL .O FILES SUCCESSFULLY DELETED\033[0m"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -f $(NAME)
	@echo -e "\033[35mCUB3D PROGRAM SUCCESSFULLY DELETED\033[0m"

re: fclean all

norme:
	@norminette $(LIBFT_DIR) $(SRC_CUB3D) cub3d.h algo.h

.PHONY: all clean fclean re norme%

# https://42-cursus.gitbook.io/guide/minilibx
# https://lodev.org/cgtutor/raycasting.html
