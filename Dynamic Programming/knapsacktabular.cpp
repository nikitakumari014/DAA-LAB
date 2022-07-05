#include<iostream>
using namespace std;
#define n 4
#define w 8
int knapsack(int DP[n+1][w+1],int profit[],int wt[])
{
    int i=0,j=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            DP[i][j] = 0;
            else if(wt[i-1] > j)
            DP[i][j] = DP[i-1][j];
            else 
            DP[i][j] = max(DP[i-1][j], profit[i-1]+DP[i-1][j- wt[i-1]]);
        }
    }
    return DP[n][w];
}
int main()
{
    int profit[n];
    for(int i=0;i<n;i++)
    cin >>profit[i];
    int wt[n];
    for(int i=0;i<n;i++)
    cin >> wt[i];
    int DP[n+1][w+1];
    int max_profit = knapsack(DP,profit,wt);
    cout<<max_profit<<endl;
}