// Print row of a matrix 
#include<stdio.h>
void main(){
	int n,m;
	int row;
	void search(int(*a)[],int,int,int);	
	printf("Enter the number of rows \n");
	scanf("%d",&m);
	printf("Enter the number of columns \n");
	scanf("%d",&n);
	int a[100][100];
	printf("Enter the elements in matrix rowwise \n");
	for(int q=0;q<m;q++){
		for(int k=0;k<n;k++){
			scanf("%d",&a[q][k]);		
		}
	}
	printf("enter row value \n");
	scanf("%d",&row);
	search(a,m,n,row);
}
void search(int (*a)[100], int m ,int n,int row){
	if(row>m){
	}
	else{
		for(int i=0;i<n;i++){
			printf("%d",a[row-1][i]);
		}
	}
}
