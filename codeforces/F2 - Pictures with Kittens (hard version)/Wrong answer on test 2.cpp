/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/18/2018 15:50                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1077/problem/F2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const long inf=1e2;
int aa[N+2];
long dp[N+2][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,x;cin>>n>>k>>x;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  n++;x++;
  for(int i=0;i<=N;i++)
    for(int j=0;j<=N;j++)
      dp[i][j]=-inf;
  dp[0][0]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=x;j++)
    {
      for(int l=i-1;l>=max(0,i-k);l--)
      {
        dp[i][j]=max(dp[i][j],dp[l][j-1]+aa[i]);
      }
    }
  }
  // for(int i=0;i<=10;i++)
  // {
  //   for(int j=0;j<=10;j++)
  //   {
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  cout<<dp[n][x]<<endl;
  return 0;
}