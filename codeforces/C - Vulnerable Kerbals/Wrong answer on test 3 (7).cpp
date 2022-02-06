/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2020 14:18                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 11000 KB                             
*  problem: https://codeforces.com/contest/800/problem/C
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define long long long
using namespace std;
const long N=2e5;
long cnt[N+2],aa[N+2],dp[N+2];
vector<long>adj[N+2],nm[N+2];
long dfs(long node)
{
  if(dp[node]!=-1)return dp[node];
  dp[node]=cnt[node];long now=0;
  for(auto x:adj[node])
  {
    dfs(x);
    now=max(now,dp[x]);
  }
  dp[node]+=now;
  return dp[node];
}
long exgcd(long a,long b,long &x,long &y)
{
  if(!b){x=1,y=0;return a;}
  long x1,y1;
  long g=exgcd(b,a%b,x1,y1);
  x=y1;
  y=x1-((long)(a/b))*y1;
  return g;
}
long modI(long a,long m)
{
  long x,y;exgcd(a,m,x,y);
  return (x%m+m)%m;
}
long vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,m;cin>>n>>m;vector<long>v;
  for(long i=1;i<=n;i++)
  {
    long x;cin>>x;if(x==0)x=m;
    vs[x]=1;
  }
  for(long i=1;i<=m;i++)
  {
    if(vs[i])continue;
    long g=__gcd(i,m);cnt[g]++;
    v.push_back(g);nm[g].push_back(i);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
    for(long i=0;i<v.size();i++)
  {
    for(long j=i+1;j<v.size();j++)
    {
      if(v[j]%v[i])continue;
      adj[v[i]].push_back(v[j]);
    }
  }
  memset(dp,-1,sizeof(dp));
  long bs=-1,rt;
  for(long i=0;i<v.size();i++)
  {
    long now=dfs(v[i]);if(now>bs)bs=now,rt=v[i];
  }
  long id=0;
  cout<<bs<<endl;cout<<nm[rt][0]<<" ";aa[++id]=nm[rt][0];
  long pr=nm[rt][0];
  while(true)
  {
    for(long i=1;i<nm[rt].size();i++)
    {
      long g=modI(pr,m),now=nm[rt][i];
      cout<<(1LL*g*(now/rt))%m<<" ";
      aa[++id]=(1LL*g*(now/rt))%m;
      pr=now;
    }
    long er=rt;
    for(auto x:adj[rt])
    {
      if(dp[x]==dp[rt]-cnt[rt]){rt=x;break;}
    }
    if(er==rt)break;
    long g=modI(pr,m),now=nm[rt][0];
    cout<<(1LL*g*(now/er))%m<<" ";
    aa[++id]=(1LL*g*(now/er))%m;
    pr=now;
  }
  cout<<endl;
  if(id!=bs)assert(0);
  long now=1;memset(vs,0,sizeof(vs));
  for(long i=1;i<=id;i++)
  {
    now=(1LL*now*aa[i])%m;if(vs[now])assert(0);
    vs[now]=1;
  }
  cout<<endl;
  return 0;
}