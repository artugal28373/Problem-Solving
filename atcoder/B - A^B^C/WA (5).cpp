/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-21 15:30:36                      
*  solution_verdict: WA                                      language: C++ (GCC 9.2.1)                         
*  run_time: 8 ms                                            memory_used: 3620 KB                              
*  problem: https://atcoder.jp/contests/arc113/tasks/arc113_b
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9;
 int mod=4;
 int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b,c;cin>>a>>b>>c;
   int p=big(b,c);
   mod=10;
   cout<<big(a,p)<<endl;
       return 0;
}