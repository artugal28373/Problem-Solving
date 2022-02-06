/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2019 08:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 43400 KB                             
*  problem: https://codeforces.com/contest/228/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
 /*************** 2_SAT **************/
const int S=1e6;
int Desc[S+2],Low[S+2],Tim,Stacked[S+2],Anc[S+2];
vector<int>Dir[S+2],Root;stack<int>St;
void Tarjan(int node)
{
  Desc[node]=Low[node]=++Tim;
  St.push(node);Stacked[node]=1;
  for(auto x:Dir[node])
  {
    if(!Desc[x])
    {
      Tarjan(x);
      Low[node]=min(Low[node],Low[x]);
    }
    else if(Stacked[x])
      Low[node]=min(Low[node],Low[x]);
  }
  if(Low[node]==Desc[node])
  {
    int now=-1;
    while(now!=node)
    {
      now=St.top();St.pop();
      Stacked[now]=0;Anc[now]=node;
    }
    Root.push_back(node);
  }
}
void Strongly_Connected_Component(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(Desc[i])continue;
    Tarjan(i);
  }
}
const int T=1e6;
vector<int>topo_sorted,topo[T+2];
int tp_vis[T+2];
void Topo_sort(int node)
{
  tp_vis[node]=1;
  for(auto x:topo[node])
  {
    if(tp_vis[x])continue;
    Topo_sort(x);
  }
  topo_sorted.push_back(node);
}
vector<int>Topological_Sort(int n)
{
  for(int i=1;i<=n;i++)
  {
    if(tp_vis[i])continue;
    Topo_sort(i);
  }
  reverse(topo_sorted.begin(),topo_sorted.end());
  return topo_sorted;
}
void OR(int n,int u,int v)
{
  Dir[n+v].push_back(u);Dir[n+u].push_back(v);
}
void AND(int n,int u,int v)
{
  Dir[u].push_back(v);Dir[v].push_back(u);
}
void XOR(int n,int u,int v)
{
  Dir[n+v].push_back(u);Dir[u].push_back(n+v);
  Dir[n+u].push_back(v);Dir[v].push_back(n+u);
}
void XNOR(int n,int u,int v)
{
  Dir[u].push_back(v);Dir[v].push_back(u);
  Dir[n+v].push_back(n+u);Dir[n+u].push_back(n+v);
}
bool Two_SAT(int n,vector<int>&ans)
{
  Strongly_Connected_Component(n+n);
  for(int i=1;i<=n;i++)
    if(Anc[i]&&Anc[n+i]&&Anc[i]==Anc[n+i])return false;
  int cnt=0,cm[n+n+2];
  for(auto x:Root)
    cm[x]=++cnt;
  for(int u=1;u<=n+n;u++)
  {
    for(auto v:Dir[u])
    {
      int x=cm[Anc[u]],y=cm[Anc[v]];
      if(x==y)continue;
      topo[x].push_back(y);
    }
  }
  vector<int>tp=Topological_Sort(cnt);
  vector<int>v[n+n+2],sat;
  for(int i=1;i<=n+n;i++)
    v[cm[Anc[i]]].push_back(i);
  for(auto x:tp)
    for(auto z:v[x])
      sat.push_back(z);
  vector<int>vis(n+n+2,0);
  for(auto x:sat)
  {
    if(x>n)vis[x-n]=1;
    else if(vis[x])ans.push_back(x);
  }
  return true;
}
///////////////////////////////////////////////
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v,w;cin>>u>>v>>w;
    if(w)XNOR(n,u,v);
    else XOR(n,u,v);
  }
  vector<int>ans;
  if(!Two_SAT(n,ans))cout<<"Impossible"<<endl;
  else
  {
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
  }
   return 0;
}