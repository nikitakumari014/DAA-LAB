#include<iostream>
using namespace std;
int binary_search(int*a,int l,int r,int key)
{
    if(l>r)
    return -1;
    int mid = (l+r)/2;
    if(a[mid] == key)
    return mid;
    if(a[mid] > key)
    return binary_search(a,l,mid-1,key);
    else
    return binary_search(a,mid+1,r,key);
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
    cout<<"Position: "<<index+1;
}