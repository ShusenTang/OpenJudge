#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXM = 505;
const int MAXK = 105;
int N,M,K;

int num[MAXK],hurt[MAXK];
int dp[MAXN][MAXM];



int main()
{
    freopen("input.txt","r",stdin);
    scanf("%d %d %d",&N,&M,&K);
    for(int i = 1; i <= K; i++) scanf("%d %d",&num[i],&hurt[i]);

    for(int k = 1; k <= K; k++){
        for(int n = N; n >= num[k]; n--){ //逆循环
            for(int h = M; h >= hurt[k]; h--) //逆循环
                dp[n][h] = max(dp[n][h],1+dp[n-num[k]][h-hurt[k]]);
        }
    }

    printf("%d ",dp[N][M]);

    for(int m = 0; m <= M; m++){ //找受伤最小
        if(dp[N][M] == dp[N][m]){
            printf("%d\n",M-m);
            break;
        }
    }
    return 0;
}
