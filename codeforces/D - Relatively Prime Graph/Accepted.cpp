/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2018 21:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/1009/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,mm;
vector<pair<int,int> >ed;
void print(void)
{
  cout<<"Possible"<<endl;
  for(int i=0;i<mm;i++)
    printf("%d %d\n",ed[i].first,ed[i].second);
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  mm=m;
   if(m<(n-1))cout<<"Impossible"<<endl,exit(0);
   for(int i=1;i<n;i++)
  {
    ed.push_back({i,i+1});
    m--;
  }
  if(m==0)print();
  for(int i=1;i<n;i++)
  {
    for(int j=i+2;j<=n;j++)
    {
      if(m==0)
        print();
      if(__gcd(i,j)==1)
      {
        ed.push_back({i,j});
        m--;
        if(m==0)
          print();
      }
    }
  }
  cout<<"Impossible"<<endl;
  return 0;
}