/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-11 12:22:16                      
*  solution_verdict: Presentation Error                      language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1014
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<long long int>v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t,p,l,e,s,i,z,tc=0;
    cin>>t;
    while(t--)
    {
        cin>>p>>l;
        e=p-l;
        for(i=1;i<=sqrt(e);i++)
        {
            if(e%i==0)v.push_back(i);
        }
        s=v.size();
        for(i=s-1;i>=0;i--)
        {
            z=e/v[i];
            if(z!=v[i])v.push_back(z);
        }
        int f=0;
        cout<<"Case "<<++tc<<": ";
        for(i=0;i<v.size();i++)
        {
            if(v[i]>l)
            {
                f=1;
                cout<<v[i]<<" ";
            }
        }
        if(f==1)cout<<endl;
        else cout<<"impossible"<<endl;
        v.clear();
    }
    return 0;
}