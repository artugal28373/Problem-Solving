/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 16:35                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 19900 KB                             
*  problem: https://codeforces.com/contest/631/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5+1;
const long b=117757711;
int n,m,l,sz,last;
char ch;
vector<int>tre[N],pos;
vector<pair<int,char> >in,pt;
struct automata
{
  int link,len,id;
  map<long,int>next;
}st[N+N];
void insrt(long c,int idx)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].id=idx;
   int p,q,cl;
  for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)
    st[p].next[c]=now;
  if(p==-1)
    st[now].link=0;
  else
  {
    q=st[p].next[c];
    if(st[p].len+1==st[q].len)
      st[now].link=q;
    else
    {
      cl=++sz;
      st[cl].id=st[q].id;
      st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      st[cl].next=st[q].next;
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        p=st[p].link;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void suffix_tree(void)
{
  for(int i=1;i<=sz;i++)
    tre[st[i].link].push_back(i);
}
void case1(void)
{
  int ans=0;
  pair<int,char>p=pt[0];
  for(auto x:in)
  {
    if(x.second==p.second)
      ans+=max(0,x.first-p.first+1);
  }
  cout<<ans<<endl;
}
void case2(void)
{
  int ans=0;
  pair<int,char>p1=pt[0];
  pair<int,char>p2=pt[1];
  for(int i=0;i<in.size()-1;i++)
  {
    if(in[i].second==p1.second&&in[i+1].second==p2.second)
      ans++;
  }
  cout<<ans<<endl;
}
void dfs(int now)
{
  pos.push_back(st[now].id);
  for(auto x:tre[now])
    dfs(x);
}
void case3(void)
{
  int now=0;
  for(int i=1;i<pt.size()-1;i++)
  {
    long x=pt[i].first*b+int(pt[i].second);
    if(st[now].next[x]==0)
    {
      cout<<0<<endl;
      return ;
    }
    now=st[now].next[x];
  }
  dfs(now);
  int nn=pt.size()-1,ans=0;
  for(auto x:pos)
  {
    if(pt.back().second==in[x].second&&in[x].first>=pt.back().first)
      if(pt[0].second==in[x-nn].second&&in[x-nn].first>=pt[0].first)
        ans++;
  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  st[0].link=-1;
  for(int i=1;i<=n;i++)
  {
    cin>>l;
    cin.ignore();
    cin>>ch;
     if(in.size()==0)
      in.push_back({l,ch});
    else
    {
      pair<int,char>p=in.back();
      if(p.second==ch)
      {
        p.first+=l;
        in[int(in.size())-1]=p;
      }
      else in.push_back({l,ch});
    }
  }
  for(int i=0;i<in.size();i++)
  {
    long x=in[i].first*b+int(in[i].second);
    insrt(x,i+1);
  }
  for(int i=1;i<=m;i++)
  {
    cin>>l;
    cin.ignore();
    cin>>ch;
     if(pt.size()==0)
      pt.push_back({l,ch});
    else
    {
      pair<int,char>p=pt.back();
      if(p.second==ch)
      {
        p.first+=l;
        pt[int(pt.size())-1]=p;
      }
      else pt.push_back({l,ch});
    }
  }
  suffix_tree();
  if(pt.size()==1)case1();
  else if(pt.size()==2)case2();
  else case3();
  return 0;
}