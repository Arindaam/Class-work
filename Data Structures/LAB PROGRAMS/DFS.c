#include<stdio.h>
#include<stdlib.h>

typedef struct stackk{
    int *b;
    int size;
    int top;
}st;

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
        if(src==-1 || des==-1 || src>n || des>n || src<-1 || des<-1 ){
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
        if(src<0 || des<0 || src>n || des>n){
            break;
        }
        node*temp=(node*)malloc(sizeof(node));
        temp->data=des;
        temp->link=a[src];
        a[src]=temp;
    }
} 
*/

int isfull(st* m){
    if(m->top==m->size){
        return 1;
    }
    return 0;
}

int isempty(st* m){
    if(m->top==-1){
        return 1;
    }
    return 0;
}

void push(st* m,int q){
    if(isfull(m)){
    }
    else{
        m->top++;
        m->b[m->top]=q;
    }
}

int pop(st* m){
    if(isempty(m)){
    }
    else{
        return(m->b[m->top--]);
    }
}

/*
void dfs(int **a,int n,int v){ //adjacency matrix
     st* m=(st*)malloc(sizeof(st));
    m->b=(int*)malloc(sizeof(int)*n+1);
    m->size=n;
    m->top=-1;
    int* visit=(int*)malloc(sizeof(int)*n+1);
    for(int i=0; i<=n;i++){
        visit[i]=0;
    }
    visit[v]=1;
    push(m,v);
    while(!isempty(m)){
        int curr=pop(m);
	    printf("%d",curr);
        for(int u=0;u<=n;u++){
            if(a[curr][u]==1 && visit[u]==0){
                push(m,u);
                visit[u]=1;
            }
        }
    }
}
*/

/*
void dfs(node **a,int n,int v){ //adjacency list
    st* m=(st*)malloc(sizeof(st));
    m->b=(int*)malloc(sizeof(int)*n+1);
    m->size=n;
    m->top=-1;
    int* visit=(int*)malloc(sizeof(int)*n+1);
    for(int i=0; i<=n;i++){
        visit[i]=0;
    }
    visit[v]=1;
    push(m,v);
    while(!isempty(m)){
        int curr=pop(m);
	printf("%d.",curr);
        node* temp=a[curr];
        while(temp!=NULL){
            if(visit[temp->data]==0){
                visit[temp->data]=1;
                push(m,temp->data);
            }
            temp=temp->link;
        }
    }
}
*/

/*
void dfs(node **a,int n,int v,int*visit){ //adjacency list recursive
    visit[v]=1;
    printf("%d",v);
    node* temp=a[v];
    while(temp!=NULL){
        if(visit[temp->data]==0){
            visit[temp->data]=1;
            dfs(a,n,temp->data,visit);
        }
        temp=temp->link;
    }
}
*/

/*
void comp(int **a,int n,int v,int*visit,int d){ //components using adjacency matrix
    visit[v]=d;
    printf("%d,",v);
    for(int i=0;i<=n;i++){
        if(a[v][i]==1 && visit[i]==0){
            comp(a,n,i,visit,d);
        }
    }
}
*/

/*
int dfsn(node **a,int n,int v,int*visit,int d){ //finding path using adjacency list
    visit[v]=1; 
    node* temp=a[v];
    while(temp!=NULL){
        if(visit[temp->data]==0){
            if(temp->data==d){
                printf("%d,",temp->data);
                return 1;
            }
            int val=dfsn(a,n,temp->data,visit,d);
            if(val==1){visit[i]=1;
                printf("%d,",temp->data);
                return 1;
            }
        }
        temp=temp->link;    
    }
    if(temp==NULL){
        return -1;
    }
}
*/

void dfs(int **a,int n,int v,int*visit){ //adjacency matrix recursive
    visit[v]=1;
    for(int i=0;i<=n;i++){
	if(a[v][i]==1 && visit[i]==0){
		visit[i]=1;		
		dfs(a,n,i,visit);
	}
    }
}

void conn(int** a,int n){
	int* visit=(int*)malloc(sizeof(int)*n+1);
    	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			visit[j]=0;
		}
		dfs(a,n,i,visit);
		for(int k=0;k<=n;k++){
			if(visit[k]!=1){
				int** z=a;
				for(int g=0;g<=n;g++){
					visit[g]=0;
				}				
				for(int b=0;b<=n;b++){
					for(int c=0;c<=n;c++){
						if(z[b][c]==1){
							z[b][c]=z[c][b]=1;
						}
					}
				}
				dfs(z,n,1,visit);
				for(int y=0;y<=n;y++){
					if(visit[y]!=1){
						printf("Not Connected");
						return;
					}
				}
				printf("Weakly Connected");
				return;
			}
		}
	}
	printf("Strongly Connected");
}


void main(){
    int n;
    printf("Enter the number of elements in graph: \n");
    scanf("%d",&n);

    int **a=(int**)malloc(sizeof(int*)*n+1); //adjacency matrix
    for(int i=0;i<=n;i++){
        a[i]=(int*)malloc(sizeof(int)*n+1);
    }
    
    //node**a = (node**)malloc(sizeof(node*)*n+1); // adjacency list
    
    create(a,n);
    int v,d=1;
    /*
    int* visit=(int*)malloc(sizeof(int)*n+1);
    for(int i=0; i<=n;i++){
        visit[i]=0;
    }
    */
    /*
    printf("Enter starting point:\n");
    scanf("%d",&v);
    */
    
    //dfs(a,n,v);
    
    /*
    printf("Enter end point:\n");
    scanf("%d",&d);
    dfsn(a,n,v,visit,d);    
    printf("%d",v);
    */
    
    /*
    for(int k=0;k<=n;k++){
        if(visit[k]==0){
            printf("%d \n",d);
            comp(a,n,k,visit,d);
            printf("\n");
            d++;
        }
    }
    */
    conn(a,n);
}
