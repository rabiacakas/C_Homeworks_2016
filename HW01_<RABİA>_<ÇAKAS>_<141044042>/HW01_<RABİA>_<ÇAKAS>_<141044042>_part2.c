/*****************************************************************************/
/*																			 */
/*	HW01_141044042_RABİA_ÇAKAS												 */
/*																			 */
/*	part2.c																	 */
/*---------																	 */
/*	Created on 05/10/2016 by Rabia Çakas									 */
/*																			 */
/*	Description																 */
/*-------------																 */
/*	The part2.c does simple arithmetic calculations. The allowed 			 */
/*  calculations are ‘+’, ‘-‘, ‘*’, and ‘\‘.								 */
/*  The operations will be applied as they come in.							 */
/*  For example “a+b*c+d” will be calculated as ((a+b)*c)+d.				 */
/*																			 */
/*																			 */
/*****************************************************************************/
/*****************************************************************************/
/*					Includes												 */
/*****************************************************************************/
#include<stdio.h>

int main(){
	
	int number1, number2, result;
	char operand;
	scanf("%d", &number1);
	scanf(" %c", &operand);
	
	result=0;
	while(operand != '='){
		
		scanf("%d", &number2);
		
		if(operand=='+'){
			result=number1+number2;
				}
		else if(operand=='-'){
			result=number1-number2;
				}
		else if(operand=='*'){
			result=number1*number2;
				}
		else if(operand=='/'){
			result=number1/number2;
				}

		number1=result;

		scanf(" %c", &operand);
		
	}

	printf("%d\n", result);
	

	return 0;
}

/*****************************************************************************/
/*					End of the part2.c										 */
/*****************************************************************************/
