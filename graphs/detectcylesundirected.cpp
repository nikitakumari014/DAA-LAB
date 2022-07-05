#include<bits/stdc++.h>
using namespace std;
bool isCyclicUtil(vector<int> g[],vector<int> visited,int src)
{
  if(visited[src]==2)
  return true;
  visited[src] = 1;
  bool flag = false;
  for(int i=0;i<g[src].size();i++)
  {
    if(visited[g[src][i]]==1)
    visited[g[src][i]] =2;
    else{
        flag = isCyclicUtil(g,visited,g[src][i]);
        if(flag==true)
        return true;
    }
  }
  return false;
}
bool isCyclic(vector<int>g[],int n)
{
    vector<int> visited(n,0);
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        visited[i] = 1;
        for(int j=0;j<g[i].size();j++)
        {
            flag = isCyclicUtil(g,visited,g[i][j]);
            if(flag==true)
            return true;
        }
        visited[i] = 1;
    }
    return false;

}
int main()
{
    int n,e;
    cin >>n>>e;
    vector <int > g[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(isCyclic(g,n))
    cout<<"yes";
    else cout<<"no";
}