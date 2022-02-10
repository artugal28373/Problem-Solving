/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-26 15:09:13                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1319
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long mm[N+2],aa[N+2];
long exgcd(long a,long b,long &x,long &y)
{
  if(!b)
  {
    x=1,y=0;return a;
  }
  long x1,y1;
  long g=exgcd(b,a%b,x1,y1);
  x=y1;
  y=x1-((long)(a/b))*y1;
  return g;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t,tc=0;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    for(long i=1;i<=n;i++)
      cin>>mm[i]>>aa[i];
    long a=aa[1],m=mm[1];
    for(long i=2;i<=n;i++)
    {
      long k1,k2,g;g=exgcd(m,mm[i],k1,k2);
      k1*=(aa[i]-a)/g;a=a+k1*m;
      m*=mm[i];a%=m;
    }
    cout<<"Case "<<++tc<<": "<<a<<endl;
  }
  return 0;
}