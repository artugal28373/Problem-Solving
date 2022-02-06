/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/11/2019 19:16                        
*  solution_verdict: Wrong answer on test 27                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/gym/102215/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int cnt[2],aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  int m=31-__builtin_clz(n);
   //cout<<m<<endl;
  vector<int>u,v;int lt=0,rt=n;
  for(int i=1;i<=n;i++)u.push_back(i);
   int ans=0;
  for(int j=m;j>=0;j--)
  {
    //cout<<lt<<" --> "<<rt<<endl;
   cnt[0]=0,cnt[1]=0;
    for(auto x:u)
    {
      cout<<"? "<<x<<" "<<j<<endl;
      int c;cin>>c;cnt[c]++;aa[x]=c;
    }
    for(int i=lt;i<=rt;i++)
    {
     bool c=(i&(1<<j));
     cnt[c]--; 
    }
    int tr=0;if(cnt[1]==-1)tr=1;
    ans|=(tr<<j);
     for(auto x:u)
     if(aa[x]==tr)v.push_back(x);
    u=v;v.clear();
     for(int i=lt;i<=rt;i++)
    {
     if((bool)(i&(1<<j))==tr)break;lt++;
    }
    for(int i=rt;i>=lt;i--)
    {
     if((bool)(i&(1<<j))==tr)break;rt--;
    }
    if(lt==rt)cout<<"! "<<lt<<endl,exit(0);
    //cout<<tr<<endl;
  }
  cout<<"! "<<ans<<endl;
  return 0;
}