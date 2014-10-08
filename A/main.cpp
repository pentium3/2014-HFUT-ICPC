#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s;
int T,l,ans,tmp;
char ch;
int st[500];
char ts[100];

int main()
{
    cin>>T;
    gets(ts);
    while (T--)
    {
        getline(cin,s);
        l=s.length();
        memset(st,0,sizeof(st));
        for (int i=0;i<l;i++)
        {
            ch=s[i];
            tmp=ch;
            //if ch//ch is a lowercase alpha
            if ((tmp>=97)&&(tmp<=122))
                st[tmp]++;
        }
        ans=0;
        for (int i=97;i<=122;i++)
            if (st[i]!=0)
                ans++;
        printf("%d\n",ans);
    }

    return 0;
}
