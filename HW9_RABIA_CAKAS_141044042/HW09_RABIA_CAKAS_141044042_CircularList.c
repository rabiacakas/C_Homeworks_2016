#include "HW09_RABIA_CAKAS_141044042_CircularList.h"

int size_cir(){
	int size=0;
	if(head==NULL){
		
		return 0;	
	}
	news=head->next;
	while(news!=head)
	{
		size++;
		news= news->next;   
   }
	
   return size;

}
void insert_node_cir(char *current, int volts){

	node_t *newin =(node_t*)malloc(sizeof(node_t));
	strcpy(newin->arr,current);
	newin->volts=volts;
	
	if(head==NULL){
		head=newin;
		head->next=head;
	}
	else
	{
		newin->next = head;
		head=newin;
	}    
	return;
}
void delete_node_cir(node_t * head) {

    if (head->next == NULL){
        free(head);
        return;
    }

    node_t * news= head;
    while (news->next->next != NULL) {
        news = news->next;
    }

    free(news->next);
    news->next = NULL;
	return;
}
void display_list_cir(){

	node_t * current=head;
	if(head!= NULL)
	{
		while(current->next !=current){     
			printf("(%s,%d) ",current->arr, current->volts);
			current= current->next;
		}

	}
}
/*int main()
{
	char current[3];
	strcpy(current, "abc");
	current[3]='\0';
	printf("size %d", size_cir());
	insert_node_cir(current,10);

	strcpy(current, "def");
	current[3]='\0';
	insert_node_cir(current,20);

	strcpy(current, "def");
	current[3]='\0';
	insert_node_cir(current,30);

	strcpy(current, "hmf");
	current[3]='\0';
	insert_node_cir(current,1);


	printf("Original List: "); 
	
  
	display_list_cir();
	return 0;
}*/



