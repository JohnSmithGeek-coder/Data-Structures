main : main.o list.o
	gcc main.o list.o -o main
list.o : list.c
	gcc list.c -c -o list.o
main.o : main.c
	gcc main.c -c -o main.o

.PHONY : clean
clean : 
	del *.o main.exe -rf