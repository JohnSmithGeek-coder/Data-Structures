main : main.o DLList.o
	gcc main.o DLList.o -o main
DLList.o : DLList.c
	gcc DLList.c -c -o DLList.o
main.o : main.c
	gcc main.c -c -o main.o

.PHONY : clean
clean :
	del *.o main.exe -rf