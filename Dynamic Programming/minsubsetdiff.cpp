#include<iostream>
#include<limits.h>
using namespace std;
int isSubset(int set[],int n,int sum)
{
    bool DP[n+1][sum+1];
    for(int i=0;i<=n;i++)
    DP[i][0] = true;
    for(int i=1;i<=sum;i++)
    DP[0][i] = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j < set[i-1])
            DP[i][j] = DP[i-1][j];
            if(j >= set[i-1])
            DP[i][j] = DP[i-1][j] || DP[i-1][j - set[i-1]];
        }
    }
    int i = n;
    int s = sum/2;
    int min = INT_MAX;
    while(s >= 0)
    {
        if(DP[i][s])
        {
            int m = sum - 2*s;
            if(m < min)
            min = m;
        }
        s--;
    }
    return min;
}
int main()
{
    int n;
    cin>>n;
    int set[n];
    int sum = 0;
    for(int i=0;i<n;i++) {
    cin >> set[i];
    sum = sum + set[i];
    }
    int min = isSubset(set,n,sum);
    cout<<"Minimum value: "<<min<<endl;
}
