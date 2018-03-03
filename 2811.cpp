#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int init_light[7][8],now_light[7][8];
int button[7][8] = {0};

void initial_now_light(){
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <=6; j++)
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
    for(int j = 1; j <= 6; j++){
        if(button[1][j]) one_button(1,j);
    }
    for(int i = 2; i <= 5; i++)
    for(int j = 1; j <= 6; j++){
        if(now_light[i-1][j]) one_button(i,j);
    }
    for(int j = 1; j <= 6; j++){
       if(now_light[5][j]) return false;
    }
    return true;
}


int main()
{

    for(int i = 1; i <= 5; i++)
    for(int j = 1; j <= 6; j++){
        scanf("%d",&init_light[i][j]);
    }

    int remain,max_cnt = (int)pow(2,6);
    for(int cnt = 0; cnt < max_cnt; cnt++){
        remain = cnt;
        for(int k = 1; k <= 6; k++){
            button[1][k] = remain % 2;
            remain /= 2;
        }
        
        initial_now_light();
        if(isOK()){
            for(int i = 2; i <= 5; i++)
            for(int j = 1; j <= 6; j++) button[i][j] = 0;
            
            initial_now_light();
            isOK();
            for(int i = 1; i <=5; i++)
            for(int j = 1; j <= 6; j++){
                printf("%d",button[i][j]);
                if(j == 6) printf("\n");
                else printf(" ");
            }
            return 0;
        }
    }
    return 0;
}
