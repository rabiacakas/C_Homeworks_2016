/******************************************************************************/
/*																			  */
/*	HW06_141044042_RABİA_ÇAKAS												  */
/*																			  */
/*	HW06_<Rabia>_<Çakas>_<141044042>_ praser.c					 			  */
/*---------																	  */
/*	Created on 29/11/2016 by Rabia Çakas									  */
/*																			  */
/*	Description																  */
/*-------------																  */
/*	 Pdf te verilen kurallara uygun olabilmesi icin hata kontrolu yapar,	  */
/* parcalara ayirir ve terminale ayrilmis seklini basar.					  */
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*					Includes												  */
/******************************************************************************/
#include <stdio.h>
#include <string.h>
/******************************************************************************/
/*					Function Prototypes										  */
/******************************************************************************/
char * parse_first(char * line, char * n_parse1, int i);
char * parse_second(char * line, char * parse2, char ch);
void token_print_func(int i, char * line, char * n_parse1, char * parse2,char ch, int size_max);
int controlTwo(char * line, char * parse2, char ch);
int getMaxSize();
void token_func();
void email_func();
int control1_email_func(char * total_line, char * parse_email, int i, int size_total);
int total_size_mail(char *linemail, int i);
int control2_email_func(char *linemail, int size_total);

/******************************************************************************/
/* 	char * parse_first(char * line, char * n_parse1, int i);				  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon line array inin '=' operatorune kadar olan kismini ayirir	  */
/* ve return eder.															  */
/******************************************************************************/
/******************************************************************************/
/* 	char * parse_second(char * line, char * parse2, char ch);				  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon line array inin '=' operatorunden sonraki kismi ayirip return */ 
/*eder.															 			  */
/******************************************************************************/
/******************************************************************************/
/*void token_print_func(int i, char * line, char * n_parse1, char * parse2,char ch, int size_max);*/
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon line array inin parcalanmis halini uygun sekilde print eder   */
/* 																			  */
/******************************************************************************/
/******************************************************************************/
/* int controlTwo(char * line, char * parse2, char ch);						  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon '='den sonra gelen kisimda numara olup olmadigini kontrol eder*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
/* 	int getMaxSize();														  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon ilk tablo icin gelen line larin maximum size ini bulur 		  */
/* ve return eder.															  */
/******************************************************************************/
/******************************************************************************/
/* 	void token_func();														  */
/* void email_func();												  		  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyonlar tablolarin basilmasi icin  gerekli fonksiyonlari cagirir.  */
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*int control1_email_func(char * total_line, char * parse_email, int i, int size_total);*/
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon alinan line icin gerekli parcalamalari yapar				  */
/*																			  */
/******************************************************************************/
/******************************************************************************/
/*int control2_email_func(char *linemail, int size_total);					  */
/*----------------------------------------------------------------------------*/
/* Bu fonksiyon alinan line icin kapanip kapanmadigini kontrol eder.		  */
/*																			  */
/******************************************************************************/

int main(){

	token_func();
	/*email_func();*/
	return 0;	
}

