CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar
ARFLAGS := rsc
SRC_DIR := ./src
INC_DIR := ./include
LIB := ft
LIB_DIR := ./libft
NAME := libftprintf.a
SRCS := ft_printf.c print_hex.c print_str.c print_num.c ft_uitoa.c ft_itoh.c darr.c darr2.c 
OBJS := $(SRCS:.c=.o)
OBJS_PATH := $(patsubst %.o, $(SRC_DIR)/%.o, $(OBJS))
LIB_PATH := $(patsubst %, $(LIB_DIR)/lib%.a, $(LIB))

all: $(NAME)
$(NAME) : $(OBJS_PATH) $(LIB_PATH)
	cp $(LIB_PATH) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_PATH)
$(OBJS_PATH): %.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
$(LIB_PATH):
	$(MAKE) -C $(LIB_DIR) all clean
.PHONY: clean fclean re all
clean:
	rm -f $(OBJS_PATH) $(NAME_NOFT)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
re: fclean all