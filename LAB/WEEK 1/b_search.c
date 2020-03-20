#include<stdio.h>
#include<stdlib.h>
void bsort(int*,int);
//void bsearch(int*,int,int);
int main(){
    int a[100];
    int choice=1;
    int i=0;
    int key;
    while(choice==1 && i<100){
        printf("Enter the number: \n");
        scanf("%d",&a[i]);
        i++;
        printf("If you want to enter more, press 1:\n");
        scanf("%d",&choice);
    }
    bsort(&a,i);
    printf("Enter element to be searched:\n");
    scanf("%d",&key);
    bsearch(&a,i,key);
    return 0;
}
void bsort(int* a,int index){
    for(int i=0;i<=index-1;i++){
        for(int j=0;j<=index-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void bsearch(int* a,int index,int key){
    int max=index;
    int min=0;
    while(max>=min){
        int mid=(max+min)/2;     
        if(a[mid]==key){
            printf("found");
        }
        else if(a[mid]<key){
            max=mid-1;
        }
        else{
            min=max+1;
        }
    }
}