void email_func(){

	FILE *inp;
	char linemail[150];
	char parse_email[150];
	int i=1, size_total;
	char total_line[15000];
	inp=fopen("email.txt", "r");
	printf("\n");

	size_total=0;
	while(fgets(linemail, sizeof(linemail),inp)){
			
			strcat(total_line, linemail);
			size_total+=strlen(linemail);
			i++;
	}
	if(control2_email_func(linemail, size_total)==-1){

		printf("ERROR FOUND\n");
		return ;
	}
	control1_email_func(total_line,parse_email, i, size_total);
	

}
int control1_email_func(char *total_line, char * parse_email, int i, int size_total){

	int j, s=0, b=0, flag=0, flag1=0 , o, flag2=0, s2=0, m, b2=0, flag3=0, t, f=0;
	char subject_arr[1500], o_subject_arr[1500];
	char body_arr[1500], body2_arr[1500];
	
	for(t=0; t<size_total;t++ ){
		if((total_line[t]=='<' && total_line[t+1]=='e' && total_line[t+2]=='m'
		 && total_line[t+3]=='a' && total_line[t+4]=='i' && total_line[t+5]=='l' && 
		total_line[t+6]=='>') &&(total_line[size_total-9]=='<' && total_line[size_total-8]=='/' &&
	 total_line[size_total-7]=='e' && total_line[size_total-6]=='m' && total_line[size_total-5]=='a' && 
	total_line[size_total-4]=='i'&& total_line[size_total-3]=='l' && total_line[size_total-2]=='>')){f++;}
		
	}

	for(i=18; flag!=-1 ; i++){
		if(total_line[i]=='<' && total_line[i+1]=='/' && total_line[i+2]=='S' &&
	 total_line[i+3]=='u' && total_line[i+4]=='b' && total_line[i+5]=='j' && total_line[i+6]=='e' &&
	 total_line[i+7]=='c' && total_line[i+8]=='t' && total_line[i+9]=='>'){flag=-1;}
		else{
		subject_arr[s]=total_line[i];
		s++;
		}

	}
	subject_arr[s]='\0';
	printf("---------------------------------------------------------------------\n");
	printf("|  #  |		Subject		|		Body		    |\n");
	printf("| 1 |%s  |  ", subject_arr);
	for(j=i+17; flag1!=-1; j++){

		if(total_line[j]=='<' && total_line[j+1]=='/' && total_line[j+2]=='B' &&
		 total_line[j+3]=='o' && total_line[j+4]=='d' && total_line[j+5]=='y' &&
		 total_line[j+6]=='>'){flag1=-1;}
		else{
		body_arr[b]=total_line[j];
		b++;
		}
	}
	body_arr[b]='\0';
	printf("%s |\n", body_arr);

	printf("\n");
	if(f>1){
	for(o=j+33; flag2!=-1; o++){
		if(total_line[o]=='<' && total_line[o+1]=='/' && total_line[o+2]=='S' &&
		 total_line[o+3]=='u' && total_line[o+4]=='b' && total_line[o+5]=='j' && 
		total_line[o+6]=='e' && total_line[o+7]=='c' && total_line[o+8]=='t' && 
		total_line[o+9]=='>'){flag2=-1;}
		else{
		o_subject_arr[s2]=total_line[o];
		s2++;
		}

	}
	o_subject_arr[s2]='\0';
	printf("| 2| %s  |  ", o_subject_arr);

	for(m=o+45; flag3!=-1; m++){
		if(total_line[m]=='<' && total_line[m+1]=='/' && total_line[m+2]=='B' &&
		 total_line[m+3]=='o' && total_line[m+4]=='d' && total_line[m+5]=='y' &&
		 total_line[m+6]=='>'){flag3=-1;}
		else{
		body2_arr[b2]=total_line[m];
		b2++;
		}
	}
	body2_arr[b2]='\0';
	printf("%s |\n", body2_arr);
	}
	if((size_total- m)==16){
		return 0;
	}

	return 0;
}
int control2_email_func(char *linemail, int size_total){

	if(strcmp(linemail, "</email>\n")==0)
		{
			return 0;
		}
	else{return -1;}

	return 0;
}

void token_func(){

	FILE *inp;
	char line[150],n_parse1[150];
	char parse2[150];
	const char ch='=';
	int i=1,f;/*i:satır sayısı, j:'=' buldugu indis*/
	int size_max;
	
	inp=fopen("token.txt", "r");
	size_max=getMaxSize();

	for(f=0; f<size_max+16; f++){

		printf("-");
	}
	printf("\n");
	printf("|  #  |	token	|   Frequency      	    	      |\n");

	for(f=0; f<size_max+16; f++){

		printf("-");
	}
	printf("\n");

	fclose(inp);

	inp=fopen("token.txt", "r");
	while((fgets(line, sizeof(line), inp)))
	{	
		
		printf("| %d |", i);
		token_print_func(i, line, n_parse1, parse2, ch, size_max);
		i++;	
	}
	

	fclose(inp);


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
