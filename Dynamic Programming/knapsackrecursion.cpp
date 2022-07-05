// 0/1 recursion using knapsack
#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int wt[],int profit[],int total, int n)
{
    if(n == 0 || total == 0)
    return 0;
    if(wt[n] > total)
    return knapsack(wt,profit,total,n-1);
    else
    return std::max(knapsack(wt,profit,total,n-1), profit[n] + knapsack(wt,profit,total-wt[n],n-1));
}
int main()
{
    int n;
    cin >> n;
    int wt[n];
    for(int i=0;i<n;i++)
    cin >> wt[i];
    int profit[n];
    for(int i=0;i<n;i++)
    cin >> profit[i];
    int total_cap;
    cin >> total_cap;
    int max_profit = knapsack(wt,profit,total_cap,n);
    cout<<max_profit<<endl;
    return 0;
}