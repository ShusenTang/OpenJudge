#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAXN 30
#define INF 99999999
using namespace std;

int n,graph[MAXN][MAXN],visited[MAXN],d[MAXN];

void init(){
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        if(i == j) graph[i][j] = 0;
        else graph[i][j] = INF;
    }
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        d[i] = INF;
    }
}

int prim(){
    d[0] = 0; //从0号结点开始
    int ans = 0;
    for(int i = 0; i < n; i++){
        int min_d_i = -1, min_d = INF;
        for(int j = 0; j < n; j++){
            if(visited[j] == 0 && d[j] < min_d){
                min_d_i = j;
                min_d = d[j];
            }
        }
        if(min_d_i == -1) return -1; //不连通
        visited[min_d_i] = 1;
        ans += d[min_d_i];

        for(int v = 0; v < n; v++){
            if(visited[v] == 0 && graph[min_d_i][v] < d[v]) d[v] = graph[min_d_i][v];
        }
    }
    return ans;
}


int main()
{
    //freopen("input.txt","r",stdin);
    int num,dist;
    char c[2];

    while(1){
        scanf("%d",&n);
        if(n == 0) break;
        init();

        for(int i = 0; i < n-1; i++){
            scanf("%s",c);
            scanf("%d",&num);
            while(num--){
                scanf("%s %d",c,&dist);
                graph[i][c[0]-'A'] = graph[c[0]-'A'][i] = dist;
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
