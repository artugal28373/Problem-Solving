/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 16:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/208/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e8;
const long N=1e2;
long n,m,dis[N+2],_dis[N+2],fr[N+2],_fr[N+2];
vector<long>adj[N+2];
void bfs(void)
{
  for(long i=1;i<=n;i++)dis[i]=inf;
  queue<long>q;
  q.push(1);
  dis[1]=0;
  fr[1]++;
   while(q.size())
  {
    long u=q.front();
    q.pop();
    for(auto x:adj[u])
    {
      if(dis[u]+1<dis[x])
      {
        dis[x]=dis[u]+1;
        q.push(x);
        fr[x]=fr[u];
      }
      else if(dis[u]+1==dis[x])
        fr[x]+=fr[u];
    }
  }
}
void _bfs(void)
{
  for(long i=1;i<=n;i++)_dis[i]=inf;
  queue<long>q;
  q.push(n);
  _dis[n]=0;
  _fr[n]++;
   while(q.size())
  {
    long u=q.front();
    q.pop();
    for(auto x:adj[u])
    {
      if(_dis[u]+1<_dis[x])
      {
        _dis[x]=_dis[u]+1;
        q.push(x);
        _fr[x]=_fr[u];
      }
      else if(_dis[u]+1==_dis[x])
        _fr[x]+=_fr[u];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  while(m--)
  {
    long u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bfs();
  _bfs();
   long ds=dis[n];
   long mx=0;
  for(long i=1;i<=n;i++)
  {
    if(dis[i]+_dis[i]==ds)
    {
      if(i==1||i==n)mx=max(mx,fr[i]*_fr[i]);
      else mx=max(mx,2*fr[i]*_fr[i]);
    }
  }
  cout<<setprecision(10)<<fixed;
  cout<<(mx*1.0)/(fr[n]*1.0)<<endl;
  return 0;
}