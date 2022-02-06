/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/28/2018 19:01                        
*  solution_verdict: Memory limit exceeded on test 1         language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/126/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int last,sz,occur[N+N],l,lid[N+N];
vector<int>v[N+N];
char s[N+2];
struct automata
{
  int len,link,next[26];
}st[N+N];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;
  lid[now]=st[now].len;
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
      st[cl].len=st[p].len+1;
      lid[cl]=st[cl].len;
      st[cl].link=st[q].link;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      //st[cl].next=st[q].next;
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void process(void)
{
  for(int i=1;i<=sz;i++)
    v[st[i].len].push_back(i);
  for(int i=l;i>=1;i--)
    for(auto x:v[i])
      occur[st[x].link]+=occur[x];
}
void rndm(void)
{
  for(int i=l;i>=1;i--)
    for(auto x:v[i])
      lid[st[x].link]=max(lid[st[x].link],lid[x]);
}
int main()
{
  scanf("%s",&s);
  l=strlen(s);
  st[0].link=-1;
  for(int i=0;i<l;i++)insrt(s[i]-'a');
  process();
  rndm();
  int now=0,ans=-1;
  for(int i=0;i<l;i++)
  {
    int c=s[i]-'a';
    now=st[now].next[c];
    if(lid[now]==l&&occur[now]>=3)
      ans=i;
  }
  if(ans==-1)printf("Just a legend");
  else for(int i=0;i<=ans;i++)printf("%c",s[i]);
  return 0;
}