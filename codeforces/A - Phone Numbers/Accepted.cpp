/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/04/2018 13:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1060/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,cnt=0;cin>>n;
  string s;cin>>s;
  for(auto x:s)
    if(x=='8')cnt++;
  cout<<min(n/11,cnt)<<endl;
   return 0;
}