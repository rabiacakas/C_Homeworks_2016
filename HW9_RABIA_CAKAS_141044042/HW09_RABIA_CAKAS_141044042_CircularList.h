#ifndef circularlinked_h
#define circularlinked_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_cir{

	char arr[3];
	int volts;
	struct node * next;

}node_t;

struct node * head= NULL;
struct node * news = NULL;

int size_cir();
void insert_node_cir(char *current, int volts);
void delete_node(node_t * head);
void display_list_cir();




#endif /*circularlinked_h*/
