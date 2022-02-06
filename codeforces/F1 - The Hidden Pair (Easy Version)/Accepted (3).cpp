/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/21/2020 01:48                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 171 ms                                          memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1370/problem/F1
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
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e3;
vector<int>adj[N+2];
vector<int>v;int dst[N+2],dp[N+2];
int dds(int node,int par)
{
  dp[node]=0;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dp[node]=max(dp[node],dds(x,node)+1);
  }
  return dp[node];
}
void dfs(int node,int par,int d)
{
  dst[node]=d;
  for(auto x:adj[node])
    if(x!=par)dfs(x,node,d+1);
}
void dfs2(int node,int par,int d)
{
  if(d==0)v.push_back(node);
  for(auto x:adj[node])
    if(x!=par)dfs2(x,node,d-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<N+2;i++)adj[i].clear();v.clear();
    for(int i=1;i<n;i++)
    {
      int u,v;cin>>u>>v;
      adj[u].push_back(v);adj[v].push_back(u);
    }
    int mx=n,rt;
    for(int i=1;i<=n;i++)
    {
      int d=dds(i,-1);if(d<mx)mx=d,rt=i;
    }
    //cout<<rt<<" ** "<<mx<<endl;
    dfs(rt,-1,0);
    cout<<"? "<<n;
    for(int i=1;i<=n;i++)cout<<" "<<i;
    cout<<endl;
    int a,ds;cin>>a>>ds;
     int lo=0,hi=mx,md;int nd=0;
    while(lo<=hi)
    {
      md=(lo+hi)/2;int cnt=0;
      for(int i=1;i<=n;i++)if(dst[i]>=md)cnt++;
      cout<<"? "<<cnt;
      for(int i=1;i<=n;i++)if(dst[i]>=md)cout<<" "<<i;
      cout<<endl;
      int b;cin>>a>>b;
      if(b==ds)lo=md+1,nd=a;else hi=md-1;
    }
    v.clear();dfs2(nd,-1,ds);assert(nd);
    assert(v.size());cout<<"? "<<v.size();
    for(int i=0;i<v.size();i++)cout<<" "<<v[i];
    cout<<endl;
    int x,y;cin>>x>>y;
    cout<<"! "<<nd<<" "<<x<<endl;string s;cin>>s;
  }
  return 0;
}