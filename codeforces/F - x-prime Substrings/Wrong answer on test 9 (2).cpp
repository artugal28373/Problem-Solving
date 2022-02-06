/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2020 19:25                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++17                               
*  run_time: 62 ms                                           memory_used: 81500 KB                             
*  problem: https://codeforces.com/contest/1400/problem/F
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
#define long long long
using namespace std;
const int N=1e3;
string s;int x,n,dp[N+2][10+2][10+2][10+2][10+2];
int dfs(int i,int a,int b,int c,int d)
{
  if(i==n)return 0;
  if(a<i)a=n;if(b<i)b=n;if(c<i)c=n;if(d<i)d=n;
  if(a>b)swap(a,b);if(a>c)swap(a,c);if(b>c)swap(b,c);
  if(a>d)swap(a,d);if(b>d)swap(b,d);if(c>d)swap(c,d);
   int aa=min(10,a-i),bb=min(10,b-i),cc=min(10,c-i),dd=min(10,d-i);
  if(i==a)return dp[i][aa][bb][cc][dd]=dfs(i+1,b,c,d,n);
   if(s[i]-'0'==x)return dp[i][aa][bb][cc][dd]=1+dfs(i+1,a,b,c,d);
   if(dp[i][aa][bb][cc][dd]!=-1)return dp[i][aa][bb][cc][dd];
   vector<int>v;int sm=0,ls;
  for(int j=i;j<n;j++)
  {
    if(j==a||j==b||j==c)continue;
    int nm=s[j]-'0';if(sm+nm>x)break;
    v.push_back(nm);sm+=nm,ls=j;
     if(x%nm==0)return dp[i][aa][bb][cc][dd]=dfs(i+1,a,b,c,d);
  }
  if(sm!=x)return dp[i][aa][bb][cc][dd]=dfs(i+1,a,b,c,d);
  for(int j=0;j<v.size();j++)
  {
    int sm=0;
    for(int k=j;k<v.size();k++)
    {
      sm+=v[k];
      if(sm!=x&&x%sm==0)return dp[i][aa][bb][cc][dd]=dfs(i+1,a,b,c,d);
    }
  }
  int dl[10+2];memset(dl,0,sizeof dl);int ad=0;
  for(int j=ls+1;j<n;j++)
  {
    if(j!=a&&j!=b&&j!=c&&j!=d)ad+=s[j]-'0';
    if(ad>=10)break;dl[ad]=1;
  }
  int mn=n+1;
  for(int j=i;j<=ls;j++)
  {
    if(j==a||j==b||j==c)continue;
    if(dl[s[j]-'0'])continue;
    if(a==n)mn=min(mn,1+dfs(i+1,j,b,c,d));
    else if(b==n)mn=min(mn,1+dfs(i+1,a,j,c,d));
    else if(c==n)mn=min(mn,1+dfs(i+1,a,b,j,d));
    else if(d==n)mn=min(mn,1+dfs(i+1,a,b,c,j));
  }
  return dp[i][aa][bb][cc][dd]=mn;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>s>>x;n=s.size();
  memset(dp,-1,sizeof dp);
  cout<<dfs(0,n,n,n,n)<<endl;
  return 0;
}