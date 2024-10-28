NAME        =   push_swap
CC          =   cc
FLAGS       =   -Wall -Wextra -Werror -g3

FT_PATH     =   .ft
FT_FILE     =   ft.a
FT_LIB      =   $(FT_PATH)/$(FT_FILE)

# Dossier pour les fichiers objets
BUILD_DIR   =   .o

# Base compiled files
C_FILES	=	src/sort.c src/utils.c src/fill_a.c src/fill_b.c src/rotate_both.c \
			src/create_stack.c src/sort_utils.c push_swap.c \
			src/commands/push.c src/commands/rev_rotate.c src/commands/rotate.c src/commands/swap.c
OBJS        =   $(C_FILES:%.c=$(BUILD_DIR)/%.o)

# Colors
DEFAULT     =   \033[0;39m
GREEN       =   \033[0;32m
YELLOW      =   \033[0;33m

# Compile part
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -I. -I$(FT_PATH) -c $< -o $@

$(NAME):    $(OBJS)
	@make -C $(FT_PATH) --no-print-directory -s
	@$(CC) $(FLAGS) $(OBJS) $(FT_LIB) -o $(NAME)
	@echo "$(GREEN)♫ $(NAME) compiled successfully! ♫$(DEFAULT)"

# Mandatory rules
all:        $(NAME)

clean:
	@rm -rf $(BUILD_DIR)
	@make clean -C $(FT_PATH) --no-print-directory -s
	@echo "$(GREEN)♫ $(NAME) object files cleaned! ♫$(DEFAULT)"

fclean:     clean
	@rm -f $(NAME)
	@make fclean -C $(FT_PATH) --no-print-directory -s
	@echo "$(GREEN)♫ $(NAME) executable files cleaned! ♫$(DEFAULT)"

re:         fclean all
	@echo "$(GREEN)♫ $(NAME) recompiled successfully! ♫$(DEFAULT)"

.PHONY:     all clean fclean re
