/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/04/2020 20:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1453/problem/D
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
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    long k;cin>>k;
    if(k%2)
    {
      cout<<-1<<endl;continue;
    }
    vector<int>v;
    k-=2;v.push_back(1);
    while(k)
    {
      for(long i=60;i>1;i--)
      {
        if(k>=((1LL<<i)-2))
        {
          for(int j=0;j<i-2;j++)v.push_back(0);
          v.push_back(1);k-=((1LL<<i)-2);
          break;
        }
      }
    }
    cout<<(int)v.size()<<'\n';
    for(auto x:v)cout<<x<<" ";cout<<'\n';
  }
  return 0;
}