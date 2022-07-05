// to detect cycles in a directed graph
#include<bits/stdc++.h>
using namespace std;
bool isCyclic_util(vector<int> g[],vector<bool> visited,int curr)
{
    if(visited[curr]==true)
    return true;
    visited[curr] = true;
    bool flag = false;
    for(int i=0;i<g[curr].size();i++)
    {
        flag = isCyclic_util(g,visited,g[curr][i]); 
        if(flag==true)
        return true;
    }
    return false;
}
bool isCyclic(int v,vector<int>g[])
{
    vector <bool> visited(v,false);
    bool flag = false;
    for(int i=0;i<v;i++)
    {
        visited[i] = true;
        for(int j=0;j<g[i].size();j++)
        {
            flag = isCyclic_util(g,visited,g[i][j]);
            if(flag==true)
            return true;
    }
    visited[i] = false;
   }
   return false;
}
int main()
{
    int n,e;
    cin >> n >>e;
    vector<int> g[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    cout<<isCyclic(n,g)<<endl;;
}