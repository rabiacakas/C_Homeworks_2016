/******************************************************************************/
/*																			  */
/*	HW03_141044042_RABİA_ÇAKAS												  */
/*																			  */
/*	HW03_141044042_RABIA_CAKAS_part1.c										  */
/*---------																	  */
/*	Created on 30/10/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	 part1.c kullanicidan degree ve n degerlerini alarak Sinus Taylor 		  */
/*	Fonksiyonunu hesaplar.													  */
/*																			  */
/******************************************************************************/

/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include <stdio.h>

/******************************************************************************/
/*					Defines													  */
/******************************************************************************/
#define pi 3.14

/******************************************************************************/
/*					Function Prototypes										  */
/******************************************************************************/

void getInputs(int *degree, int *n);
/******************************************************************************/
/* 	void getInputs(int *degree, int *n);									  */
/*----------------------------------------------------------------------------*/
/* Kullanicidan formulde yerine konacak derece(degree) ve n degerlerini alir. */
/* Kullanici girisini saglar.												  */
/******************************************************************************/

double sine(int degree, int n);
/******************************************************************************/
/* 	double sine(int degree, int n);											  */
/*----------------------------------------------------------------------------*/
/*	Aldigi degree ve n parametreleriyle sinus Taylor fonksiyonunu hesaplar	  */
/*																			  */
/******************************************************************************/
double myPower(double degToRad, int n);

/******************************************************************************/
/* 	double myPower(double degToRad, int n);									  */
/*----------------------------------------------------------------------------*/
/*	math.h kutuphanesindeki pow fonksiyonu gibi calisir. Aldigi taban ve üs   */
/*	parametrelerle üs alma islemini gerceklestirir.							  */
/******************************************************************************/
int fac(int n);

/******************************************************************************/
/* int fac(int n);															  */
/*----------------------------------------------------------------------------*/
/*	Parametre olarak aldigi integer degerin faktoriyel formunu hesaplar ve 	  */
/*	return eder.															  */
/******************************************************************************/

int main(){

	int degree=0;
	int n=0;
	getInputs(&degree, &n);
	sine(degree, n);
	
	return 0;

}
double sine(int degree, int n){

	double degToRad=0.0;
	double pays=0.0;
	double p=0.0, i=0.0, k=0.0, l=0.0;
	degToRad= (double) degree* (pi/180);


	if(degree>360){

		degree=degree%360;
	}
	
	if(degree>=180 && degree<=360){

		degree=-degree;
	}

	for(p=0.0; p<n ; p++){
		
		i=(double) fac((2*p)+1);
		k=(double) myPower(-1, p);
		l=(double) myPower(degToRad, ((2*p)+1));
		pays += (k*l)/i;
	}

	printf("sin(%d) where n is %d = %.4f\n", degree, n, pays);
	return pays;
}
double myPower(double degToRad, int n){

	int i;
	double result=0.0;
	result=degToRad;

	if(n==0){
		return 1;
	}

	for(i=1; i<n ; ++i){

		result*=degToRad;

	}

	return result;
}
int fac(int n){

	int i, result;
	result=1;
	for(i=n; i>1 ; --i){

		result=result*i;
	
	}

	return result;
}
void getInputs(int *degree, int *n){

	printf("Please enter degree-->\n");
	scanf("%d", degree);
	printf("Please enter n value-->\n");
	scanf("%d", n);

	return;
}
/******************************************************************************/
/*			#	End of HW03_141044042_RABIA_CAKAS_part1.c	#	  			  */
/******************************************************************************/




