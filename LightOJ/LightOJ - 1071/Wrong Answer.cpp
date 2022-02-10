/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-07 17:37:25                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1071
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e7;
int t,n,m,mat[102][102],tc,dp[102][102][102];
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    memset(mat,0,sizeof(mat));
    memset(dp,0,sizeof(dp));

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d",&mat[i][j]);
    int sum=mat[1][1];
    for(int k=2;k<=m;k++)
    {
      sum+=mat[1][k];
      dp[1][1][k]=sum;
    }
    for(int i=2;i<=n;i++)
    {
      for(int k=1;k<=m;k++)
      {
        for(int j=1;j<k;j++)
        {
          dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+mat[i][j]+mat[i][k]);
          dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+mat[i][j]);
          if(j<k-1)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+mat[i][k]);
        }
//        for(int j=1;j<k-1;j++)
//          dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+mat[i][k]);
      }
    }
    printf("Case %d: %d\n",++tc,dp[n][m-1][m]);
  }
  return 0;
}