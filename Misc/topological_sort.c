#include <stdio.h>
 
int main(){
	int i,j,k,n,count=0;
	printf("Enter the no of vertices:\n");
	scanf("%d",&n);
      const int m=n;
      int a[m][m],indeg[m],flag[m];
      
      for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                  a[i][j]=0;
            }
      }   
            
      while(1){
            printf("Enter source and dest: \n");
            scanf("%d %d",&i,&j);
            if(i>n || j>n ||i==j){
                  break;
            }
            a[i-1][j-1]=1;
      }
      
	for(i=0;i<n;i++){
        indeg[i]=0;
        flag[i]=0;
    }
       
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indeg[i]=indeg[i]+a[j][i];
    
    for(i=0;i<n;i++){
      printf("\n %d ",indeg[i]);
    }
    
    printf("\nThe topological order is:");
 
    while(count<n){
        for(k=0;k<n;k++){
            if((indeg[k]==0) && (flag[k]==0)){
                printf("%d ",(k+1));
                flag [k]=1;
            }
 
            for(i=0;i<n;i++){
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }
 
        count++;
    }
 
    return 0;
}

