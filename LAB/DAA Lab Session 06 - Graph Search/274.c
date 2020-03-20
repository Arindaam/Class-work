/*#include<stdio.h>
#include"graphSearch.h"
#include<stdbool.h>
void dfs(int s,int n,const int graph[][n],int v[],int p,int *check){
       v[s]=1;
       for(int i=0;i<n;i++){
            if(v[i]==0 && graph[s][i]==1){
                    dfs(i,n,graph,v,s,check);
            }
            else if(v[i]==1 && graph[s][i]==1 && i!=p){
                *check=1;
            }
       }
}
bool isTree(int n, const int graph[][n])
{
    int v[n];
    int p=-1;
    int check=0;
    for(int i=0;i<n;i++){
        v[i]=0;
    }
    dfs(0,n,graph,v,p,&check);
    if(check==1){
        return false;
        }
    for(int i=0;i<n;i++){
            if(v[i]==0){
                   return false;
            }
    }
    return true;
}
void dfs1(Result *r,int s,int n,const int graph[][n],int v[]){
       v[s]=1;
       for(int i=0;i<n;i++){
            if(v[i]==0 && graph[s][i]==1){
                    r->maxHouses++;
                    dfs1(r,i,n,graph,v);
            }
       }
}
Result pepesAnswers(int n, const int safeSeq[][n]){
    int v[n];
    for(int i=0;i<n;i++){
        v[i]=0;
    }
   
    int max=-1;
    Result re;
    re.numDeliveryFrogs=0;
    for(int i=0;i<n;i++){
        if(v[i]==0){
        re.numDeliveryFrogs++;
        dfs1(&re,i,n,safeSeq,v);
        if(re.maxHouses>max){
                max=re.maxHouses;
        }
    }
    }
    re.maxHouses=max;
    
    return re;
 }
 Result pepesAnswersWithK(int n, const int safeSeq[][n], int k){
 
       int v[n];
    for(int i=0;i<n;i++){
        v[i]=0;
    }

    int max=-1;
    Result re;
    re.numDeliveryFrogs=0;
    for(int i=0;i<n;i++){
        if(v[i]==0){
        re.numDeliveryFrogs++;
        dfs1(&re,i,n,safeSeq,v);
        if(re.maxHouses>max){
                max=re.maxHouses;
        }
    }
    }
        re.maxHouses=max;
    
    return re;
    }
    
 */ 
 #include<stdbool.h>
#include "graphSearch.h"

int max = 0;
int count = 0;

bool isCyclic(int u, bool visited[], int parent, int n, const int graph[][n])
{
  visited[u] = true;
  for(int v = 0; v<n; v++)
  {
    if(graph[u][v])
    {
      if(!visited[v])
      {
        if(isCyclic(v, visited, u, n, graph))
        {
               return true;
        }
      }
      else if(v != parent)
      {    //when adjacent vertex is visited but not parent
        return true;    //there is a cycle
      }
    }
  }
   return false;
}

bool isTree(int n, const int graph[][n])
{
  bool visited[n];
  for (int i = 0; i < n; i++)
    visited[i] = false;
  if (isCyclic(0, visited, -1, n, graph))
    return false;
  for (int i = 0; i < n; i++)
    if (!visited[i])
      return false;

return true;
}

void DFS(int v, bool visited[], int n, const int graph[][n])
{
  count++;
  visited[v] = true;
  for(int i = 0; i<n; i++)
  {
    if(graph[v][i] && !visited[i])
    {
      DFS(i, visited, n, graph);
    }
  }
}

Result pepesAnswers(int n, const int safeSeq[][n])
{
  bool visited[n];
  int comp = 0;
  for(int v = 0; v < n; v++)
  {
    visited[v] = false;
  }
  for(int v = 0; v < n; v++)
  {
    if(visited[v] == false)
    {
      count = 0;
      DFS(v, visited, n, safeSeq);
      comp += 1;
      if(count > max)
        max = count;
    }
  }

  Result res;
  res.numDeliveryFrogs = comp;
  res.maxHouses = max;
  return res;

}


Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
        bool visited[n];
  int comp = 0;
  for(int v = 0; v < n; v++)
  {
    visited[v] = false;
  }
  for(int v = 0; v < n; v++)
  {
    if(visited[v] == false)
    {
      count = 0;
      DFS(v, visited, n, safeSeq);
      comp += 1;
      if(count > max)
        max = count;
    }
  }

  Result res;
  res.numDeliveryFrogs = comp;
  res.maxHouses = max;
  return res;
}  
