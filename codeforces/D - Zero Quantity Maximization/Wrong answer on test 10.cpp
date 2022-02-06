/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/07/2019 21:52                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1133/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],cc[N+2];
map<pair<int,int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];
  for(int i=1;i<=n;i++)
    cin>>bb[i];
  int ans=0,add=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]==0&&bb[i]==0)
      ans++;
    else if(aa[i]==0)continue;
    else
    {
      int gc=__gcd(abs(aa[i]),abs(bb[i]));
      aa[i]/=gc,bb[i]/=gc;
      if(aa[i]<0&&bb[i]<0)
        aa[i]*=-1,bb[i]*=-1;
      else if(aa[i]<0||bb[i]<0)
      {
        aa[i]=-abs(aa[i]);
        bb[i]=abs(bb[i]);
      }
      mp[{aa[i],bb[i]}]++;
      add=max(add,mp[{aa[i],bb[i]}]);
    }
  }
  cout<<ans+add<<endl;
  return 0;
}