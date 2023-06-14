##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

SRC	=	./src/main.c 					\
		./src/open_file.c				\
		./src/formate_string.c			\
		./src/error/error_handling.c 	\
		./src/error/error.c 			\
		./src/error/error_ese.c 			\
		./src/parsing/parse.c 			\
		./src/parsing/rooms.c 			\
		./src/algo/algo.c 				\
		./src/algo/end.c 				\
		./src/free.c					\
		./src/algo/condition_one_path.c

OBJ = $(SRC:.c=.o)

NAME =	lem_in

YEAR = 2023

LIBFLAGS = -L ./lib/my/ -lmy -lm

CFLAGS += -Wall -Wextra -I./include -g

all :
	@$(MAKE) -s -j8 $(NAME)

default:
		@make all --no-print-directory

lib:
		@unset MAKEFLAGS
		@unset MAKELEVEL
		@make -C lib/my --no-print-directory
all:
		@make $(NAME) --no-print-directory

clean:
		@make clean -s --no-print-directory -C lib/my
		@touch $(OBJ)
		@rm $(OBJ)

fclean: clean
		@make fclean -s --no-print-directory -C lib/my
		@rm vgcore*
		@rm coding-style-report*
		@touch $(NAME)
		@rm $(NAME)

$(NAME): 	$(OBJ)
		@printf "\033[1;33m--- $(NAME) [EPITECH $(YEAR) Project] "
		@printf "\033[1;33m---\033[0m\n"
		@make lib --no-print-directory -B
		@make build --no-print-directory

.ONESHELL:
build:
	@gcc -o $(NAME) $(OBJ) $(LIBFLAGS)
	if [ $$? -eq 0 ]; then
		printf "\033[1;32m"
		echo "[*] $(NAME) compiled"
		printf "\033[0m--- END OF COMPILATION ---\n"
	else
		printf "\033[1;31m"
		echo "[!] $(NAME) compilation failed"
		printf "\033[0m"
	fi

re: fclean
		@printf "\033[1;36m[*] Force Recompilation [*]\033[0m\n"
		@make $(NAME) --no-print-directory

unit_tests: clean_tests
		@printf "\033[1;33m--- $(NAME) [EPITECH $(YEAR) Project] "
		@printf "\033[1;33m---\033[0m\n"
		@printf "\033[1;32m[*] Unit Tests Compilation\033[0m\n"
		@make re
		@gcc -o test $(SRC) tests/*.c $(lib) $(include) -lcriterion --coverage

tests_run: unit_tests
		@printf "\033[1;32m[*] Unit Tests Execution\033[0m\n"
		@./test > testlog
		@rm testlog

coverage: tests_run
		@printf "\033[1;32m[*] Unit Tests Coverage\033[0m\n"
		@gcovr --exclude tests/ --exclude lib/my/
		@make clean_tests

clean_tests:
		@printf "\033[1;34m[*] Cleaning Unit Tests\033[0m\n"
		@rm -f test
		@rm -f *.gc*
