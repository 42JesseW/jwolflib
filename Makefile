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
				mem/ft_memccpy.c \
				mem/ft_memchr.c \
				mem/ft_memcmp.c \
				mem/ft_memcpy.c \
				mem/ft_memmove.c \
				mem/ft_memset.c \
				put/ft_putchar_fd.c \
				put/ft_putendl_fd.c \
				put/ft_putnbr_fd.c \
				put/ft_putstr_fd.c \
				str/ft_strchr.c \
				str/ft_strcpy.c \
				str/ft_strdup.c \
				str/ft_strjoin.c \
				str/ft_strnjoin.c \
				str/ft_strlcat.c \
				str/ft_strlcpy.c \
				str/ft_strlen.c \
				str/ft_strmapi.c \
				str/ft_strncmp.c \
				str/ft_strncpy.c \
				str/ft_strnstr.c \
				str/ft_strrchr.c \
				str/ft_strtrim.c \
				str/ft_strarrfree.c \
                str/ft_strarrexists.c \
				ft_split.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				lst/ft_lstadd_back.c \
				lst/ft_lstadd_front.c \
				lst/ft_lstdelone.c \
				lst/ft_lstlast.c \
				lst/ft_lstnew.c \
				lst/ft_lstsize.c \
				lst/ft_lstclear.c \
				lst/ft_lstiter.c \
				lst/ft_lstmap.c \
				ft_ternary_int.c \
				ft_ternary_charp.c


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
	@if $(CC) -c $(CFLAGS) -I$(HEADER_DIR) -o $@ $<; then \
		printf "[$(G)INFO$(W)]: Successfully created object file %-33.33s\r" $@; \
	else \
  		printf "[$(R)ERROR$(W)]: Failed to create object file %-33.33s\n" $@; \
  		$(CC) -c $(CFLAGS) -I$(HEADER_DIR) -o $@ $<; \
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
	@$(CC) $(CFLAGS) $< $(SRC_OBJ) $(GNL_OBJ) $(PRINTF_OBJ) -I$(HEADER_DIR) -o $@ -lcriterion

test: $(NAME) $(TEST)/bin $(TEST_OBJ)
	for test in $(TEST_OBJ) ; do ./$$test ; done

.PHONY: fclean clean re
