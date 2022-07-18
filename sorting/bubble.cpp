#include<iostream>
using namespace std;
void print(int*a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    
}
void bubblesort(int*a,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j] > a[j+1])
            swap(a[j],a[j+1]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    bubblesort(a,n);
    print(a,n);
    return 0;
}
