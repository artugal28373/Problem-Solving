/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/14/2017 22:28                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 529 ms                                          memory_used: 7900 KB                              
*  problem: https://codeforces.com/contest/831/problem/C
****************************************************************************************/
/*
4 1
-5 5 0 20
10
*/
#include<bits/stdc++.h>
using namespace std;
int k,n,sum,kk[2002],nn[2002],in,x,cnt,ans,i,j;
map<int,int>mp;
int main()
{
    cin>>k>>n;
    for(i=1;i<=k;i++)
    {
        cin>>x;
        sum+=x;
        kk[i]=sum;
    }
    for(i=1;i<=n;i++)
    {
        cin>>nn[i];
        mp[nn[i]]=1;
    }
    x=nn[1];
    set<int>s;
    for(i=1;i<=k;i++)
    {
        in=x-kk[i];
        cnt=n;
        for(j=1;j<=k;j++)
        {
            int xx=in+kk[j];
            ///cout<<xx<<" ";
            if(mp[xx]==1)cnt--;
        }
        ///cout<<endl;
        if(cnt<=0)s.insert(in);
     }
    cout<<s.size()<<endl;
     return 0;
}