// using disjoint set, determine if an undirected graph is cyclic or not.
#include<bits/stdc++.h>
using namespace std;
vector<int> dsuf;
int find(int v)
{
    if(dsuf[v]==-1)
    return v;
    return find(dsuf[v]);
}
void union_op(int fromP, int toP)
{
  int f = find(fromP);
  int t = find(toP);
  dsuf[f] = t;
}
bool iscyclic(vector<pair<int,int>> &edge_list)
{
    for(auto p: edge_list)
    {
        int fromP = find(p.first);
        int toP = find(p.second);
        if(fromP==toP)
        return true;
        union_op(fromP,toP);
    }
    return false;
}
int main()
{
    int v,e;
    cin>>v>>e;
    dsuf.resize(v,-1); // to store the parent nodes
    vector<pair<int,int> > edge_list; // to store the edges
    for(int i=0;i<e;i++)
    {
        int fromP,toP;
        cin>>fromP>>toP;
        edge_list.push_back({fromP,toP});
    }
    if(iscyclic(edge_list))
    cout<<"cycle detected";
    else cout<<"Cycle not exists";
    return 0;
}