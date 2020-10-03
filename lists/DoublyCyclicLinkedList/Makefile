main : main.o DCLList.o
	gcc main.o DCLList.o -o main
DCLList.o : DCLList.c
	gcc DCLList.c -c -o DCLList.o
main.o : main.c
	gcc main.c -c -o main.o

.PHONY : clean
clean :
	del *.o main.exe -rf