// Finding HCF of two numbers
#include<stdio.h>
void main(){
	int a,b;
	int hcf(int,int);
	printf("Enter the two numbers: \n");
	scanf("%d %d",&a,&b);
	int h=hcf(a,b);
	printf("GCD of %d and %d is: %d",a,b,h);
}
int nxtpr(int prev,int* a){ //Function which gives the next odd prime number	
	if(prev==2){
		a[0]=3;	// This array stores the previous prime numbers which helps us generate the next ones	
		return(3);
	}
	else{
		prev=prev+2;
		int i=0;	
		while(a[i]!=0){
			if(prev%a[i]==0){
				prev=prev+2;
				return(nxtpr(prev,a));				
			}
		i++;
		}
		a[i]=prev;
	}	return(prev);
}
			
int hcf(int a , int b){
	int m[100]={0};
	int small;	
	if(a>b){
		small=a;
	}
	else{
		small=b;
	}
	if(a%2==0 && b%2==0){
		return(2*hcf(a/2,b/2)); //Checks if 2 is a common factor. If so we find the GCF of the two numbers after both are divided by 2. In the first step itself, the even factors are filtered out. 
	}
	else{
		int prev=2;
		int nxt=nxtpr(prev,&m);
		while(nxt<=small && (a%nxt!=0 || b%nxt!=0)){//This generates prime numbers till we get a commn divisor or the prime number becomes greater than the smaller of the two numbers.
			prev=nxt;
			nxt=nxtpr(prev,&m);
		}
		if(nxt>small){
			return 1;
		}
		else{
			return(nxt*hcf(a/nxt,b/nxt));// Similar to the step where we find the even factors
		}
	}
}
			

	

