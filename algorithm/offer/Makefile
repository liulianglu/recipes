
all:40
40obj=testcase.o 40_1.o
40:$(40obj)
	g++ -o 40 $(40obj)

%.o:%.cpp
	cc -g -c $< -o $@

clean:
	rm -f *.o 40
