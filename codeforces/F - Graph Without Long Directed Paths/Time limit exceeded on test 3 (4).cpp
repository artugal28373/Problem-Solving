/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/01/2019 14:35                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 21500 KB                             
*  problem: https://codeforces.com/contest/1144/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N=1e6;
vector<int>adj[N+2];
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash
{
  size_t operator()(const pair<int,int>&x)const
  {
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<30));
  }
};
cc_hash_table<pair<int,int>,int,chash>vs,dr;
void dfs(int node,int par,int cl)
{
  int u=par,v=node;if(cl)swap(u,v);
  if(vs[{min(u,v),max(u,v)}])
  {
    if(dr.find({u,v})==dr.end())
      cout<<"NO"<<endl,exit(0);
    return ;
  }
  vs[{min(u,v),max(u,v)}]=1;
  dr[{u,v}]=1;
  for(auto x:adj[node])
    dfs(x,node,cl^1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<pair<int,int> >ed;
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ed.push_back({u,v});
  }
  dfs(1,-1,0);cout<<"YES"<<endl;
  for(auto x:ed)
  {
    if(dr.find(x)==dr.end())cout<<'1';
    else cout<<'0';
  }
  cout<<endl;
  return 0;
}