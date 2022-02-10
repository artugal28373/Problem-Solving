/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-31 00:06:30                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1043
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc;
double ab,ac,bc,s,area,ade,rat,bdec;
const double eps=0.000000001;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>ab>>ac>>bc>>rat;
        s=(ab+bc+ac)/2.0;
        area=sqrt(s*(s-ab)*(s-bc)*(s-ac));
        double lo,hi;
        lo=0;
        hi=area;
        for(int i=1; i<=10000; i++)
        {
            bdec=(lo+hi)/2.0;
            ade=bdec*rat;
            if((bdec+ade)>area)
                hi=bdec;
            else
                lo=bdec;
        }
        ade=bdec*rat;
        double ans=sqrt((ade*ab*ab)/area);
        cout<<setprecision(12)<<fixed<<ans<<endl;
    }
    return 0;
}