#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *link;
} Node;
typedef struct List {
	Node* head;
	int number_of_nodes;
} List;
/* initializes a linked list */
List* list_initialize(); 

/* Inserts a new node with data at the beginning 
void list_insert_beginning(List* list, int data);*/

/* Removes the last node of the linked list
void list_delete_rear(List* list); */

/* Print the contents of a list */
void list_print(List* list); 

/* deallocates resources held by the list */
void list_destroy(List* list); 

void ordered_list(List* list ,int );

int main() 
{
	int choice;
	List* list;
	list=list_initialize();
	do {
		printf("Enter Choice\n");		
		scanf("%d", &choice);
		switch(choice){
			int element;
			/*case 1:
				 Insert an element at beginning of the list  
					scanf("%d", &element);
					list_insert_beginning(list, element);
					break;*/
			/*case 2:
				 Remove rear elements  
				    list_delete_rear(list);
					break;*/
			case 1:
				/* Insert an element at beginning of the list */ 
				printf("enter element \n");					
				scanf("%d",&element);
                    		ordered_list(list, element);
				break;    
			case 2:
				/* Print list contents */ 
				list_print(list);
				break;

			default: 
				list_destroy(list);
				exit(0);
		}
	} while(choice >= 1 && choice < 3);
	
	return 0;
}
//DO NOT MODIFY THE ABOVE CODE.
//WRITE YOUR CODE BELOW.

void list_destroy(List* list){
	Node* temp=list->head;
	if(list->head==NULL){
	}
	else{   	
		while(temp!=NULL){	
      	 		list->number_of_nodes--;
	       		temp=temp->link;
			free(temp);
   		}
		free(list);
	}
}
List* list_initialize(){   
	List* list;
    	list=(List*)malloc(sizeof(List));
    	list->head=NULL;
    	list->number_of_nodes=0;
   	return list;
}

/*void list_delete_rear(List* list)
{
    Node* temp=list->head;
    Node* temp1=NULL;
    //temp=list->head;
    if(list->head==NULL)
    {    
        ;
    
    }
    else if(list->head->link==NULL)
    {   
        list->head=NULL;
        free(list->head);
        //list->head=NULL;
    }
    else
    {
       
        while(temp->link!=NULL)
        {   temp1=temp;
            temp=temp->link;
            
        }
        temp1->link=NULL;
        free(temp);
        
    }
    
}    
 

Node* create_node(int data)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->link=NULL;
    return temp;
}

void list_insert_beginning(List* list, int data)
{  
    Node* new_node=create_node(data);
    
    new_node->link=list->head;
    list->head=new_node;
    list->number_of_nodes++;
   
    
    
 
}*/    
void list_print(List * list)
{
    Node* temp = list->head;
    
    if(list->head == NULL)
    {
       printf("EMPTY\n");
        
    }
  
    
    else
    {
        while(temp!= NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void ordered_list(List* list,int key){
	Node* temp;
	temp=(Node*)malloc(sizeof(Node*));
	temp->data=key;	
	temp->link=NULL;
	if(list->head==NULL){
		list->head=temp;
	}
	else{
		Node* prev;
		Node* next=list->head;
		if(key<next->data){
			temp->link=next;
			list->head=temp;
		}
		else{
			while(next!=NULL && next->data<key){
				prev=next;
				next=next->link;
			}
			temp->link=next;
			prev->link=temp;
		}

	}
}
