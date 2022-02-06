/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/21/2018 23:06                        
*  solution_verdict: Time limit exceeded on test 38          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 110700 KB                            
*  problem: https://codeforces.com/contest/474/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const long R=1e15;
long aa[N+2],dp[N+2];
unordered_map<long,int>bit,btt;
void upd(long x,int vl)
{
  for( ;x<=R;x+=x&-x)
    bit[x]=max(bit[x],vl);
}
int qry(long x)
{
  int mx=0;
  for( ;x>0;x-=x&-x)
    mx=max(mx,bit[x]);
  return mx;
}
void _upd(long x,int vl)
{
  for( ;x>0;x-=x&-x)
    btt[x]=max(btt[x],vl);
}
int _qry(long x)
{
  int mx=0;
  for( ;x<=R;x+=x&-x)
    mx=max(mx,btt[x]);
  return mx;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  bit.reserve((1<<22));btt.reserve((1<<22));
  bit.max_load_factor(0.35);btt.max_load_factor(0.35);
   long n,d;scanf("%lld%lld",&n,&d);
  for(int i=1;i<=n;i++)
    scanf("%lld",&aa[i]);
  for(int i=n;i>=1;i--)
  {
    dp[i]=max(qry(aa[i]-d),_qry(aa[i]+d))+1;
    upd(aa[i],dp[i]);_upd(aa[i],dp[i]);
  }
  long ans=0;
  for(int i=1;i<=n;i++)
    ans=max(ans,dp[i]);
  printf("%lld\n",ans);
  long last=1e18;ans++;
  for(int i=1;i<=n;i++)
  {
    if(dp[i]==ans-1&&abs(aa[i]-last)>=d)
    {
      printf("%d ",i);last=aa[i];ans--;
    }
  }
  return 0;
}