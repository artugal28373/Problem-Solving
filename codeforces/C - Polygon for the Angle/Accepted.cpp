/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/31/2018 12:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1700 KB                              
*  problem: https://codeforces.com/contest/1096/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
vector<double>vv[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=3;i<=500;i++)
  {
    double tt=(i-2)*180;
    double per=tt/(i*1.0);
    double mn=per/((i-2)*1.0);double ang=mn;
    while(ang<=per)
    {
      vv[i].push_back(ang);
      ang+=mn;
    }
  }
  int t;cin>>t;
  while(t--)
  {
    double n;cin>>n;int f=0;
    for(int i=1;i<=500;i++)
    {
      for(auto x:vv[i])
      {
        if(fabs(x-n)<=0.000000000001)
        {
          cout<<i<<endl;
          f=1;break;
        }
      }
      if(f)break;
    }
  }
  // for(int i=3;i<=10;i++)
  // {
  //   for(auto x:vv[i])
  //   {
  //     cout<<x<<" ";
  //   }
  //   cout<<endl;
  // }
  return 0;
}