/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2018 16:19                        
*  solution_verdict: Time limit exceeded on test 97          language: GNU C++17                               
*  run_time: 4500 ms                                         memory_used: 65300 KB                             
*  problem: https://codeforces.com/contest/1009/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,u,v,tmp[N+2],ans[N+2],mxx,st[N+2],tim;
int sz[N+2],hg[N+2],fr[N+2],trg,ed[N+2],lin[N+2];
vector<int>adj[N+2];
void whore(int node,int par,int h)
{
  ++tim;
  lin[tim]=node;
  st[node]=tim;
  sz[node]=0;
  hg[node]=h;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    whore(xx,node,h+1);
    sz[node]+=sz[xx];
  }
  ed[node]=tim;
}
void calculate(int node,int par)
{
  int x=hg[node];
  fr[x]++;
  if(fr[x]>mxx)mxx=fr[x],trg=x;
  else if(fr[x]==mxx&&x<trg)trg=x;
  for(auto xx:adj[node])
  {
    if(xx==par||tmp[xx])continue;
    calculate(xx,node);
  }
}
void do_clear(int node)
{
  for(int i=st[node];i<=ed[node];i++)
    fr[hg[lin[i]]]--;
}
void dfs(int node,int par,int clr)
{
  int mx=-1,spc=-1;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    if(sz[xx]>mx)mx=sz[xx],spc=xx;
  }
  for(auto xx:adj[node])
  {
    if(xx==par||xx==spc)continue;
    dfs(xx,node,1);
  }
  if(spc!=-1)dfs(spc,node,0),tmp[spc]=1;
  calculate(node,par);
  ans[node]=trg-hg[node];
  if(spc!=-1)tmp[spc]=0;
  if(clr)do_clear(node),mxx=0;
}
int main()
{
  scanf("%d",&n);
  for(int i=1;i<n;i++)
  {
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  whore(1,-1,1);
  dfs(1,-1,0);
  for(int i=1;i<=n;i++)
    printf("%d\n",ans[i]);
  return 0;
}