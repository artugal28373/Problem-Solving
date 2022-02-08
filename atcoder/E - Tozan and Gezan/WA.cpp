/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-07 19:36:41                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 10 ms                                           memory_used: 768 KB                               
*  problem: https://atcoder.jp/contests/arc094/tasks/arc094_c
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
struct data
{
  long a,b,d;
}arr[200005];
bool cmp(data A,data B)
{
  return A.d<B.d;
}
bool cmp2(data A,data B)
{
  return A.a>B.a;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].a>>arr[i].b;
    arr[i].d=arr[i].a-arr[i].b;
  }
  sort(arr+1,arr+n+1,cmp);
  long bn=0,sum=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[i].d<0)
    {
      bn-=arr[i].d;
      sum+=arr[i].a;
    }
  }
  sort(arr+1,arr+n+1,cmp2);
  for(int i=1;i<=n;i++)
  {
    if(arr[i].d<0)continue;
    if(arr[i].d<bn)
    {
      sum+=arr[i].a;
      bn-=arr[i].d;
    }
    else
    {
      sum+=bn;
      bn=0;
      break;
    }
  }
  cout<<sum<<endl;
  return 0;
}