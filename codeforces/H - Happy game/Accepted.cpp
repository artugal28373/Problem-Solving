/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2021 22:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 56700 KB                             
*  problem: https://codeforces.com/gym/102700/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
const int inf=1e9;
 /*
there can be atmost n distinct palindromic substring of a string of length n.
every node of an eertree is a palindromic substring(and two roots for odd even)
a transition marked c from X to Y means Y=cXc;
a suffix link from X to Y means Y is proper suffix of X.
*/
pair<int,int>dp[N+2];//minimum odd and even factorization, 1 indexed
int nw,last;//last keeps track of the lps suffix of till inserted string
struct node
{
  int next[26],len,link;
   int dif,sLink;//for factorization
  pair<int,int>tmp;//for factorization
}pal[N+2];int occur[N+2];
 void init()
{
  pal[0].link=0;pal[0].len=-1;//odd length root
  pal[1].link=0;pal[1].len=0;//even length root
  nw=1,last=1;
   dp[0]={N+3,0};
   for(int i=0;i<N+2;i++)
  {
    pal[i].tmp={N+2,N+2};occur[i]=0;
    memset(pal[i].next,0,sizeof pal[i].next);
  }
}
void build(string s)
{
  s="#"+s;
  for(int p=1;p<s.size();p++)
  {
    while(s[p-pal[last].len-1]!=s[p])last=pal[last].link;
    int x=pal[last].link,c=s[p]-'a';
    while(s[p-pal[x].len-1]!=s[p])x=pal[x].link;//finding suffix link
    if(!pal[last].next[c])
    {
      pal[last].next[c]=++nw;pal[nw].len=pal[last].len+2;
      if(pal[nw].len==1)pal[nw].link=1;
      else pal[nw].link=pal[x].next[c];
       last=pal[last].next[c];
     }
    else last=pal[last].next[c];
    occur[last]++;
  }
  for(int i=nw;i>=2;i--)occur[pal[i].link]+=occur[i];
}
int cnt;
void dfs(int now)
{
  if(pal[now].len>1)cnt++;
  for(int i=0;i<26;i++)
    if(pal[now].next[i])dfs(pal[now].next[i]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  init();
  int n;cin>>n;string s;cin>>s;build(s);
   dfs(0);cout<<cnt<<endl;
   return 0;
}