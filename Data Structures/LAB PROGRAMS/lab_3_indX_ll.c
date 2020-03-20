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
List* list_initialize(); 
void list_print(List*);
void insert(List*,int,int);
void delete(List*,int);
void list_destroy(List* list);
void main(){
	List* p=list_initialize();	
	int pos;
	int ele;
	if (p->head==NULL){
		printf("List is currently empty \n");
	}
	int choice;
	do{
		printf("enter choice \n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter element \n");
				scanf("%d",&ele);
				printf("Enter pos: \n");
				scanf("%d",&pos);	
				insert(p,ele,pos);
				break;						
			case 2: printf("Enter pos \n");
				scanf("%d",&pos);
				delete(p,pos);
				break;
			case 3: list_print(p);
				break;
			default:list_destroy(p);
				exit(0);
		}
	} while(choice >= 1 && choice < 4);
}
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
	}
	free(list);
}
List* list_initialize(){   
	List* list;
    	list=(List*)malloc(sizeof(List));
    	list->head=NULL;
    	list->number_of_nodes=0;
   	return list;
}
void insert(List* p,int ele, int pos){
	Node* temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=ele;
	Node* prev;
	Node* next;
	next=p->head;
	if(pos<1){
		printf("Invalid");
	}
	else{
		if(pos==1){
			temp->link=next;
			p->head=temp;
		}
		else{	
			int i=1;
			while(next!=NULL && i<pos){
				prev=next;			
				next=next->link;
				i++;
			}
			if(next==NULL){
				if(i==pos){
					prev->link=temp;
					temp->link=next;
				}	
				else{
					printf("InValid \n");		
				}
			}
			else{
				
				prev->link=temp;
				temp->link=next;
			}
		}
	}	
}
void delete(List* p, int pos){
	Node* temp;
	Node* prev;
	temp=p->head;	
	if(p->head==NULL){
		printf("INVALID");
	}
	else{
		if(pos==1){
			p->head=temp->link;
		}
		else{
			int i=1;			
			while(temp!=NULL && i<=pos){
				prev=temp;
				temp=temp->link;
				i++;
			}
			if(temp==NULL){
				printf("INVALID POSITION");
			}
			else{
				prev->link=temp->link;
				free(temp);
			}

		}
	}
}
void list_print(List * list){
    	Node* temp = list->head;
    	if(list->head == NULL){
      	printf("EMPTY\n");
    	}
	else{
        	while(temp!= NULL){
            		printf("%d ", temp->data);
            		temp = temp->link;
        	}
        	printf("\n");
    	}
}
