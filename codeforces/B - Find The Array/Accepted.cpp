/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2020 21:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1463/problem/B
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
const int N=1e6;
int a[N+2];
int find(int x)
{
  int mn=2e9,ret;
  for(int i=0;i<30;i++)
  {
    int p=abs((1<<i)-x);
    if(p<mn)mn=p,ret=(1<<i);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cout<<find(a[i])<<" ";
      cout<<endl;
  }
   return 0;
}