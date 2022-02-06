/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/12/2018 02:06                        
*  solution_verdict: Time limit exceeded on test 11          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/721/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e3;
int n,m,t,mx,f;
vector<pair<int,int> >adj[N+2];
vector<int>pr;
void dfs(int node,int c,int ans)
{
  if(c>t)return ;
  if(node==n)
  {
    mx=max(mx,ans);
    return ;
  }
  for(auto x:adj[node])
    dfs(x.first,c+x.second,ans+1);
}
void dds(int node,int c,int ans)
{
  if(c>t)return ;
  if(node==n)
  {
    if(ans==mx)f=1;
    return ;
  }
  for(auto x:adj[node])
  {
    dds(x.first,c+x.second,ans+1);
    if(f)
    {
      pr.push_back(x.first);
      return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>t;
  while(m--)
  {
    int u,v,w;cin>>u>>v>>w;
    adj[u].push_back({v,w});
  }
  for(int i=1;i<=n;i++)
    random_shuffle(adj[i].begin(),adj[i].end());
  dfs(1,0,1);
  cout<<mx<<endl;
  dds(1,0,1);
  reverse(pr.begin(),pr.end());
  cout<<1<<" ";
  for(auto x:pr)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}