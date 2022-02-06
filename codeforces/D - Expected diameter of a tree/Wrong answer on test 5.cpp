/****************************************************************************************
*  @author: kzvd4729                                         created: May/16/2020 11:58                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 39000 KB                             
*  problem: https://codeforces.com/contest/804/problem/D
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
#define long long long
using namespace std;
const int N=1e6;
int com[N+2],d[N+2];long sm[N+2],sz[N+2];
vector<int>adj[N+2];
void dfs(int node,int par,int c)
{
  com[node]=c;
  for(auto x:adj[node])
  {
    if(x==par)continue;dfs(x,node,c);
    d[node]=max(d[node],d[x]+1);
  }
}
void dds(int node,int par,int an)
{
  int mx=max(d[node],an);//cout<<node<<" "<<mx<<endl;
  sm[com[node]]+=mx,sz[com[node]]++;
  multiset<int>st;
  for(auto x:adj[node])if(x!=par)st.insert(d[x]);
  for(auto x:adj[node])
  {
    if(x==par)continue;
    st.erase(st.find(d[x]));
    int ex=-2;if(st.size())ex=*st.rbegin();
    dds(x,node,max(an+1,ex+2));
    st.insert(d[x]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,q;cin>>n>>m>>q;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++)
  {
    if(com[i])continue;
    dfs(i,-1,i);dds(i,-1,0);
  }
  while(q--)
  {
    int u,v;cin>>u>>v;
    if(com[u]==com[v])cout<<-1<<"\n";
    else 
    {
      long up=sm[com[u]]*sz[com[v]]+sm[com[v]]*sz[com[u]];
      long dw=sz[com[u]]*sz[com[v]];
      double ans=(up*1.0)/(dw*1.0)+1.0;
      cout<<setprecision(9)<<fixed<<ans<<"\n";
    }
  }
  return 0;
}