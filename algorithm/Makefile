
all:depend recursion circulation

CXX=g++

depend:
	gcc -MM *.cpp > makefile.depend
	gcc -MM *.c >> makefile.depend

include makefile.depend

recursion:test.o recursion.o
	$(CXX) -o recursion test.o recursion.o
circulation:test.o circulation.o
	g++ -o circulation test.o circulation.o

#recursion.o: recursion.cpp algorithm.h
#	$(CXX) -g -c recursion.cpp 
#circulation.o: circulation.cpp algorithm.h
#	g++ -g -c circulation.cpp
#test.o: test.cpp algorithm.h
#	$(CXX) -g -c test.cpp

clean:
	rm -f *.o core.* *.txt a.out recursion circulation
	rm -f binarysearch
obj:
	rm -f *.o
core:
	rm -f core.*


tree_recursion_obj=test_binary_tree.o binary_tree_recursion.o 
tree_recursion:$(tree_recursion_obj)
	$(CXX) -o tree_recursion $(tree_recursion_obj) 

test_tree_obj=test_binary_tree.o binary_tree_circulation.o
tree_circulation:$(test_tree_obj)
	$(CXX) -o tree_circulation $(test_tree_obj)

rbtree_obj=test_rbtree.o rb_tree.o
rbtree:$(rbtree_obj)
	g++  -o rbtree $(rbtree_obj)

CFLAGS = -g -Wall -fkeep-inline-functions 
%.o:%.c
	$(CXX) -c $(CFLAGS) $< -o $@
%.o:%.cpp
	$(CXX) -c $(CFLAGS) $< -o $@
