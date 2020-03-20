#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char * sort(char * a)
{
int n=  strlen(a);

for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n-1; j++)
  {
    if(a[j]>a[j+1])
    {
      int temp = a[j+1];
      a[j+1] = a[j];
      a[j] = temp;
    }
  }
  }
  return a;
}
int strmatch(char * f , char * b)
{
int n=  strlen(f);
for(int i= 0;i<n ;++i )
      {
      if(f[i]!=b[i])
            return 0;
      }
      return 1;
}
void anagram(char *str,char a[][1000])
{

int n= strlen(str);
for(int i = 0;i<6; ++i)
      {
      int m = strlen(a[i]);
      if(m==n)
            {
            char c[n];
            strcpy(c,a[i]);
            char * f = sort(str);
            char * b = sort(c);
            int d = strmatch(f,b);
            if(d)
                  printf("%s\n",a[i]);
            }
      }
}
int main()
{
    char a[7][1000]={"ate","eat","pea","dog","god","cat","act"};
    char b[3][1000]={"eat","dog","cat"};
    int n = 3;
    for(int i=0 ;i<n;++i )
      {
      printf("%d)\n",i+1);
      anagram(b[i],a);
      }
}

