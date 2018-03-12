#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAXN 100010

using namespace std;

int n,price[MAXN],left[MAXN],right[MAXN];


void com_left_max(){
    //memset(left,0,sizeof(left));
    left[0] = 0;

    int max1 = left[0], min1 = price[0];
    for(int i = 1; i < n; i++){
        if(price[i] < min1) min1 = price[i];

        if(price[i]-min1 > max1){
            left[i] = price[i]-min1;
            max1 = left[i];
        }
        else left[i] = max1;
    }
}

void com_right_max(){
    //memset(left,0,sizeof(left));
    right[n-1] = 0;

    int max1 = right[n-1], max2 = price[n-1];
    for(int i = n-2; i >= 0; i--){
        if(price[i] > max2) max2 = price[i];

        if(max2 - price[i] > max1){
            right[i] = max2 - price[i];
            max1 = right[i];
        }
        else right[i] = max1;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",&price[i]);
        com_left_max();
        com_right_max();
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(ans < left[i]+right[i]) ans =  left[i]+right[i];
        printf("%d\n",ans);
    }
    return 0;
}
