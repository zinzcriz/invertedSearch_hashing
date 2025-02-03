OBJ=$(patsubst %.c,%.o,$(wildcard *.c))
run.exe : $(OBJ)
	gcc -o $@ $^
clean :
	rm *.o