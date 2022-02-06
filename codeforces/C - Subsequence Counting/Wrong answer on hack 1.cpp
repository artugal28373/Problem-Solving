/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/08/2018 00:32                        
*  solution_verdict: Wrong answer on hack 1                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/960/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long pw[64],x,d,xx,p;
vector<long>print;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>x>>d;
   pw[1]=1LL;
  for(long i=2;i<=60;i++)pw[i]=pw[i-1]*2LL;
   long cnt=0,now=0,p=0;
  while(true)
  {
    for(long i=1;i<=10000;i++)
    {
      if(x==0)
      {
        cout<<print.size()<<endl;
        for(auto x:print)cout<<x<<" ";
        cout<<endl;
        return 0;
      }
      ++p;
      p=min(p,d);
      xx=pw[p];
      if(xx>x)
      {
        now+=d+10000000000LL;
        p=0;
        break;
      }
      else
      {
        print.push_back(++now);
        x-=xx;
        cnt++;
      }
      if(cnt>10000)
      {
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  return 0;
}