/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2020 19:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 71000 KB                             
*  problem: https://codeforces.com/contest/1129/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=3e3,mod=1e9+7;
long dp[N+2][N+2]; 
string s;
bool ck(long i)
{
  if(i+4>s.size())return 0;
  if(s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='1'&&s[i+3]=='1')return false;
  if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0'&&s[i+3]=='1')return false;
  if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='1'&&s[i+3]=='0')return false;
  if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='1'&&s[i+3]=='1')return false;
  return true;
}
long dfs(long i,long j)
{
  if(i>j)
  {
    if(i==j+1)return 1;
    return 0;
  }
  if(dp[i][j]!=-1)return dp[i][j];
  long ret=dfs(i+1,j);
  ret+=dfs(i+2,j);
  ret+=dfs(i+3,j);
  if(ck(i))ret+=dfs(i+4,j);
  return dp[i][j]=ret%mod;
}
const long mod1=1000001011,mod2=1000009999;
const long b1=193,b2=307;
long pw1[N+2],pw2[N+2];
void cal(long n)
{
  pw1[0]=1;pw2[0]=1;
  for(long i=1;i<=n;i++)
  {
    pw1[i]=(1LL*pw1[i-1]*b1)%mod1;
    pw2[i]=(1LL*pw2[i-1]*b2)%mod2;
  }
}
struct hsh
{
  string s;vector<pair<long,long> >v;
  pair<long,long>makeHash(void)
  {
    long hs1=0,hs2=0;
    for(auto x:s)
    {
      hs1=(1LL*hs1*b1+x)%mod1;
      hs2=(1LL*hs2*b2+x)%mod2;
      v.push_back({hs1,hs2});
    }
    return {hs1,hs2};
  }
  pair<long,long>segment(long lt,long rt)
  {
    long x=v[rt].first,y=v[rt].second;
    if(!lt)return {x,y};
    x=x-(1LL*v[lt-1].first*pw1[rt-lt+1])%mod1;
    y=y-(1LL*v[lt-1].second*pw2[rt-lt+1])%mod2;
    if(x<0)x+=mod1;if(y<0)y+=mod2;
    return {x,y};
  }
};
long dp2[N+2];
long dpRET(long i)
{
  if(i<0)return 1;return dp2[i];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;cal(n);
  for(long i=0;i<n;i++)
  {
    long x;cin>>x;if(x==0)s.push_back('0');
    else s.push_back('1');
  }
  memset(dp,-1,sizeof(dp));hsh h;h.s=s;h.makeHash();
  for(long i=0;i<s.size();i++)
  {
    long pt=i-1;
    for(long j=i;j>=0;j--)
    {
      long f=0;
      while(true)
      {
        if(pt-(i-j)<0)break;
         if(h.segment(pt-(i-j),pt)==h.segment(j,i)){f=1;break;}
        else pt--;
      }
      //if(i==2)cout<<f<<endl;
      if(!f)dp2[i]=(dp2[i]+dfs(j,i)+mod)%mod;
    }
    long ans=0;
    for(long j=0;j<=i;j++)ans=(ans+dp2[j])%mod;
    cout<<ans<<"\n";
  }
  return 0;
}