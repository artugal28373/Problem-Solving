/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2019 18:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 639 ms                                          memory_used: 119800 KB                            
*  problem: https://codeforces.com/contest/702/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2];
cc_hash_table<int,int,hash<long long>>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;for(int i=1;i<=n;i++)cin>>aa[i];
  long long ans=0;
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