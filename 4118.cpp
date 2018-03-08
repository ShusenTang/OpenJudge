#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAXN = 100;
int m[MAXN],p[MAXN],dp[MAXN]; // dp[i]代表位置为0-i上的餐馆最大利润


int main()
{
    //freopen("input.txt","r",stdin);

    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i = 0; i < n; i++) scanf("%d",&m[i]);
        for(int i = 0; i < n; i++) scanf("%d",&p[i]);

        dp[0] = p[0];
        for(int i = 1; i < n; i++){
            dp[i] = p[i];
            for(int j = i-1; j >= 0; j--)
                if(m[i] - m[j] > k) dp[i] = max(dp[i],dp[j]+p[i]);
                else dp[i] = max(dp[i],dp[j]);
        }
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
