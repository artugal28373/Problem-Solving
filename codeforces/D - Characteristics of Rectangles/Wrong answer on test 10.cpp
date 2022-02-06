/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/18/2018 04:37                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++17                               
*  run_time: 686 ms                                          memory_used: 7200 KB                              
*  problem: https://codeforces.com/contest/333/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int b1=31,b2=37;
int n,m,mat[N+2][N+2];
vector<int>v[N+2];
unordered_set<int>st;
bool ok(int x)
{
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    v[i].clear();
    for(int j=1;j<=m;j++)
    {
      if(mat[i][j]>=x)
      {
        v[i].push_back(j);
        cnt++;
      }
    }
  }
  if(cnt>30*N)return true;
  st.clear();
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<v[i].size();j++)
    {
      for(int k=j+1;k<v[i].size();k++)
      {
        int hs=(v[i][j]*1LL)*b1+(v[i][k]*1LL)*b2;
        if(st.find(hs)!=st.end())return true;
        st.insert(hs);
      }
    }
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  st.max_load_factor(0.25);st.reserve((1<<15));
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>mat[i][j];
    }
  }
  int lo=0,hi=1e9+9,md;
  while(hi-lo>1)
  {
    md=(hi+lo)/2;
    if(ok(md))lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
    if(ok(md))cout<<md<<endl,exit(0);
  return 0;
}