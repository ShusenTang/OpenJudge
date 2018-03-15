#include<bits/stdc++.h>
using namespace std;

const int MAXN = 51;
int dp[MAXN];
//int w[MAXN];
int n;
int main()
{
    //freopen("input.txt","r",stdin);
    while( scanf("%d",&n)!= EOF ){
        fill(dp,dp+n+1,0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++)
                dp[j] += dp[j-i];
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
