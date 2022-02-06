/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/27/2019 21:46                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1260/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;long f=0;set<pair<long,long> >a,b;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];
    if(!f)
    {
      if(aa[i]==-1)f=1;aa[i]=0;
    }
    a.insert({i,aa[i]});b.insert({aa[i],i});
  }
  long ans=0;long pw=n;
  while(true)
  {
    if(a.size()==0)break;pw/=2;
    pair<long,long>p=*a.rbegin();ans+=p.second;
     a.erase(p);b.erase({p.second,p.first});
    for(long i=1;i<pw;i++)
    {
      p=*b.rbegin();b.erase(p);
      a.erase({p.second,p.first});
    }
    //cout<<a.size()<<" "<<b.size()<<endl;
  }
  cout<<ans<<endl;
  return 0;
}