/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2019 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1187/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,a,b;cin>>n>>a>>b;
    cout<<max(n-a,n-b)+1<<"\n";
  }
  return 0;
}