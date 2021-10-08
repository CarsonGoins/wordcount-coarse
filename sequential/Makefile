SRCS =  main.cpp Dictionary.cpp  MyHashtable.cpp 


# Everything below that should not have to change ever.

LD=g++

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g -std=c++17 -O3


all: main

main: $(OBJS)
	$(LD)  $(OBJS) -o main

.SUFFIXES: .cpp

run:
	./main test_sources.txt the 1000000

bench:
	./queue.sh

clean:
	-rm $(OBJS)
	-rm main

