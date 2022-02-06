/****************************************************************************************
*  @author: kzvd4729                                         created: May/08/2018 21:46                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++11                               
*  run_time: 30 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/980/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k;
char mat[5][102];
void mem(void)
{
  for(int i=1;i<=4;i++)
    for(int j=1;j<=100;j++)
      mat[i][j]='.';
}
void print(void)
{
  for(int i=1;i<=4;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cout<<mat[i][j];
    }
    cout<<endl;
  }
}
void case1(void)
{
  if(k>n-2)
  {
    cout<<"NO"<<endl;
    return ;
  }
  cout<<"YES"<<endl;
  for(int i=2;i<k+2;i++)
    mat[2][i]='#';
  print();
  return ;
}
void case2(void)
{
  cout<<"YES"<<endl;
  k/=2;
  for(int i=2;i<2+k;i++)
  {
    mat[2][i]='#';
    mat[3][i]='#';
  }
  print();
  return ;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mem();
  cin>>n>>k;
  if(k%2==0)
    case2();
  else case1();
   return 0;
}