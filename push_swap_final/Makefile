# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 00:25:40 by totoletoto        #+#    #+#              #
#    Updated: 2025/02/13 08:20:28 by thofstet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


SRCDIR = res
OBJDIR = obj
INCDIR = inc
LIBFTDIR = libraries/libft


SRCS = $(SRCDIR)/main.c $(SRCDIR)/checks.c $(SRCDIR)/checks_args.c \
    	 $(SRCDIR)/utils.c $(SRCDIR)/rotate_and_push.c $(SRCDIR)/reverse_rotate.c \
		 $(SRCDIR)/swap.c $(SRCDIR)/radix.c $(SRCDIR)/few_values.c


OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


LIBFT = $(LIBFTDIR)/libft.a


CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCDIR) -I$(LIBFTDIR)/include


RM = rm -f


RESET = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m


all: $(LIBFT) $(NAME)


TOTAL_FILES := $(words $(SRCS))
COMPILED_FILES := 0

$(NAME): $(OBJS)
	@printf "\r\033[K$(BOLD)$(GREEN)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "\r\033[K$(BOLD)$(GREEN)Compilation complete: $(NAME) is ready!$(RESET)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(OBJDIR)
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES) + 1))))
	@printf "\r\033[K$(YELLOW)Compiling [%3d%%] %-33s$(RESET)" $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) )) "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@printf "$(YELLOW)Compiling libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@printf "$(YELLOW)Cleaning object files...$(RESET)\n"
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@printf "$(YELLOW)Cleaning executable...$(RESET)\n"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all


.PHONY: all clean fclean re
