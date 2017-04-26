#ifndef sfrac_h
#define sfrac_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *sfrac_simplify(char *n);
char * sfrac_add(char * n1, char * n2);
char * sfrac_sub(char * n1, char * n2);
char * sfrac_negate(char * n);
char * sfrac_mult(char * n1, char * n2);
char * sfrac_div(char * n1, char * n2);
char * sfrac_fromdouble(double x, char *n);
double sfrac_todouble(char * x);
void sfrac_print(char *a1,char *n1, char *a2,char *n2, char *a3,char *n3, char *a4);
int min_value(int x, int y);
int gcd(int x, int y);
int myStoi(char *n);

#endif /*sfrac_h*/
