/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-28 13:38:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1192                                       memory_used (MB): 19.1                            
*  problem: https://vjudge.net/problem/LightOJ-1011
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,mat[17][17],m,dp[17][1<<17],tc;
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=0; i<n; i++)
        {
            for(long j=0; j<n; j++)
            {
                cin>>mat[i][j];
            }
        }
        memset(dp,0,sizeof(dp));
        for(long i=0; i<n; i++)
        {
            if(i==0)
            {
                for(long j=0; j<n; j++)
                {
                    dp[i][1<<j]=mat[0][j];
                }
            }
            else
            {
                for(long j=0; j<n; j++)
                {
                    for(long k=1; k<(1<<n); k++)
                    {
                        if(dp[i-1][k])dp[i][k|(1<<j)]=max(dp[i][k|(1<<j)],dp[i-1][k]+mat[i][j]);
                    }
                }
            }
        }
        cout<<"Case "<<++tc<<": "<<dp[n-1][(1<<n)-1]<<endl;
    }
    return 0;
}