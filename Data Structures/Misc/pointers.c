// Using pointers to add numbers
#include<stdio.h>
void main(){
	void add(int*,int*);	
	int a,b;
	printf("Enter the Numbers:");
	scanf("%d %d",&a,&b);
	add(&a,&b);
}
void add(int* a, int* b){
	printf("%d",*a+*b);
}
