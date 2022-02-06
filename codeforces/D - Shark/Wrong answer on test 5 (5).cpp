/****************************************************************************************
*  @author: kzvd4729                                         created: May/19/2018 00:27                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/982/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,arr[N+2],mn=2e9,id,ans,now,loc;
vector<int>tmp,lft,rgt;
bool check(int xx,int sz)
{
  int here=0;
  loc=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[i]>=xx)
    {
      if(here)loc++;
      if(here!=0&&here!=sz)return false;
      here=0;
    }
    else here++;
  }
  if(here)loc++;
  if(here!=0&&here!=sz)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    tmp.push_back(arr[i]);
    if(arr[i]<mn)
    {
      mn=arr[i];
      id=i;
    }
  }
  sort(tmp.begin(),tmp.end());
  for(int i=id;i<=n;i++)
    rgt.push_back(arr[i]);
  for(int i=id;i>=1;i--)
    lft.push_back(arr[i]);
  for(int i=1;i<lft.size();i++)
    lft[i]=max(lft[i],lft[i-1]);
  for(int i=1;i<rgt.size();i++)
    rgt[i]=max(rgt[i],rgt[i-1]);
  ans=mn;
  int lcc=-1;
  for(int i=1;i<=n;i++)
  {
    if(i==id)continue;
    now=arr[i];
    int les=lower_bound(tmp.begin(),tmp.end(),now)-tmp.begin();
    int llt=lower_bound(lft.begin(),lft.end(),now)-lft.begin();
    int lrt=lower_bound(rgt.begin(),rgt.end(),now)-rgt.begin();
     if(les%(llt+lrt-1))continue;
     if(check(arr[i],llt+lrt-1))
    {
      if(loc==lcc)
        ans=min(ans,arr[i]);
      if(loc>lcc)
      {
        lcc=loc;
        ans=arr[i];
      }
      if(ans==45567032)
      {
        cout<<ans<<endl;
        return 0;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}