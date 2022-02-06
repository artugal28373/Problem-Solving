/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2018 14:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 3728 ms                                         memory_used: 36200 KB                             
*  problem: https://codeforces.com/contest/612/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>pp[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,id=0;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    int x,y;cin>>x>>y;
    pp[++id]={x,-1};pp[++id]={y,1};
  }
  sort(pp+1,pp+id+1);int nw=0,lt;
  vector<pair<int,int> >ans;
  for(int i=1;i<=id;i++)
  {
    if(pp[i].second==-1)
    {
      nw++;
      if(nw==k)lt=pp[i].first;
    }
    else
    {
      if(nw==k)ans.push_back({lt,pp[i].first});
      nw--;
    }
  }
  if(ans.size()==0)cout<<0<<endl,exit(0);
  vector<pair<int,int> >pr;
  pr.push_back(ans[0]);
  for(int i=1;i<ans.size();i++)
  {
    if(ans[i].first<=pr[pr.size()-1].second)
      pr[pr.size()-1].second=ans[i].second;
    else pr.push_back(ans[i]);
  }
  cout<<pr.size()<<endl;
  for(auto x:pr)
    cout<<x.first<<" "<<x.second<<endl;
  return 0;
}