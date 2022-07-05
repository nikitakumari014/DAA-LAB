#include<bits/stdc++.h>
using namespace std;
#define v 3
struct edge
{
    int src,dest,wt;
};
void bellmanford(vector<edge> &edge,int e)
{
    int parent[v];
    int cost_parent[v];
    vector<int> value(v,INT_MAX);
    parent[0] = -1;
    value[0] = 0;
    bool updated;
    for(int i=0;i<v-1;i++)
    {
        updated= false;
        for(int j=0;j<e;j++){
        int u = edge[i].src;
        int v1 = edge[i].dest;
        int w = edge[i].wt;
        if(value[u]!=INT_MAX and value[u]+ w <value[v1])
        {
          value[v1] = w + value[u];
          parent[v1] = u;
          cost_parent[v1] = value[v1];
          updated = true;
        }
        }
        if(updated==false)
        break;
    }
    for(int j=0;j<e && updated==true; j++)
    {
        int u = edge[j].src;
        int v1 = edge[j].dest;
        int w = edge[j].wt;
        if(value[u]!=INT_MAX && value[u]+w < value[v1])
        {
            cout<<"Graph has -ve edge cycle";
            return;
        }
    }
    for(int i=1;i<v;i++)
    {
        cout<<parent[i]<<" "<<i<<" = "<<value[i]<<endl  ;
    }
}
int main()
{
    int e;
    cin>>e;
    vector <edge> edge(e);
    int src,dest,wt;
    for(int i=0;i<e;i++)
    {
        cin>>src>>dest>>wt;
        edge[i].src = src;
        edge[i].dest = dest;
        edge[i].wt = wt;
    }
    bellmanford(edge,e);
    return 0;
}