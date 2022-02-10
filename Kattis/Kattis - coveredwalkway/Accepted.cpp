/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-18 17:45:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 690                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-coveredwalkway
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long vv[N+2],dis[N+2],lst[N+2];

#pragma once
struct line
{
  mutable long k,m,p;
  bool operator<(const line& o)const{return k<o.k;}
  bool operator<(long x)const{return p<x;}
};
struct lineContainer:multiset<line,less<>>
{
  //(for doubles,use inf=1/.0,div(a,b)=a/b)
  const long inf=LLONG_MAX;
  long div(long a,long b){return a/b-((a^b)<0&&a%b);}
  bool isect(iterator x,iterator y)
  {
    if(y==end()){x->p=inf;return false;}
    if(x->k==y->k)x->p=x->m>y->m?inf:-inf;
    else x->p=div(y->m-x->m,x->k-y->k);
    return x->p>=y->p;
  }
  void add(long k,long m)
  {
    k*=-1;m*=-1;//for min
    auto z=insert({k,m,0}),y=z++,x=y;
    while(isect(y,z))z=erase(z);
    if(x!=begin()&&isect(--x,y))isect(x,y=erase(y));
    while((y=x)!=begin()&&(--x)->p>=y->p)
      isect(x,erase(y));
  }
  long get(long x)
  {
    assert(!empty());
    auto l=*lower_bound(x);
    return -(l.k*x+l.m);//for min return -;
  }
};
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,c;cin>>n>>c;
  lineContainer hl;//hl.add(0,0);

  long now=0;
  for(int i=1;i<=n;i++)
  {
    long x;cin>>x;
    hl.add(-2*x,x*x+c+now);
    now=hl.get(x)+x*x;
  }
  cout<<now<<endl;
  return 0;
}