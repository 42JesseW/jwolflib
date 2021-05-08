# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jevan-de <jevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/23 16:04:57 by jevan-de      #+#    #+#                  #
#    Updated: 2020/07/17 14:49:20 by jevan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

HEADER_DIR =	includes

CFLAGS =		-Wall -Werror -Wextra

SRCDIR =		srcs/
GNL_SRCDIR =	get_next_line/
PRINTF_SRCDIR =	printf/

PRINTF_SRC =	utils/utils.c \
				utils/utils_build.c \
				utils/utils_itoa.c \
				utils/utils_lst.c \
				utils/utils_other.c \
				utils/utils_str.c \
				utils/utils_write.c \
				wrappers/wrappers_char.c \
				wrappers/wrappers_num.c \
				writers/writer_c.c \
				writers/writer_d.c \
				writers/writer_p.c \
				writers/writer_s.c \
				writers/writer_u.c \
				writers/writer_x.c \
				ft_printf.c

GNL_SRC =		get_next_line.c \
				get_next_line_utils.c

SRC =			ft_atof.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstdelone.c \
				ft_lstlast.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

PRINTF_OBJ =	$(addprefix $(PRINTF_SRCDIR), $(PRINTF_SRC:.c=.o))

GNL_OBJ =		$(addprefix $(GNL_SRCDIR), $(GNL_SRC:.c=.o))

SRC_OBJ =		$(addprefix $(SRCDIR), $(SRC:.c=.o))

UNAME_S =		$(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	P = 			\x1b[35m
	B = 			\x1b[34m
	Y = 			\x1b[33m
	G = 			\x1b[32m
	R = 			\x1b[31m
	W = 			\x1b[0m
else ifeq ($(UNAME_S), Linux)
	P = 			\033[35m
	B = 			\033[34m
	Y = 			\033[33m
	G = 			\033[32m
	R = 			\033[31m
	W = 			\033[0m
endif


all: $(NAME)

$(NAME): $(SRC_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	@echo "\n$(B)CREATING LIBFT LIBRARY...$(W)"
	@ar vrcs $@ $^
	@echo "\n$(G)SUCCESSFULLY CREATED LIBFT!"

%.o: %.c
	@echo "$(Y)Compiling $< to $@..."
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "$(R)Cleaning up OBJ files... $(W)"
	@rm -vf $(SRC_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	@echo "$(R)Cleaning up $(NAME)... $(W)"
	@rm -vf $(NAME)

re: fclean all

.PHONY: fclean clean re
