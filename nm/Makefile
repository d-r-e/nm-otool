NAME=ft_nm
MKFL=Makefile
SRC=src/main.c src/string.c src/output.c src/mach.c src/libft.c src/segments.c src/arch.c src/fat.c src/byte.c
OBJ=obj/main.o obj/string.o obj/output.o obj/mach.o obj/libft.o obj/segments.o obj/arch.o obj/fat.o obj/byte.o
INC=include/nm.h
LIBFT=libft/libft.a
CFLAGS= -g -Wall -Wextra -Werror -Wformat-security #  -fsanitize=address -g

$(NAME): $(OBJ) $(INC) $(LIBFT) $(SRC)
	gcc $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

$(OBJ): $(SRC) $(INC)
	gcc $(CFLAGS) -c $(SRC)
	@mv *.o obj/


all: $(NAME)


clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft 
	@rm -f $(NAME)

re: fclean all

$(LIBFT):
	$(MAKE) -C libft

commit: all fclean
	@git add $(SRC) Makefile include/nm.h
	@git commit -am "auto commit by ${USER} `date +%d-%m-%Y` from `uname -n | cut -d. -f1`"

push: commit
	@git push origin master

x: $(NAME)
		@./$(NAME) libft/ft_memcpy.o && echo _______________________ && nm --no-sort libft/ft_memcpy.o


h: $(NAME) $(SRC)
	./$(NAME) test/bin_helloworld && echo && nm test/bin_helloworld

o: $(NAME)
	@./$(NAME) libft/ft_memcpy.o && echo _______________________ && nm --no-sort libft/ft_memcpy.o

g: $(NAME)
	nm --no-sort /Users/darodrig/Desktop/nm-otool/kcosta/tests/ahah_gotcha.o
	@./$(NAME) /Users/darodrig/Desktop/nm-otool/kcosta/tests/ahah_gotcha.o

sync: $(SYNC)
	@./$(NAME) /bin/sync && echo _______________________ && nm --no-sort /bin/sync

valgrind: re
	@gcc test/test.c
	valgrind --leak-check=full ./$(NAME) `(ls -1 test/*.out)` && echo SUCCESS || echo FAIL
	@rm -f src/*

test: $(NAME) 
	./test.sh

pull: re fclean
	git pull origin master


activate_leaks: $(SRC)

deactivate_leaks: $(SRC)

onleaks:
	@sed "s_\/\/system_system_g" src/main.c > src/main2.c
	@mv src/main.c src/main_noleaks.c
	@mv src/main2.c src/main.c
offleaks:
	@sed "s_system_\/\/system_g" src/main.c > src/main2.c
	@mv src/main.c src/main_leaks.c
	@mv src/main2.c src/main.c

testleaks: $(NAME)
	./$(NAME) test/*

leaks: onleaks testleaks offleaks fclean

.PHONY: clean re all sync
