#include<bits/stdc++.h>
using namespace std;
#define v 4
int min(int a,int b)
{
    if(a < b)
    return a;
    else return b;
}
int shortestpath(int graph[v][v],int src,int dest,int k)
{
    if(k==0 && src == dest) return 0;
    if(k==1 && graph[src][dest]) return graph[src][dest];
    if(k<=0) return INT_MAX;
    int res = INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(graph[src][i]!=0 && src!=i && dest!=i)
        {
            int res1 = shortestpath(graph,i,dest,k-1);
            res = min(res , res1 + graph[src][i]);
        }
    }
    return res;

}
int main()
{
    int graph[v][v] = {{0,10,3,2},
                       {0,0,0,7},
                       {0,0,0,6},
                       {0,0,0,0}};
    int src,dest,k;
    cin >> src >> dest >> k;
    int total;
    total = shortestpath(graph,src,dest,k);
    if(total)
    cout<<"Minimum weight from "<<src<<" to "<<dest<<" = "<<total;
    else
    cout<<"No path of lenght k is available ";

}