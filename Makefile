NAME = lem-in
LIBFT_FILE = libft.a

LIBFT_DIR = ./libft
EXECUTION_DIR = ./src/execution
PARSER_DIR = ./src/parser
INC_DIR = ./includes/
LIBFT_INC = $(LIBFT_DIR)/
OBJ_DIR = ./obj

LFLAG = 

LIBFT = $(LIBFT_DIR)/$(LIBFT_FILE)

HEADERS = $(INC_DIR)lem_in.h
LIBFT_HEADERS = $(LIBFT_INC)libft.h $(LIBFT_INC)get_next_line.h

EXECUTION_FILES = ants.c ants2.c bfs.c main.c pathgen.c pathgen2.c pathgen3.c set_dept_layers.c

PARSER_FILES = check_error.c initialize_var.c input_to_list.c liberate_memory.c save_input.c save_input2.c

LIBFT_FILES = ft_atoi.c ft_bzero.c ft_del.c ft_ifcount.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memindex.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_strindex.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strreplace.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c

LIBFT_SRC = $(addprefix $(LIBFT_DIR)/, $(LIBFT_FILES))
OBJ_EXECUTION = $(addprefix $(OBJ_DIR)/, $(EXECUTION_FILES:%.c=%.o))
OBJ_PARSER = $(addprefix $(OBJ_DIR)/, $(PARSER_FILES:%.c=%.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
INC = -I $(INC_DIR) -I $(LIBFT_INC)

C_RED = \033[31m
C_GREEN = \033[32m
C_CYAN = \033[36m
C_NONE = \033[0m

all: $(NAME)

$(LIBFT_FILE):
	@make -C $(LIBFT_DIR)
	@printf "Lem-in:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJ_DIR)/%.o: $(EXECUTION_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@
	@printf "Lem-in:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJ_DIR)/%.o: $(PARSER_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@
	@printf "Lem-in:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@printf "Lem-in:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(NAME): $(LIBFT_FILE) $(OBJ_DIR) $(OBJ_PARSER) $(OBJ_EXECUTION)
	@$(CC) $(OBJ_PARSER) $(OBJ_EXECUTION) $(LIBFT) $(LFLAG) -o $(NAME)
	@printf "Lem-in:  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@printf "Lem-in:  %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "Lem-in:  %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all