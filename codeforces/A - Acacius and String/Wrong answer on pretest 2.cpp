/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/19/2020 15:20                        
*  solution_verdict: Wrong answer on pretest 2               language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1379/problem/A
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
string p="abacaba",s;
bool solve()
{
  int n;cin>>n;cin>>s;
   int cnt=0;
  for(int i=0;i<n;i++)
  {
    int f=1;
    for(int j=0;j<p.size();j++)
    {
      if(i+j==n){f=0;break;}
      if(s[i+j]!=p[j])f=0;
    }
    cnt+=f;
  }
  if(cnt==1)
  {
    for(int i=0;i<n;i++)if(s[i]=='?')s[i]='d';
    return true;
  }
  if(cnt>1)return false;
   for(int i=0;i<n;i++)
  {
    int f=1;
    for(int j=0;j<p.size();j++)
    {
      if(i+j==n){f=0;break;}
      if(s[i+j]==p[j]||s[i+j]=='?');
      else f=0;
    }
    if(f)
    {
      for(int j=0;j<p.size();j++)
        s[i+j]=p[j];
      return true;
    }
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    if(solve())cout<<"Yes\n"<<s<<"\n";
    else cout<<"No\n";
  }
  return 0;
}