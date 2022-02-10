/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-28 00:10:45                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1112
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long int
using namespace std;
long t,n,q,bit[100005],arr[100005],tc,x1,x2,x3;
void updp(long id,long v)
{
    for( ; id<=n; id+=id&-id)
    {
        bit[id]+=v;
    }
}
void updm(long id,long v)
{
    for( ; id<=n; id+=id&-id)
    {
        bit[id]-=v;
    }
}
long get(long id)
{
    long sum=0;
    for( ;id>0;id-=id&-id)
    {
        sum+=bit[id];
    }
    return sum;
}
int main()
{
    ///cin>>t;
    scanf("%lld",&t);
    while(t--)
    {
        tc=0;
        memset(bit,0,sizeof(bit));
        ///cin>>n>>q;
        scanf("%lld%lld",&n,&q);
        for(long i=1; i<=n; i++)
        {
            ///cin>>arr[i];
            scanf("%lld",&arr[i]);
            updp(i,arr[i]);
        }
        long f=0;
        while(q--)
        {
            ///cin>>x1;
            scanf("%lld",&x1);
            if(x1==1)
            {
                ///cin>>x2;
                scanf("%lld",&x2);
                x2++;
                if(f==0)
                {
                    ///cout<<"Case "<<++tc<<":"<<endl;
                    printf("Case %lld:\n",++tc);
                    f=1;
                }
                ///cout<<arr[x2]<<endl;
                printf("%lld\n",arr[x2]);
                updm(x2,arr[x2]);
            }
            else if(x1==2)
            {
                ///cin>>x2>>x3;
                scanf("%lld%lld",&x2,&x3);
                x2++;
                updp(x2,x3);
            }
            else
            {
                ///cin>>x2>>x3;
                scanf("%lld%lld",&x2,&x3);
                x2++;
                x3++;
                if(f==0)
                {
                    ///cout<<"Case "<<++tc<<":"<<endl;
                    printf("Case %lld:\n",++tc);
                    f=1;
                }
                ///cout<<get(x3)-get(x2-1)<<endl;
                printf("%lld\n",get(x3)-get(x2-1));
            }

        }

    }

    return 0;
}