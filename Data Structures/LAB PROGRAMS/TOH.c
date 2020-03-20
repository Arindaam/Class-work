#include<stdio.h>
void toh(int n, char s, char t, char d){
        if(n==1){
            printf("%d is moved from %c to %c \n",n,s,d);
        }
        else{
            toh(n-1,s,d,t);
            printf("%d is moved from %c to %c \n",n,s,d);
            toh(n-1,t,s,d);
        }
}
void main(){
    toh(3,'s','t','d');
}