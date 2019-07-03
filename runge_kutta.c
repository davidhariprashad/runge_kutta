#include "runge_kutta.h"

void runge_kutta_array_init(struct runge_kutta_array* const array, const int size, const double y_0)
{
	array->_size = size;
	array->_y = (double*)malloc(array->_size * sizeof(double));
	array->_y[0] = y_0;
	return;
}

void runge_kutta_array_free(struct runge_kutta_array* const array)
{
	free(array->_y);
	return;
}

void runge_kutta_4(
	struct runge_kutta_array* const array,
	double (*dy_dx)(const double x, const double y),
	const double h,
	const int n,
	const double x_0)
{
	double x_i;
	double g_1, g_2, g_3, g_4;
	int i = 0;
	while (i <  n)
	{
		x_i = x_0 + i * h;
		g_1 = dy_dx(x_i, array->_y[i]);
		g_2 = dy_dx(x_i + 0.5 * h, array->_y[i] + 0.5 * h * g_1);
		g_3 = dy_dx(x_i + 0.5 * h, array->_y[i] + 0.5 * h * g_2);
		g_4 = dy_dx(x_i + h, array->_y[i] + h * g_3);
		array->_y[i + 1] = array->_y[i] + (h / 6.0) * (g_1 + 2.0 * g_2 + 2.0 * g_3 + g_4);
		//printf("%f, %f\n", x_i, array->_y[i]);
		++i;
	}
	return;
}

void runge_kutta_2(
	struct runge_kutta_array* const array,
	double (*dy_dx)(const double x, const double y),
	const double h,
	const int n,
	const double x_0)
{
	double x_i;
	double g_1, g_2;
	int i = 0;
	while (i < n)
	{
		x_i = x_0 + i * h;
		g_1 = h * dy_dx(x_i, array->_y[i]);
		g_2 = h * dy_dx(x_i + 0.5 * h, array->_y[i] + 0.5 * g_1);
		array->_y[i + 1] = array->_y[i] + g_2;
		//printf("%f, %f\n", x_i, array->_y[i]);
		++i;
	}
	return;
}
