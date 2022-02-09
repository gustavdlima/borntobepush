NAME	= push_swap

CC	= gcc
CFLAGS	= -g
RM	= rm -f

INCLUDES_DIR	= ./includes ./libs/libft
SRC_DIR	= ./src
OBJ_DIR	 = ./build

LIBFT_PATH	 = ./libs/libft
LIBFT	= $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft
INCLUDES	= $(addprefix -I,$(INCLUDES_DIR))

SRCS	= tests.c push_swap.c push_swap_utils.c list_utils.c validation_utils.c validation_utils_2.c
SRCS	+= operation_swap.c operation_push.c operation_rotate.c 
SRCS	+= operation_reverse_rotate.c

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
	./so_long

.PHONY:	all clean fclean re
