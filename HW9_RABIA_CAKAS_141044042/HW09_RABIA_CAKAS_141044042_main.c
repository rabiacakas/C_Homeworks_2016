#include "HW09_RABIA_CAKAS_141044042_DoubleList.h"
#include "HW09_RABIA_CAKAS_141044042_DoubleList.c"


#include <stdio.h>
#include <stdlib.h>

int main(){

	char current[3]="abc";
	current[3]='\0';
	insert_node(current, 1, 1);
	printf("size is %d", size_list());
	display_forward();
	printf("\n");

	strcpy(current, "hdh");
	current[3]='\0';
	insert_node(current, 2, 2);
	printf("size is %d", size_list());
	display_forward();
	printf("\n");

	strcpy(current, "new");
	current[3]='\0';
	insert_node(current, 3, 3);
	printf("size is %d", size_list());
	display_forward();
	printf("\n");

	strcpy(current, "neh");
	current[3]='\0';
	insert_node(current, 4, 2);
	printf("size is %d", size_list());
	display_forward();
	printf("\n");

	printf("Delete the final node:\n");
	delete_final();
	printf("size is %d", size_list());
	display_forward();
	printf("\n");
}

