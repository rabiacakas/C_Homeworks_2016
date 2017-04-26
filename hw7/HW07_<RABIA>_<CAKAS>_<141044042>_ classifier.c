/******************************************************************************/
/*																			  */
/*	HW07_141044042_RABİA_ÇAKAS												  */
/*																			  */
/*	HW07_<Rabia>_<Çakas>_<141044042>_ praser.c					 			  */
/*---------																	  */
/*	Created on 06/12/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	 Pdf te verilen kurallara uygun olabilmesi icin hata kontrolu yapar,	  */
/* parcalara ayirir token.txt deki frekans degerine esit olup olmadigini	  */
/* kontrol eder, esitse spam esit degilse no-spam olarak adlandirir.		  */
/******************************************************************************/
/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include <stdio.h>
#include <string.h>
/******************************************************************************/
/*					Function Prototypes										  */
/******************************************************************************/

void token_func();
/******************************************************************************/
/* 	void token_func();														  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon tablolarin basilmasi icin  gerekli fonksiyonlari cagirir. 	  */
/*																			  */
/******************************************************************************/
char * parse_first(char * line, char * n_parse1, int i);
/******************************************************************************/
/* 	char * parse_first(char * line, char * n_parse1, int i);				  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon line array inin '=' operatorune kadar olan kismini ayirir	  */
/* ve return eder.															  */
/******************************************************************************/
char * parse_second(char * line, char * parse2, char ch);
/******************************************************************************/
/* 	char * parse_second(char * line, char * parse2, char ch);				  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon line array inin '=' operatorunden sonraki kismi ayirip return */ 
/*eder.															 			  */
/******************************************************************************/
int getMaxSize();
/******************************************************************************/
/* 	int getMaxSize();														  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon ilk tablo icin gelen line larin maximum size ini bulur 		  */
/* ve return eder.															  */
/******************************************************************************/
void token_print_func(int i, char * line, char * n_parse1, char * parse2, char ch, int size_max);
/******************************************************************************/
/*void token_print_func(int i, char * line, char * n_parse1, char * parse2,char ch, int size_max);*/
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon line array inin parcalanmis halini uygun sekilde print eder   */
/* 																			  */
/******************************************************************************/
int controlTwo(char * line, char * parse2, char ch);
/******************************************************************************/
/* int controlTwo(char * line, char * parse2, char ch);						  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon '='den sonra gelen kisimda numara olup olmadigini kontrol eder*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
char * email_func(char * total_line);

int control_found(char * n_parse1, char * parse2, char * total_line, char * temiz_2);
/******************************************************************************/
/*int control_found(char * n_parse1, char * parse2, char * total_line, char * temiz_2);*/
/*----------------------------------------------------------------------------*/
/*Bu fonksiyon token.txt deki parcalarin frekanslarinin dogru sekilde var olup*/
/*olmadigini kontrol eder, dogruysa spam degilse no-spam olarak adlandirir.	  */
/******************************************************************************/
int myStoi(char * n);
/******************************************************************************/
/* int myStoi(char * n);													  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon atoi gibi calisir, aldigi string i integer degere cevirir.	  */
/*----------------------------------------------------------------------------*/
/******************************************************************************/
int low_to_up(char *n);
/******************************************************************************/
/* int low_to_up(char *n);													  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon token.txt ile email.txt arasindaki buyuk-kucuk harf farklilik */
/*larini ortadan kaldirmak icin kullanilmistir, kucuk harfleri buyuge 		  */
/*donusturur. 																  */
/*----------------------------------------------------------------------------*/
/******************************************************************************/

int main(){
	
	char total_line[15000];
	token_func();
	email_func(total_line);
	return 0;
}

