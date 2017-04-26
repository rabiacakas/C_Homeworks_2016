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
/*	part2.c MyPuzzle array inde kullanicidan aldigi row, column orientation   */
/* ve word e göre arama yapar. Kullanici c ye bastigi surece calismaya devam  */
/* eder. MyPuzzle in icinde word arrayini arar. Bulursa 					  */
/* 1 bulamazsa 0 return eder.												  */															
/*	## word array inin size ini bulabilmek icin kullanicinin word ardindan	  */
/* 0 girmesini istedim##													  */
/******************************************************************************/
/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include <stdio.h>
#include <string.h>
/******************************************************************************/
/*					Defines													  */
/******************************************************************************/
#define Max_N 200
/******************************************************************************/
/*					Function Prototypes										  */
/******************************************************************************/
void user_agreement(char MyPuzzle[][Max_N]);
/******************************************************************************/
/* 	void user_agreement(char MyPuzzle[][Max_N]);							  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon MyPuzzle array ini basar.									  */
/*																			  */
/******************************************************************************/

int find(char Puzzle[][Max_N],int row , int column ,char orientation,char *word);
/******************************************************************************/
/*int find(char Puzzle[][Max_N],int row , int column ,char orientation,char *word)*/
/*----------------------------------------------------------------------------*/
/*	Bu fonksiyonda MyPuzzle in icinde r, l, b ve t gibi orientation durumlari */
/* icin arama yapar, bulursa 1 bulamazsa 0 return eder.						  */
/*																			  */
/******************************************************************************/

int main(){
	int row, column, t;
	char orientation, qorc;
	char word[Max_N]; 

	char MyPuzzle[Max_N][Max_N]={
	{'I','N','E','U','E','L','G','C'},
	{'T','L','E','M','O','N','E','O'},
	{'S','C','H','E','R','R','Y','T'}};

	user_agreement(MyPuzzle);
	printf("To quit, please enter q-->\nTo continue,please enter c-->\n");
	scanf("%c", &qorc);
	if(qorc=='q'){

		printf("Good bye!\n");
		return 0;
	}
	while(qorc!='q' && qorc=='c'){
		printf("Enter row and column number:\n");
		scanf("%d %d", &row, &column);

		printf("Please enter orientation form must be r or R, l or L, b or B, t or T-->\n");
		scanf(" %c", &orientation);
		if(orientation!='r' && orientation!='R' && orientation!='l' && orientation!='L' && orientation!='b' && orientation!='B' && orientation!='t' && orientation!='T'){

			printf("Invalid orientation form!\n");
			return 0;
		}

		

		printf("Please enter the search letter and press 0-->\n");

		t=0;
		scanf(" %c", (&word[t]));
		while(word[t]!='0'){
			if(word[t]=='0'){
				return 0;
			}
			else{
			scanf(" %c", &(word[t+1]));
			t++;}
		}
		if((orientation=='r' || orientation=='R' || orientation=='l' || orientation=='L') && (t-1>Max_N))
		{
			printf("CAN NOT FIND, SIZE OF WORD THAN BIGGER EXAMPLE PUZZLE!\n");
			return 0;
		}

		if((orientation=='b' || orientation=='B' || orientation=='T' || orientation=='t') && (t-1>Max_N))
		{
			printf("CAN NOT FIND, SIZE OF WORD THAN BIGGER EXAMPLE PUZZLE!\n");
			return 0;
		}

		
		find(MyPuzzle, row, column, orientation, word);
	
		user_agreement(MyPuzzle);
		printf("To quit, please enter q-->\nTo continue, please enter c-->\n");
		scanf(" %c", &qorc);
		if(qorc=='q'){

			printf("Good bye!\n");
			return 0;
		}
	}
	
	return 0;
}
int find(char Puzzle[][Max_N],int row , int column ,char orientation,char *word){
	
	int i, j=0;
	int sizekel, p, h=0;
	sizekel=strlen(word) -1;

	if(orientation=='R' || orientation=='r'){
		for(i=0; i<sizekel; i++){
			if(Puzzle[row][column+i]!=word[i]){
				printf("Orientation is : 'R' Puzzle[][]: %c word[]: %c\n", Puzzle[row][column+i], word[i]);
				}
			else{
				j++;
			}
	
		}
		if(j==sizekel){
			printf("FOUND!\n");
			return 1;	
		}
		else
			printf("NOT FOUND!\n");
			return 0;

	}

	if(orientation=='L' || orientation=='l'){
		for(p=sizekel; p>0 ; p--){
			printf("%c %c\n", Puzzle[row][column+p-sizekel], word[sizekel-p]);
			if(Puzzle[row][column+p-sizekel]!=word[sizekel-p]){
				printf("Orientation is: 'L' %c %c\n", Puzzle[row][column+p-sizekel], word[sizekel-p]);
						
			}
			else{
				h++;
			}

		}
	if(h==sizekel){
		printf("FOUND!\n");
		return 1;
	}
	else{
		printf("NOT FOUND!\n");
		return 0;
	}
}

	if(orientation=='t' || orientation=='T'){

		for(i=0; i<sizekel; i++){
			if(Puzzle[row+i][column]!=word[i]){
				printf("Orientation is: 'T' %c %c\n",Puzzle[row+i][column], word[i]);
				}
			else{
				j++;
			}
	
		}
		if(j==sizekel){
			printf("FOUND!\n");
			return 1;	
		}
		else{
			printf("NOT FOUND!\n");
			return 0;
		}

	}


	if(orientation=='b' || orientation=='B'){
		for(p=sizekel; p>0 ; p--){
			printf("%c %c\n", Puzzle[row+p-sizekel][column], word[sizekel-p]);
			if(Puzzle[row+p-sizekel][column]!=word[sizekel-p]){
				printf("Orientation is: 'L' %c %c\n", Puzzle[row+p-sizekel][column], word[sizekel-p]);
						
			}
			else{
				h++;
			}

		}
	if(h==sizekel){
		printf("FOUND!\n");
		return 1;
	}
	else{
		printf("NOT FOUND!\n");
		return 0;
	}

	}
	return 0;
}
void user_agreement(char MyPuzzle[][Max_N])
{
	
		int i=0, j=0;
		while(MyPuzzle[i][j]!='\0'){
			while(MyPuzzle[i][j]!='\0'){
				printf("%c ", MyPuzzle[i][j]);

				j++;
		}
		j=0;
		printf("\n");
		i++;
		}
}







