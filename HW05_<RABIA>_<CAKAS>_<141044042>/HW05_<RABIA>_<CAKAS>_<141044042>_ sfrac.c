/******************************************************************************/
/*																			  */
/*	HW05_141044042_RABİA_ÇAKAS												  */
/*																			  */
/*	HW05_<RABIA>_<CAKAS>_<141044042>_sfrac.c								  */
/*-------------------------------------------								  */
/*	Created on 19/11/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	HW05_<RABIA>_<CAKAS>_<141044042>_sfrac.c de								  */
/*HW05_<RABIA>_<CAKAS>_<141044042>_sfrac.h  dosyasindaki fonksiyonlarin		  */
/*implementation lari yer alir. Odev pdf 'inde yer almayan helper fonksiyonlar*/
/*kullanilmistir.			 												  */
/*														  		              */										
/*int min_value(int x, int y);->gcd fonksiyonunda x ve y degerlerinden minimum*/
/*olanini dondurur.															  */
/*int gcd(int x, int y);->ortak bolenlerin en buyugunu bulur ve return eder.  */
/*int myStoi(char *n);->char array alir ve integer degerini return eder.	  */
/*													 						  */
/******************************************************************************/
/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "HW05_<RABIA>_<CAKAS>_<141044042>_ sfrac.h"
/******************************************************************************/
/*					Function Implementations								  */
/******************************************************************************/
/*char *sfrac_simplify(char *n);											  */
/*-------------------------------											  */
/*Bu fonksiyon n array ini parametre olarak alir, pay ve payda olmak uzere iki*/
/*kisma ayirir, fractional array i degerlerine ulasmak amaciyla parcalar,	  */
/*karakterlerin integer degerlerini hesaplar ve ortak bolenlerin en buyugunu  */
/*bukarak ayirdigi pay ve paydayi max ortak bolene boler,bu sekilde sadelestir*/
/*me islemini yapar, sadelestirdigi array i return eder.					  */
/******************************************************************************/
/******************************************************************************/
/*char * sfrac_add(char * n1, char * n2);									  */
/*-------------------------------											  */
/* Bu fonksiyon n1 ve n2 arraylerini parametre olarak alir, rasyonel sayilarda*/
/*toplama islemini gerceklestirir, sonucu n1 array ine atar ve return eder.	  */
/*n1 ve n2 array leri sadelesmis bicimde fonksiyona gelir ve yine sadelestiril*/
/*dikten sonra return edilir.												  */
/******************************************************************************/
/******************************************************************************/
/*char * sfrac_sub(char * n1, char * n2);									  */
/*-------------------------------											  */
/* Bu fonksiyon n1 ve n2 arraylerini parametre olarak alir, rasyonel sayilarda*/
/*cikarma islemini gerceklestirir, sonucu n1 array ine atar ve return eder.	  */
/*n1 ve n2 array leri sadelesmis bicimde fonksiyona gelir ve yine sadelestiril*/
/*dikten sonra return edilir.												  */
/******************************************************************************/
/******************************************************************************/
/*char * sfrac_negate(char * n);											  */
/*-------------------------------											  */
/*Bu fonksiyon eger char * n in ilk index elemani yani n[0]=='-' ise cagirilir*/
/*Hesaplamalarda ve donusumlerde '-' karakterin sonucu etkilememesi icin -	  */
/*silinip return edilir,integer deger hesaplanirken -1le carpilarak fractional*/
/*sayinin - hali elde edlimis olur.											  */
/******************************************************************************/
/******************************************************************************/
/*char * sfrac_mult(char * n1, char * n2);									  */
/*-------------------------------											  */
/* Bu fonksiyon n1 ve n2 arraylerini parametre olarak alir, rasyonel sayilarda*/
/*carpma islemini gerceklestirir, sonucu n1 array ine atar ve return eder.	  */
/*n1 ve n2 array leri sadelesmis bicimde fonksiyona gelir ve yine sadelestiril*/
/*dikten sonra return edilir.												  */
/******************************************************************************/
/******************************************************************************/
/*char * sfrac_div(char * n1, char * n2);									  */
/*-------------------------------											  */
/* Bu fonksiyon n1 ve n2 arraylerini parametre olarak alir, rasyonel sayilarda*/
/*bolme islemini gerceklestirir, sonucu n1 array ine atar ve return eder.	  */
/*n1 ve n2 array leri sadelesmis bicimde fonksiyona gelir ve yine sadelestiril*/
/*dikten sonra return edilir.												  */
/******************************************************************************/
/******************************************************************************/
/*char * sfrac_fromdouble(double x, char *n);								  */
/*-------------------------------											  */
/* Bu fonksiyon double x parametresini alir, fractional sayiya donusturur	  */
/* bunu char *n e atar ve return eder.										  */
/******************************************************************************/
/******************************************************************************/
/*double sfrac_todouble(char * x);											  */
/*-------------------------------											  */
/* Bu fonksiyon char array i alir double bir sayiya cevirir ve return eder.	  */
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*void sfrac_print(char*a1,char*n1,char*a2,char*n2,char*a3,char*n3,char*a4);  */
/*-------------------------------											  */
/* Bu fonksiyon mainde tanimlanan a1, a2 ve a3 array leri ile isleme giren n1 */
/* n2 array lerini ve n3 olarak tanimlanan sonuc array ini alir odev pdf inde */
/* belirlenen sekilde print eder.											  */
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*int min_value(int x, int y);												  */
/*-------------------------------											  */
/* Bu fonksiyon gcd fonksiyonunda kullanilacak bir degerin belirlenmesi		  */
/* amaciyla olusturulmustur. int x ve y degerlerini alir, hangisi daha kucukse*/
/* onu return eder.															  */
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*int gcd(int x, int y);													  */
/*-------------------------------											  */
/*Bu fonksiyon sadelestirme islemini gerceklestirmek icin aldigi iki parametre*/
/*nin en buyuk ortak bolenini bulur ve return eder.							  */
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*int myStoi(char *n);														  */
/*-------------------------------											  */
/*	Bu fonksiyon aldigi karakter array in integer degerini hesaplar ve return */
/*	eder. 																	  */
/******************************************************************************/
char *sfrac_simplify(char *n){

	int i,j=0,x,k=0,ipay,ipayda,gc,sonpay,sonpayda,f,f2,d,size,flag=0,flag1=0;
	char pay[100];
	char payda[100];
	char sonpayar[100];
	char sonpaydaar[100];
	char sade[100];

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
	ipayda=myStoi(payda);
	}
	
	gc=gcd(ipay, ipayda);
	if(ipayda==0){
		printf("Error denominator number, can not be 0!\n");
		exit(1);
	}

	sonpay=ipay/gc;
	sonpayda=ipayda/gc;
	sprintf(sonpayar, "%d", sonpay);
	sprintf(sonpaydaar, "%d", sonpayda);
	
	f2=strlen(sonpaydaar);
	strcpy(sade, sonpayar);
	f=strlen(sade);
	sade[f]='/';
	for(d=0; d<f2; d++){

		sade[f+1]=sonpaydaar[d];
			f++;
	}
	sade[f+1]='\0';
	strcpy(n, sade);
	return n;
}
char * sfrac_add(char * n1, char * n2){
	int first_frac_pay, first_frac_payda, second_frac_pay,second_frac_payda, i,
 j=0, x, k=0, h, m=0,d=0, y,result_pay, result_payda, f, f2, gc, sonpay, sonpayda;
	char first_pay[100], first_payda[100], second_pay[100], second_payda[100];
	char sonpayar[100];
	char sonpaydaar[100];
	char result_sade[100];

	for(i=0;n1[i]!='/'; i++){
		if(n1[i]=='/'){break;}		
		first_pay[j]=n1[i];
		j++;
	}
	first_pay[j]='\0';
	if(first_pay[0]=='-'){
		
		sfrac_negate(first_pay);
		first_frac_pay=(-1)*myStoi(first_pay);
	}
	else{
	first_frac_pay=myStoi(first_pay);}

	for(x=j+1; n1[x]!='\0'; x++){
		if(n1[x]=='\0'){break;}		
		first_payda[k]=n1[x];
		k++;
	}
	first_payda[k]='\0';
	if(first_payda[0]=='-'){
		
		sfrac_negate(first_payda);
		first_frac_payda=(-1)*myStoi(first_payda);
	}
	else{
	first_frac_payda=myStoi(first_payda);}

	for(h=0;n2[h]!='/'; h++){
		if(n2[h]=='/'){break;}		
		second_pay[m]=n2[h];
		m++;
	}
	second_pay[m]='\0';
	if(second_pay[0]=='-'){
		
		sfrac_negate(second_pay);
		second_frac_pay=(-1)*myStoi(second_pay);
	}
	else{
	second_frac_pay=myStoi(second_pay);}

	for(y=m+1; n2[y]!='\0'; y++){
		if(n2[y]=='\0'){break;}		
		second_payda[d]=n2[y];
		d++;
	}
	second_payda[d]='\0';
	if(second_payda[0]=='-'){
		
		sfrac_negate(second_payda);
		second_frac_payda=(-1)*myStoi(second_payda);
	}
	else{
	second_frac_payda=myStoi(second_payda);}

	if(first_frac_payda==second_frac_payda)
	{
		result_pay=first_frac_pay+second_frac_pay;
		result_payda=first_frac_payda;
	}
	else{

		result_pay=(second_frac_payda*first_frac_pay)+(first_frac_payda*second_frac_pay);
		result_payda=(first_frac_payda*second_frac_payda);

	}

	gc=gcd(result_pay, result_payda);
	sonpay=result_pay/gc;
	sonpayda=result_payda/gc;
	sprintf(sonpayar, "%d", sonpay);
	sprintf(sonpaydaar, "%d", sonpayda);
	
	f2=strlen(sonpaydaar);
	strcpy(result_sade, sonpayar);
	f=strlen(result_sade);
	result_sade[f]='/';
	for(d=0; d<f2; d++){

		result_sade[f+1]=sonpaydaar[d];
			f++;
	}
	result_sade[f+1]='\0';
	strcpy(n1, result_sade);
	
	return n1;	


}
char * sfrac_sub(char * n1, char * n2){

	int first_frac_pay, first_frac_payda, second_frac_pay,second_frac_payda, i,
	j=0,x,k=0,h, m=0,d=0, y,result_pay, result_payda, f, f2,gc,sonpay,sonpayda,
	flag2=0, flag3=0;
	char first_pay[100], first_payda[100], second_pay[100], second_payda[100];
	char sonpayar[100];
	char sonpaydaar[100];
	char result_sade[100];

	for(i=0;n1[i]!='/'; i++){
		if(n1[i]=='/'){break;}		
		first_pay[j]=n1[i];
		j++;
	}
	first_pay[j]='\0';
	for(x=j+1; n1[x]!='\0'; x++){
		if(n1[x]=='\0'){break;}		
		first_payda[k]=n1[x];
		k++;
	}
	first_payda[k]='\0';

	for(h=0;n2[h]!='/'; h++){
		if(n2[h]=='/'){break;}		
		second_pay[m]=n2[h];
		m++;
	}
	second_pay[m]='\0';
	for(y=m+1; n2[y]!='\0'; y++){
		if(n2[y]=='\0'){break;}		
		second_payda[d]=n2[y];
		d++;
	}
	second_payda[d]='\0';
	if(first_pay[0]=='-')
	{
		sfrac_negate(first_pay);
		first_frac_pay=(-1)*myStoi(first_pay);
		flag2=-1;
	}
	if(flag2!=-1){
	first_frac_pay=myStoi(first_pay);
	}
	first_frac_payda=myStoi(first_payda);
	if(second_pay[0]=='-')
	{
		sfrac_negate(second_pay);
		second_frac_pay=(-1)*myStoi(second_pay);
		flag3=-1;
	}
	if(flag3!=-1){
	second_frac_pay=myStoi(second_pay);
	
	}
	second_frac_payda=myStoi(second_payda);
	if(first_frac_payda==second_frac_payda)
	{
		result_pay=first_frac_pay-second_frac_pay;
		result_payda=first_frac_payda;

	}
	else{

		result_pay=(second_frac_payda*first_frac_pay)-(first_frac_payda*second_frac_pay);
		result_payda=(first_frac_payda*second_frac_payda);

	}
	
	gc=gcd(result_pay, result_payda);
	sonpay=result_pay/gc;
	sonpayda=result_payda/gc;
	sprintf(sonpayar, "%d", sonpay);
	sprintf(sonpaydaar, "%d", sonpayda);
	
	f2=strlen(sonpaydaar);
	strcpy(result_sade, sonpayar);
	f=strlen(result_sade);
	result_sade[f]='/';
	for(d=0; d<f2; d++){

		result_sade[f+1]=sonpaydaar[d];
			f++;
	}
	result_sade[f+1]='\0';
	strcpy(n1, result_sade);
	
	return n1;	


}
int myStoi(char *n)
{
    int convert, i;
 	convert=0;
    for(i=0; n[i] !='\0'; ++i)
	{
        convert=(convert*10 +n[i] - '0');
	}

    return convert;
}
int gcd(int x, int y){

	int gcd=1,i, temp, mutlakx, mutlaky;
	mutlaky=abs(y);
	mutlakx=abs(x);
	if(mutlakx==mutlaky){
		gcd=mutlakx;
	}
	if(abs(x)==abs(y)){
		gcd=1;
	}
	temp=abs(min_value(x, y));
	i=2;
	while(i<=temp){
		if((x%i==0) && (y%i==0)){
			gcd=gcd*i;
			x=x/i;
			y=y/i;
		}
		else
			i++;
	}
	/*printf("gcd: %d\n", gcd);*/
	return gcd;

}
int min_value(int x, int y){

	int minim;
	if(x< y){
		minim=x;
	}
	else if(x>y){
		minim=y;
	}
	else{
		minim=x;
	}
	return minim;
}
char * sfrac_negate(char * n){
	char new_array[100];
	int i,size,h=0;
	size=strlen(n);
	
	for(i=1;i<size; i++){
		new_array[h]=n[i];
		h++;
	}
	new_array[h]='\0';
	
	strcpy(n, new_array);
	return n;
}
char * sfrac_mult(char * n1, char * n2){

	int first_frac_pay, first_frac_payda, second_frac_pay,second_frac_payda, 
	i,j=0,x,k=0,h,m=0,d=0,y,result_pay,result_payda,f,f2,gc,sonpay,sonpayda;

	char first_pay[100], first_payda[100], second_pay[100], second_payda[100];
	char sonpayar[100];
	char sonpaydaar[100];
	char result_sade[100];

	for(i=0;n1[i]!='/'; i++){
		if(n1[i]=='/'){break;}		
		first_pay[j]=n1[i];
		j++;
	}
	first_pay[j]='\0';
	if(first_pay[0]=='-'){
		
		sfrac_negate(first_pay);
		first_frac_pay=(-1)*myStoi(first_pay);
	}
	else{
	first_frac_pay=myStoi(first_pay);}

	for(x=j+1; n1[x]!='\0'; x++){
		if(n1[x]=='\0'){break;}		
		first_payda[k]=n1[x];
		k++;
	}
	first_payda[k]='\0';
	if(first_payda[0]=='-'){
		
		sfrac_negate(first_payda);
		first_frac_payda=(-1)*myStoi(first_payda);
	}
	else{
	first_frac_payda=myStoi(first_payda);}

	for(h=0;n2[h]!='/'; h++){
		if(n2[h]=='/'){break;}		
		second_pay[m]=n2[h];
		m++;
	}
	second_pay[m]='\0';
	if(second_pay[0]=='-'){
		
		sfrac_negate(second_pay);
		second_frac_pay=(-1)*myStoi(second_pay);
	}
	else{
	second_frac_pay=myStoi(second_pay);}

	for(y=m+1; n2[y]!='\0'; y++){
		if(n2[y]=='\0'){break;}		
		second_payda[d]=n2[y];
		d++;
	}
	second_payda[d]='\0';
	if(second_payda[0]=='-'){
		
		sfrac_negate(second_payda);
		second_frac_payda=(-1)*myStoi(second_payda);
	}
	else{
	second_frac_payda=myStoi(second_payda);}


	result_pay=(second_frac_pay*first_frac_pay);
	result_payda=(first_frac_payda*second_frac_payda);
	gc=gcd(result_pay, result_payda);
	sonpay=result_pay/gc;
	sonpayda=result_payda/gc;
	sprintf(sonpayar, "%d", sonpay);
	sprintf(sonpaydaar, "%d", sonpayda);
	
	f2=strlen(sonpaydaar);
	strcpy(result_sade, sonpayar);
	f=strlen(result_sade);
	result_sade[f]='/';
	for(d=0; d<f2; d++){

		result_sade[f+1]=sonpaydaar[d];
			f++;
	}
	result_sade[f+1]='\0';
	strcpy(n1, result_sade);
	
	return n1;	

}
char * sfrac_div(char *n1, char *n2){

	int first_frac_pay, first_frac_payda, second_frac_pay,second_frac_payda,
	i,j=0,x,k=0,h,m=0,d=0,y,result_pay,result_payda,f,f2,gc,sonpay,sonpayda;

	char first_pay[100], first_payda[100], second_pay[100], second_payda[100];
	char sonpayar[100];
	char sonpaydaar[100];
	char result_sade[100];

	for(i=0;n1[i]!='/'; i++){
		if(n1[i]=='/'){break;}		
		first_pay[j]=n1[i];
		j++;
	}
	first_pay[j]='\0';
	if(first_pay[0]=='-'){
		
		sfrac_negate(first_pay);
		first_frac_pay=(-1)*myStoi(first_pay);
	}
	else{
	first_frac_pay=myStoi(first_pay);}

	for(x=j+1; n1[x]!='\0'; x++){
		if(n1[x]=='\0'){break;}		
		first_payda[k]=n1[x];
		k++;
	}
	first_payda[k]='\0';
	if(first_payda[0]=='-'){
		
		sfrac_negate(first_payda);
		first_frac_payda=(-1)*myStoi(first_payda);
	}
	else{
	first_frac_payda=myStoi(first_payda);}

	for(h=0;n2[h]!='/'; h++){
		if(n2[h]=='/'){break;}		
		second_pay[m]=n2[h];
		m++;
	}
	second_pay[m]='\0';
	if(second_pay[0]=='-'){
		
		sfrac_negate(second_pay);
		second_frac_pay=(-1)*myStoi(second_pay);
	}
	else{
	second_frac_pay=myStoi(second_pay);}

	for(y=m+1; n2[y]!='\0'; y++){
		if(n2[y]=='\0'){break;}		
		second_payda[d]=n2[y];
		d++;
	}
	second_payda[d]='\0';
	if(second_payda[0]=='-'){
		
		sfrac_negate(second_payda);
		second_frac_payda=(-1)*myStoi(second_payda);
	}
	else{
	second_frac_payda=myStoi(second_payda);}

	result_pay=(first_frac_pay*second_frac_payda);
	result_payda=(first_frac_payda*second_frac_pay);

	gc=gcd(result_pay, result_payda);
	sonpay=result_pay/gc;
	sonpayda=result_payda/gc;
	sprintf(sonpayar, "%d", sonpay);
	sprintf(sonpaydaar, "%d", sonpayda);
	
	f2=strlen(sonpaydaar);
	strcpy(result_sade, sonpayar);
	f=strlen(result_sade);
	result_sade[f]='/';
	for(d=0; d<f2; d++){

		result_sade[f+1]=sonpaydaar[d];
			f++;
	}
	result_sade[f+1]='\0';
	strcpy(n1, result_sade);
	
	return n1;	


}
double sfrac_todouble(char * n){
	int i, j=0, x, k=0, gc, size, flag=0, flag1=0;
	char pay[100];
	char payda[100];
	
	double result, ipay, ipayda=0,sonpay, sonpayda;
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
	
	gc=gcd(ipay, ipayda);
	if(ipayda==0){
		printf("Error denominator number, can not be 0!\n");
		return 0;
	}

	
	sonpay=ipay/gc;
	sonpayda=ipayda/gc;
	
	result=sonpay/sonpayda;
	/*printf("double result is %.2f\n", result);*/
	return result;
}
char * sfrac_fromdouble(double x, char * n_t){

	char temp[100], temp_pay[100], temp_payda[100], result_sade[100];
	int size_temp, i,f2, d, f;
	double result_pay, result_payda;
	sprintf(temp, "%.2f", x);
	
	size_temp=strlen(temp);
	for(i=0; temp[i]!='.'; i++){
		if(temp[i]=='.'){break;}
		
	}
	/*printf("i %d\n", i); noktayı buldugu index*/
	result_pay=x*pow(10,(size_temp-i-1));
	result_payda=pow(10, (size_temp-i-1));
	
	sprintf(temp_pay, "%.0f", result_pay);
	sprintf(temp_payda, "%.0f", result_payda);
	
	f2=strlen(temp_payda);
	strcpy(result_sade, temp_pay);
	f=strlen(result_sade);
	result_sade[f]='/';
	for(d=0; d<f2; d++){

		result_sade[f+1]=temp_payda[d];
			f++;
	}
	result_sade[f+1]='\0';
	strcpy(n_t, result_sade);
	sfrac_simplify(n_t);
	/*printf("n_t %s\n", n_t);*/
	return n_t;
}
void sfrac_print(char *a1,char *n1, char *a2,char *n2, char *a3,char *n3, char *a4){
	
	int i, j=0, x, k=0,n,size_a3, ipay,t,w,r, ipayda, gc, sonpay, sonpayda,size,
	flag=0, flag1=0,m,pay1_size, payda1_size;
	char pay[100];
	char payda[100];

	int i2, j2=0, x2, k2=0, ipay2, ipayda2, gc2, sonpay2, sonpayda2, size2,size_a1, s,
	flag2=0, flag12=0,pay2_size, payda2_size;
	char pay2[100];
	char payda2[100];
	char n1_pay[100], n1_payda[100], n2_pay[100], n2_payda[100];

	int z, e=0, q=0, y, u;
	int ipay3, ipayda3, gc3, sonpay3, sonpayda3, size3, flag3=0, flag13=0,payda3_size;
	char pay3[100];
	char payda3[100];
	char n1_pay3[100], n1_payda3[100];

	size=strlen(n1);
	
	for(i=0; n1[i]!='/'; i++){
		if(n1[i]=='/'){break;}		
		pay[j]=n1[i];
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
	
	for(x=j+1; n1[x]!='\0'; x++){
		if(n1[x]=='\0'){break;}		
		payda[k]=n1[x];
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
	
	gc=gcd(ipay, ipayda);
	if(ipayda==0){
		printf("Error denominator number, can not be 0!\n");
		return ;
	}

	sonpay=ipay/gc;
	
	sonpayda=ipayda/gc;
	sprintf(n1_pay, "%d", sonpay);
	sprintf(n1_payda, "%d", sonpayda);
	pay1_size=strlen(n1_pay);
	payda1_size=strlen(n1_payda);
	
/*----------------------------------------------------------------------------*/
/*Ayni islemleri uc farklı array icin de tanimladim: parcala, ayir, size bul,*/
/*islem yapmak icin integer a cevir, return type a uymasi icin char * a cevir */
/*----------------------------------------------------------------------------*/
	size2=strlen(n2);

	for(i2=0; n2[i2]!='/'; i2++){
		if(n2[i2]=='/'){break;}		
		pay2[j2]=n2[i2];
		j2++;
	}
	pay2[j2]='\0';
	
	if(pay2[0]=='-'){
		
		sfrac_negate(pay2);
		ipay2=(-1)*myStoi(pay2);
		if(size2==2){
			payda2[0]='1';
			payda2[1]='\0';
			ipayda2=myStoi(payda2);
			flag2=-1;
		}
		
	}
	
	else{
	ipay2=myStoi(pay2);}

	if(size2==1){

		payda2[0]='1';
		payda2[1]='\0';
		ipayda2=myStoi(payda2);
		flag12=-1;
	}
	
	for(x2=j2+1; n2[x2]!='\0'; x2++){
		if(n2[x2]=='\0'){break;}		
		payda2[k2]=n2[x2];
		k2++;
	}
	payda2[k2]='\0';
	if(payda2[0]=='-'){
		
		sfrac_negate(payda2);
		ipay2=(-1)*myStoi(pay2);
		ipayda2=myStoi(payda2);
	}
	
	if((flag2!=-1) &&(flag12!=-1)){
	ipayda2=myStoi(payda2);}
	
	gc2=gcd(ipay2, ipayda2);
	if(ipayda2==0){
		printf("Error denominator number, can not be 0!\n");
		return ;
	}
	sonpay2=ipay2/gc2;
	sonpayda2=ipayda2/gc2;
	sprintf(n2_pay, "%d", sonpay2);
	sprintf(n2_payda, "%d", sonpayda2);
	pay2_size=strlen(n2_payda);
	payda2_size=strlen(n2_payda);
/*----------------------------------------------------------------------------*/
	size3=strlen(n3);
	
	for(z=0; n3[z]!='/'; z++){
		if(n3[z]=='/'){break;}		
		pay3[e]=n3[z];
		e++;
	}
	pay3[e]='\0';
	
	if(pay3[0]=='-'){
		
		sfrac_negate(pay3);
		ipay3=(-1)*myStoi(pay3);
		if(size3==2){
			payda3[0]='1';
			payda3[1]='\0';
			ipayda3=myStoi(payda3);
			flag3=-1;
		}
		
	}
	
	else{
	ipay3=myStoi(pay3);}

	if(size3==1){

		payda3[0]='1';
		payda3[1]='\0';
		ipayda3=myStoi(payda3);
		flag13=-1;
	}
	
	for(y=e+1; n3[y]!='\0'; y++){
		if(n3[e]=='\0'){break;}		
		payda3[q]=n3[y];
		q++;
	}
	payda3[q]='\0';
	if(payda3[0]=='-'){
		
		sfrac_negate(payda3);
		ipay3=(-1)*myStoi(pay3);
		ipayda3=myStoi(payda3);
	}
	
	if((flag3!=-1) &&(flag13!=-1)){
	ipayda3=myStoi(payda3);}
	
	gc3=gcd(ipay3, ipayda3);
	if(ipayda3==0){
		printf("Error denominator number, can not be 0!\n");
		return ;
	}

	sonpay3=ipay3/gc3;
	
	sonpayda3=ipayda3/gc3;
	sprintf(n1_pay3, "%d", sonpay3);
	sprintf(n1_payda3, "%d", sonpayda3);
	
	payda3_size=strlen(n1_payda3);
	
/*----------------------------------------------------------------------------*/
/*Butun arrayler icin tekrarlanan islemler sonucunda ekrana basilacak degerler*/
/*pdf teki sekilde yerine koydum, fakat parametre olarak 0 girildiginde	pdf te*/
/*beklenildigi gibi calismiyor. 										 	  */
/*----------------------------------------------------------------------------*/	
	size_a1=strlen(a1);
	for(s=0; s<size_a1; s++){
		printf(" ");
	}
	printf("%d", sonpay);
	for(m=0; m<abs(payda1_size-pay1_size+1); m++){
		printf(" ");
	}
	printf("%d", sonpay2);
	
	size_a3=strlen(a3);
	
	for(n=0; n<=abs(payda2_size-pay2_size+size_a3); n++){
		printf(" ");
	}
	printf("%d\n", sonpay3);
	
	printf("%s", a1);
	for(w=0; w<payda1_size; w++){
		printf("-");
	}

	printf("%s", a2);
	for(r=0; r<payda2_size; r++){
		printf("-");
	}
	
	printf("%s", a3);
	for(u=0; u<payda3_size; u++){
		printf("-");
	}
	printf("%s", a4);
	printf("\n");
	for(s=0; s<size_a1; s++){
		printf(" ");
	}

	printf("%s ", n1_payda);
	printf("%s", n2_payda);
	
	for(t=0; t<size_a3; t++){
		printf(" ");
	}
	printf("%d\n", sonpayda3);	
}

