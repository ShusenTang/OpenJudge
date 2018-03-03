#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[200];

void big_mul(int m){
    int tmp,cin = 0;
    for(int i = 0; i < 200; i++){
       tmp = cin + m*ans[i];
       ans[i] = tmp % 10;
       cin = tmp / 10;
    }
}

int dot_digit(char *strR){
    for(int i = 5; i >= 0; i--){
        if(strR[i] == '.') return 5-i;
    }
}

void print_ans(int dot){
    int pos = 0,final_i = 0; //final_i为最输出时最后位置
    while(ans[pos] == 0) pos++;
    if(pos <= dot) final_i = pos;
    else final_i = dot;

    int flag = 0;
    for(int i = 199; i >= final_i; i--){
        if(i == dot-1) {
            printf(".");
            flag = 1;
        }
        if(flag == 0 && ans[i] != 0) flag = 1;
        if(flag) printf("%d",ans[i]);
        //if(i == dot) printf(".");
    }
    if(flag == 0) printf("0");
    printf("\n");

}

int main()
{
    //freopen("input.txt","r",stdin);
    char strR[7];
    int R,n,dot_pos,dot_num;
    while(scanf("%s %d",strR,&n) != EOF){
       dot_num = dot_digit(strR);
       dot_pos = 5 - dot_num;
       for(; dot_pos < 6; dot_pos++) strR[dot_pos] = strR[dot_pos+1];
       sscanf(strR,"%d",&R);
       memset(ans,0,sizeof(ans));
       ans[0] = 1;
       dot_num *= n;
       while(n--) big_mul(R);
       print_ans(dot_num);
    }
    return 0;
}

