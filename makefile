all: linked_slist.o sbucket.o slist_test.o
	gcc -o slist linked_slist.o sbucket.o slist_test.o
linked_slist.o: linked_slist.c
	gcc -c linked_slist.c
slist_test.o: slist_test.c linked_slist.h sbucket.h
	gcc -c slist_test.c
sbucket.o: sbucket.c linked_slist.h
	gcc -c sbucket.c
run: all
	./slist
