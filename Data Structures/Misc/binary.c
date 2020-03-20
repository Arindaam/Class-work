// Convert any number to binary
#include<stdio.h>
int bin(int);
void main(){
	int a;	
	printf("Enter number:");
	scanf("%d",&a);
	printf("%d",bin(a));
}
int bin(int a){
	if(a==0){
		return(0);
	}
	else{
		return(a%2 + 10*bin(a/2));
	}
}
