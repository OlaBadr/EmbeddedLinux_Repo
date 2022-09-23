mystaticexe : main.o myfuncs.h libmyfuncs.a
	@gcc -o mystaticexe main.o ./libmyfuncs.a
	@./mystaticexe
	
libmyfuncs.a : fact.o fib.o myrand.o
	@ar -rs libmyfuncs.a fact.o fib.o myrand.o
	
main.o : main.c
	@gcc -c main.c

fact.o : fact.c
	@gcc -c fact.c

fib.o : fib.c
	@gcc -c fib.c

myrand.o : myrand.c
	@gcc -c myrand.c
	
	
mydynamicexe : main.c fact.c fib.c myrand.c 
	@gcc -shared -fpic -o libmyfuncs.so fact.c fib.c myrand.c
	@gcc -o mydynamicexe main.c ./libmyfuncs.so
	@./mydynamicexe


clean : 
	-@rm -f *.o

	




























