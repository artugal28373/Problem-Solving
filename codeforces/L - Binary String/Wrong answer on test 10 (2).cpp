/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2019 13:14                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102001/problem/L
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long b;cin>>b;string s;cin>>s;
   long nm=0;
  if(s.size()>61)nm=(1LL<<60)+1;
  else 
  {
    for(int i=0;i<s.size();i++)
      nm=nm*2+s[i]-'0';
  }
  if(nm<=b)cout<<0<<endl,exit(0);
   string bn;
  while(b)
  {
    bn.push_back(char(b%2+'0'));
    b/=2;
  }
  reverse(bn.begin(),bn.end());
  //cout<<bn<<endl;
  bn.push_back('2');int pt=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]==bn[pt])pt++;
  }
  //cout<<pt<<endl;
  //cout<<s.size()-bn.size()<<endl;
  if(pt==bn.size()-1)cout<<s.size()-bn.size()+1<<endl;
  else cout<<s.size()-bn.size()+2<<endl;
    return 0;
}