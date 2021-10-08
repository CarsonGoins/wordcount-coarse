SRCS =  main.cpp Dictionary.cpp  MyHashtable.cpp 


# Everything below that should not have to change ever.

LD=g++

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g -std=c++17 -O3

LDFLAGS =  -pthread

all: main

main: $(OBJS)
	$(LD)  $(OBJS) -o main $(LDFLAGS)

.SUFFIXES: .cpp

run:
	./main test_sources.txt the 1000000

test:
	./test.sh

bench:
	./queue.sh

plot:
	./plot.sh

clean:
	-rm $(OBJS)
	-rm ./main

