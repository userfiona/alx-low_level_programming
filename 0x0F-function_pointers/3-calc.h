#ifndef _3_CALC_H_
#define _3_CALC_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct op - struct op
 *
 * @op: the opreator
 * @f: function associated
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

int(*get _op_fun(char *s))(int,int);

#endif
