/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/19/2020 18:58                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1083/problem/B
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  string a,b;cin>>a>>b;
   int na=0,nb=0;int df=1;long ans=0;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]=='a'&&b[i]=='b')df*=2;
    else if(a[i]==b[i])df=df*2-1;
    else df=df*2-2;
     df=min(df,k);ans+=df;
  }
  cout<<ans<<endl;
  return 0;
}