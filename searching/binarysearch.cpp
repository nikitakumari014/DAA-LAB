#include<iostream>
using namespace std;
int binary_search(int *a,int l,int r,int key)
{
    while(l<=r)
    {
        int m = (l+r)/2;
        if(a[m]==key)
        return m;
        else if(key > a[m])
        l = m+1;
        else
        r=m-1;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int key;
    cin>>key;
    int index = binary_search(a,0,n,key);
    if(index==-1)
    cout<<"Not found. ";
    else
    cout<<"Position : "<<index+1;
}