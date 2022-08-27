dep = double-linked_list.o test.o

test : $(dep)
	cc -o test $(dep)

double-linked_list.o : double-linked_list.h
test.o : 

.PHONY : test, clean

clean : 
	rm $(dep) test