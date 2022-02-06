/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2018 22:39                        
*  solution_verdict: Time limit exceeded on test 26          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 9900 KB                              
*  problem: https://codeforces.com/contest/418/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int vis[N+2][N+2];
vector<pair<int,int> >v;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int kk=k;
    for(int j=1;j<=n;j++)
    {
      if(!kk)break;
      if(i==j)continue;
      if(vis[i][j])continue;
      v.push_back({i,j});
      vis[i][j]=1;vis[j][i]=1;
      kk--;
    }
    if(kk)cout<<-1<<endl,exit(0);
  }
  cout<<v.size()<<endl;
  for(auto x:v)
    cout<<x.first<<" "<<x.second<<endl;
  return 0;
}