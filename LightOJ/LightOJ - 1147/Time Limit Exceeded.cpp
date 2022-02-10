/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-14 00:48:59                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1147
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
bitset<N+2>dp[2][52];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;int hl=n/2,sum=0;
    for(int i=1;i<=n;i++)cin>>aa[i],sum+=aa[i];
    for(int i=0;i<2;i++)
      for(int j=0;j<=hl;j++)
        dp[i][j].reset();
    for(int i=0;i<2;i++)
        dp[i][0][0]=1;
    for(int i=1;i<=n;i++)
    {
      int id=i%2;int di=id^1;
      for(int j=min(i,hl);j>=0;j--)
      {
        dp[id][j]=dp[di][j];
        if(j)dp[id][j]|=(dp[di][j-1]<<aa[i]);
      }
    }
    int mn=1e9,ans,id=n%2;
    for(int i=0;i<=sum;i++)
    {
      if(dp[id][hl][i])
      {
        int df=abs(sum-i-i);
        if(df<mn)
        {
          mn=df;ans=i;
        }
      }
    }
    int a=ans,b=sum-ans;if(a>b)swap(a,b);
    cout<<"Case "<<++tc<<": "<<a<<" "<<b<<"\n";
  }
  return 0;
}