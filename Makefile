# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 13:34:44 by youarzaz          #+#    #+#              #
#    Updated: 2020/11/28 09:24:39 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =  lem-in
CFLAGS = # -Wextra -Wall -Werror 
SOURCESPS = check_error.c input_to_list.c liberate_memory.c save_input.c initialize_var.c
SOURCESEXE = bfs.c main.c pathgen.c ants.c test_print.c
SOURCESGNL = get_next_line.c my_get_next_line.c 
HEADERS = includes/lem-in.h gnl/get_next_line.h
OBJDIR = obj
SRCDIRPS = parse
SRCDIREXE = execution
SRCDIRGNL = gnl
OBJSPS = $(addprefix $(OBJDIR)/,$(SOURCESPS:%.c=%.o))
OBJSEXE = $(addprefix $(OBJDIR)/,$(SOURCESEXE:%.c=%.o))
OBJSGNL = $(addprefix $(OBJDIR)/,$(SOURCESGNL:%.c=%.o))
LIB = libft/libft.a

all :           $(NAME)

$(OBJDIR)/%.o: $(SRCDIRPS)/%.c $(HEADERS)
	@gcc -g $(CFLAGS) -c $< -I includes/ -o $@

$(OBJDIR)/%.o: $(SRCDIREXE)/%.c $(HEADERS)
	@gcc -g $(CFLAGS) -c $< -I includes/ -o $@

$(OBJDIR)/%.o: $(SRCDIRGNL)/%.c $(HEADERS)
	@gcc -g $(CFLAGS) -c $< -I gnl/ -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIB):
	@make -C libft

$(NAME) : $(LIB) $(OBJDIR) $(OBJSPS) $(OBJSEXE) $(OBJSGNL)
	@gcc -g $(CFLAGS) $(OBJSPS) $(OBJSEXE) $(OBJSGNL) $(LIB) -o $(NAME)
	@echo "MAKEFILE LEM-IN ...[OK]"
clean :
	@make clean -C libft
	@rm -rf $(OBJDIR)
	@echo "Removing LEM-IN objects ...[OK]"

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all
