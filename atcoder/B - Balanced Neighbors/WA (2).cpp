/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-05-02 14:31:57                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 8 ms                                            memory_used: 384 KB                               
*  problem: https://atcoder.jp/contests/agc032/tasks/agc032_b
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int aa[N+2],bb[N+2],rq[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int tr=(n*(n-1))/2;if(n%2==0)tr--;
   for(int i=1;i<=n;i++)rq[i]=tr;
  vector<pair<int,int> >ed;
  for(int i=n;i>=1;i--)
  {
    for(int j=i-1;j>=1;j--)
    {
      if(rq[i]>=j&&rq[j]>=i)
        ed.push_back({i,j}),rq[i]-=j,rq[j]-=i;
    }
  }
  cout<<ed.size()<<endl;
  for(auto x:ed)cout<<x.first<<" "<<x.second<<endl;
  return 0;
}