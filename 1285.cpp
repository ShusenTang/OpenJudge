#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;


int mp[51];

long long unsigned ans[51];
int m,n,r;

void init(){
    fill(mp,mp+51,0);
    ans[0] = 1;
    for(int i = 1; i < 51; i++) ans[i] = 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int case_cnt = 1,num;
    while(1){
        scanf("%d %d",&n,&m);
        if(m == 0 && n == 0) break;
        printf("Case %d:\n",case_cnt++);

        init();
        for(int i = 0; i < n; i++){
            scanf("%d",&num);
            mp[num]++;
        }

        for(int i = 1; i <= n; i++){ //针对数 1~n 作更新
            if(mp[i] == 0) continue; //mp[i]为数i的出现次数
            for(int j = n; j >= 0; j--){//j只能从n到0而不能从0到n,因为下面循环要用ans[j-k]更新ans[j],其中ans[j-k]应该是旧值，即j-k要后于j，即从大到小
                for(int k = 1; k <= mp[i]; k++){
                    if(j-k >= 0) ans[j] += ans[j-k]; //ans[j]表示从当前i个数取j个数的种数,ans[j-k]表示从上一次循环的i(即i-1)个数取j-k个数的种数
                }
            }
        }


        for(int i = 0; i < m; i++){
            scanf("%d",&r);
            printf("%llu\n",ans[r]);
        }
    }

    return 0;
}
