IDIR = inc
CC = clang++ -stdlib=libc++ -std=gnu++11
CFLAGS = -I$(IDIR)

SDIR = src

_DEPS = knightTour.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC = main.cpp knightTour.cpp
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))


build: $(SRC) $(DEPS)
	$(CC) $(CFLAGS) -o knight_tour $(SRC)


run: 
	./knight_tour

clean:
	rm knight_tour
#	rm -f *.o core	
#	rm *.bin
	

