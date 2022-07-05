#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct node{
    int parent;
    int rank;
};
struct edges{
    int src;
    int dest;
    int wt;
};
vector <node> dsuf;
vector <edges>  mst;
int find(int v)
{
    if(dsuf[v].parent==-1)
    return v;
    return dsuf[v].parent = find(dsuf[v].parent);
}
void union_op(int fromP,int toP)
{
    if(dsuf[fromP].rank < dsuf[toP].rank)
    dsuf[fromP].parent = toP;
    else if(dsuf[fromP].rank > dsuf[toP].rank)
    dsuf[toP].parent = fromP;
    else{
        dsuf[fromP].parent = toP;
        dsuf[toP].rank+=1;
    }

}
bool comparator(edges a,edges b)
{
	return a.wt < b.wt;
}
void kruskals(vector<edges> &edge_list,int v,int e)
{
    sort(edge_list.begin(),edge_list.end(),comparator); //
    int i=0,j=0;
    while(i< v-1 && j<e)
    {
        int fromP = find(edge_list[j].src);
        int toP= find(edge_list[j].dest);
        if(fromP == toP) {
            ++j;
            continue;
        }
        union_op(fromP,toP);
        mst.push_back(edge_list[j]);
        ++i; }

}
void printmst(vector <edges> &mst)
{
        cout<<"MST formed is\n";
    for(auto p: mst)
    {
      cout<<p.src<<"to "<<p.dest<<"= "<<p.wt<<endl;
    }
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
    vector<edges> edge_list;
    edges temp;
    for(int i=0;i<e;i++)
    {
        int from,to,wt;
        cin>>from>>to>>wt;
        temp.src = from;
        temp.dest = to;
        temp.wt = wt;
        edge_list.push_back(temp);
    }
    kruskals(edge_list,v,e);
    printmst(mst);
    return 0;
}
