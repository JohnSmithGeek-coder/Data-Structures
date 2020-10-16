main : main.o cycliclist.o
	gcc main.o cycliclist.o -o main
cycliclist.o : cycliclist.c
	gcc cycliclist.c -c -o cycliclist.o
main.o : main.c
	gcc main.c -c -o main.o

.PHONY : clean
clean :
	del *.o main.exe -rf