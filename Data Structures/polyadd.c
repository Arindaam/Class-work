#include<stdio.h>
#include<stdlib.h>
typedef struct poly{
	int coef;
	int pow;
	struct poly* link;
}poly;
poly* insert(poly*);
void display(poly*);
poly* add(poly*,poly*); 
void destroy(poly*);
void main(){
	poly* poly1,*poly2;	
	poly1=(poly*)malloc(sizeof(poly*));
	poly1=NULL;
	poly2=(poly*)malloc(sizeof(poly*));
	poly2=NULL;
	int i=1;
	while(i==1){
		printf("Insert term into polynomial 1\n");
		poly1=insert(poly1);
		printf("If you want to add more terms press 1:\n");		
		scanf("%d",&i);
	}
	i=1;
	while(i==1){
		printf("Insert term into polynomial 2\n");
		poly2=insert(poly2);
		printf("If you want to add more terms press 1:\n");
		scanf("%d",&i);
	}
	display(poly1);
	display(poly2);
	/*poly1=add(poly1,poly2);*/
	display(poly1);
	destroy(poly1);
	destroy(poly2);
	free(poly1);
	free(poly2);
}
poly* insert(poly* poly1){
	int coef,pow;
	poly* temp;
	temp=(poly*)malloc(sizeof(poly));
	printf("Enter the Coefficient \n");
	scanf("%d",&coef);
	printf("Enter power of x \n");
	scanf("%d",&pow);
	temp->coef=coef;
	temp->pow=pow;
	if(poly1==NULL){
		poly1=temp;
		temp->link=NULL;
	}
	else{
		poly* next;
		poly* prev;
		next=poly1;
		if(next->coef>temp->coef){
			temp->link=poly1;
			poly1=temp;
		}
		else{
			while(next!=NULL && next->pow<temp->pow){
				prev=next;
				next=next->link;
			}
			prev->link=temp;
			temp->link=next;
		}
	}
	return(poly1);
}
void display(poly* poly1){
	if(poly1==NULL){
		printf("EMPTY");
	}
	else{
		while(poly1!=NULL){
			printf("%d,%d \n",poly1->coef,poly1->pow);
			poly1=poly1->link;
		}
	}
}
void destroy(poly* poly1){
	if(poly1==NULL){	
	}
	else{	
		poly* tempa;
		while(poly1!=NULL){
			tempa=poly1;			
			poly1=poly1->link;
			free(tempa);
		}
		free(poly1);
	}
}			
poly* add(poly* poly1,poly* poly2){
	poly* temp;
	poly* res;	
	if (poly1==NULL){
		return(poly2);
	}
	if (poly2==NULL){
		return(poly2);
	}
	if(poly1->pow < poly2->pow){	
		temp=poly2;
		poly2=poly2->link;
	}
	else if(poly2->pow < poly1->pow){
		temp=poly1;
		poly1=poly1->link;
	}
	else{
		temp=poly1;
		temp->coef=poly1->coef+poly2->coef;
		poly1=poly1->link;
	}  
	res=temp;
	while(poly1!=NULL && poly2!=NULL){	
		if(poly1->pow > poly2->pow){
			temp->link=poly1;
			temp=temp->link;
			poly1=poly1->link;
		}
		else if(poly1->pow<poly2->pow){
			temp->link=poly2;
			temp=temp->link;
			poly2=poly2->link;
		}
		else{
			poly1->coef=poly1->coef+poly2->coef;
			temp->link=poly1;
			temp=temp->link;
			poly1=poly1->link;
		}
	}
	return(res);
}
			
