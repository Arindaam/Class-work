#include<stdio.h>
#include<stdlib.h>

int main(){
    int heap[15];
    void read(int*);
    void display(int*,int);
    read(&heap);
    void bot_heap(int*);
    //bot_heap(&heap);
    void top_heap(int*,int);
    int count =15;
    top_heap(&heap,count);
    top_heap(&heap,count);
    int delete(int*,int);

    count=delete(&heap,count);
}

void read(int* heap){
    for(int i=1;i<=15;i++){
        printf("Enter element: \n");
        scanf("%d",&heap[i]);
    }
}
void display(int* heap,int count){
    for(int i=1;i<=count;i++){
        printf(" element: \n");
        printf("%d \n",heap[i]);
    }
}

void bot_heap(int* a){
    for(int k=15/2;k>=1;k--){ // if starting from 1...then n/2 to 1 and 2*i ...if starting from 0 then n/2-1 to 0 and 2*i+1...if number of elements is n and u pass n-1 and start from 0... then n-1/2 to 0 and 2*i+1  
        int i=k;
        int j=2*i;
        int flag=0;
        while(j<=15 && !flag){
            if(a[j]<a[j+1] && j+1<=15 ){
                j++;
            }
            if(a[i]<a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i=j;
                j=2*i;
            }
            else{
                flag=1;
            }
        }
    }
}
void top_heap(int* a,int count){
    for(int k=2;k<=count;k++){
        int i=k; //i is the child
        int j=i/2; // j is the parent
        int flag=0;
        while(j>=1 && !flag){
            if(a[i]<a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                i=j; //previous parent becomes child
                j=i/2; //check is parent of previous parent(grand-parent) with the child now at index of the  parent
            }
            else{
                flag=1;
            }
        }
    }
}

int delete(int* a,int count){
    printf("%d",a[1]);
    int temp=a[1];
    a[1]=a[count];
    a[count]=temp;
    count--;
    top_heap(&a,count);
    return(count);
}

//Heapify vs Top_down is that top down is to make the entire array to heap...whereas heapify is used when u swap last and max value and now want to put the swapped element in right place.
