/****************************************************************************************
*  @author: kzvd4729                                         created: 03/04/2021 14:45                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 4 ms                                            memory_used: 6.2 MB                               
*  problem: https://leetcode.com/problems/regular-expression-matching
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int dp[30+2][30+2];
string tx,pt;int a,b;
bool dfs(int i,int j)
{
  if(i==a&&j==b)return true;
  if(j==b)return false;
  if(dp[i][j]!=-1)return dp[i][j];
  bool ret=false;
  if(j+1<b&&pt[j+1]=='*')
  {
    ret|=dfs(i,j+2);
    if(pt[j]=='.')
    {
      for(int k=i;k<a;k++)
        ret|=dfs(k+1,j+2);
    }
    else if(i<a&&pt[j]==tx[i])
    {
      for(int k=i;k<a;k++)
      {
        if(tx[k]==tx[i])ret+=dfs(k+1,j+2);
        else break;
      }
    }
  }
  else
  {
    if(i<a&&tx[i]==pt[j])ret|=dfs(i+1,j+1);
    if(i<a&&pt[j]=='.')ret|=dfs(i+1,j+1);
  }
  return dp[i][j]=ret;
}
bool solve(string s,string p)
{
  while(true)
  {
    int f=1;
    for(int i=1;i<(int)p.size();i++)
    {
      if(p[i]=='*'&&p[i-1]=='*')
      {
        p.erase(p.begin()+i);
        f=0;break;
      }
    }
    if(f)break;
  }
  tx=s;pt=p;a=tx.size(),b=pt.size();
  memset(dp,-1,sizeof dp);
  return dfs(0,0);
}
class Solution {
public:
    bool isMatch(string s, string p) 
    {
      return solve(s,p);    
    }
};