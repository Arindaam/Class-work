#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int *q;
    int size;
    int front;
    int rear;
}qu;

typedef struct Node{ //adjacency list
    int data;
    struct Node* link;
}node;


void create(int** a,int n){ //using adjacency matrix
    for (int i=0;i<=n;i++){
        for(int j=0; j<n;j++){
            a[i][j]=0;
        }
    }
    int src,des;
    while(1){
        printf("enter the graph: \n");
        scanf("%d %d",&src,&des);
        if(src<0 || des<0 || src>n || des>n ){
            break;
        }
        a[src][des]=1;
    }
}
 
/*
void create(node** a,int n){ // adjacency list
    for (int i=0;i<=n;i++){
        a[i]=NULL;
    }
    int src,des;    
    while(1){
        printf("enter the graph: \n");
        scanf("%d %d",&src,&des);
        if(src<0 || des<0 || src>n || des>n ){
            break;
        }
        node*temp=(node*)malloc(sizeof(node));
        temp->data=des;
        temp->link=a[src];
        a[src]=temp;
    }
} 
*/
int isfull(qu* m){
    if(m->rear==m->size){
        return 1;
    }
    return 0;
}

int isempty(qu* m){
    if(m->front==-1){
        return 1;
    }
    return 0;
}

void enq(qu* m,int t){
    if(isfull(m)){
    }
    else if(isempty(m)){
        m->front++;
        m->q[++m->rear]=t;
    }
    else{
        m->q[++m->rear]=t;
    }
}

int dq(qu* m){
    if(isempty(m)){
    }
    else if(m->front==m->rear){
        int g =m->q[m->front];
        m->front=m->rear=-1;
        return g;
    }
    else{
        return(m->q[m->front++]);
    }
}

/*
void bfs(node **a,int n,int v,int* visit){ //adjacency list
    qu* m=(qu*)malloc(sizeof(qu));
    m->q=(int*)malloc(sizeof(int)*n+1);
    m->size=n;
    m->front=m->rear=-1;

    visit[v]=1;
    enq(m,v);
    printf("%d,",v);
    while(!isempty(m)){
        int curr=dq(m);
        node* temp=a[curr];
        while(temp!=NULL){
            if(visit[temp->data]==0){
                visit[temp->data]=1;
                printf("%d,",temp->data);
                enq(m,temp->data);
            }
            temp=temp->link;
        }
    }
}
*/

void bfs(int **a,int n,int v,int* visit){ //adjacency MATRIX
    qu* m=(qu*)malloc(sizeof(qu));
    m->q=(int*)malloc(sizeof(int)*n+1);
    m->size=n;
    m->front=m->rear=-1;

    visit[v]=1;
    enq(m,v);
    printf("%d,",v);
    while(!isempty(m)){
        int curr=dq(m);
        for(int i=0;i<=n;i++){
            if(a[curr][i]==1 && visit[i]==0){
                enq(m,i);
                printf("%d,",i);
                visit[i]=1;
            }
        }
    }
}

void main(){
    int n;
    printf("Enter the number of elements in graph: \n");
    scanf("%d",&n);
    
    int **a=(int**)malloc(sizeof(int*)*n+1); //adjacency matrix
    for(int i=0;i<=n;i++){
        a[i]=(int*)malloc(sizeof(int)*n+1);
    }

    /*
    node** a = (node**)malloc(sizeof(node*)*n+1); // adjacency list
    */

    int* visit=(int*)malloc(sizeof(int)*n+1);
    for(int i=0; i<=n;i++){
        visit[i]=0;
    }
    
    create(a,n);
    int v;
    printf("Enter root:\n");
    scanf("%d",&v);
    bfs(a,n,v,visit); 
}
