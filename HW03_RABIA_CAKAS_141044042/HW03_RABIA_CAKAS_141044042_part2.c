/******************************************************************************/
/*																			  */
/*	HW03_141044042_RABİA_ÇAKAS												  */
/*																			  */
/*	HW03_141044042_RABIA_CAKAS_part2.c										  */
/*---------																	  */
/*	Created on 30/10/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	 part2.c kullanicidan x degerini alarak girilen fonksiyonlarin turevlerini*/
/* hesaplar.																  */
/*																			  */
/******************************************************************************/

/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include <stdio.h>
#include <math.h>
/******************************************************************************/
/*					Defines													  */
/******************************************************************************/
#define pi 3.14
#define e 2.718
/******************************************************************************/
/*					Function Prototypes										  */
/******************************************************************************/

int user_agreement();
/******************************************************************************/
/* 	int user_agreement();													  */
/*----------------------------------------------------------------------------*/
/* Kullanici girisini saglar ve bilgilendirme yapar.						  */
/******************************************************************************/

int constant_derivative();
/******************************************************************************/
/* 	int constant_derivative();												  */
/*----------------------------------------------------------------------------*/
/*	Kullanici yalnizca constant deger girecekse bu fonk nu kullanir, 		  */
/*	sonuc 0 olacaktir.														  */
/******************************************************************************/
int square_derivative(int x);

/******************************************************************************/
/* int square_derivative(int x);											  */
/*----------------------------------------------------------------------------*/
/*	Kullanici eger x^2 li polinomik bir fonksiyon girecekse bu secenegi secer */
/*	türevi hesaplar return eder.											  */
/******************************************************************************/
int exponential_func(int x);

/******************************************************************************/
/* int exponential_func(int x);												  */
/*----------------------------------------------------------------------------*/
/*	e^x veya a^x gibi fonksiyonlarin turevini hesaplamak uzere olusturulmustur*/
/*	Kullanici bu tip bir fonk girecekse bu fonk nu kullanmalidir.			  */
/******************************************************************************/

int logarithms_func(int x);
/******************************************************************************/
/* int logarithms_func(int x);												  */
/*----------------------------------------------------------------------------*/
/*	lnx veya logx gibi fonkların turevini hesaplamak uzere olusturulmustur.	  */
/*	Kullanici bu tip bir fonk girecekse bu fonk nu kullanmalidir.			  */
/******************************************************************************/
int trigonometry_func(int x);
/******************************************************************************/
/* int trigonometry_func(int x);											  */
/*----------------------------------------------------------------------------*/
/*	sinx cosx ve tanx gibi fonkların turevini hesaplamak uzere olusturulmustur*/
/*	Kullanici bu tip bir fonk girecekse bu fonk nu kullanmalidir.			  */
/******************************************************************************/
int inverse_tri(int x);
/******************************************************************************/
/* int inverse_tri(int x);													  */
/*----------------------------------------------------------------------------*/
/*sin-1 cos-1 ,tan-1 gibi fonkların turevini hesaplamak uzere olusturulmustur */
/*	Kullanici bu tip bir fonk girecekse bu fonk nu kullanmalidir.			  */
/******************************************************************************/

