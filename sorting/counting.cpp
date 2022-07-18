#include<iostream>
using namespace std;
void count_sort(int*a,int n)
{
    int max = a[0];
    int *o = new int[n];
    for(int i=1;i<n;i++) // finding the range
    if(a[i] > max)
    max = a[i];
    int *b = new int [max];      
    for(int i=0;i<=max;i++) // initializing the array.
    b[i] = 0;
    for(int i=0;i<n;i++)
    b[a[i]]++;
    for(int i=1;i<=max;i++)
    b[i]+= b[i-1];
    for(int i=n-1;i>=0;i--)
    {
        o[b[a[i]]-1] = a[i];
        b[a[i]]--;
    }
    for(int i=0;i<n;i++)
    a[i] = o[i];



}
void print(int*a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    
}
int main()
{
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    count_sort(a,n);
    print(a,n);
    return 0;
}