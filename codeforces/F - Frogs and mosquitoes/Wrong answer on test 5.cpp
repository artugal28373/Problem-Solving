/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2020 19:19                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 166900 KB                            
*  problem: https://codeforces.com/contest/609/problem/F
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
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=2e5;
const int inf=1e9;
struct segment
{
  int l,r,mn;
}sg[70*N];
int nw=1;
void create(int x)
{
  sg[x]={0,0,inf};
}
void pushDown(int nd)
{
  if(sg[nd].l==0)
  {
    create(++nw);sg[nd].l=nw;
  }
  if(sg[nd].r==0)
  {
    create(++nw);sg[nd].r=nw;
  }
  sg[sg[nd].l].mn=min(sg[sg[nd].l].mn,sg[nd].mn);
  sg[sg[nd].r].mn=min(sg[sg[nd].r].mn,sg[nd].mn);
}
void upd(int nd,int lo,int hi,int lt,int rt,int vl)
{
  if(lo!=hi)pushDown(nd);
  if(lo>rt||hi<lt)return ;
  if(lo>=lt&&hi<=rt)
  {
    sg[nd].mn=min(sg[nd].mn,vl);pushDown(nd);
    return;
  }
  int md=(lo+hi)/2;
  upd(sg[nd].l,lo,md,lt,rt,vl);
  upd(sg[nd].r,md+1,hi,lt,rt,vl);
}
int get(int nd,int lo,int hi,int id)
{
  if(lo!=hi)pushDown(nd);
  if(lo>id||hi<id)return inf;
  if(lo==hi)return sg[nd].mn;
  int md=(lo+hi)/2;
  if(id<=md)return get(sg[nd].l,lo,md,id);
  else return get(sg[nd].r,md+1,hi,id); 
}
int cnt[N+2],a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<vector<int> >v(n);
  for(int i=0;i<n;i++)
  {
    v[i].resize(3);
    cin>>v[i][0]>>v[i][1];
    v[i][2]=i+1;
  }
  sort(v.begin(),v.end());create(1);
  for(int i=0;i<n;i++)
    upd(1,0,inf,v[i][0],min(inf,v[i][0]+v[i][1]),i+1);
  set<pair<int,int> >st;
  while(m--)
  {
    int p,b;cin>>p>>b;int mn=get(1,0,inf,p);
    if(mn==inf)st.insert({p,b});
     else
    {
      int id=mn-1;
      cnt[id]++;v[id][1]+=b;
      upd(1,0,inf,v[id][0],min(inf,v[id][0]+v[id][1]),id+1);
       auto it=st.lower_bound({v[id][0],-1});
      vector<pair<int,int> >bf;
      while(it!=st.end())
      {
        if(it->first>v[id][0]+v[id][1])break;
        cnt[id]++;v[id][1]+=it->second;
        upd(1,0,inf,v[id][0],min(inf,v[id][0]+v[id][1]),id+1);
        bf.push_back(*it);it++;
      }
      for(auto x:bf)st.erase(x);
    }
  }
  for(int i=0;i<n;i++)
    a[v[i][2]]=cnt[i],b[v[i][2]]=v[i][1];
  for(int i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<'\n';
  return 0;
}