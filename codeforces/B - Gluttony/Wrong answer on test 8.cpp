/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/18/2020 19:15                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 1918 ms                                         memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/891/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],n;long tt;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool dfs(int i,long a,long b)
{
  if(a==tt-1)return true;
  if(i==n)return (a==-1)|(a!=b);
  return dfs(i+1,a,b)&dfs(i+1,a+aa[i],b+bb[i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0;i<n;i++)cin>>aa[i],tt+=aa[i];vector<int>v;
  for(int i=0;i<n;i++)v.push_back(i);
  while(clock()<CLOCKS_PER_SEC*1.9)
  {
    shuffle(v.begin(),v.end(),rng);
    for(int i=0;i<n;i++)bb[i]=aa[v[i]];
    if(!dfs(0,-1,-1))continue;
    for(int i=0;i<n;i++)cout<<bb[i]<<" ";
      cout<<endl;exit(0);
  }
  cout<<-1<<endl;
  return 0;
}