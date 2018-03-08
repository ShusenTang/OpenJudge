#include<stdio.h>

int moun[109][109];
int ans[109][109] = {0};
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int r,c;;

bool ok(int i,int j)
{
   return ( i>=0 && i<r && j>=0 && j<c );
}

int dp(int i, int j){
    if( ans[i][j] > 0 ) return ans[i][j];

    for(int k = 0; k < 4; k++){
        int next_i = i + dx[k],next_j = j + dy[k];
        if(ok(next_i,next_j)){
            if(moun[next_i][next_j] < moun[i][j] && dp(next_i,next_j)+1 > ans[i][j]) ans[i][j] = dp(next_i,next_j)+1;
        }
    }
    return ans[i][j];
}

int main()
{
    freopen("input.txt","r",stdin);

    int maxans = 0;
    scanf("%d %d",&r,&c);
    for(int i = 0; i < r; i++)
        for(int j= 0; j < c; j++) scanf("%d",&moun[i][j]);

    for(int i = 0; i < r; i++)
        for(int j= 0; j < c; j++)
                dp(i,j);

    for(int i = 0; i < r; i++)
        for(int j= 0; j < c; j++)
            if( maxans < ans[i][j] ) maxans = ans[i][j];

    printf("%d\n",maxans+1);


    return 0;
}
