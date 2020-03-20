#include<stdio.h>
#include<stdlib.h>
typedef struct Hash {
    int* tabl;
    int size;
}hash;

hash* init_ta(){
    hash* temp=(hash*)malloc(sizeof(hash));
    int syz;
    printf("Enter the szize of your table: \n");
    scanf("%d",&syz);
    temp->size=syz;
    temp->tabl=(int*)malloc(sizeof(int)*syz);
    for(int i=0;i<syz;i++){
        temp->tabl[i]=-1;
    }
    return temp;
}

void insert(hash* table,int ele){
    int count=0;
    int index=ele%table->size;
    while(table->tabl[index]!=-1 && count!=table->size){
        index=(index+1)%table->size;
        count++;
    }
    if(count==table->size){
        return;
    }
    else{
        table->tabl[index]=ele;
    }
}

void search(hash* table,int ele){
    int count=0;
    int index=ele%table->size;
    while(table->tabl[index]!=-1 && count!=table->size){
        if(ele==table->tabl[index]){
            printf("FOUND");
            return;
        }
        index=(index+1)%table->size;
        count++;
    }   
    if(count==table->size){
        printf("NOPE fully traversed");
        return;
    }
    printf("Nope Found empty slot");
}

void main(){
    hash* table= init_ta();
    int ch,ele,loop=1;
    while (loop){
        printf("Enter your choice: \n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter your element: \n");
                    scanf("%d",&ele);
                    insert(table,ele);
                    break;
            case 2: printf("Enter the element to be searched \n");
                    scanf("%d",&ele);
                    search(table,ele);
                    break;
            default:   
                    loop=0;
                    break;
        }
    }
}


