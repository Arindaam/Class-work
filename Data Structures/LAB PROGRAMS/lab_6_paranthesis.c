#include<stdlib.h>
#include<stdio.h>

typedef struct stack{
    char* arr;
    int top;
    int size;
}Stack;

int main(){
    char p[30];
    int paranthesis_checking(char*);
    printf("Enter the expression: \n");
    scanf("%s",p);
    int m=paranthesis_checking(p);
    printf("%d",m);
    return 0;
}

int paranthesis_checking(char* p){
    int is_empty(Stack*);
    int is_full(Stack*);
    void push(Stack*,char);
    void pop(Stack*);
    Stack* stck=(Stack*)malloc(sizeof(Stack));
    printf("Enter size of stack: \n");
    scanf("%d",&stck->size);
    stck->arr=(char*)malloc(sizeof(char)*stck->size);
    stck->top=-1;
    for(int i=0; p[i]!='\0';i++){
        char ch=p[i];
        if (ch=='{' || ch=='(' || ch=='['){
            push(stck,ch);
        }
        else if(ch=='}' || ch==')' || ch==']'){
            switch(ch){
                case '}':   if(stck->arr[stck->top]=='{'){
                                pop(stck);
                            }
                            else{
                                printf("1");
                                return 0;
                            }
                case ']':   if(stck->arr[stck->top]=='['){
                                pop(stck); 
                            }
                            else{   
                                printf("2");
                                return 0;
                            }
                case ')':   if(stck->arr[stck->top]=='('){
                                pop(stck);
                            }
                            else{
                                printf("3");
                                return 0;
                            }
            }
        }
    }
    
    printf("finish \n");
    printf("%d \n",stck->top);
    if(is_empty(stck)){
        free(stck);
        return(1);
    }
    free(stck);
    return(0);
}    

int is_empty(Stack* stck){
    if(stck->top==-1){
        return(1);
    }
    return(0);
}
int is_full(Stack* stck){
    if(stck->top==stck->size){
        return(1);
    }
    return(0);
}
void push(Stack* stck, char ch){
    if(is_full(stck)){
    }
    else{
        stck->arr[++(stck->top)]=ch;
    }
}
void pop(Stack* stck){
    if(is_empty(stck)){
    }
    else{
        stck->top--;
    }
}