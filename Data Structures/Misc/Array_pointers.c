//Using array pointers to read arrays
#include<stdio.h>
void main(){
	int a[100][100];
	int m;
	scanf("%d",&m);
	void make(int(*a)[],int m);
	void out(int(*a)[],int m);
	make(a,m);
	out(a,m);
}
void make(int(*a)[100],int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void out(int(*a)[100],int m){
	int count=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]!=20){
				count++;
			}
		}
	}
	printf("%d",count);

}	

