/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/30/2018 20:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/976/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,cnt,zero;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='1')cnt++;
    else zero++;
  }
  if(cnt)cout<<'1';
  while(zero--)cout<<'0';
  cout<<endl;
  return 0;
}