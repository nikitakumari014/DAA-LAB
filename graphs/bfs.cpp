#include<bits/stdc++.h>
using namespace std;
void bfs(int s,vector<int>g[],bool *vis,int n)
{
    queue <int> q;
    q.push(s);
    vis[s] = true;
    while(!(q.empty()))
    {
      int curr = q.front();
      cout<<curr<<" ";
      q.pop();
      for(int i=0;i<g[curr].size();i++)
      {
          if(vis[g[curr][i]]==false)
          {
              q.push(g[curr][i]);
              vis[g[curr][i]] = true;
          }
      }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector <int> g[n];
    bool vis[n]={false};
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(0,g,vis,n);
}