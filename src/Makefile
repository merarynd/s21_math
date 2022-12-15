CC = gcc
CFLAGS = -Wall -Werror -Wextra
C11 = -std=c11

all: rebuild

build: s21_math

s21_math: 
	$(CC) $(CFLAGS) $(C11) s21_*.c main.c -o s21_math

test: clean s21_math.a
	gcc -fsanitize=address -lcheck test.c s21_math.a -o test.out && ./test.out

gcov_report: coverage run_coverage lcov genhtml open

coverage:
	gcc --coverage -lcheck  s21_*.c test.c  -o test

run_coverage:
	./test

lcov:
	/Users/*/goinfre/homebrew/bin/lcov -t "Core" -o s21_test.info -c -d .
genhtml:
	/Users/*/goinfre/homebrew/bin/genhtml -o report s21_test.info
open:
	open ./report/index.html

s21_math.a: s21_math.o
	ar rc s21_math.a s21_*.o

s21_math.o:
	gcc -c $(FLAGS) s21_*.c
clean:
	rm -rf s21_math *.o *.a *.info *.gcda *.gcno *.out test report/

rebuild: clean build