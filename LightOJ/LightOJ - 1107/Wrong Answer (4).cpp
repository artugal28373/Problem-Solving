/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-29 22:36:56                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1107
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc,a,b,c,d,x,y,n;
int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
        scanf("%ld",&n);
        printf("Case %ld:\n",++tc);
        while(n--)
        {
            scanf("%ld%ld",&x,&y);
            ///if(x<a||x>c||y<b||y>d)printf("No\n");
            ///else printf("Yes\n");
            if(x>=a&&x<=c&&y>=b&&y<=d)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}