char * email_func(char * total_line){

	FILE *inp;
	char linemail[150];
	int i=1, size_total;
	
	inp=fopen("emails.txt", "r");

	if(inp== NULL){

		printf("Can't open file error!\n");
	}
	if(inp != NULL){
		printf("\n");

	size_total=0;
	while(fgets(linemail, sizeof(linemail),inp)){
			
			strcat(total_line, linemail);
			size_total+=strlen(linemail);
			i++;
	}
	
	fclose(inp);

	}
	return total_line;
}
void token_func(){

	FILE *inp;
	char line[150],n_parse1[150], temiz_2[150];
	char parse2[150];
	const char ch='=';
	int i=1;/*i:satır sayısı*/
	int size_max;

	char total_line[15000];
	email_func(total_line);

	inp=fopen("token.txt", "r");
	if(inp== NULL){

		printf("Can't open file error!\n");
	}
	if(inp!=NULL){
		size_max=getMaxSize();
	
		fclose(inp);

		inp=fopen("token.txt", "r");
		while((fgets(line, sizeof(line), inp)))
		{	
		
			printf("| %d |", i);
			token_print_func(i, line, n_parse1, parse2, ch, size_max);
			control_found(n_parse1,parse2, total_line, temiz_2);
			i++;	
		}
	
	
		fclose(inp);

}
	return;


}
char * parse_first(char * line, char * n_parse1, int i){

	int j,size, flag1=0, p;
	char parse1[150];
	for(j=0 ; line[j]!='='; j++){}
	size=strlen(line);
	if(j>=size){j=-1;}
	if(j==-1){

		printf("IN %d. LINE FOUND ERROR TYPE 1! INVALID ASSIGNMENT OPERATOR!\n", i);
		flag1=-1;
	}
		
	if(flag1!=-1){
		for(p=0; p<j-1; p++){
			parse1[p]=line[p];
		}
		parse1[p]='\0';

		strcpy(n_parse1, parse1);

	}
	if(flag1==-1){
		return 0;
	}
	
	return n_parse1;
}
char * parse_second(char * line, char * parse2, char ch){

	int t, c, m=0, size;
	size=strlen(line);
	for(t=0; line[t]!='='; t++){}
	if(t<0 || t>size){
		return 0;
	}
	for(c=t+1; line[c]!='\0'; c++){
		if(line[c]!='\n'){
		parse2[m]=line[c];
		m++;}
	}
	parse2[m]='\0';

	return parse2;
}
void token_print_func(int i, char * line, char * n_parse1, char * parse2, char ch, int size_max){
	int size, t;
	size=strlen(line);
	
	if(parse_first(line, n_parse1, i)!=0 && parse_second(line, parse2, ch)!=0 && controlTwo(line, parse2, ch)!=0){
		printf("%s", parse_first(line, n_parse1, i));
		printf("	|	");
		printf("%s", parse_second(line, parse2, ch));
		if(size<size_max){

			for(t=0; t<size_max-size-3; t++){

				printf(" ");
			}

		}
		printf("|\n");
		
	
	}

	return;
}
int low_to_up(char *n){

	int size, p;
	size=strlen(n);
	for(p=0; p<size; p++)
	{
		if(n[p]>='a' && n[p]<='z')
		{
			n[p]-='a'- 'A';
				
		}
	}
	return 0;

}
int control_found(char * n_parse1, char * parse2, char * total_line, char * temiz_2){

	int freq, i, t=0, size_p2, count;
	char * temp;
	
	size_p2=strlen(parse2);
	/*string in basindaki boslugu sildim*/
	for(i=1; i<size_p2; i++){

		temiz_2[t]=parse2[i];
		t++;
	}
	temiz_2[t]='\0';

	
	freq=myStoi(temiz_2);
	
/*Buyuk kucuk harf farkliligi yuzunden iki stringi de buyuk harfe cevirdim */

	low_to_up(total_line);
	low_to_up(n_parse1);
	count = 0;
	temp = total_line;
	while(temp=strstr(temp, n_parse1))
	{
	   count++;
	   temp++;
	}
	if(count==freq){

		printf("## FREQUENCE DEGREE TRUE, SO EMAIL IS SPAM! ##\n");
		
	}
	else
		printf("## FREQUENCE DEGREE NOT TRUE, SO EMAIL NO-SPAM! ##\n");

	return 0;
}
int getMaxSize(){

	FILE *inp;
	char line[150];
	int size_first, size_max, temp,i=1;
	inp=fopen("token.txt", "r");
		
	fgets(line, sizeof(line), inp);
	size_first=strlen(line);
	
	while((fgets(line, sizeof(line), inp)))
	{	
		temp=strlen(line);
		
		if(temp>size_first){
			size_max=temp;

		}
		i++;	
	}
	fclose(inp);
	return size_max;

}
int controlTwo(char * line, char * parse2, char ch){

	char * cntrl_two, cntrl_arr[150];
	int size,i;

	cntrl_two=parse_second(line, parse2, ch);
	strcpy(cntrl_arr, cntrl_two);
	size=strlen(cntrl_arr);
	for(i=1; i<size-1; i++){

		if(cntrl_arr[i]!='0' && cntrl_arr[i]!='1' && cntrl_arr[i]!='2' && 
		cntrl_arr[i]!='3' && cntrl_arr[i]!='4' && cntrl_arr[i]!='5' && 
		cntrl_arr[i]!='6' && cntrl_arr[i]!='7' && cntrl_arr[i]!='8' && cntrl_arr[i]!='9')
		{
			printf("ERROR TYPE 2! FREQUENCIES DEGREE MUST BE NUMBER !\n");
			return 0;
		}
	}
	return 1;
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
