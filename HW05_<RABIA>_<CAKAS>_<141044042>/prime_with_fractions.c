/******************************************************************************/
/*																			  */
/*	HW05_141044042_RABİA_ÇAKAS												  */
/*																			  */
/*	HW05_<RABIA>_<CAKAS>_<141044042>_prime_with_fractions.c					  */
/*-------------------------------------------								  */
/*	Created on 19/11/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	HW05_<RABIA>_<CAKAS>_<141044042>_prime_with_fractions.c de				  */
/*HW05_<RABIA>_<CAKAS>_<141044042>_sfrac.h dosyasindaki fonksiyonlar kullanil-*/
/*mistir. Ilk 1000 prime number i bulup print eder.							  */
/*Kalan(%) yerine bolme sonucunun paydasinin 1 olma sonucunu kullandim.		  */
/*																			  */															
/*#### NOT:PROGRAMIN CALISMASININ BITME SURESI ORTALAMA 50 SANIYE SURUYOR.####*/
/*	Hızlandirmak icin denedigim birkac sey oldu fakat sureyi azaltamadim.	  */
/*													 						  */
/******************************************************************************/
/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include "HW05_<RABIA>_<CAKAS>_<141044042>_ sfrac.h"
#include "HW05_<RABIA>_<CAKAS>_<141044042>_ sfrac.c"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/******************************************************************************/
int main(){

	int count;
	double ic= 3,c;
	char n_first[1000];
	char n_second[1000];
	int i, j, x, k,ipay, ipayda=1, size, flag, flag1;
	char *n;
	char pay[1000];
	char payda[1000];
	
	printf("1. prime number is 2\n");
	count=1;
	while(count<1000){
		  for (c=2.0 ; c<=ic-1.0 ; c++)
		  {
			j=0, k=0, flag=0, flag1=0;
			sfrac_fromdouble(ic, n_first);
			sfrac_fromdouble(c, n_second);
			n=sfrac_div(n_first, n_second);
			
			size=strlen(n);
	
			for(i=0; n[i]!='/'; i++){
				if(n[i]=='/'){break;}		
				pay[j]=n[i];
				j++;
			}
			pay[j]='\0';
			
			if(pay[0]=='-'){
		
				sfrac_negate(pay);
				ipay=(-1)*myStoi(pay);
				if(size==2){
					payda[0]='1';
					payda[1]='\0';
					ipayda=myStoi(payda);
					flag=-1;
				}
		
			}
	
			else{
			ipay=myStoi(pay);}

			if(size==1){

				payda[0]='1';
				payda[1]='\0';
				ipayda=myStoi(payda);
				flag1=-1;
			}
	
			for(x=j+1; n[x]!='\0'; x++){
				if(n[x]=='\0'){break;}		
				payda[k]=n[x];
				k++;
			}
			payda[k]='\0';
			if(payda[0]=='-'){
		
				sfrac_negate(payda);
				ipay=(-1)*myStoi(pay);
				ipayda=myStoi(payda);
			}
			
			if((flag!=-1) &&(flag1!=-1)){
			ipayda=myStoi(payda);}
	
			if(ipayda==0 && ipay!=0){
				printf("Error denominator number, can not be 0!\n");
				return 0;
			}
			
			if(ipayda==1){
				break;
			}
		}
		 	if ( c == ic )
		  {
		     printf("%d. prime number is %.0f\n",count+1,ic);
		     count++;
		  }
		  ic++;
	}

	return 0;
}

