/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/17/2018 23:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 935 ms                                          memory_used: 103400 KB                            
*  problem: https://codeforces.com/contest/741/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5,inf=1e9;
int n,mask[N+2],sz[N+2],st[N+2],ed[N+2];
int tim,sack[(1<<23)],lin[N+2],lev[N+2];
int ans[N+2],f;
vector<pair<int,char> >adj[N+2];
void dfs(int node,int par,int msk,int lv)
{
  st[node]=++tim;sz[node]=1;lin[tim]=node;
  mask[node]=msk;lev[node]=lv;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    dfs(x.first,node,msk^(1<<(x.second-'a')),lv+1);
    sz[node]+=sz[x.first];
  }
  ed[node]=tim;
}
int dsu(int node,int par,int clr)
{
  int mx=-1,big=-1;
  for(auto x:adj[node])
  {
    if(x.first==par)continue;
    if(sz[x.first]>mx)
      mx=sz[x.first],big=x.first;
  }
  for(auto x:adj[node])
  {
    if(x.first==par||x.first==big)continue;
    ans[node]=max(ans[node],dsu(x.first,node,1));
  }
  if(big!=-1)ans[node]=max(ans[node],dsu(big,node,0));
  for(auto x:adj[node])
  {
    if(x.first==par||x.first==big)continue;
    for(int i=st[x.first];i<=ed[x.first];i++)
    {
      int msk=mask[lin[i]];
      ans[node]=max(ans[node],lev[lin[i]]+sack[msk]-2*lev[node]);
      for(int j=0;j<22;j++)
        ans[node]=max(ans[node],lev[lin[i]]+sack[(msk^(1<<j))]-2*lev[node]);
    }
    for(int i=st[x.first];i<=ed[x.first];i++)
    {
      int msk=mask[lin[i]];
      sack[msk]=max(sack[msk],lev[lin[i]]);
    }
  }
  int tmp=mask[node];ans[node]=max(ans[node],sack[tmp]-lev[node]);
  for(int j=0;j<22;j++)
    ans[node]=max(ans[node],sack[(tmp^(1<<j))]-lev[node]);
  sack[mask[node]]=max(sack[mask[node]],lev[node]);
  if(clr)
    for(int i=st[node];i<=ed[node];i++)
      sack[mask[lin[i]]]=-inf;
  return ans[node];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    int x;char c;cin>>x>>c;
    if(i==5&&x==1&&c=='h')f=1;
    adj[i].push_back({x,c});
    adj[x].push_back({i,c});
  }
  for(int i=0;i<(1<<23);i++)sack[i]=-inf;
  dfs(1,-1,0,1);dsu(1,-1,0);
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}