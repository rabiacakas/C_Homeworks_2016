#include "HW09_RABIA_CAKAS_141044042_DoubleList.h"

int size_list(){
	int size=0;
	struct node *current;
	for(current =head; current !=NULL; current =current->next){
      size++;
	}
	
	return size;
}

int insert_begin(char * current, int volts)
{

	struct node *new=(struct node*)malloc(sizeof(struct node));
	strcpy(new->arr,current);
	new->volts=volts;
	if(head== NULL)
	{
		final=new;
	}
	else
	{	
		head->prev=new;
	}

	new->next = head;
	head =new;
}
int insert_final(char * current, int volts){

	struct node *new=(struct node*)malloc(sizeof(struct node));
	strcpy(new->arr,current);
	new->volts=volts;

	if(head== NULL){
		final= new;
	}
	else
	{
		final->next =new;
		new->prev =final;
	}

	final =new;
	return 0;
}
void display_forward(){

	struct node *p= head;
	printf("\n");
	while(p!= NULL)
	{        
		printf("(%s,%d) ",p->arr, p->volts);
		p= p->next;
	}
	return;
}
void display_backward(){

	struct node *p = final;
	while(p!= NULL)
	{    
		printf("(%s,%d) ",p->arr, p->volts);
		p= p->prev;
	}
	return;
}
int insert_node(char *current, int volts, int position){

	if(position==1 && size_list()==0){

		insert_begin(current, volts);
	}

	else if(position==size_list()+1){

		insert_final(current, volts);
	}
	else if(position<size_list()){

		insert_spesific(current, volts,position);
	}
	else{

		printf("POSITION IS NOT LEGAL !\n");

	}
	
}
int insert_spesific(char *current, int volts, int position){

	struct node *new=(struct node*)malloc(sizeof(struct node));
	struct node * temp1=NULL;
	struct node * prev=NULL;	
	int i, j;
	strcpy(new->arr,current);
	new->volts=volts;
	
	return 0;

}
int delete_final(){
	struct node *delete = final;
	
	if(head->next==NULL){
		head = NULL;
	}
	else
	{
		final->prev->next = NULL;
	}
	
	final = final->prev;
	
	return 0;
}


