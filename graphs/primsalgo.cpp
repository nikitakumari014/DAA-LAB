#include<bits/stdc++.h>
using namespace std;
#define V 6
int min_vertex(vector<int> &value, vector<bool> &setMst)
{
    int min= INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(setMst[i]==false && value[i]<min)
        {
            vertex = i;
            min = value[i];
        }
    }
    return vertex;
}
void findMst(int graph[V][V])
{
    int parent[V];
    vector<int> value(V,INT_MAX);
    vector<bool> setMst(V,false);
    parent[0] = -1;
    value[0] = 0;
    // the main algorithm.
//From mst with v-1 number of edges
for(int i=0;i<V-1;i++)
{
    int u = min_vertex(value,setMst); // select the node with minimum number of weight and is not present in mst(==false).
    setMst[u] = true; // include that in the mst
    // relax all the adjacent vertices
    for(int j=0;j<V;j++)
    {
        // '''
        // condition to relax:
        //  1. there must be an edge present from u to j
        //  2. vertex j must not be present in the setmst
        //  3. edge weight is smaller than the current weight 
        // '''
        if(graph[u][j]!=0 && setMst[j]==false && graph[u][j]<value[j])
        {
            value[j] = graph[u][j];
            parent[j] = u;
        }

    }
}
// print mst
for(int i=1;i<V;i++)
{
    cout<<parent[i]<<"->"<<i<<"= "<<graph[parent[i]][i]<<endl;
}
}
int main()
{
    int graph[V][V] = {{0,4,6,0,0,0},
                       {4,0,6,3,4,0},
                       {6,6,0,1,8,0},
                       {0,3,1,0,2,3},
                       {0,4,8,2,0,7},
                       {0,0,0,3,7,0}};
    findMst(graph);
}