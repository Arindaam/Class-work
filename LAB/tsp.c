#include"tsp.h"
#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

int tspBacktrackRecursive(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int minCost)
{
    if(nodesVisited == n)
    {
        currentCost = currentCost + graph[v][0] ;
        minCost = currentCost;

        // printf("%d %d\n",minCost,currentCost);
        return minCost;
        
    }
    for(int i = 0;i<n;++i)
    {
        if(visited[i] == 0 && graph[v][i])
        {
            if(currentCost + graph[v][i] < minCost)
            {
                // currentCost = currentCost + graph[v][i];
                visited[i] = 1;
                minCost = min(minCost,tspBacktrackRecursive(i,n,graph,visited,nodesVisited+1,currentCost+graph[v][i],minCost));
                visited[i] = 0;
            }
        }
    }
    return minCost;
}

int tspBacktrackRecursivewp(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int minCost,int* path,int* minpath)
{
    if(nodesVisited == n)
    {
        if(currentCost + graph[v][0]<minCost) 
        {
            minCost = currentCost + graph[v][0];
            currentCost = minCost;
            for(int i = 0;i<n;i++)
            {
                minpath[i] = path[i];
            }
        }
        // printf("%d %d\n",currentCost,minCost);

        return minCost;
        
    }
    for(int i = 0;i<n;++i)
    {
        if(visited[i] == 0)
        {
            if(currentCost + graph[v][i] < minCost)
            {
                // currentCost = currentCost + graph[v][i];
                visited[i] = 1;
                path[nodesVisited]=i;
                minCost = min(minCost,tspBacktrackRecursivewp(i,n,graph,visited,nodesVisited+1,currentCost+graph[v][i],minCost,path,minpath));
                visited[i] = 0;
            }
        }
    }
    return minCost;
}


int tspBackTrack(int n, int graph[][n])
{
    bool* visited = (bool*)calloc(n,sizeof(bool));
    visited[0] = 1;
    return(tspBacktrackRecursive(0, n, graph, visited, 1, 0, 1000000));
}

int *printPath(int n, int graph[][n])
{
    int* p = (int*)malloc(sizeof(int)*n);
    int* min = (int*)malloc(sizeof(int)*n);

    bool* visited = (bool*)calloc(n,sizeof(bool));
    visited[0] = 1;
    p[0] = 0;
    min[0] = 0;
    tspBacktrackRecursivewp(0, n, graph, visited, 1, 0, 1000000,p,min);

    
    return(min);
}