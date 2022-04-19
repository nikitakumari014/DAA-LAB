#include<iostream>
using namespace std;
void find_dup(int*a,int n,int*b,int m)
{
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
         {
        cout<<a[i]<<" ";
        i++;
        j++;
        }
        else{
            if(a[i] < b[j])
            ++i;
            else ++j;
        }
    }
}
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int *a = new int[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        cin>>m;
        int *b = new int[m];
         for(int i=0;i<m;i++)
        cin>>b[i];
        find_dup(a,n,b,m);
    }
}