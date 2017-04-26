/******************************************************************************/
/*																			  */
/*	HW8_1_b_<RABIA>_<CAKAS>.c"												  */
/*																			  */
/*	HW8_1_b_<RABIA>_<CAKAS>.c												  */
/*---------																	  */
/*	Created on 15/12/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	Parametre olarak aldigi x ve y degerlerini kullanarak pdf te verilen	  */
/*	recursive islemi gerceklestirir ve print eder					   		  */
/******************************************************************************/
/******************************************************************************/
/*								DEFINES										  */
/******************************************************************************/
#include <stdio.h>
/******************************************************************************/
/*							FUNCTION PROTOTYPE								  */
/******************************************************************************/
int f(int x, int y);
int main(){

	int main_kontrol;

	main_kontrol=f(2, 1);
	printf("main kontrol %d\n", main_kontrol);

	return 0;
}
int f(int x, int y){

	if (x> 0 && y > 0){

		return(f(x-1 , y) + f(x , y-1) + x + y);
	}

	else{

		return 0;
	}
}
