rk: main.c runge_kutta.o
	gcc -o rk main.c runge_kutta.o
runge_kutta.o: runge_kutta.c
	gcc -c runge_kutta.c
clean:
	rm *.o rk
run: rk
	./rk
