/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 12:55                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/121/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long lm=1e9;
long ans,l,r;
vector<long>v;
void dfs(long n)
{
  v.push_back(n);
  if(n>lm)return ;
  dfs(n*10+4);
  dfs(n*10+7);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     dfs(0);
    sort(v.begin(),v.end());
    cin>>l>>r;
    for(long i=l;i<=r;i++)
    {
      long xx=v[lower_bound(v.begin(),v.end(),i)-v.begin()];
      if(xx<=r)ans+=xx;
    }
    cout<<ans<<endl;
    return 0;
}