#include "runge_kutta.h"
#include <stdio.h>

static const int INTERVALS = 100;

double derivative(double x, double y)
{
	return (-2.0 * x * y);
}

int main(void)
{
	struct runge_kutta_array array;
	runge_kutta_array_init(&array, INTERVALS + 1, 2.0);
	const double lhs = 0.0;
	const double rhs = 2.0;
	const double h = (rhs - lhs) / INTERVALS;
	const double x_0 = 0.0;

	runge_kutta_4(&array, derivative, h, INTERVALS, x_0);
	printf("Value at x_%i (%f): %f\n", INTERVALS, rhs, array._y[INTERVALS]);

	runge_kutta_2(&array, derivative, h, INTERVALS, x_0);
	printf("Value at x_%i (%f): %f\n", INTERVALS, rhs, array._y[INTERVALS]);

	runge_kutta_array_free(&array);
	return 0;
}
