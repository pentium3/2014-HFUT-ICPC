
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> ans;
int RMQ[301000][20],GCD[301000][20];
int T,n,l,r,mx,num;
int a[301000];

int gcd(int x,int y)
{
    return (y==0)?x:gcd(y,x%y);
}

void ST()
{
    memset(RMQ,1,sizeof(RMQ));
    memset(GCD,1,sizeof(GCD));

    for(int i=1;i<=n;i++)
        RMQ[i][0]=GCD[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
    {
        RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+(1<<(j-1))][j-1]);
        GCD[i][j]=gcd(GCD[i][j-1],GCD[i+(1<<(j-1))][j-1]);
    }
}

bool Query(int L,int R)
{
    if (L==R) return true;
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    int ta=min(RMQ[L][k],RMQ[R-(1<<k)+1][k]);
    int tb=gcd(GCD[L][k],GCD[R-(1<<k)+1][k]);
    if (ta==tb)   return true;
        else return false;
}

/*
bool calc(int x)
{
    for (int i=1;i<=n-x+1;i++)
    {
        bool ok=Query(i,i+x-1);
        if (ok)
        {
            cout<<"----"<<i<<" "<<i+x-1<<" "<<x<<endl;  //record the answer,use vector
            if (x==mx)
            {
                num++;
                ans.push_back(i);
            }
            else if (x>mx)
            {
                num=1;
                mx=x;
                ans.clear();
                ans.push_back(i);
            }
            return true;
        }
    }
    return false;
}
*/

bool calc(int x)        //x: r-l
{
    bool res=false;
    for (int i=1;i<=n-x;i++)
    {
        bool ok=Query(i,i+x);
        if (ok)
        {
            res=true;
            //cout<<"----"<<i<<" "<<i+x<<" "<<x<<endl;  //record the answer,use vector
            if (x==mx)
            {
                num++;
                ans.push_back(i);
            }
            else if (x>mx)
            {
                num=1;
                mx=x;
                ans.clear();
                ans.push_back(i);
            }
        }
    }
    return res;
}

int main()
{
        mx=-1;
        num=0;
        ans.clear();
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];

        ST();

        l=0;    r=n;
        while (r>=l)
        {
            int mid=(l+r)/2;    //mid: r-l
            if (calc(mid))
                l=mid+1;
            else
                r=mid-1;
        }
        cout<<num<<" "<<mx<<endl;
            vector<int>::iterator ii;
            for (ii=ans.begin();ii!=ans.end();ii++)
                cout<<*ii<<" ";
        cout<<endl;

    return 0;
}


/*
注意特殊情况：
5
2 3 5 7 11
计算时应把r-l=0也考虑进去
(r==l)
*/

