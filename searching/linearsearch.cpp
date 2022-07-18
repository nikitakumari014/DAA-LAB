#include<iostream>
using namespace std;
int linearsearch(int*a,int n,int key)
{
  for(int i=0;i<n;i++)
  if(a[i] == key)
  return i;
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
    int index = linearsearch(a,n,key);
    if(index==-1)
    cout<<"Not found. ";
    else
    cout<<index+1;
}