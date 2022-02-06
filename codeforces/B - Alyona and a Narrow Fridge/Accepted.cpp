/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2019 22:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1119/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,h;cin>>n>>h;
  for(int i=1;i<=n;i++)cin>>aa[i];
  int lo=1,hi=n,md,ans;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;vector<int>v;
    for(int i=1;i<=md;i++)
      v.push_back(aa[i]);
    sort(v.begin(),v.end(),greater<int>());
    long ad=0;
    for(int i=0;i<v.size();i+=2)
      ad+=(v[i]*1LL);
    if(ad<=h)lo=md;else hi=md;
  }
  for(md=hi;md>=lo;md--)
  {
    vector<int>v;
    for(int i=1;i<=md;i++)
      v.push_back(aa[i]);
    sort(v.begin(),v.end(),greater<int>());
    long ad=0;
    for(int i=0;i<v.size();i+=2)
      ad+=(v[i]*1LL);
    if(ad<=h)cout<<md<<endl,exit(0);
  }
  return 0;
}