/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-20 18:10:39                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/agc024/tasks/agc024_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=2e18;
long a,b,c,k,ta,tb,tc;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>a>>b>>c>>k;
   if(k%2==0)cout<<a-b<<endl;
  else cout<<b-a<<endl;
   return 0;
}