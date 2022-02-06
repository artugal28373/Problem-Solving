/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/17/2017 00:07                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 2900 KB                              
*  problem: https://codeforces.com/contest/825/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s,t;
int arr1[2222],arr2[2222];
char ans[999999];
long long int i,j,lo,hi,mid,cnt,sum,nd;
int main()
{
    cin>>s>>t;
    for(i=0; i<t.size(); i++)
    {
        arr2[(int)(t[i]-'a')]++;
    }
    /*for(i=0;i<26;i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;*/
    cnt=0;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='?')cnt++;
        else arr1[(int)(s[i]-'a')]++;
    }
    ///cout<<cnt<<endl;
    /*for(i=0;i<26;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;*/
    lo=0;
    hi=10000000;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        sum=0;
        for(i=0; i<26; i++)
        {
            nd=arr2[i]*mid;
            nd-=arr1[i];
            if(nd<0)nd=0;
            sum=sum+nd;
        }
        if(sum>=cnt)hi=mid-1;
        else lo=mid+1;
     }
    mid++;
    sum=0;
    for(i=0; i<26; i++)
    {
        nd=arr2[i]*mid;
        nd-=arr1[i];
        if(nd<0)nd=0;
        sum=sum+nd;
    }
    if(sum>cnt)
    {
        mid--;
        sum=0;
        for(i=0; i<26; i++)
        {
            nd=arr2[i]*mid;
            nd-=arr1[i];
            if(nd<0)nd=0;
            sum=sum+nd;
        }
        if(sum>cnt)mid--;
     }
    ///cout<<mid<<endl;
    int id=-1;
    for(i=0;i<26 ; i++)
    {
        arr2[i]=arr2[i]*mid;
        if(arr2[i])
        {
            while(arr2[i]--)
            {
                ans[++id]=(char)i+'a';
                if(arr1[i])arr1[i]--;
                else cnt--;
            }
        }
    }
    for(i=0;i<26;i++)
    {
        while(arr1[i]--)ans[++id]=(char)i+'a';
    }
    while(cnt--)ans[++id]='z';
     ans[++id]='\0';
    cout<<ans<<endl;
     return 0;
}