/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/16/2019 00:36                        
*  solution_verdict: Wrong answer on test 16                 language: GNU C++14                               
*  run_time: 374 ms                                          memory_used: 204100 KB                            
*  problem: https://codeforces.com/contest/599/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=13;
int con[15];
long dp[(1<<(N-1))+2][(1<<(N-1))+2];
long mp[(1<<(N-2))+2][(1<<(N-1))+2];
vector<int>adj[N+2],sub[(1<<N)+2];
vector<pair<int,int> >lc[N+2];int n;
long dfs(int,int,int);
long dfs2(int rt,int ms,int msk)
{
  if(!(ms&(1<<11)))
    if(mp[ms][msk]!=-1)return mp[ms][msk];
  int z=31-__builtin_clz(ms);
  if(__builtin_popcount(ms)==1)
  {
    int f=0;int mm=msk|(1<<z);
    for(auto y:lc[rt])
    {
      if((mm&(1<<y.first))&&(mm&(1<<y.second)))
      {
        f=1;break;
      }
    }
    if(!f)return dfs(z,rt,msk|(1<<z));
    else return 0;
  }
  long ret=dfs(z,rt,(1<<z))*dfs2(rt,ms^(1<<z),msk);
  for(auto x:sub[msk])
  {
    int f=0;int mm=x|(1<<z);
    for(auto y:lc[rt])
    {
      if((mm&(1<<y.first))&&(mm&(1<<y.second)))
      {
        f=1;break;
      }
    }
    if(!f)ret+=dfs(z,rt,x|(1<<z))*dfs2(rt,ms^(1<<z),msk^x);
  }
  if(!(ms&(1<<11)))
    mp[ms][msk]=ret;
  return ret;
}
long dfs(int node,int par,int msk)
{
  for(auto x:lc[node])
  {
    if(!(msk&(1<<x.first)))return 0;
    if(!(msk&(1<<x.second)))return 0;
  }
  int ovs=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    if(!(msk&(1<<x)))return 0;
    ovs|=(1<<x);
  }
  msk^=(1<<node);
  if(!msk)return 1;
  if(dp[msk][ovs]!=-1)return dp[msk][ovs];
   long now=0;
  for(auto x:sub[msk])
  {
    if((x&ovs)!=ovs)continue;
    now+=dfs2(node,x,msk^x);
  }
  return dp[msk][ovs]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,k;cin>>n>>m>>k;
  for(int i=0;i<n;i++)
    con[i]=n-1-i;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;u--,v--;
    u=con[u];v=con[v];
    adj[u].push_back(v);
    adj[v].push_back(u);
    if(u==v)cout<<0<<endl,exit(0);
  }
  for(int i=1;i<=k;i++)
  {
    int a,b,c;cin>>a>>b>>c;
    a--,b--,c--;a=con[a];b=con[b];c=con[c];
    if(a==b)
    {
      if(c==a)continue;
      else cout<<0<<endl,exit(0);
    }
    lc[c].push_back({a,b});
  }
  for(int i=1;i<(1<<n);i++)
    for(int j=1;j<=i;j++)
      if((i&j)==j)
        sub[i].push_back(j);
  memset(mp,-1,sizeof(mp));
  memset(dp,-1,sizeof(dp));
  cout<<dfs(n-1,n+1,(1<<n)-1)<<endl;
  return 0;
}