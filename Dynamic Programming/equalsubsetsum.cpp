#include<iostream>
using namespace std;
bool subsetsum(int set[],int n,int sum)
{
    if(sum%2!=0)
    return false;
    int s = sum/2;
    bool DP[n+1][s+1];
    for(int i=0;i<=n;i++)
    DP[i][0] = true;
    for(int i=1;i<=s;i++)
    DP[0][i] = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(j < set[i-1])
            DP[i][j]= DP[i-1][j];
            if(j >= set[i-1])
            DP[i][j] = DP[i-1][j] || DP[i-1][j - set[i-1]];
        }
    }
    return DP[n][sum];
}
int main()
{
    int n;
    cin>>n;
    int set[n];
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> set[i];
        sum = sum + set[i];
    }
    if(subsetsum(set,n,sum))
    cout<<"Partition can be possible.\n";
    else cout<<"Partition can't be possible\n";
}