#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H

#include <stdio.h>
#include <stdlib.h>

struct runge_kutta_array
{
	double* _y;
	int _size;
};

void runge_kutta_array_init(struct runge_kutta_array* const, const int, const double);
void runge_kutta_array_free(struct runge_kutta_array* const);

void runge_kutta_4(struct runge_kutta_array* const,
	double (*)(const double x, const double y),
	const double,
	const int,
	const double);

void runge_kutta_2(struct runge_kutta_array* const,
	double (*)(const double x, const double y),
	const double,
	const int,
	const double);

#endif
