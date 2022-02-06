/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/19/2020 11:31                        
*  solution_verdict: Time limit exceeded on test 1           language: GNU C++17                               
*  run_time: 1000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1103/problem/B
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   while(true)
  {
    string s;cin>>s;
    if(s=="end")break;
     int a=1,b=1;
    while(true)
    {
      cout<<"? "<<a<<" "<<b<<endl;
      char c;cin>>c;
       if(c=='x')break;
      a=b;b+=b;b=min(b,inf);
    }
    if(a==1&&b==1){cout<<"! "<<1<<endl;continue;}
    int lo=a+1,hi=b,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      cout<<"? "<<a<<" "<<md<<endl;
      char c;cin>>c;
      if(c=='x')hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)
    {
      cout<<"? "<<a<<" "<<md<<endl;
      char c;cin>>c;
      if(c=='x')break;
    }
    cout<<"! "<<md<<endl;
  }
  return 0;
}