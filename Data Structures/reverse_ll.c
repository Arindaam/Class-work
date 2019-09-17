#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* link;
}node;
typedef struct List{
	node* head;
}list;
void main()
{
	list* p;
	p=(list*)malloc(sizeof(list));
	p->head=NULL;
	int ele;
	void insert(int,list*);
	void rev(list*,int,list*);
	void destroy(list*);
	void print(list*);
	int i=1;
	int ch;
	while(i==1){
		printf("Enter element\n");
		scanf("%d",&ele);
		insert(ele,p);
		printf("If you want add elements press 1:\n");
		scanf("%d",&ch);
		if (ch!=1){
			i=0;
		}
	}	
	rev(p,0,NULL);
	print(p);
	destroy(p);
	free(p);
}
void insert(int ele, list* p){
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->data=ele;
	if(p->head==NULL){
		p->head=temp;
		temp->link=NULL;
	}
	else{
		node* tem;
		tem=p->head;
		while(tem->link!=NULL){
			tem=tem->link;
		}
		tem->link=temp;
		temp->link=NULL;
	}
}
void rev(list* p,int i,list* res){	
	node* temp;
	node* num;
	node* next;
	list* nxt;	
	if(p->head==NULL){
	}
	else{	
		if(i==0){
			res=p;
			num=p->head;
		}
		i++;
		next=p->head;
		if(next->link==NULL){
			res->head=next;
		}
		else{
			temp=next;
			next=next->link;
			nxt->head=next;
			rev(nxt,i,res);
			next->link=temp;
		}
		num->link=NULL;
	}
}
void print(list* p){
	if(p->head==NULL){
		printf("List empty");
	}
	else{
		node* temp;	
		temp=p->head;	
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->link;
		}
	}
}	
void destroy(list* p){
	if(p->head==NULL){
	}
	else{
		node* temp;		
		node* next;
		temp=p->head;
		while(temp->link!=NULL){
			next=temp;
			temp=temp->link;
			free(next);
		}
		free(temp);	
	}
}
			

