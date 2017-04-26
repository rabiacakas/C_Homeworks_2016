#include "HW05_<RABIA>_<CAKAS>_<141044042>_ sfrac.h"
#include "HW05_<RABIA>_<CAKAS>_<141044042>_ sfrac.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(){
	char n_first[100];
	char operationn;
	char *operation;
	char n_second[100];
	char n_t[100];
	char n_temp[100];
	char *n1;
	char *n2;
	char *n3, a1[10], a3[10], a4[10];
	double deneme1, deneme2;
	int i=0,j=0, k=0;
	
	a1[i]='R';
	a1[i+1]='e';
	a1[i+2]='s';
	a1[i+3]='u';
	a1[i+4]='l';
	a1[i+5]='t';
	a1[i+6]='=';
	a1[i+7]='\0';

	a3[j]='?';
	a3[j+1]='=';
	a3[j+2]='?';
	a3[j+3]='\0';
	
	a4[k]='.';
	a4[k+1]='\0';
	printf("Input your operation: ");
	scanf("%s", n_first);
	strcpy(n_temp,n_first);
	scanf(" %c", &operationn);
	scanf("%s",n_second);
	operation=&operationn;
	n1=sfrac_simplify(n_first);
	n2=sfrac_simplify(n_second);
	deneme1=sfrac_todouble(n_first);
	deneme2=sfrac_todouble(n_second);
	sfrac_fromdouble(deneme1, n_t);
	sfrac_fromdouble(deneme2, n_t);
	switch(operationn){
	case '+':
			printf("Result is:  %s\n", n3=sfrac_add(n1, n2));
			sfrac_print(a1, n_temp, operation , n2, a3, n3, a4);
			break;
	case '-':
			printf("Result is:  %s\n", n3=sfrac_sub(n1, n2));
			sfrac_print(a1, n_temp, operation , n2, a3, n3, a4);
			break;
	case '*':
			printf("Result is:  %s\n", n3=sfrac_mult(n1, n2));
			sfrac_print(a1, n_temp, operation , n2, a3, n3, a4);
			break;
	case ':':
			printf("Result is:  %s\n", n3=sfrac_div(n1, n2));
			sfrac_print(a1, n_temp, operation , n2, a3, n3, a4);
			break;
	default:
			printf("Operator can be--> +, -, * or : !\n");
	}
	
	return 0;
}
