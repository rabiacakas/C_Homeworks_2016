/******************************************************************************/
/*																			  */
/*	HW04_141044042_RABİA_ÇAKAS												  */
/*																			  */
/*	part1.c																	  */
/*---------																	  */
/*	Created on 11/11/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	part1.c sudoku.txt deki sudoku örnegini cozumler, dosyadan okudugu her x  */
/* degeri icin kural kontrolu yapar. Dogruysa yani legal fonksiyonu hata 	  */
/* dondurmuyorsa write_to_the_file fonksiyonu ile dosyaya yazar.			  */															
/*	Hata buldugu her x degeri icin error mesajini kullanici ekranina yazar ve */
/*program sonlandirilir.													  */
/******************************************************************************/
/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/******************************************************************************/
/*					Function Prototypes										  */
/******************************************************************************/
void init(int S[][9]);
/******************************************************************************/
/* 	void init(int S[][9]);													  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon S[9][9] un icini sifirlar ve kontrole hazir hale getirir.	  */
/*																			  */
/******************************************************************************/

int is_legal (int S[][9] , int r, int c, int x);
/******************************************************************************/
/* 	int is_legal (int S[][9] , int r, int c, int x);						  */
/*----------------------------------------------------------------------------*/
/*	Bu fonksiyonda sudoku nun oyuna uygun olup olmadigi kontrol edilir		  */
/* Ayni satirda ve sutunda ve bulundugu yerin 3X3 luk matrisinde kendisinden  */
/* olmadigi surece legal olma durumundadir.									  */
/******************************************************************************/

void read_from_file (FILE *file_pointer, int S[][9]);
/******************************************************************************/
/* 	void read_from_file (FILE *file_pointer, int S[][9]);					  */
/*----------------------------------------------------------------------------*/
/*	Bu fonksiyon kullanicinin görebilmesi icin ilk adimda sudoku.txt den 	  */
/* okuduklarini	ekrana basar.												  */
/*																			  */
/******************************************************************************/
void place(int S[][9] , int r, int c, int x);
/******************************************************************************/
/* void place(int S[][9] , int r, int c, int x);				  			  */
/*----------------------------------------------------------------------------*/
/*	 Bu fonksiyon dosyadan gelen x degeri eger is_legal fonksiyonundaki		  */
/*	kurallara uygunsa ilgili x degerini yerine  atar.						  */
/******************************************************************************/

void write_to_the_file(FILE *file_pointer, int S[][9]);
/******************************************************************************/
/* void write_to_the_file(FILE *file_pointer, int S[][9]);					  */
/*----------------------------------------------------------------------------*/
/*	 Bu fonksiyon place fonksiyonu atama yapabiliyorsa yani x degeri ilgili   */
/*	row ve column icin uygunsa output.txt adinda bir dosyaya yazar, uygun	  */
/* degilse hata mesaji verir.												  */
/******************************************************************************/

int main(){
	int x, r, c;
	int S[9][9];
	FILE *file_pointer;
	file_pointer=fopen("sudoku.txt", "r");
	if(file_pointer==NULL){
		printf("Can't open file error!\n");
		return 0;
	}
	read_from_file(file_pointer, S);
	
	init(S);
	
	fclose(file_pointer);

	file_pointer=fopen("sudoku.txt", "r");
	
		r=1;
		while(r<=9){
		c=1;
		while(c<=9){
			
			fscanf(file_pointer, "%d", &x);		
			place(S, r, c, x);
			c++;
		}
		r++;
		
		
	}
	
	fclose(file_pointer);


	return 0;
}
void init(int S[][9]){

	int i, j;
	for(i=0; i<9 ; i++){
		for(j=0; j<9; j++){
			S[i][j]=0;
		}
	}
	return;
}
void read_from_file (FILE *file_pointer, int S[9][9]){
	
	int i, j;
	for(i=0; i<9 ; i++){
		for(j=0; j<9; j++){
			fscanf(file_pointer,"%d", &S[i][j]);
			printf("%d ", S[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	return;
}
int is_legal(int S[9][9] , int r, int c, int x){

	int i, j , flag_first_illegal=0, flag_second_illegal=0, flag_thirdr_illegal=0, flag_thirdc_illegal=0;	
	i=r-1;
	j=c-1;
	
	if((x<0) || (x>9)){
		printf("The number of x is illegal!\n");
		exit(1);
	}
	
	if(x!=0){
	
		for(j=0; j<9; j++){
		
			if(x== S[i][j]){
				printf("<<<<%d in find the S[%d][%d] so it's ILLEGAL PIECES!(row kontrol)\n", x, i+1, j+1);
				flag_first_illegal=-1;
			}
		}
	
	
		i=r-1;
		j=c-1;
	
		for(i=0; i<9; i++){
				
			if(x== S[i][j]){
				printf("<<<<%d in find the S[%d][%d] so it's ILLEGAL PIECES!(column control)\n", x, i+1, j+1);
				flag_second_illegal=-1;
			
			}
		}

		i=r-1;
		j=c-1;
		for(j=0; j<2; j++){
		
			if(x== S[i][j]){
				printf("<<<<%d in find the 3X3 matrix S[%d][%d] so it's ILLEGAL PIECES!\n", x, i+1, j+1);
				flag_thirdr_illegal=-1;
			}
		}
	
		i=r-1;
		j=c-1;
	
		for(i=0; i<2; i++){
				
			if(x== S[i][j]){
				printf("<<<<%d in find the 3X3 matrix S[%d][%d] so it's ILLEGAL PIECES!\n", x, i+1, j+1);
				flag_thirdc_illegal=-1;
				
			}
		}

		if(flag_first_illegal==-1 || flag_second_illegal==-1 || flag_thirdr_illegal==-1 || flag_thirdc_illegal==-1 ){

			return 1;
		}
	
	}

	return 0;

}
void place(int S[9][9] , int r, int c, int x){

	int ret_control;
	FILE *file_pointer;
	file_pointer=fopen("output.txt", "a+");
	if(x!=0){
		ret_control=is_legal(S, r, c, x);
		if(ret_control==0){
		
			S[r-1][c-1]=x;
		
			write_to_the_file(file_pointer, S);
		}
		else if(ret_control==1){
			S[r-1][c-1]=0;
			printf("WRONG ENTRY CAN'T ASSIGN INTO!\tPlease try again-->\n");
			exit(1);
		}
	}
	fclose(file_pointer);
	return;
}
void write_to_the_file(FILE *file_pointer, int S[9][9]){

	int i, j;
	fprintf(file_pointer, "\n");
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){

			fprintf(file_pointer, "%d ", S[i][j]);


		}

	fprintf(file_pointer, "\n");

	}

	return;

}

