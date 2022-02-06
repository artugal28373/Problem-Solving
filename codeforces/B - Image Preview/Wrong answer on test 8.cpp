/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/02/2019 11:03                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/650/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2],bc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,a,b,t;cin>>n>>a>>b>>t;
  string s;cin>>s;
  for(int i=1;i<=n;i++)
  {
    fr[i]=fr[i-1];if(i>1)fr[i]+=a;
    if(s[i-1]=='w')fr[i]+=b;fr[i]++;
  }
  for(int i=n;i>=1;i--)
  {
    bc[i]=bc[i+1];bc[i]+=a;
    if(s[i-1]=='w')bc[i]+=b;bc[i]++; 
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(fr[i]<=t)ans=i;
    //cout<<fr[i]<<" ";
  }
  //cout<<endl;
  for(int i=1;i<=n;i++)
  {
    if(bc[i]<=t)ans=max(ans,n-i+1);
    //cout<<bc[i]<<" ";
  }
  //cout<<endl;
  for(int i=1;i<n;i++)
  {
    int lo=i+1,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      long cs=min(i-1,hi-md+1)*a+fr[i]+bc[md];
      if(cs>t)lo=md;else hi=md;
    }
    for(md=lo;md<=hi;md++)
    {
      long cs=min(i-1,hi-md+1)*a+fr[i]+bc[md];
      if(cs<=t)
      {
        ans=max(ans,i+hi-md+1);
        break;
      } 
    }
  }
  cout<<ans<<endl;
  return 0;
}