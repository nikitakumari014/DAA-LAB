#include<iostream>
using namespace std;
int lcs(char ch[],char ch1[],int a,int b)
{
  int DP[a+1][b+1];
  for(int i=0;i<=a;i++)
  DP[i][0] = 0;
  for(int i=1;i<=b;i++)
  DP[0][i] = 0;
  for(int i=1;i<=a;i++)
  {
    for(int j=1;j<=b;j++)
    {
        if(ch[i-1]==ch1[j-1])
        DP[i][j] = 1 + DP[i-1][j-1];
        else 
        DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
    }
  }
  return DP[a][b];
}
int main()
{
    int n1,n2;
    cin >>n1>>n2;
    char ch[n1];
    char ch1[n2];
    for(int i=0;i<n1;i++)
    cin >> ch[i];
    for(int i=0;i<n2;i++)
    cin >> ch1[i];
    int count = lcs(ch,ch1,n1,n2);
    cout<<"count: "<<count<<endl;
}