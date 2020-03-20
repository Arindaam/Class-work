//Finding LCM of two numbers
#include<stdio.h>
const int a,b;
void main(){
	printf("Enter the numbers:");
	scanf("%d %d",&a,&b);
	int lcm(int,int,int,int);	
	int q=lcm(a,b,1,1);
	printf("%d is the lcm of %d and %d",q,a,b);
}
int lcm(int m,int n,int count_a,int count_b){
	if(m && n){	
		if(m==n){
			return(m);
		}
		else if(m>n){
			count_b++;
			n=b*count_b;
			return(lcm(m,n,count_a,count_b));
		}
		else{
			count_a++;
			m=a*count_a;
			return(lcm(m,n,count_a,count_b));
		}
	}
	else{
		return(0);
	}
}
		
