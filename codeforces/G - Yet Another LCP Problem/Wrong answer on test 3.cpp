/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2019 22:16                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 982 ms                                          memory_used: 63300 KB                             
*  problem: https://codeforces.com/contest/1073/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int ent[N+2],tim,index[N+2],fra[N+2],frb[N+2],aa[N+2],bb[N+2];
long qma[N+2],qmb[N+2],qmfra[N+2],qmfrb[N+2];
struct suffixAutomata
{
  int sz,last,occur[N+N+2];
  struct node
  {
    int len,link,next[26];
  }aut[N+N+2];//2*insrt function call
  vector<int>tree[N+2];
  void clean(int n=N)//must call before insert
  {
    for(int i=0;i<=n+n;i++)
    {
      memset(aut[i].next,0,sizeof(aut[i].next));
    }
    sz=0,last=0,aut[0].link=-1;
  }
  int con(char c)//check for word size
  {
    return c-'a';
  }
  void insrt(int c,int id)
  {
    int now=++sz;aut[now].len=aut[last].len+1;
    occur[now]=1;int p,q,cl;index[id]=now;
    for(p=last;p!=-1&&!aut[p].next[c];p=aut[p].link)
      aut[p].next[c]=now;
    if(p==-1)
      aut[now].link=0;
    else
    {
      q=aut[p].next[c];
      if(aut[p].len+1==aut[q].len)
        aut[now].link=q;
      else
      {
        cl=++sz;aut[cl].len=aut[p].len+1;
        aut[cl].link=aut[q].link;
        memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));//for array
        //aut[cl].next=aut[q].next;//for map
        for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
          aut[p].next[c]=cl;
        aut[now].link=aut[q].link=cl;
      }
    }
    last=now;
  }
  void dfs(int nd)
  {
    ent[nd]=++tim;
    for(auto x:tree[nd])
      dfs(x);
  }
  void makeTree(void)
  {
    for(int i=1;i<=sz;i++)
      tree[aut[i].link].push_back(i);
  }
}sam;
pair<int,int>pp[N+2];
bool cmp(pair<int,int>a,pair<int,int>b)
{
  int x=a.first,y=b.first;
  return ent[index[x]]<ent[index[y]];
}
string s;
int match(int i,int j)
{
  for(int k=-1; ;k++)
  {
    if(i+k==s.size()||j+k==s.size()||s[i+k]!=s[j+k])
      return k+1;
    if(k>=1000)return s.size()-max(i,j);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  sam.clean();cin>>s;
  for(int i=s.size()-1;i>=0;i--)
    sam.insrt(s[i]-'a',i+1);
  sam.makeTree();sam.dfs(0);
  while(q--)
  {
    int a,b;cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
      cin>>pp[i].first;pp[i].second=1;
    }
    for(int i=a+1;i<=a+b;i++)
    {
      cin>>pp[i].first;pp[i].second=2;
    }
    sort(pp+1,pp+a+b+1,cmp);
     /*cout<<endl<<endl;
    for(int i=1;i<=a+b;i++)
      cout<<pp[i].first<<" "<<pp[i].second<<endl;*/
    int pra=-1,prb=-1,x=0,y=0;
    aa[0]=-1;bb[0]=-1;
    long ans=0,asam=0,bsam=0;
    for(int i=1;i<=a+b;i++)
    {
      if(pp[i].second==1)
      {
        if(prb!=-1)
        {
          int mt=match(prb,pp[i].first);
          ans+=mt;
           if(y<1||mt==0);
          else{
          int lo=1,hi=y,md;
          while(hi-lo>2)
          {
            md=(lo+hi)/2;
            if(bb[md]>mt)hi=md;
            else lo=md;
          }
          for(md=hi;md>=lo;md--)
            if(bb[md]<=mt)break;
          ans+=qmb[bb[md]]+1LL*mt*(qmfrb[bb[y]]-qmfrb[bb[md]]);}
         }
        if(pra!=-1)
        {
          int mt=match(pra,pp[i].first);
          fra[mt]++;
          while(true)
          {
            int nm=aa[x];
            if(nm>mt)
            {
              fra[mt]+=fra[nm];fra[nm]=0;
              qma[nm]=0;qmfra[nm]=0;
              x--;
            }
            else if(nm==mt)break;
            else
            {
              aa[++x]=mt;break;
            }
          }
          qma[mt]=1LL*mt*fra[mt];qmfra[mt]=fra[mt];
          if(aa[x-1]!=-1)qma[mt]+=qma[aa[x-1]],qmfra[mt]+=qmfra[aa[x-1]];
        }
        pra=pp[i].first;
      }
      else
      {
        if(pra!=-1)
        {
          int mt=match(pra,pp[i].first);
          ans+=mt;
           if(x<1||mt==0);
          else{
          int lo=1,hi=x,md;
          while(hi-lo>2)
          {
            md=(lo+hi)/2;
            if(aa[md]>mt)hi=md;
            else lo=md;
          }
          for(md=hi;md>=lo;md--)
            if(aa[md]<=mt)break;
          ans+=qma[aa[md]]+1LL*mt*(qmfra[aa[x]]-qmfra[aa[md]]);}
         }
        if(prb!=-1)
        {
          int mt=match(prb,pp[i].first);
          frb[mt]++;
          while(true)
          {
            int nm=bb[y];
            if(nm>mt)
            {
              frb[mt]+=frb[nm];frb[nm]=0;
              qmb[nm]=0;qmfrb[nm]=0;
              y--;
            }
            else if(nm==mt)break;
            else
            {
              bb[++y]=mt;break;
            }
          }
          qmb[mt]=1LL*mt*frb[mt];qmfrb[mt]=frb[mt];
          if(bb[y-1]!=-1)qmb[mt]+=qmb[bb[y-1]],qmfrb[mt]+=qmfrb[bb[y-1]];
        }
        prb=pp[i].first;
      }
      //cout<<ans<<endl;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=x;i++)fra[aa[i]]=0,qma[aa[i]]=0,qmfra[aa[i]]=0;
    for(int i=1;i<=y;i++)frb[bb[i]]=0,qmb[bb[i]]=0,qmfrb[bb[i]]=0;
  }
  return 0;
}