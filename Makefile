CC=gcc
CFLAGS= -Wall -std=c99
MATHLIBS = -lm

ifdef DEBUG
CFLAGS += -g
endif

ifdef STATIC
CFLAGS += -STATIC
endif

bin_dir:
	mkdir -p bin
	mkdir -p bin/exercises
	mkdir -p bin/labs
	mkdir -p bin/hws

all: clean bin_dir exercises hws labs

clean:
	@rm -rf bin

exercises: fckconverter histogram_min_max minesweeper_render clock histogram_min_max_hor classroom gauss_jordan oguz1 cramers_rule root_find hws

labs: lab-1 lab-2 lab-3 lab-5 lab-6 lab-7 lab-8 lab-9

hws: hw1-t1 hw1-t2 hw1-t3

fckconverter:
	$(CC) $(CFLAGS) -o bin/exercises/fckconverter exercises/fckconverter.c

histogram_min_max:
	$(CC) $(CFLAGS) -o bin/exercises/histogram_min_max exercises/histogram_min_max.c

minesweeper_render:
	$(CC) $(CFLAGS) -o bin/exercises/minesweeper_render exercises/minesweeper_render.c

clock:
	$(CC) $(CFLAGS) -o bin/exercises/clock exercises/clock.c $(MATHLIBS)

histogram_min_max_hor:
	$(CC) $(CFLAGS) -o bin/exercises/histogram_min_max_hor exercises/histogram_min_max_hor.c

classroom:
	$(CC) $(CFLAGS) -o bin/exercises/classroom exercises/classroom.c

gauss_jordan:
	$(CC) $(CFLAGS) -o bin/exercises/gauss_jordan exercises/gauss_jordan.c

oguz1:
	$(CC) $(CFLAGS) -o bin/exercises/oguz1 exercises/oguz1.c $(MATHLIBS)

cramers_rule:
	$(CC) $(CFLAGS) -o bin/exercises/cramers_rule exercises/cramers_rule.c

root_find:
	$(CC) $(CFLAGS) -o bin/exercises/root_find exercises/root_find.c


lab-1:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab1 labs/furkanselek_lab1.c

lab-2:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab2 labs/furkanselek_lab2.c

lab-3:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab3 labs/furkanselek_lab3.c $(MATHLIBS)

hw1-t1:
	$(CC) $(CFLAGS) -o bin/hws/furkanselek_hw1_t1 hws/furkanselek_hw1_t1.c $(MATHLIBS)

hw1-t2:
	$(CC) $(CFLAGS) -o bin/hws/furkanselek_hw1_t2 hws/furkanselek_hw1_t2.c $(MATHLIBS)

hw1-t3:
	$(CC) $(CFLAGS) -o bin/hws/furkanselek_hw1_t3 hws/furkanselek_hw1_t3.c $(MATHLIBS)

lab-5:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab5 labs/furkanselek_lab5.c $(MATHLIBS)

lab-6:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab6 labs/furkanselek_lab6.c $(MATHLIBS)
lab-7:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab7 labs/furkanselek_lab7.c $(MATHLIBS)
lab-8:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab8 labs/furkanselek_lab8.c $(MATHLIBS)

lab-9:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab9 labs/furkanselek_lab9.c $(MATHLIBS)

lab-10:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_lab10 labs/furkanselek_lab10.c $(MATHLIBS)

lab-final:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_labfinal labs/furkanselek_labfinal.c $(MATHLIBS)

lab-final2:
	$(CC) $(CFLAGS) -o bin/labs/furkanselek_labfinal2 labs/furkanselek_labfinal2.c $(MATHLIBS)