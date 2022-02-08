/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-24 17:23:10                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 198 ms                                          memory_used: 114944 KB                            
*  problem: https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int tr[63*N+2][4],nw,n,k,aa[N+2];
void insrt(int x)
{
  int now=0;
  for(long i=61;i>=0;i--)
  {
    bool z=(x&(1LL<<i));
    tr[now][2+z]++;
    if(!tr[now][z])tr[now][z]=++nw;
    now=tr[now][z];
  }
}
int qry()
{
  long ret=0;int now=0;
  for(long i=61;i>=0;i--)
  {
    if(tr[now][3]>=k)
    {
      ret|=(1LL<<i);
      now=tr[now][1];
    }
    else now=tr[now][0];
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=n;i++)
  {
    long sum=0;
    for(int j=i;j<=n;j++)
    {
      sum+=aa[j]*1LL;//cout<<sum<<endl;
      insrt(sum);
    }
  }
  cout<<qry()<<endl;
  return 0;
}