/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/01/2019 14:41                        
*  solution_verdict: Time limit exceeded on test 13          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 31300 KB                             
*  problem: https://codeforces.com/contest/1144/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>adj[N+2];
set<pair<int,int> >vs,dr;
void dfs(int node,int par,int cl)
{
  int u=par,v=node;if(cl)swap(u,v);
  if(vs.find({min(u,v),max(u,v)})!=vs.end())
  {
    if(dr.find({u,v})==dr.end())
      cout<<"NO"<<endl,exit(0);
    return ;
  }
  vs.insert({min(u,v),max(u,v)});
  dr.insert({u,v});
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
    if(dr.find(x)!=dr.end())cout<<'0';
    else cout<<'1';
  }
  cout<<endl;
  return 0;
}