int main(){
	int choice;
	int x;
	
	while(choice!=-1){

		user_agreement();
		scanf("%d", &choice);
	
		if(choice!=-1 && choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6){
			printf("WRONG ENTRY PLEASE RETURN AGAIN!\n");
			break;
		}
		if(choice!=1 && choice!=-1)
		{
			printf("Please enter x number to use: \n");
			scanf("%d", &x);
		}
		if(choice==1)
		{
			constant_derivative();
		}
		if(choice==2)
		{
			square_derivative(x);
		}

		if(choice==3)
		{
			exponential_func(x);
		}
		if(choice==4)
		{
			logarithms_func(x);
		}
		if(choice==5){

			trigonometry_func(x);
		}
		if(choice==6){

			inverse_tri(x);		
		}

	
}
	return 0;

}
int user_agreement(){

	printf("WELCOME TO THE RABIA CAKAS'S DERIVATIVE PROGRAM!\n");
	printf("Please choose one and continue: \n");
	printf("* CONSTANT ONLY * --> [1]\n");
	printf("* WITH SQUARE FUNCTION * --> [2]\n");
	printf("* WITH EXPONENTIAL FUNCTION * --> [3]\n");
	printf("* WITH LOGARITHMS FUNCTION * --> [4]\n");
	printf("* WITH TRIGONOMETRY FUNCTION * --> [5]\n");
	printf("* WITH INVERSE TRIGONOMETRY FUNCTION * --> [6]\n");
	printf("* TO EXIT * --> [-1]\n");

	return 0;

}
int constant_derivative(){

	printf("The result is: 0\n");
	return 0;

}
int square_derivative(int x){
	
	int first_constant;
	char ch;
	int to_power;
	int result;
	printf("Please enter the form of -->\nfirst_constant\n*\n%d\n^\nto_power\n", x);
	scanf("%d", &first_constant);
	scanf(" %c", &ch);
	scanf("%d", &to_power);
	if(ch=='^')
	{
		result=(first_constant * to_power * pow(x, to_power-1));
		printf("The result is %d\n", result);
		return result;

	}
	else{
		printf("THE FORM OF WRONG PLEASE TRY AGAIN!\n");
		return -1;
	}
	return 0;
}
int exponential_func(int x){
	
	int first_constant;
	char f_control;
	int f_control_i;
	int ex;
	int note;
	char op;
	double a,result, result1;

	printf("Please enter the form of -->\nfirst_constant * e or other integer number ^ %d to_power\n", x);
	scanf("%d", &first_constant);
	scanf("%c", &f_control);
	ex = scanf("%c", &f_control);
	if(f_control!='e' && ex!=0)
	{
		scanf("%d", &f_control_i);
	}

	note = scanf("%d", &f_control_i);
	scanf(" %c", &op);

	if(ex==1 && f_control=='e' && note==0 && op=='^')
	{	
		a=pow(e, x);
		printf("a---%.2f\n", a);
		result= first_constant * pow(e, x);
		printf("The exponential function result is: %.2f\n", result);
		return result;
	}
	
	if(ex==1 && note==1 && op=='^')
	{
		result1=(first_constant * log(f_control_i) * pow(f_control_i, x));
		printf("Second form of exponential function result is: %.2f\n", result1);
		return result1;

	}
	return 0;

}
int logarithms_func(int x){
	
	char first, second, third, op;
	int constant, base;
	double result1, result2,a;
	scanf("%d", &constant);
	scanf(" %c", &first);
	scanf(" %c", &second);
	if(first=='l' && second=='o')
	{
		scanf(" %c", &third);
	}
	scanf(" %c", &op);
	scanf("%d", &base);
	
	if(first=='l' && second=='n' && op=='^')
	{	
		result1=(double)constant/x;
		printf("Logarithms_func result is %.2f\n", result1);
	}
	else if(first=='l' && second=='o' && third=='g' && op=='^')
	{
		a=x*log(base);
		printf("%f", a);
		result2= constant * (1/ a);
		printf("Logarithms_func result is %.2f\n", result2);
	}
	return 0;
}
int trigonometry_func(int x){
	char arr[10];
	int i, first_constant;
	double deg;
	double res, result;
	deg = (x*(pi/180));
	printf("Please entry that form of--> first_constant, sin cos or tan\n");
	scanf("%d", &first_constant);
	for(i=0; i<3 ; ++i){

		scanf(" %c", &(arr[i]));
	}
	
	if(arr[0]=='s' && arr[1]=='i' && arr[2]=='n')
	{
		result=first_constant*cos(deg);
		printf("Trigonometry_func result is %.2f\n", result);	
	}

	else if(arr[0]=='c' && arr[1]=='o' && arr[2]=='s'){
	
		result=first_constant* (- sin(deg));
		printf("Trigonometry_func result is %.2f\n", result);
	}

	else if(arr[0]=='t' && arr[1]=='a' && arr[2]=='n'){
		res= tan(deg);
		result=first_constant*( 1+ (res* res));
		printf("Trigonometry_func result is %.2f\n", result);
	}

	else
	{
		printf("Wrong entry please try again!\n");
		return -1;
	}
	return 0;
}
int inverse_tri(int x){
	char arr[10];
	int i, first_constant;
	double res, res1, result;
	
	printf("Please entry that form of--> first_constant, sin-1 cos-1 or tan-1\n");
	scanf("%d\n", &first_constant);
	for(i=0; i<5 ; ++i){

		scanf(" %c", &(arr[i]));
	}
	
	if(arr[0]=='s' && arr[1]=='i' && arr[2]=='n' && arr[3]=='-' && arr[4]=='1'){

		res=(1- (x*x));
		if(res<0){
			res=-res;
		}
		res1= sqrt(res);
		result= (1/ res1);
		printf("Inverse_tri function result is %.2f\n",result);
	}
	else if(arr[0]=='c' && arr[1]=='o' && arr[2]=='s' && arr[3]=='-' && arr[4]=='1'){
		res=(1- (x*x));
		if(res<0){
			res=-res;
		}
		res1= sqrt(res);
		result= -(1/ res1);
		printf("Inverse_tri function result is %.2f\n",result);

	}
	else if(arr[0]=='t' && arr[1]=='a' && arr[2]=='n' && arr[3]=='-' && arr[4]=='1'){
		res=(1+ (x*x));
		result=(1/res);
		printf("Inverse_tri function result is %.2f\n",result);

	}
	else
	{

		printf("Wrong entry please try again!\n");
		return -1;
	}

	return 0;
}
/******************************************************************************/
/*				# End of HW03_141044042_RABIA_CAKAS_part2.c	#				  */
/******************************************************************************/













