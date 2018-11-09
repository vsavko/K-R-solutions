#include <stdio.h>
#include "calc.h"
#define MAXVAL 1000

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack overflow, %g doesn't fit\n", f);
}

/* pop: взять с вершины стека и выдать в качестве результата */
double pop(void)
{
	double temp;
	
	if (sp > 0){
		temp = val[--sp];
		val[sp] = 0;
		return temp;

	}
	else {
		printf ("error: stack empty\n");
		return 0.0;
	}
}