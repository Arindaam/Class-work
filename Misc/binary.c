#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void binary(int r,int m)
{
    int b[m];
    for(int i=0;i<m;i++)
        b[i] = 0;
    for(int y=m-1;r>0 && y>=0;y--)
    {
        b[y] = r%2;
        r = r/2;
    }
    for(int j=0;j<m;j++)
        printf("%d",b[j]);
    printf("\n");
}

int main()
{
    int m=3;
    int y=2;
    int n=1;
    for(int i=0;i<m;i++)
        n = n*y;    
    for(int i=0;i<n;i++)
    {
        binary(i,m);
    }
}