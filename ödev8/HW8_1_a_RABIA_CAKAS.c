/******************************************************************************/
/*																			  */
/*	HW8_1_a_<RABIA>_<CAKAS>.c"												  */
/*																			  */
/*	HW8_1_a_<RABIA>_<CAKAS>.c												  */
/*---------																	  */
/*	Created on 15/12/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	Parametre olarak aldigi n degerini binary formuna donusturur ve print eder*/
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*								DEFINES										  */
/******************************************************************************/
#include <stdio.h>
/******************************************************************************/
/*							FUNCTION PROTOTYPE								  */
/******************************************************************************/
int recur_binary(int n);

int main(){

	int number, status;
	printf("Please enter a integer number ->\n");
	status=scanf("%d", &number);

	if(status!= 1){

		printf("ENTRY MUST BE INTEGER , PLEASE TRY AGAIN!\n");
		return -1;
	}
	if(number>=0)
	{
		recur_binary(number);
	}

	else
	{
		printf("(-)");
		number=number*-1;
		recur_binary(number);
		
	}
	printf("\n");
	return 0;
}
int recur_binary(int n){

	int remain, n2;

	if(n ==0 || n ==1){
		printf("%d", n);
		return 0;
	}

	else{

		remain = n%4;		
		n2=n/4;
		
		recur_binary(n2);
		printf("%d",remain);
	}
	
	return 0;
}
