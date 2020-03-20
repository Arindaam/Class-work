// Sum of the digits of a number
#include<stdio.h>
#include<stdlib.h>
int sum(double);
#include<math.h>
void main(){
	double a;	
	printf("Enter the number");
	scanf("%lf",&a);
	printf("Sum of digits is: %d",sum(a));
}	
int sum(double a){	
	int p=fmod(a,10);
	int q=a/10;
	if(p==0 && q==0){
		return 0;
	}
	else{
		return(p+sum(q));	
	}
}
