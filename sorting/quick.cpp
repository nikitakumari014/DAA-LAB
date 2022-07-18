#include<iostream>
using namespace std;
int partition(int *a,int l,int r)
{
    int pivot = a[r];
    int i = l-1;
    for(int j=l;j<=r-1;j++)
    {
        if(a[j] < pivot){
            ++i;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
void quick_sort(int *a,int l,int r)
{
    if(l<r) {
    int p = partition(a,l,r);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,r);
    }
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
    quick_sort(a,0,n-1);
    print(a,n);
    return 0;
}