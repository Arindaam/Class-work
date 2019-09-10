#include<stdio.h>
void main()
{
	int m=1000;
	int* p=&m;
	int* q=p;
	int** n=&p;
	int* g=&p;
	printf("%d \n",*p);
	printf("%p \n",p);
	printf("%p \n",&p);
	printf("%d \n",*q);
	printf("%p \n",q);
	printf("%p \n",*n);
	printf("%p \n",n);
	printf("%p \n",g);
	printf("%d \n",**n);
}

	
