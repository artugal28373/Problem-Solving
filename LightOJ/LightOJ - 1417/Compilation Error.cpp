/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-08 22:25:18                      
*  solution_verdict: Compilation Error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1417
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int R=2e7;
bool vis[R+2];
int aa[N+2];
void seive(void)
{
  vis[0]=1,vis[1]=1;int sq=sqrt(R+1);
  for(int i=2;i<=R;i+=2)vis[i]=1;
  for(int i=3;i<=R;i+=2)
  {
    if(vis[i])continue;
    if(i>sq)continue;
    for(int j=i*i;j<=R;j+=2*i)
      vis[j]=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();

  int n,sum=0;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>aa[i];sum+=aa[i];

  return 0;
}