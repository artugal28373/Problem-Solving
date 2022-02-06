/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2019 18:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1107 ms                                         memory_used: 489200 KB                            
*  problem: https://codeforces.com/contest/665/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int cnt=2;
int aa[N+2],nw,tr[N*31+1][4],k;
void add(int x)
{
  int now=0;
  for(int i=30;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(!tr[now][z])tr[now][z]=++nw;
    tr[now][z+cnt]++;now=tr[now][z];
  }
}
int qry(int x)
{
  int now=0,ret=0,nm=0;
  for(int i=30;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if((nm|(1<<i))>=k)
    {
      ret+=tr[now][(z^1)+cnt];
      now=tr[now][z];
    }
    else
    {
      nm|=(1<<i);
      now=tr[now][(z^1)];
    }
    if(!now)return ret;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n>>k;int xx=0;add(xx);long ans=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;xx^=x;
    long zz=qry(xx);add(xx);
    //cout<<zz<<endl;
    ans+=zz;
  }
  cout<<ans<<endl;
  return 0;
}