#include<cstdio>
#include<cstring>

//using namespace std;

/*
row1   :  -
col1[2]: | |
row2   :  -
col2[2]: | |
row3   :  -
*/

//int row1[10] = {1,0,1,1,0,1,1,1,1,1};
//int col1[10][2] = {{1,1},{1,0},{0,1},{0,1},{1,1},{1,0},{1,0},{0,1},{1,1},{1,1}};
//int row2[10] = {0,0,1,1,1,1,1,0,1,1};
//int col2[10][2] = {{1,1},{1,0},{1,0},{0,1},{0,1},{0,1},{1,1},{0,1},{1,1},{0,1}};
//int row3[10] = {1,0,1,1,0,1,1,0,1,1};
int row[3][10] = {{1,0,1,1,0,1,1,1,1,1},{0,0,1,1,1,1,1,0,1,1},{1,0,1,1,0,1,1,0,1,1}};
int col[2][10][2] = {{{1,1},{0,1},{0,1},{0,1},{1,1},{1,0},{1,0},{0,1},{1,1},{1,1}},{{1,1},{0,1},{1,0},{0,1},{0,1},{0,1},{1,1},{0,1},{1,1},{0,1}}};
int times;

void print_row(int digit,int tag){
    printf(" ");
    int tmp = times;
    while(tmp--){
        if(row[tag][digit]) printf("-");
        else printf(" ");
    }
    printf(" ");
}


void print_col(int digit,int tag){
    if(col[tag][digit][0]) printf("|");
    else printf(" ");

    int tmp = times;
    while(tmp--) printf(" ");

    if(col[tag][digit][1]) printf("|");
    else printf(" ");
}



void print_num(char num[]){
    for(int i = 0; i < strlen(num); i++) {
        print_row(num[i]-'0',0);
        if(i == strlen(num)-1) printf("\n");
        else printf(" ");
    }

    int tmp = times;
    while(tmp--){
        for(int i = 0; i < strlen(num); i++) {
            print_col(num[i]-'0',0);
            if(i == strlen(num)-1) printf("\n");
            else printf(" ");
        }
    }


    for(int i = 0; i < strlen(num); i++) {
        print_row(num[i]-'0',1);
        if(i == strlen(num)-1) printf("\n");
        else printf(" ");
    }

    tmp = times;
    while(tmp--){
        for(int i = 0; i < strlen(num); i++) {
            print_col(num[i]-'0',1);
            if(i == strlen(num)-1) printf("\n");
            else printf(" ");
        }
    }


    for(int i = 0; i < strlen(num); i++) {
        print_row(num[i]-'0',2);
        if(i == strlen(num)-1) printf("\n");
        else printf(" ");
    }
}


int main(){
    //freopen("input.txt","r",stdin);
    int n;
    char num[20];
    int flag = 0;
    while(1){
        scanf("%d %d",&times,&n);
        if(times == 0 && n == 0) break;

        if(flag != 0) printf("\n");
        flag = 1;
        sprintf(num,"%d",n);
        print_num(num);
    }

    return 0;
}
