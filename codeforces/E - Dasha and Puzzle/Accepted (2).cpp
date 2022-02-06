/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2018 00:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/761/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=30;
long deg[N+2],id;long df[N+2];
vector<long>adj[N+2];
pair<long,long>ans[N+2];
void dfs(long node,long par,long r,long c,long ck)
{
  ans[node]={r,c};
   long f=0;
  for(auto xx:adj[node])
  {
    if(xx==par)continue;
    if(f==0&&ck!=2)
      dfs(xx,node,r+df[++id],c,0);
    else if(f==1&&ck!=3)
      dfs(xx,node,r,c+df[++id],1);
    else if(f==2&&ck!=0)
      dfs(xx,node,r-df[++id],c,2);
    else
      dfs(xx,node,r,c-df[++id],3);
    f++;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<n;i++)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++,deg[v]++;
  }
  long rt=1;
  for(long i=1;i<=n;i++)
  {
    if(deg[i]==4)rt=i;
    if(deg[i]>4)cout<<"NO"<<endl,exit(0);
  }
  df[1]=1;
  for(long i=2;i<=n;i++)
    df[i]=df[i-1]*3LL;
  reverse(df+1,df+n+1);
  dfs(rt,-1,0,0,5);cout<<"YES"<<endl;
  for(long i=1;i<=n;i++)
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  return 0;
}