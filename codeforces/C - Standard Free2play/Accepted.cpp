/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2019 14:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1238/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int h,n;cin>>h>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
     int ans=0;aa[n+1]=0;
    for(int i=2;i<=n;i++)
    {
      if(aa[i+1]==aa[i]-1)i++;
      else ans++;
    }
    cout<<ans<<"\n";
  }
  return 0;
}