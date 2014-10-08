/*
#include <iostream>
using namespace std;

int main()
{
    cin>>T;
    while T--
    {
        cin>>n>>l>>r>>ql>>qr;
        for (int i=1;i<=n;i++)
            cin>>w[i];

        tl=1;   tr=n;
        memset(f,0,sizeof(f));
        f[1][1]=w[1]*l;
        f[1][2]=w[n]*r;

        for (int i=2;i<=n;i++)
        {
            f[i][1]=min(f[i-1][2]+w[tl]*l,
                        f[i-1][1]+w[tl]*l+ql);
            f[i][2]=min(f[i-1][2]+w[tr]*r+qr,
                        f[i-1][1]+w[tl]*l);
        }

        ans=min(f[n][1],f[n][2]);
    }
    return 0;
}
*/

#include <iostream>
#include <cmath>
#define INF 99999
using namespace std;

int T,n,l,r,ql,qr,ans,mn,mni,tl,tr;
int w[1000];

int main()
{
    cin>>T;
    while (T--)
    {
        cin>>n>>l>>r>>ql>>qr;
        for (int i=1;i<=n;i++)
            cin>>w[i];

        mn=INF;
        for (int i=0;i<=n;i++)
        {
            ans=0;
            for (int j=1;j<=i;j++)
                ans+=w[j]*l;
            for (int j=i+1;j<=n;j++)
                ans+=w[j]*r;
            tl=i;   tr=n-i;
            if (tl>tr)
                ans+=ql*(tl-tr-1);
            else if (tl<tr)
                ans+=qr*(tr-tl-1);
            if (ans<mn)
            {
                mn=ans;
                mni=i;
            }
        }
        cout<<mn<<endl;
    }
}
