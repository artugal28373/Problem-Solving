/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2017 09:21                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++14                               
*  run_time: 1000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/844/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long v,id,n,s,x,vl,nx;
int main()
{
    cin>>n>>s>>x;
    cout<<"? "<<s<<endl;
    fflush(stdout);
    cin>>v>>id;
    vl=v;
    nx=id;
    vl=0;
    for(long i=1;i<=n;i+=23)
    {
        cout<<"? "<<i<<endl;
        fflush(stdout);
        cin>>v>>id;
        if(v<=x&&v>vl)
        {
            vl=v;
            nx=id;
        }
     }
    while(true)
    {
        if(nx==-1)break;
        if(vl>=x)break;
        cout<<"? "<<nx<<endl;
        fflush(stdout);
        cin>>vl>>nx;
    }
    if(vl>=x)cout<<"! "<<vl<<endl;
    else cout<<"! "<<-1<<endl;
    fflush(stdout);
    return 0;
}