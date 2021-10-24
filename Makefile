# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jevan-de <jevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/23 16:04:57 by jevan-de      #+#    #+#                  #
#    Updated: 2021/10/17 15:33:53 by jevan-de      ########   odam.nl          #
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
				real_printf.c \
				ft_dprintf.c \
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
				ft_lstmap.c \
				ft_ternary_int.c \
				ft_ternary_charp.c \
				ft_strarrfree.c \
				ft_strarrexists.c

PRINTF_OBJ =	$(addprefix $(PRINTF_SRCDIR), $(PRINTF_SRC:.c=.o))

GNL_OBJ =		$(addprefix $(GNL_SRCDIR), $(GNL_SRC:.c=.o))

SRC_OBJ =		$(addprefix $(SRCDIR), $(SRC:.c=.o))

TEST =			tests

TEST_SRC =		test_stringmanip.c

TEST_OBJ =		$(addprefix $(TEST)/bin/, $(TEST_SRC:.c=.o))

UNAME_S =		$(shell uname -s)

P=$(shell tput setaf 5)
B=$(shell tput setaf 4)
Y=$(shell tput setaf 3)
G=$(shell tput setaf 2)
R=$(shell tput setaf 1)
W=$(shell tput setaf 7)

U=$(shell tput smul)
N=$(shell tput sgr0)

define ASCII


          $P██╗     $B██╗$Y██████╗ $G███████╗$R████████╗
          $P██║     $B██║$Y██╔══██╗$G██╔════╝$R╚══██╔══╝
          $P██║     $B██║$Y██████╔╝$G█████╗     $R██║
          $P██║     $B██║$Y██╔══██╗$G██╔══╝     $R██║
          $P███████╗$B██║$Y██████╔╝$G██║        $R██║
          $P╚══════╝$B╚═╝$Y╚═════╝ $G╚═╝        $R╚═╝
              $W-- created by jevan-de --

endef
export ASCII

all: ascii $(NAME)

ascii:
	@printf "$$ASCII\n"

$(NAME): $(SRC_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	@printf "[$(G)INFO$(W)]: Building library $(NAME)...\n"
	@ar rcs $@ $^
	@printf "[$(G)INFO$(W)]: Finished building library $(NAME)\n"

%.o: %.c
	@if $(CC) -c $(CFLAGS) -o $@ $<; then \
		printf "[$(G)INFO$(W)]: Successfully created object file %-33.33s\r" $@; \
	else \
  		printf "[$(R)ERROR$(W)]: Failed to create object file %-33.33s\n" $@; \
  		$(CC) -c $(CFLAGS) -o $@ $<; \
  	fi

clean:
	@printf "[$(G)INFO$(W)] Cleaning up OBJ files...\n"
	@rm -f $(SRC_OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(TEST_OBJ)

fclean: clean
	@printf "[$(G)INFO$(W)]: Cleaning up $(NAME)...\n"
	@rm -f $(NAME) test

re: fclean all

$(TEST)/bin:
	@echo "$(B)Creating $(TEST)/bin because not created yet"
	@mkdir -p $@

$(TEST)/bin/%.o: $(TEST)/%.c
	@$(CC) $(CFLAGS) $< $(SRC_OBJ) $(GNL_OBJ) $(PRINTF_OBJ) -o $@ -lcriterion

test: $(NAME) $(TEST)/bin $(TEST_OBJ)
	for test in $(TEST_OBJ) ; do ./$$test ; done

.PHONY: fclean clean re
