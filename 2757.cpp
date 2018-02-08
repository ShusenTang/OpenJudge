#include<cstdio>
using namespace std;

int num[1005];
int ans[1005] = {0};  //ans[i]表示以num[i]为最大值的最长子序列，则可通过 ans[0~i-1] 和 num[0~i-1]与num[i]的大小关系 推出ans[i]
int len;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&len);
    for(int i = 0; i < len; i++){
        scanf("%d",&num[i]);
        int leftmax = 0;
        for(int j = 0; j < i; j++){
            if(ans[j] > leftmax && num[i] > num[j]) leftmax = ans[j];  //通过 ans[0~i-1] 和 num[0~i-1]与num[i]的大小关系 推出ans[i]
        }
        ans[i] = leftmax + 1;
    }

    int maxans = 0;
    for(int i = 0; i < len; i++){
        if(ans[i] > maxans) maxans = ans[i];
    }
    printf("%d\n",maxans);

    return 0;
}
