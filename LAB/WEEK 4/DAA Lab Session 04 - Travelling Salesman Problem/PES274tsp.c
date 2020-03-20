// Header file for travelling salesman problem

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int tsp(int n, int graph[][n]){
    int* v_arr=(int*)malloc(sizeof(int)*n);
    int i,min,sum;
    min=0;
    for(i=0;i<n;i++){
        v_arr[i]=i;
    }
    do{
        sum=0;
        for(int j=0;j<n-1;j++){
            sum+=graph[v_arr[j]][v_arr[j+1]];
        }
        sum+=graph[v_arr[n-1]][v_arr[0]];
        if(min==0){
            min=sum;
        }
        else if(sum<min){
            min=sum;
        }
    }
    while(get_next_permutation(v_arr,n));
    return min;
}               

// Returns an array of size n, 
// starting at city_0 (that is the first node) 
// traversing the path with min-cost
// Note: Return the path which is lexicographically smaller in case two paths have the same cost
int* printPath(int n, int graph[][n]){
    int* v_arr=(int*)malloc(sizeof(int)*n);
    int i,sum,cost;
    cost=tsp(n,graph);
    for(i=0;i<n;i++){
        v_arr[i]=i;
    }
    do{
        sum=0;
        for(int j=0;j<n-1;j++){
            sum+=graph[v_arr[j]][v_arr[j+1]];
        }
        sum+=graph[v_arr[n-1]][v_arr[0]];
        if(sum==cost){
            return v_arr;
        }
    }
    while(get_next_permutation(v_arr,n));
    return ;
}

// Given a permutation of path - P[], 
// Return the cost from the starting city through the path and back
// P[0] -> P[1] -> ... -> P[n-1] -> P[0]
int getCost(int n, int graph[][n], int *P){
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum+=graph[P[i]][P[i+1]];
    }
    sum+=graph[P[n-1]][P[0]];
    return sum;
}
// Get the next permutation in lexicographical order
// Returns 0 if there is no permutation which lexicographically bigger 
// Implemented in tsp_sampletest.c and tsp_tests.c
// Not to be implemented as a part of lab session
int get_next_permutation(int *permutation, int n);
