#include<bits/stdc++.h>
using namespace std;
int mcm(int a[],int l,int r)
{
    if(l>=r)
    return 0;
    int ans = INT_MAX;
    int temp;
    for(int i=l;i<r;i++)
    {
       temp = mcm(a,l,i) + mcm(a,i+1,r) + (a[l-1] * a[i] * a[r]);
       ans  = min(ans,temp);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    int minim = mcm(a,1,n-1);
    cout<<minim<<endl;
}