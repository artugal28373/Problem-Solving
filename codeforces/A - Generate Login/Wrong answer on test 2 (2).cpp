/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/28/2017 08:50                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/909/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
string s1,s2;
cin>>s1>>s2;
char x=s2[0];
if(s1[0]>=s2[0])
{
cout<<s1[0]<<s2[0]<<endl;
return 0;   
}
for(long i=0;i<s1.size();i++)
{
char z=s1[i];
if(z<x)cout<<z;
else break;
}
cout<<x<<endl;
 return 0;
}