/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2020 22:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 888 ms                                          memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1423/problem/J
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
vector<int>v;
int ex;
int dp[10+2][10+2];
int dfs(int id,int pr)
{
  if(id<0)return pr==ex;
  int tmp=v[id]+pr*2;
  int ret=0;
  if(dp[id][pr]!=-1)return dp[id][pr];
  for(int i=0;i<=6;i++)
  {
    if(tmp-i<=7&&tmp-i>=0)ret=(ret+dfs(id-1,i))%mod;
  }
  return dp[id][pr]=ret;
}
int str[6+2][(1<<10)+2][6+2];
void pre()
{
  for(int i=0;i<(1<<10);i++)
  {
    v.clear();
    for(int j=0;j<10;j++)v.push_back((bool)(i&(1<<j)));
    for(int pr=0;pr<=6;pr++)
    {
      for(ex=0;ex<=6;ex++)
      {
        memset(dp,-1,sizeof dp);
        //if(i==0&&pr==0)cout<<"*"<<dfs(10-1,pr)<<endl;
        str[ex][i][pr]=dfs(10-1,pr);
        //cout<<dfs(10-1,pr)<<endl;
      }
    }
  }
}
int d[6+2][6+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pre();//cout<<4*6*6*500000<<endl;
  int t;cin>>t;
  while(t--)
  {
    long n;cin>>n;v.clear();
     int m=10,msk=0;
    for(int i=60-1;i>=50;i--)
    {
      --m;
      if(n&(1LL<<i))msk|=(1<<m);
    }
    v.push_back(msk);
     m=10,msk=0;
    for(int i=50-1;i>=40;i--)
    {
      --m;
      if(n&(1LL<<i))msk|=(1<<m);
    }
    v.push_back(msk);
     m=10,msk=0;
    for(int i=40-1;i>=30;i--)
    {
      --m;
      if(n&(1LL<<i))msk|=(1<<m);
    }
    v.push_back(msk);
     m=10,msk=0;
    for(int i=30-1;i>=20;i--)
    {
      --m;
      if(n&(1LL<<i))msk|=(1<<m);
    }
    v.push_back(msk);
     m=10,msk=0;
    for(int i=20-1;i>=10;i--)
    {
      --m;
      if(n&(1LL<<i))msk|=(1<<m);
    }
    v.push_back(msk);
     m=10,msk=0;
    for(int i=10-1;i>=0;i--)
    {
      --m;
      if(n&(1LL<<i))msk|=(1<<m);
    }
    v.push_back(msk);
     reverse(v.begin(),v.end());
    int aa[6+2];
    for(int i=0;i<v.size();i++)aa[i]=v[i];
    d[0][0]=1;
    for(int id=1;id<=6;id++)
    {
      for(int pr=0;pr<=6;pr++)
      {
        long ret=0;
        for(int ex=0;ex<=6;ex++)
        {
          ret=ret+1LL*str[ex][aa[id-1]][pr]*d[id-1][ex];
        }
        d[id][pr]=ret%mod;
      }
    }
    cout<<d[6][0]<<" ";
  }
  cout<<endl;
  return 0;
}