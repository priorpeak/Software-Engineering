GCC = g++

OBJS = pa2Functions.o main.o

default: Q1

Q1: $(OBJS)
	$(GCC) -o Q1 $(OBJS)

pa2Functions.o: pa2Functions.cpp pa2Functions.h
	$(GCC) -c pa2Functions.cpp -o pa2Functions.o

main.o: main.cpp pa2Functions.h
	$(GCC) -c main.cpp pa2Functions.o

clean: 
	rm $(OBJS) Q1