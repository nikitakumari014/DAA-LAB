#include<bits/stdc++.h>
using namespace std;
struct node
{
    int parent;
    int rank;
};
vector<node> dsuf;
int find_v(int v)
{
    if(dsuf[v].parent==-1)
    return v;
    return dsuf[v].parent = find_v(dsuf[v].parent);
}
void union_p(int fromP,int toP)
{
   if(dsuf[fromP].rank > dsuf[toP].rank)
   {
     dsuf[toP].parent = fromP;
   }
   else if(dsuf[fromP].rank < dsuf[toP].rank)
   dsuf[fromP].parent = toP;
   else{
       dsuf[fromP].parent = toP;
       dsuf[toP].rank+=1;
   }
}
bool iscyclic(vector<pair<int,int>> &edge_list)
{
    for(auto p:edge_list) {
    int fromP = find_v(p.first);
    int toP = find_v(p.second);
    if(fromP==toP)
    return true;
    union_p(fromP,toP);
    }
    return false;
}
int main()
{
    int v,e;
    cin>>v>>e;
    dsuf.resize(v);
    for(int i=0;i<v;i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }
    vector<pair<int,int> > edge_list;
    for(int i=0;i<e;i++)
    {
        int from,top;
        cin>>from>>top;
        edge_list.push_back({from,top});
    }
    if(iscyclic(edge_list))
    {
        cout<<"Cyclic exists";
    }
    else cout<<"Cycle doesnot exists";
}
