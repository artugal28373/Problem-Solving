/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-05-09 17:28:28                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1420
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const long mod=1000000007;
int dp[N+2][N+2][N+2],qm[N+2];
string a,b,c;
vector<int>po[3][30];
inline int norm(int x)
{
  if(x>=mod)return x-mod;
  return x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>a>>b>>c;
    for(int i=0;i<26;i++)po[1][i].clear(),po[2][i].clear();
    for(int i=0;i<a.size();i++)
      po[1][a[i]-'a'].push_back(i);
    for(int i=0;i<b.size();i++)
      po[2][b[i]-'a'].push_back(i);
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=a.size();i++)
      for(int j=0;j<=b.size();j++)
        dp[i][j][c.size()]=1;

    for(int k=c.size()-1;k>=0;k--)
    {
      memset(qm,0,sizeof(qm));
      for(int i=a.size();i>=0;i--)
      {
        int sm=0;
        for(int j=b.size();j>=0;j--)
        {
          if(a[i]==c[k])qm[j]+=dp[i+1][j][k+1];norm(qm[j]);
          if(b[j]==c[k])sm+=dp[i][j+1][k+1];norm(sm);
          int l=c[k]-'a';int now=0;
          int id1=lower_bound(po[1][l].begin(),po[1][l].end(),i)-po[1][l].begin();
          int id2=lower_bound(po[2][l].begin(),po[2][l].end(),j)-po[2][l].begin();
          now+=qm[j];norm(now);now+=sm;norm(now);
          dp[i][j][k]=now;
        }
      }
    }
    cout<<"Case "<<++tc<<": "<<dp[0][0][0]<<"\n";
  }
  return 0;
}