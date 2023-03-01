CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic -g #$(shell pkg-config --cflags check)  -fprofile-arcs -ftest-coverage# -std=c11 -c - compile without linking
GCOVFLAGS=--coverage -fprofile-arcs -ftest-coverage

# SANITIZER = -fsanitize=address

all: clean style_check s21_math.a test gcov_report

%.o: %.c test_21_math.h
	$(CC) $(CFLAGS) $< $(GCOVFLAGS) -o $@

test: s21_math.a test.c
	$(CC)  -Werror -Wextra -Wall -std=c11 -pedantic test.c  s21_math.a -lcheck -o test
	./test

s21_math.o: s21_math.c  s21_math.h
	$(CC) $(CFLAGS) -c s21_math.c 

s21_math.a: s21_math.o
		ar rcs s21_math.a s21_math.o

gcov_report: s21_math.a test
	$(CC)  -Werror -Wextra -Wall -std=c11 -pedantic $(GCOVFLAGS) test.c s21_math.a -lcheck -o s21_gcov
	./s21_gcov
	lcov -t "gcov_report" -o s21_gcov_report.info -c -d .
	genhtml -o s21_report s21_gcov_report.info
	open ./s21_report/index.html

clang: 
	cp ../materials/linters/.clang-format .
	clang-format -i *.c
	clang-format -i *.h
	clang-format -n *.c
	clang-format -n *.h
	rm -rf .clang-format

style_check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c
	clang-format -n *.h
	rm -rf .clang-format

clean:
	rm -rf test s21_gcov *.o *.a *.gcno *.gcda *.info *.html *.css *.png
	rm -rf report s21_report 
