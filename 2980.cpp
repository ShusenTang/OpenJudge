#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char num1[205],num2[205];
int ans[405] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%s",num1);
    scanf("%s",num2);
    int len1 = strlen(num1),len2 = strlen(num2);
    reverse(num1,num1+len1);
    reverse(num2,num2+len2);
    for(int i = 0; i < len1; i++)
    for(int j = 0; j < len2; j++){
        ans[i+j] += (num1[i]-'0')*(num2[j]-'0'); //先不管进位
    }
    
    //处理进位
    int tmp,cin = 0;
    for(int i = 0; i < 405; i++){
        tmp = ans[i] + cin;
        cin = tmp / 10;
        ans[i] = tmp % 10;
    }

    //输出
    int flag = 0;
    for(int i = 404; i >= 0; i--){
        if(flag == 0 && ans[i] != 0) flag = 1;
        if(flag) printf("%d",ans[i]);
    }
    if(flag == 0) printf("0");
    printf("\n");

    return 0;
}

