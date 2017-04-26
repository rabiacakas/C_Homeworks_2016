#ifndef my_doubly_linked_h
#define my_doubly_linked_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{

	char arr[3];
	int volts;
	struct node * next;
	struct node * prev;

}node_t;

struct node * head= NULL;

struct node * final= NULL;

struct node * current= NULL;

int size_list();
int insert_begin(char * current, int volts);
int insert_final(char * current, int volts);
void display_forward();
void display_backward();
int insert_node(char *current, int volts, int position);
int insert_spesific(char *current, int volts, int position);
int delete_final();

#endif/*my_doubly_linked_h*/
