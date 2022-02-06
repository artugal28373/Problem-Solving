/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2019 18:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 872 ms                                          memory_used: 168900 KB                            
*  problem: https://codeforces.com/contest/702/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2];
unordered_map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  mp.max_load_factor(0.25);mp.reserve((1<<18));
  int n;cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=30;j++)
    {
      int p=(1<<j);
      ans+=(mp[p-aa[i]])*1LL;
    }
    mp[aa[i]]++;
  }
  cout<<ans<<endl;
  return 0;
}