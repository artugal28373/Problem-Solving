/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-29 20:14:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 149                                        memory_used (MB): 2.1                             
*  problem: https://vjudge.net/problem/LightOJ-1244
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const int mod=10007;
typedef vector<vector<int> > v2d;
/*
1 1 1   f[n]       f[n+1]
1 0 0 X f[n-1]  =  f[n]
0 1 0   f[n-2]     f[n-1]
*/
v2d multiply(v2d &a,v2d &b)
{
  int d=a.size(),e=a[0].size();
  int f=b.size(),g=b[0].size();
  if(e!=f)assert(0);//impossible to multiply
  v2d c;c.resize(d);
  for(int i=0;i<d;i++)
  {
    c[i].resize(g,0);
    for(int j=0;j<g;j++)
      for(int k=0;k<e;k++)
        c[i][j]=(c[i][j]+1LL*a[i][k]*b[k][j])%mod;
  }
  return c;
}
v2d expo(v2d a,long p)
{
  int n=a.size();if(a[0].size()!=n)assert(0);//impossible
  v2d ret;ret.resize(n);
  for(int i=0;i<n;i++)ret[i].resize(n);
  for(int i=0;i<n;i++)ret[i][i]=1;
  while(p)
  {
    if(p&1)ret=multiply(ret,a);
    a=multiply(a,a);p/=2;
  }
  return ret;
}
/*
used to get query faster
complexity q*logp*d^2
*/
v2d power[65];//max power
void precalPower(v2d &b,long mx)
{
  power[0]=b;long p=1;
  for(int i=1;p+p<=mx;i++,p=p+p)
    power[i]=multiply(power[i-1],power[i-1]);
}
int compute(v2d v,long p)//v is a column vector
{
  while(p)
  {
    long z=63-__builtin_clzll(p);
    p^=(1LL<<z);
    v=multiply(power[z],v);
  }
  return v[0][0];
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  v2d b(4);
  b[0].resize(4);b[0][0]=1,b[0][1]=1,b[0][3]=2;
  b[1].resize(4);b[1][0]=1;
  b[2].resize(4);b[2][1]=1;
  b[3].resize(4);b[3][1]=1,b[3][3]=1;

  precalPower(b,1e9);

  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    cout<<"Case "<<++tc<<": ";
    if(n==1){cout<<1<<"\n";continue;}
    if(n==2){cout<<2<<"\n";continue;}
    v2d v(4);
    v[0].push_back(2);v[1].push_back(1);
    v[2].push_back(1);v[3].push_back(1);

    cout<<compute(v,n-2)<<"\n";
  }
  return 0;
}