/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-08 18:06:01                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1010
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m,n,tc=0;
    ///cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        ///cout<<"Case "<<++tc<<": "<<((m*n)+1)/2<<endl;
        printf("Case %d: %d\n",++tc,max(((m*n)+1)/2,max(m,n)));
    }
    return 0;
}