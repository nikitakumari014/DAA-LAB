#include<iostream>
#include<math.h>
using namespace std;
int jump_search(int*a,int key,int n)
{
    int start = 0;
    int end = sqrt(n);
    while(end<n && a[end]<=key)
    {
        start=end;
        end+=sqrt(n);
        if(end>n-1)
        end=n;
    }
    for(int i=start;i<end;i++)
    {
       if(a[i]==key)
       return i;
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
    int index = jump_search(a,key,n);
    if(index==-1)
    cout<<"Not found. ";
    else
    cout<<"Position : "<<index+1;
}