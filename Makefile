#### VARIABLES ####
NAME = push_swap
LIBFT = ./libft/libft.a
# HEADER_PATH = include
CC= cc
# CFLAGS=-Wall -Wextra -Werror -I $(HEADER0_PATH)
CFLAGS=-Wall -Wextra -Werror
# OBJ=ft_*.c =.o
# SRCS = $(HEADER_PATH)ft_atoi
#### SOURCE ####
SRC_FILES = ft_strjoin.c \
		liste_utils.c \
		operation_global.c \
		index.c \
		radix_sort.c \
		algo_sort_small.c \
		operation_precise.c \
		operation_precise2.c \
		free.c \
		parsing.c

OBJ_FILES = $(SRC_FILES:.c=.o)
# OBJ_FILES = $(addsuffix .o, $(SRC_FILES))
#### RULES ####
all: ${NAME}


${NAME} : ${LIBFT} ${OBJ_FILES} 
	${CC} ${CFLAGS} -o ${NAME} ${OBJ_FILES} ${LIBFT} -g3

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -g3
${LIBFT} :
	$(MAKE) -C ./libft
clean:
	rm -f ${OBJ_FILES}
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f ${NAME}
	$(MAKE) -C ./libft fclean

val: all clean
	valgrind --leak-check=full ./${NAME} "4 1 3 0 2"

re: fclean  all

.PHONY: all clean fclean re 
