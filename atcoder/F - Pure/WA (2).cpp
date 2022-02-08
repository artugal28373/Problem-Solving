/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-12 23:51:10                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 24 ms                                           memory_used: 25728 KB                             
*  problem: https://atcoder.jp/contests/abc142/tasks/abc142_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>adj[N+2];
vector<pair<int,int> >bk;
int vis[1000+2],lev[N+2],prnt[1000+2];
void dfs(int node,int par,int lv)
{
  lev[node]=lv;prnt[node]=par;
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])bk.push_back({node,x});
    else dfs(x,node,lv+1);
  }
}
int main()
{
  //freopen("inp.txt","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)adj[i].clear();
  for(int i=1;i<=m;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
  }
  int mn=n+1,u,v;vector<int>pr;
  for(int i=1;i<=n;i++)
  {
    memset(vis,0,sizeof(vis));
    bk.clear();dfs(i,-1,1);
    for(auto x:bk)
    {
      int df=lev[x.first]-lev[x.second];
      if(df>0&&df<mn)
      {
        mn=df,u=x.first,v=x.second;pr.clear();
        while(true)
        {
          if(u==-1)
          {
            cout<<-1<<endl,exit(0);
          }
          pr.push_back(u);if(u==v)break;
          u=prnt[u];
        }
      }
    }
  }
  if(mn>n)cout<<-1<<endl,exit(0);
  cout<<mn+1<<"\n";
  for(auto x:pr)
    cout<<x<<"\n";
  return 0;
}