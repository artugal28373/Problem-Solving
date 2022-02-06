/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/02/2020 01:34                        
*  solution_verdict: Compilation error                       language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/F
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
const int N=4e5;
struct suffixArray
{
  char t[N+12];int idx[N+12];//N is atleast 300
  int n,c[N+12],RA[N+12],SA[N+12],tRA[N+12],tSA[N+12];
  void init(string s)
  {
    n=s.size();
    for(int i=0;i<n;i++)t[i]=s[i];
    t[n++]='#';
  }
  void countingSort(int k)
  {
    memset(c,0,sizeof c);
    for(int i=0;i<n;i++)c[i+k<n?RA[i+k]:0]++;
    for(int i=0,sm=0;i<max(300,n);i++)
    {
      int d=c[i];c[i]=sm;sm+=d;
    }
    for(int i=0;i<n;i++)tSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++]=SA[i];
    for(int i=0;i<n;i++)SA[i]=tSA[i];
  }
  void buildSA()
  {
    for(int i=0;i<n;i++)RA[i]=t[i];
    for(int i=0;i<n;i++)SA[i]=i;
    for(int k=1,r;k<n;k<<=1)
    {
      countingSort(k);countingSort(0);tRA[SA[0]]=r=0;
      for(int i=1;i<n;i++)  
        tRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]]&&RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
      for(int i=0;i<n;i++)RA[i]=tRA[i];
      if(RA[SA[n-1]]==n-1)break;
    }
    //suffixes are sorted in index SA[1] to SA[n-1];
    //use SA index 1 to s.size() for outside use;
  }
  int phi[N+12],tmp[N+12],lcp[N+12];
  void computeLCP()
  {
    phi[SA[0]]=-1;
    for(int i=1;i<n;i++)phi[SA[i]]=SA[i-1];
    for(int i=0,l=0;i<n;i++)
    {
      if(phi[i]==-1){tmp[i]=0;continue;}
      while(t[i+l]==t[phi[i]+l])l++;
      tmp[i]=l;l=max(l-1,0);
    }
    for(int i=0;i<n;i++)lcp[i]=tmp[SA[i]];//lcp with previous suffix in sorted order
    for(int i=0;i<n;i++)idx[SA[i]]=i;//order of suffix i in sorted list
  }
  void print()
  {
    for(int i=0;i<n;i++)printf("%2d\t%2d\t%s\n",SA[i],lcp[i],t+SA[i]);
  }
}sa;
int sp[N+2][20+2],a[N+2];
void build(int n)
{
  for(int i=1;i<=n;i++)sp[i][0]=a[i];//array
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if((i+(1<<(j-1)))<=n)
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int get(int lt,int rt)
{
  if(rt<lt)return 1e9;
  //cout<<lt<<" "<<rt<<endl;
  int dg=31-__builtin_clz(rt-lt+1);
  return min(sp[lt][dg],sp[rt-(1<<dg)+1][dg]);
}
int lcp(int i,int j)
{
  int a=sa.idx[i],b=sa.idx[j];
  if(a>b)swap(a,b);return get(a+1,b);
}
const int magic=200;
int n;
int cal(int i,int j)
{
  if(j-i+1<=magic)continue;
  int now=1,l=i,r=j;int df=j-i+1;
  while(true)
  {
    if(r==n-1)break;int x=lcp(l,r+1);int gp=r-l+1;
    if(x>=gp)now*=2,r+=gp;
    else 
    {
      int mt=x/df;now+=mt;
      r+=df*mt;break;
    }
  }
  while(true)
  {
    int gp=r-l+1;if(l-gp<0)break;
     int x=lcp(l-gp,l);
    if(x>=gp)now*=2,l-=gp;
    else break;
  }
  int lo=0,hi=n/df+2,md;
  while(hi-lo>2)
  {
    md=(lo+hi)/2;
    if(l-md*df<0)hi=md;
    else if(lcp(l-md*df,l)>=md*df)lo=md;
    else hi=md;
  }
  for(md=hi;md>=lo;md--)
  {
    if(l-md*df<0)continue;
    else if(lcp(l-md*df,l)>=md*df)break;
  }
  return now+md;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;n=s.size();
  sa.init(s);sa.buildSA();sa.computeLCP();
  //sa.print();
   for(int i=1;i<=n;i++)a[i]=sa.lcp[i];
  build(n);
   int ans=1;
  for(int l=1;l<=magic;l++)
  {
    for(int b=0;b<l;b++)
    {
      int cr=1;
      for(int i=b+l;i<n;i+=l)
      {
        if(lcp(i,i-l)>=l)cr++;else cr=1;
        if(cr>ans)ans=cr;
      }
    }
  }
  for(int i=2;i<=n;i++)
  {
    ans=max(ans,cal(min(sa.SA[i],sa.SA[i-1]),max(sa.SA[i],sa.SA[i-1])-1));
    if(sa.lcp[i]==0)continue;
    ans=max(ans,cal(sa.SA[i],sa.SA[i]+sa.lcp[i]-1));
    ans=max(ans,cal(sa.SA[i-1],sa.SA[i-1]+sa.lcp[i]-1));
  }
  cout<<ans<<endl;
  return 0;
}