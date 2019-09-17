#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}Node;
void main(){	
	int key,n;
	Node *p;
	p=(Node*)malloc(sizeof(Node*));
	Node* mylist(Node*);
	Node* pop(Node*);
	Node* push(Node*,int);
	p=mylist(p);
 	printf("enter number of elements tp be pushed");
	scanf("%d",&n);
	while(n>0){
		printf("enter \n");	
		scanf("%d",&key);
		p=push(p,key);
		n--;
	}
	while(p!=NULL){
		p=pop(p);
	}	
	free(p);
}
Node* mylist(Node* p){
	p=NULL;
	return(p);
}
Node* push(Node* p, int key)//push in the beginning
{
	Node* temp;
	temp=(Node*)malloc(sizeof(Node));
	if(p==NULL){
		p=temp;
		temp->data=key;
		temp->link=NULL;
		printf("printed %d \n",temp->data);
	}
	else{
		temp->link=p;
		temp->data=key;
		p=temp;
		printf("printed %d \n",temp->data);
	}
	return(p);
}
Node* pop(Node*p){//pop from the end
	Node* temp=p;
	if(p->link==NULL){
		printf("%d is removed \n",p->data);
		p=NULL;
		printf("List empty now");
	}
	else{
		Node* prev=NULL;
		while(temp->link!=NULL){
			prev=temp;
			temp=temp->link;
		}
		prev->link=NULL;
		printf("%d is removed \n",temp->data);
	}
	free(temp);
	return(p);
}	










	


