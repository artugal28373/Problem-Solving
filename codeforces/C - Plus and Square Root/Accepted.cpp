/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2018 20:16                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 249 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/716/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,now,tmp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  now=2;
  cout<<2<<endl;
  for(long i=2;i<=n;i++)
  {
    tmp=i*(i+1)*(i+1)-(i-1);
    cout<<tmp<<endl;
  }
  return 0;
}