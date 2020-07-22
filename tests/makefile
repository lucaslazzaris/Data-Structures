  
CC=g++
IDIR=../
CFLAGS=-I$(IDIR)
OUT=out_test.out

doit:
	$(CC) -std=c++1z -Wall -fsanitize=address testList.cpp -o $(OUT) $(CFLAGS)

run:
	./$(OUT) -r compact  -d yes

debug:
	$(CC) -ggdb -std=c++1z -Wall testList.cpp -o $(OUT) $(CFLAGS)