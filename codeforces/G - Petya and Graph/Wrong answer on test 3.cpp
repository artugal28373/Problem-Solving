/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/22/2020 00:18                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/1082/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,inf=1e9;
struct edge
{
  int a,b,f,c;
};
int sr,sn;//sr=0,sn=last node+1;
vector<edge>ed;vector<int>adj[N+2];
void addEdge(int a,int b,int c)
{
  edge e;e={a,b,0,c};
  adj[a].push_back(ed.size());
  ed.push_back(e);e={b,a,0,0};
  adj[b].push_back(ed.size());
  ed.push_back(e);
}
int dis[N+2],pt[N+2];
bool bfs(void)
{
  for(int i=0;i<=sn;i++)dis[i]=inf;
  queue<int>q;q.push(sr);dis[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();
    for(auto x:adj[u])
    {
      int v=ed[x].b;
      if(dis[v]==inf&&ed[x].f<ed[x].c)dis[v]=dis[u]+1,q.push(v);
    }
  }
  return dis[sn]!=inf;
}
int dfs(int u,int flow)
{
  if(!flow||u==sn)return flow;
  for( ;pt[u]<adj[u].size();pt[u]++)
  {
    int id=adj[u][pt[u]];int v=ed[id].b;
    if(dis[v]!=dis[u]+1)continue;
    if(int pushed=dfs(v,min(flow,ed[id].c-ed[id].f)))
    {
      ed[id].f+=pushed;ed[id^1].f-=pushed;return pushed;
    }
  }
  return 0;
}
int dinic(void)
{
  int flow=0;
  while(bfs())
  {
    for(int i=0;i<=sn;i++)pt[i]=0;
    while(int pushed=dfs(sr,inf))flow+=pushed;
  }
  return flow;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;sn=n+m+1;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;addEdge(m+i,sn,x);
  }
  int sm=0;
  for(int i=1;i<=m;i++)
  {
    int u,v,w;cin>>u>>v>>w;sm+=w;
    addEdge(sr,i,w);addEdge(i,m+u,inf);addEdge(i,m+v,inf);
  }
  cout<<sm-dinic()<<endl;
  return 0;
}