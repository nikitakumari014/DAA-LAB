#include<bits/stdc++.h>
using namespace std;
struct node{
    int parent;
    int rank;
};
struct edge{
    int src;
    int dest;
    int wt;
};
vector<node> dsuf;
vector<edge> mst;
bool comparator(edge a, edge b)
{
    return a.wt < b.wt;
}
int find_p(int v)
{
    if(dsuf[v].parent==-1)
    return v;
    return dsuf[v].parent = find_p(dsuf[v].parent);
}
void union_op(int fromP,int toP)
{
    if(dsuf[fromP].rank < dsuf[toP].rank)
    dsuf[fromP].parent = toP;
    else if(dsuf[fromP].rank > dsuf[toP].rank)
    dsuf[toP].parent = fromP;
    else{
        dsuf[toP].parent = fromP;
        dsuf[fromP].rank+=1;
    }
}
void kruskals(vector<edge> &edge_list,int v,int e)
{
    sort(edge_list.begin(),edge_list.end(),comparator); //
    int i=0,j=0;
    while(i< v-1 && j<e)
    {
        int fromP = find_p(edge_list[j].src);
        int toP= find_p(edge_list[j].dest);
        if(fromP == toP) {
            ++j;
            continue;
        }
        union_op(fromP,toP);
        mst.push_back(edge_list[j]);
        ++i; }

}
int weight(vector<edge> &mst)
{
    int sum = 0;
    for(auto p: mst)
    sum = sum + p.wt;
    return sum;
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
    vector<edge> edge_list;
    edge temp;
    for(int i=0;i<e;i++)
    {
        int from,to,wt;
        cin>>from>>to>>wt;
        temp.src = from;
        temp.dest = to;
        temp.wt = wt;
        edge_list.push_back(temp);
    }
   int total;
    kruskals(edge_list,v,e);
    total = weight(mst);
  cout<<"Minimum spanning weight: "<<total<<endl;
  return 0;
}
