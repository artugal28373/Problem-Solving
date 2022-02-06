/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2019 18:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/803/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long n,k;
long mul(long a,long b)
{
  long cnt=0,c=a,d=b;
  while(a)
  {
    cnt++;a/=10;
  }
  while(b)
  {
    cnt++;b/=10;
  }
  if(cnt>15)return 100000000000000000LL;
  else return c*d;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;if(k>1000000)cout<<-1<<endl,exit(0);
  long sq=sqrt(n+1);long sum=(k*(k-1))/2;
  long ans=-1;
  for(long i=1;i<=sq;i++)
  {
    if(n%i==0)
    {
      long a=i,b=n/i,d;
      long aa=mul(a,sum);d=n-aa;
      aa=a*(k-1);if(d>aa)ans=max(ans,a);
       long bb=mul(b,sum);d=n-bb;
      bb=b*(k-1);if(d>bb)ans=max(ans,b);
    }
  }
  if(ans==-1)cout<<-1<<endl,exit(0);
  long pr=0,sm=0;
  for(int i=1;i<k;i++)
  {
    pr+=ans;cout<<pr<<" ";
    sm+=pr;
  }
  cout<<n-sm<<endl;
  return 0;
}