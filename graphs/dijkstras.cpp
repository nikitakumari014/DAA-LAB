#include<bits/stdc++.h>
using namespace std;
#define V 6
int min_vertex(vector<int> &value, vector<bool> &status)
{
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(value[i] < min  && status[i]==false){
           min = value[i];
           vertex = i;
        }
    }
    return vertex;
}
void dijkstra(int graph[V][V])
{
    int parent[V];
    vector<int> value(V,INT_MAX);
    vector<bool> processed(V,false);
    parent[0]=-1;
    value[0]=0;
    for(int i=0;i<V-1;i++)
    {
        int u = min_vertex(value,processed);
        processed[u] = true;
        for(int j=0;j<V;j++)
        {
            if(graph[u][j]!=0 && processed[j]==false && (value[j] > graph[u][j]+value[u]) && value[u]!=INT_MAX)
            {
                value[j] = graph[u][j] + value[u];
                parent[j] = u;
            }
        }
    }
    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<" to "<< i << " = "<<graph[parent[i]][i]<<endl;
    }
}
int main()
{
    int graph[V][V] = {{0,1,4,0,0,0},
                       {1,0,4,2,7,0},
                       {4,4,0,3,5,0},
                       {0,2,3,0,4,6},
                       {0,7,5,4,0,7},
                       {0,0,0,6,7,0}};
    dijkstra(graph);
    return 0;
}