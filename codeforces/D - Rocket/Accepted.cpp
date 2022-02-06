/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2018 16:17                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1011/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int m,n,p[33];
int main()
{
  cin>>m>>n;
   for(int i=0;i<n;i++)
  {
    cout<<1<<endl;
    fflush(stdout);
    cin>>p[i];
    if(p[i]==0)exit(0);
  }
  int lo=1,hi=m,md;
   int i=0;
  while(true)
  {
    md=(lo+hi)/2;
    cout<<md<<endl;
    fflush(stdout);
    int tmp;
    cin>>tmp;
    if(tmp==0)exit(0);
    tmp*=p[i];
    i=(i+1)%n;
    if(tmp==1)
      lo=md+1;
    else hi=md-1;
  }
  return 0;
}