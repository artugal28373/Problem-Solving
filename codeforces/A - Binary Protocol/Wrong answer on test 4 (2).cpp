/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2017 21:52                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/825/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
char ans[2099];
long long int n,i,cnt,id,zero;
int main()
{
    cin>>n;
    cin>>s;
    id=-1;
    cnt=0;
    zero=0;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            cnt++;
            zero=0;
        }
        else
        {
            if(cnt)ans[++id]=(char)cnt+'0';
            cnt=0;
            zero++;
            if(zero>1)ans[++id]='0';
        }
    }
    if(cnt)ans[++id]=(char)cnt+'0';
    ans[++id]='\0';
    cout<<ans<<endl;
     return 0;
}