/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-14 00:15:00                      
*  solution_verdict: Memory Limit Exceeded                   language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1081
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,mat[510][510],sp1[510][510][20],sp2[510][510][20],sp3[510][510][20],sp4[510][510][20],n,q;
void sparse(void)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sp1[i][j][0]=mat[i][j];
            sp2[i][j][0]=mat[i][j];
            sp3[i][j][0]=mat[i][j];
            sp4[i][j][0]=mat[i][j];
        }
    }
    for(int k=1;k<=13;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                sp1[i][j][k]=sp1[i][j][k-1];
                if(i+(1<<(k-1))<=n)sp1[i][j][k]=max(sp1[i][j][k],sp1[i+(1<<(k-1))][j][k-1]);
                if(j+(1<<(k-1))<=n)sp1[i][j][k]=max(sp1[i][j][k],sp1[i][j+(1<<(k-1))][k-1]);
                if(i+(1<<(k-1))<=n&&j+(1<<(k-1))<=n)sp1[i][j][k]=max(sp1[i][j][k],sp1[i+(1<<(k-1))][j+(1<<(k-1))][k-1]);

                sp2[i][j][k]=sp2[i][j][k-1];
                if(i+(1<<(k-1))<=n)sp2[i][j][k]=max(sp2[i][j][k],sp2[i+(1<<(k-1))][j][k-1]);
                if(j-(1<<(k-1))>=0)sp2[i][j][k]=max(sp2[i][j][k],sp2[i][j-(1<<(k-1))][k-1]);
                if(i+(1<<(k-1))<=n&&j-(1<<(k-1))>=0)sp2[i][j][k]=max(sp2[i][j][k],sp2[i+(1<<(k-1))][j-(1<<(k-1))][k-1]);

                sp3[i][j][k]=sp3[i][j][k-1];
                if(i-(1<<(k-1))>=0)sp3[i][j][k]=max(sp3[i][j][k],sp3[i-(1<<(k-1))][j][k-1]);
                if(j+(1<<(k-1))<=n)sp3[i][j][k]=max(sp3[i][j][k],sp3[i][j+(1<<(k-1))][k-1]);
                if(i-(1<<(k-1))>=0&&j+(1<<(k-1))<=n)sp3[i][j][k]=max(sp3[i][j][k],sp3[i-(1<<(k-1))][j+(1<<(k-1))][k-1]);

                sp4[i][j][k]=sp4[i][j][k-1];
                if(i-(1<<(k-1))>=0)sp4[i][j][k]=max(sp4[i][j][k],sp4[i-(1<<(k-1))][j][k-1]);
                if(j-(1<<(k-1))>=0)sp4[i][j][k]=max(sp4[i][j][k],sp4[i][j-(1<<(k-1))][k-1]);
                if(i-(1<<(k-1))>=0&&j-(1<<(k-1))>=0)sp4[i][j][k]=max(sp4[i][j][k],sp4[i-(1<<(k-1))][j-(1<<(k-1))][k-1]);

            }
        }
    }

}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    int tc=0;
    while(t--)
    {
        memset(mat,0,sizeof(mat));
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>mat[i][j];
            }
        }
        sparse();
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<sp4[i][j][0]<<" "<<sp4[i][j][1]<<" "<<sp4[i][j][2]<<" "<<sp4[i][j][3]<<endl;
            }
        }*/
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            int i,j,s;
            cin>>i>>j>>s;
            int ii=i+s-1;
            int jj=j+s-1;
            int ans=0;
            for(int k=13;k>=0;k--)
            {
                if((1<<k)<=s)
                {
                    ans=max(sp1[i][j][k],max(sp2[i][jj][k],max(sp3[ii][j][k],sp4[ii][jj][k])));
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}