/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/15/2017 22:35                        
*  solution_verdict: Time limit exceeded on test 12          language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/785/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,s,x,i;
    while(cin>>n>>m)
    {
        x=n;
        if(n<m)
        {
            for(i=1;  ;i++)
            {
                x=x-i;
                if(x<=0)break;
            }
             cout<<i<<endl;
        }
        else
        {
            for(i=m;  ;i++)
            {
                x=x+m;
                if(x>=n)x=n;
                x=x-i;
                if(x<=0)break;
             }
             cout<<i<<endl;
        }
      }
     return 0;
}