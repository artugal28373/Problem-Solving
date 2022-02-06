/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 19:57                        
*  solution_verdict: Time limit exceeded on test 16          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/534/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=20;
int n,m,rw[N+2],cl[N+2],f;
vector<int>sg[6],ans;
//bool vis[22][(1<<5)+1][12][12][12][12][12];
void dfs(int st,int last,int on,int tw,int th,int fr,int fv,vector<int>ans)
{
  if(st==m)
  {
    if(on==rw[0]&&tw==rw[1]&&th==rw[2]&&fr==rw[3]&&fv==rw[4])
    {
      f=1;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if((ans[j]&(1<<i)))cout<<'*';
          else cout<<'.';
        }
        cout<<endl;
      }
    }
    return ;
  }
  for(auto x:sg[cl[st]])
  {
    int onn=on,tww=tw,thh=th,frr=fr,fvv=fv;
    for(int i=0;i<5;i++)
    {
      if(!(last&(1<<i))&&(x&(1<<i)))
      {
        if(i==0)onn++;if(i==1)tww++;if(i==2)thh++;
        if(i==3)frr++;if(i==4)fvv++;
      }
    }
    vector<int>tmp=ans;tmp.push_back(x);
    dfs(st+1,x,onn,tww,thh,frr,fvv,tmp);
    if(f)
    {
      ans.push_back(x);
      return ;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>rw[i];
  for(int i=0;i<m;i++)
    cin>>cl[i];
  for(int i=0;i<(1<<n);i++)
  {
    bool last=0;int cnt=0;
    for(int j=0;j<n;j++)
    {
      bool z=(i&(1<<j));
      if(z&&!last)cnt++;
      last=z;
    }
    sg[cnt].push_back(i);
  }
  vector<int>tmp;
  dfs(0,0,0,0,0,0,0,tmp);
//  reverse(ans.begin(),ans.end());
//  for(int i=0;i<n;i++)
//  {
//    for(int j=0;j<m;j++)
//    {
//      if((ans[i]&(1<<j)))cout<<'*';
//      else cout<<'.';
//    }
//    cout<<endl;
//  }
  return 0;
}