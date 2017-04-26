/******************************************************************************/
/*																			  */
/*	HW02_141044042_RABİA_ÇAKAS												  */
/*																			  */
/*	part1.c																	  */
/*---------																	  */
/*	Created on 20/10/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	part1.c kullanicidan input parametreleri alarak ilgili sekli ekrana		  */
/*basar.																	  */															
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include <stdio.h>
/******************************************************************************/
/*					Function Prototypes										  */
/******************************************************************************/
void Draw_rect(int starting_point, int length, int width, int layer_type);
/******************************************************************************/
/* 	void Draw_rect(int starting_point, int length, int width, int layer_type);*/
/*----------------------------------------------------------------------------*/
/*Fonksiyon baslangictan uzaklik icin starting_point, genislik ve uzunluk icin*/
/*length ve width, seklin tek yada cift katli olma secenegi icin layer_type   */
/*parametrelerini alir.														  */
/******************************************************************************/
void Draw_Triangle(int starting_point, int length, int layer_type);
/******************************************************************************/
/* 	void Draw_Triangle(int starting_point, int length, int layer_type);		  */
/*----------------------------------------------------------------------------*/
/*	Fonksiyon baslangictan uzaklik icin starting_point, uzunluk icin		  */
/*length , seklin tek yada cift katli olma secenegi icin layer_type   		  */
/*parametrelerini alir.														  */
/******************************************************************************/
/*void Draw_Circle(int center, int radius, int layer_type);*/
/******************************************************************************/
/* 	void drawing_test();													  */
/*----------------------------------------------------------------------------*/
/*	Kullanici bilgilendirmesi yapar.	 									  */
/*																			  */
/******************************************************************************/

void drawing_test();
int main(){
	
	int draw_choice, starting_point, length, width, layer_type;
	while(1){
		drawing_test();
		scanf("%d", &draw_choice);
		if(draw_choice==1)
			{
				printf("Please enter 4 argument must be integer-->");
				scanf("%d %d %d %d", &starting_point, &length, &width, &layer_type);
				if(layer_type!=1 && layer_type!=2)
				{
					printf("Layer_type must be 1 or 2!\n");
					break;
				}
				Draw_rect(starting_point, length, width, layer_type);
			}
		else if(draw_choice==2)
			{
				printf("Please enter 3 argument must be integer-->");
				scanf("%d%d%d", &starting_point, &length, &layer_type);
				if(layer_type!=1 && layer_type!=2)
				{
					printf("Layer_type must be 1 or 2!\n");
					break;
				}
				Draw_Triangle(starting_point, length, layer_type);	
			}
		else if(draw_choice==3)
			break;

		else
			printf("Invalid input ! Please try again\n");
		
	}

	return 0;
}
void drawing_test(){

	printf("WELCOME TO DRAWER!\n");
	printf("[1]-->Drawing a rectangle\n");
	printf("[2]-->Drawing a triangle\n");
	printf("[3]-->Good bye!\n");
	printf("Your selection: ");

	return;
}

void Draw_rect(int starting_point, int length, int width, int layer_type)
{
	int k,h, t,p, w;
	k=width*layer_type;
	p=length*layer_type;
	if(layer_type==2)
	{
		for(h=1; h<=p; h++)
		{
			for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}
		
			for(w=1; w<=k; w++)
			{
				if(h==1 || h==2 || h==p || h==p-1 || w==1 ||  w==2 || w==k || w==k-1)
					printf("*");
		
				else
					printf(" ");
			}

		printf("\n");
		}
	}
	if(layer_type==1)
	{
			for(h=1; h<=p; h++)
		{
			for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}
		
			for(w=1; w<=width; w++)
			{
				if(h==1 || h==p  || w==1  || w==k)
					printf("*");
		
				else
					printf(" ");
			}

		printf("\n");
		}

	}

}
void Draw_Triangle(int starting_point, int length, int layer_type){

	int space, inn_space, i, l, t,h,p, x;
	
	space = (length-1);
	if(layer_type==1)
	{
	
		for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}
		/*bastaki boslukları basıyor ilk satir icin length-1 kadar bosluk bas*/
		i =space;
		while( i > 0){
			printf(" ");
			--i;
		}	
		printf("*\n");
		for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}	
		inn_space = 1;
		space--;
		/*diger satırlar icin bastaki boslukları basıyor*/
		while( space != 0 ){
			
			l = space;
			while( l > 0){
				printf(" ");
				--l;
			}
			printf("*");	
			/*aradaki boslukları basıyor*/
			x = inn_space;
			while( x > 0){
				printf(" ");
				--x;
			}
			printf("*\n");
			for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}
		
			inn_space += 2;
			space--;	

		}	
		h=((length*2)-1);
		while( h > 0){
			printf("*");
			--h;
		}
	
	printf("\n");
	}
	if(layer_type==2)
	{
		for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}
		/*bastaki boslukları basıyor ilk satir icin length-1 kadar bosluk bas*/
		i =space;
		while( i > 0){
			printf(" ");
			--i;
		}	
		printf("**\n");
		for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}	
		inn_space = 1;
		space--;
		/*diger satırlar icin bastaki boslukları basıyor*/
		while( space != 0 ){
			
			l = space;
			while( l > 0){
				printf(" ");
				--l;
			}
			printf("**");	
			/*aradaki boslukları basıyor*/
			x = inn_space;
			while( x > 0){
				printf(" ");
				--x;
			}
			if(x==length-1)
			{
				for(p=length; p>0; p--)
				{
					printf("**");
				}
			}
			printf("**\n");
			for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}
		
			inn_space += 2;
			space--;	

		}
		for(i=0; i< 2; i++){
			
			h=((length*2)-1);
			while( h > 0){
				printf("*");
				--h;
			}
			printf("**");
			printf("\n");
			for(t=1; t<=starting_point; t++)
			{
				printf(" ");
			}	
			
			
		}
		printf("\n");
	}
	return;
}




















