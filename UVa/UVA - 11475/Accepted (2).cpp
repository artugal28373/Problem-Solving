/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-06 12:49:52                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11475
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manacher(string s)
{
  int n=s.size();
  od.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?1:min(od[l+r-i],r-i+1);
    while(0<=i-k&&i+k<n&&s[i-k]==s[i+k])k++;
    od[i]=k--;
    if(i+k>r)l=i-k,r=i+k;
  }
  ev.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?0:min(ev[l+r-i+1],r-i+1);
    while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k])k++;
    ev[i]=k--;
    if(i+k>r)l=i-k-1,r=i+k;
  }
  for(int i=0;i<n;i++)od[i]=od[i]*2-1;
  ev.erase(ev.begin());
  for(int i=0;i<n-1;i++)ev[i]=ev[i]*2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;while(cin>>s)
  {
    od.clear(),ev.clear();manacher(s);
    int b=0;
    for(int i=0;i<od.size();i++)
    {
      if(i+od[i]/2==s.size()-1)b=max(b,od[i]);
    }
    for(int i=0;i<ev.size();i++)
    {
      if(i+ev[i]/2==s.size()-1)b=max(b,ev[i]);
    }
    cout<<s;for(int i=s.size()-b-1;i>=0;i--)cout<<s[i];
    cout<<endl;
  }
  return 0;
}