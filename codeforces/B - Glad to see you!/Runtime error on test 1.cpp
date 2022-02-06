/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2020 23:58                        
*  solution_verdict: Runtime error on test 1                 language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/809/problem/B
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
const int N=1e5;
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
   int lo=1,hi=n,md;
  while(lo<hi)
  {
    md=(lo+hi)/2;
    cout<<1<<" "<<md<<" "<<md+1<<endl;
    string s;cin>>s;
    if(s=="TAK")hi=md;else lo=md+1;
  }
  int a=lo;assert(a<n);
   lo=1,hi=a,md;
  while(lo<hi)
  {
    md=(lo+hi)/2;
    cout<<1<<" "<<md<<" "<<md+1<<endl;
    string s;cin>>s;
    if(s=="TAK")hi=md;else lo=md+1;
  }
  int b=-1;if(lo<a)b=lo;
   lo=a,hi=n,md;
  while(lo<hi)
  {
    md=(lo+hi+1)/2;
    cout<<1<<" "<<md-1<<" "<<md<<endl;
    string s;cin>>s;
    if(s=="TAK")hi=md-1;else lo=md;
  }
  int c=-1;if(hi>a)c=hi;
  assert(b!=-1||c!=-1);
  int d=b;if(b==-1)d=c;
  cout<<2<<" "<<a<<" "<<d<<endl;
  return 0;
}