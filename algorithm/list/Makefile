
all:depend

depend:
	gcc -MM *.c > make.depend

list_obj=list.o test_list.o
list: $(list_obj)
	$(CXX) -o list $(list_obj)

clean:
	rm -f *.o

%.o:%.c
	$(CXX) -c $< -o $@
