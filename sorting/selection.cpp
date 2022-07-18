#include<iostream>
using namespace std;
void print(int*a,int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    
}
void selection_sort(int*a,int n)
{
    int j;
    for(int i=0;i<n-1;i++)
    {
        
        int min = i;
        for(j=i+1;j<n;j++)
        if(a[min] > a[j]){
        min = j;
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
int main()
{
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    selection_sort(a,n);
    print(a,n);
    return 0;
}
