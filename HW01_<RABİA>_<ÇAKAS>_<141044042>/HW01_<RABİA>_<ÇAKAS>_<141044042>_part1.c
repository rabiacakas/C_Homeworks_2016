/*****************************************************************************/
/*																			 */
/*	HW01_141044042_RABİA_ÇAKAS												 */
/*																			 */
/*	part1.c																	 */
/*---------																	 */
/*	Created on 05/10/2016 by Rabia Çakas									 */
/*																			 */
/*	Description																 */
/*-------------																 */
/*																			 */
/*	The part1.c converts the user’s numeric grades to letter grades.		 */
/* The program asks the user inputs when -1 is								 */
/* given,the user input is finished. If the first input is sentinel function */
/* return -1. For each input, the corresponding letter						 */
/* User inputs are converted the letter grade is printed.					 */
/* Once the user input is finished, the average of the numeric				 */
/* grade and letter grade is printed. 										 */
/*																			 */
/*****************************************************************************/
/*****************************************************************************/
/*					Includes												 */
/*****************************************************************************/
#include <stdio.h>
/*****************************************************************************/
/*					Defines													 */
/*****************************************************************************/
#define SENTINEL -1

int main(){
	
	int n, c, sum, avg;
	scanf("%d", &n);
	
	if(n==-1){
		printf("0 F\n");
		return -1;}
	
	c=0;
	sum=0;
	while(n != SENTINEL)
	{
		c++;
		sum=sum+n;
		
		if (n <60){
			printf("F\n");}
		else if ((n >=60) && (n <70)){
			printf("D\n");}
		else if ((n >=70) && (n <80)){
			printf("C\n");}
		else if ((n >=80) && (n <90)){
			printf("B\n");}
		else
			printf("A\n");
	

		scanf("%d", &n);
		
	}
	avg=sum/c;

	printf("%d ", avg);
	if (avg <60){
		printf("F\n");}
	else if ((avg >=60) && (avg <70)){
		printf("D\n");}
	else if ((avg >=70) && (avg <80)){
		printf("C\n");}
	else if ((avg >=80) && (avg <90)){
		printf("B\n");}
	else
		printf("A\n");

	return 0;

}
/*****************************************************************************/
/*					End of the part1.c										 */
/*****************************************************************************/



