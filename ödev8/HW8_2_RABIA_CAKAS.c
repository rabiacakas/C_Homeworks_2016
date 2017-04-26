/******************************************************************************/
/*																			  */
/*	HW8_2_<RABIA>_<CAKAS>.c"												  */
/*																			  */
/*	HW8_2_<RABIA>_<CAKAS>.c													  */
/*---------																	  */
/*	Created on 15/12/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	 Maze.txt deki matrix in 1 lerden cikis yolunu nulur ve print eder.		  */
/*	(Satir sayisini yanlis algiladigi icin malesef dogru bir cozum uretemiyor)*/
/******************************************************************************/
/******************************************************************************/
/*								DEFINES										  */
/******************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/******************************************************************************/
/*						FUNCTION PROTOTYPES									  */
/******************************************************************************/
int control1_maze(char * new_maze, int x, char * sol, int c);
int control_maze(char * new_maze, int x, int c);
int solve_maze(char * new_maze, int c);
void print_maze(char * sol, int c);

int main()
{

	FILE * inp;
	char line[100], maze[10000];
	char * new_maze;	
	int c=0, i=0, j=0;
	inp=fopen("maze.txt", "r");
	if(inp== NULL){

		printf("Can't open file error! \n");
		return -1;	
	}
	else
	{
		while(fgets(line, sizeof(line), inp)){
			
			strcat(maze, line);
			c++;
		}
		
		new_maze=(char *)calloc(pow(c,2)+c*c, sizeof(char));
		for(i=0; i<(pow(c,2)+c*c); i++){
		
			if(maze[i]=='0' || maze[i]=='1' || maze[i]=='\n')
			{
				new_maze[j]=maze[i];
				j++;

			}
		}
		new_maze[j]='\0';

	}
	
    solve_maze(new_maze,c);
    return 0;
}
int control_maze(char * new_maze, int x, int c)
{
    if(x >= 0 && x < pow(c,2)+c && new_maze[x]== 1)
	{
        return 0;
	}
 
    return -1;
}
 

int solve_maze(char * new_maze, int c)
{
	int m, i;
	char * sol;
	m=pow(c, 2)+ c;
	
	sol=(char*)calloc(m,sizeof(char));
	for(i=0; i< m; i++){

		sol[i]='0';
	}
    if(control1_maze(new_maze, 0, sol, 0) == -1)
    {
        printf("Doesn't exit! \n");
        return -1;
    }
 
    print_maze(sol, c);
    return 0;
}
 
int control1_maze(char * new_maze, int x, char * sol, int c)
{
	
	if(x == pow(c,2)+c)
    {
        sol[x] = '*';
        return -1;
    }
 
	if(control_maze(new_maze, x, c) ==0)
    {
       
        sol[x] = '*';

        if(control1_maze(new_maze, x+1, sol, c) == 0){
            return 0;}
 
        
        if(control1_maze(new_maze, x+c, sol, c) == 0){
            return 0;}

       else
		{ 
		sol[x]= '0';
		return -1;
		}
    }   
 
    return -1;
}


void print_maze(char * sol, int c)
{
	int i;
    for(i = 0; i < pow(c,2)+c; i++)
    {
        printf(" %c ", sol[i]);
        printf("\n");
    }
}
 

