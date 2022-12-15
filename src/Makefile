CC = gcc
CFLAGS = -Wall -Werror -Wextra
C11 = -std=c11

all: rebuild

build: s21_math

s21_math: 
	$(CC) $(CFLAGS) $(C11) s21_*.c -o s21_math

test: clean s21_math.a
	gcc -fsanitize=address -lcheck test.c s21_math.a -o test.out && ./test.out

gcov_report: coverage run_coverage lcov genhtml open

coverage:
	gcc --coverage -lcheck  s21_*.c test.c  -o test

run_coverage:
	./test

lcov:
	lcov -t "Core" -o s21_test.info -c -d .
genhtml:
	genhtml -o report s21_test.info
open:
	open ./report/index.html

s21_math.a: s21_math.o
	ar rc s21_math.a s21_*.o

s21_math.o:
	gcc -c $(FLAGS) s21_floor.c s21_ceil.c s21_abs.c s21_fabs.c s21_log.c s21_exp.c s21_sqrt.c s21_fmod.c s21_atan.c s21_asin.c s21_acos.c s21_sin.c s21_factorial.c s21_cos.c s21_tan.c s21_pow.c

clean:
	rm -rf s21_math *.o *.a *.info *.gcda *.gcno *.out test report/

rebuild: clean build