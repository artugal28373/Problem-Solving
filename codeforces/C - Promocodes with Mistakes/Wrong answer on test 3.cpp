/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2018 16:05                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/637/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans=999999999,cnt;
string s[1003];
int main()
{
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            cnt=0;
            for(long k=0;k<6;k++)
            {
                if(s[i][k]!=s[j][k])cnt++;
            }
            ans=min(ans,(cnt-1)/2);
        }
    }
    cout<<ans<<endl;
    return 0;
}