#include <stdio.h>
#include <string.h>
int dp[100][100];
int dig[100];

int dfs(int i,int s,bool e)
{
	if (!i) return (s==0?1:0);
	if ((!e)&&(dp[i][s]!=-1))	return dp[i][s];
	int res=0;
	int u=e?dig[i]:9;
	for (int q=0;q<=u;q++)
		res+=dfs(i-1,(s+q)%10,e&&q==u);
    if (!e)    dp[i][s]=res;
	return res;
}

int f(int n)
{
    int len = 0;
    while(n)
    {
        dig[++len] = n % 10;
        n /= 10;
    }
    return dfs(len,0,true);
}

int main()
{
    int a,b,T;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",f(b)-f(a-1));
    }
    return 0;
}

