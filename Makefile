NAME	= push_swap

CC	= gcc
CFLAGS	= -g -Wall -Werror -Wextra
RM	= rm -f
VALGRIND =	valgrind --leak-check=full --show-leak-kinds=all \
			--track-origins=yes -q --tool=memcheck
INCLUDES_DIR	= ./includes ./libs/libft
SRC_DIR	= ./src
OBJ_DIR	 = ./src/build

LIBFT_PATH	 = ./libs/libft
LIBFT	= $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
INCLUDES	= $(addprefix -I,$(INCLUDES_DIR))

SRCS	= tests.c push_swap.c push_swap_utils.c list_utils.c validation_utils.c
SRCS	+= operation_swap.c operation_push.c normalize.c
SRCS	+= operation_rotate.c operation_reverse_rotate.c
SRCS	+= sort.c sort_utils.c big_sort.c free_utils.c initialise_utils.c

OBJS	:= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
SRCS	:= $(addprefix $(SRC_DIR)/,$(SRCS))

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBFT_FLAGS)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBFT_FLAGS)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re:	fclean all

go: all
	./$(NAME) $$ARG

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $$ARG

.PHONY:	all clean fclean re go valgrind
