/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/02/2021 15:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 39900 KB                             
*  problem: https://codeforces.com/contest/1477/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string a,b;
int sg[4*N+8],lz[4*N+8];
void build(int nd,int lo,int hi)
{
  lz[nd]=-1;
  if(lo==hi)
  {
    sg[nd]=b[lo-1]-'0';return ;
  }
  int md=(lo+hi)/2;
  build(nd*2,lo,md);build(nd*2+1,md+1,hi);
   sg[nd]=sg[nd*2]+sg[nd*2+1];
}
void tooLazy(int nd,int lo,int hi)
{
  if(lz[nd]==-1)return ;
   sg[nd]=(hi-lo+1)*lz[nd];
  if(lo==hi)return;
   lz[nd*2]=lz[nd];lz[nd*2+1]=lz[nd];
  lz[nd]=-1;
}
void upd(int nd,int lo,int hi,int lt,int rt,int vl)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    lz[nd]=vl;tooLazy(nd,lo,hi);
    return ;
  }
  int md=(lo+hi)/2;
  upd(nd*2,lo,md,lt,rt,vl);
  upd(nd*2+1,md+1,hi,lt,rt,vl);
   sg[nd]=sg[nd*2]+sg[nd*2+1];
}
int get(int nd,int lo,int hi,int lt,int rt)
{
  tooLazy(nd,lo,hi);
  if(lo>rt||hi<lt)return 0;
  if(lo>=lt&&hi<=rt)return sg[nd];
  int md=(lo+hi)/2;
  return get(nd*2,lo,md,lt,rt)+get(nd*2+1,md+1,hi,lt,rt);
}
int l[N+2],r[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,q;cin>>n>>q;
    cin>>a>>b;build(1,1,n);
     for(int i=1;i<=q;i++)cin>>l[i]>>r[i];
    int f=0;
    for(int i=q;i>=1;i--)
    {
      int g=get(1,1,n,l[i],r[i]);
      int mx=(r[i]-l[i])/2;
       if(g<=mx)upd(1,1,n,l[i],r[i],0);
      else if(r[i]-l[i]+1-g<=mx)upd(1,1,n,l[i],r[i],1);
      else f=1;
    }
    for(int i=1;i<=n;i++)
    {
      int g=get(1,1,n,i,i);
      if(g!=a[i-1]-'0')f=1;
    }
    if(f)cout<<"NO\n";else cout<<"YES\n";
  }
  return 0;
}