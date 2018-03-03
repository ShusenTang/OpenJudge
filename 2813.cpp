//改编自2811:熄灯问题
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

int init_light[17][17],now_light[17][17];
int button[17][17] = {0};
int n;

void initial_now_light(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=n; j++)
        now_light[i][j] = init_light[i][j];
}

void change_light(int i, int j){
    if(now_light[i][j]) now_light[i][j] = 0;
    else now_light[i][j] = 1;
}

void one_button(int i, int j){
    button[i][j] = 1;
    change_light(i,j);
    change_light(i+1,j);
    change_light(i,j+1);
    change_light(i-1,j);
    change_light(i,j-1);
}

bool isOK(){
    for(int j = 1; j <= n; j++){
        if(button[1][j]) one_button(1,j);
    }
    for(int i = 2; i <= n; i++)
    for(int j = 1; j <= n; j++){
        if(now_light[i-1][j]) one_button(i,j);
    }
    for(int j = 1; j <= n; j++){
       if(now_light[n][j]) return false;
    }
    return true;
}


int main()
{
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    int found = 0,ans = 0;

    char tmp[20];
    for(int i = 1; i <= n; i++){
        scanf("%s",tmp);
        for(int j = 1; j <= n; j++){
            if(tmp[j-1] == 'y') init_light[i][j] = 0;
            else init_light[i][j] = 1;
        }
    }

    int remain,max_cnt = (int)pow(2,n);
    for(int cnt = 0; cnt < max_cnt; cnt++){
        remain = cnt;
        for(int k = 1; k <= n; k++){
            button[1][k] = remain % 2;
            remain /= 2;
        }

        initial_now_light();
        if(isOK()){
            found = 1;
            for(int i = 2; i <= n; i++)
            for(int j = 1; j <= n; j++) button[i][j] = 0;

            initial_now_light();
            isOK();
            for(int i = 1; i <=n; i++)
            for(int j = 1; j <= n; j++) ans += button[i][j];
            break;
        }
    }
    if(found) printf("%d\n",ans);
    else printf("inf\n");
    return 0;
}
