# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkoster <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 15:09:38 by mkoster           #+#    #+#              #
#    Updated: 2024/04/15 15:09:41 by mkoster          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = sources/push_swap
BSRCS_DIR = sources/checker

PS_MAIN = $(addprefix $(SRCS_DIR)/, push_swap_main.c)
CH_MAIN = $(addprefix $(BSRCS_DIR)/, checker_main.c)
SRCS +=	$(addprefix $(SRCS_DIR)/, error_handling.c big_sort.c commands_a.c \
	ft_lstadd_back.c ft_split.c sort_three_helper_func.c \
	additional_files.c check_sorted.c commands_b.c ft_atoi.c \
	ft_lstnew.c more_commands.c sort_b.c push_to_b.c \
	sort_a.c sort_a_helper.c init_stack.c)
BSRCS = $(addprefix $(BSRCS_DIR)/, get_next_line.c get_next_line_utils.c checker_utils.c)
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
NAME = push_swap
BNAME = checker
CFLAGS = -Wall -Wextra -Werror -I./includes/
CC = cc

all: $(NAME) $(BNAME)

$(NAME): $(OBJS) $(PS_MAIN:.c=.o)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PS_MAIN:.c=.o)

bonus: $(BNAME)

$(BNAME): $(OBJS) $(BOBJS) $(CH_MAIN:.c=.o)
	$(CC) $(CFLAGS) -o $(BNAME) $(OBJS) $(BOBJS) $(CH_MAIN:.c=.o)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS) $(PS_MAIN:.c=.o) $(CH_MAIN:.c=.o)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all re clean fclean bonus
