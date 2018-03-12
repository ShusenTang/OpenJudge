#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define MAXN 40
#define INF 99999999

using namespace std;

struct cell{
    int x,y,z;
    cell(int a, int b, int c){
        z = a;
        x = b;
        y = c;
    }
};

char maze[MAXN][MAXN][MAXN]; //z,x,y
int visited[MAXN][MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];

int L,R,C;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

void init(){
    for(int z = 0; z < L; z++)
    for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++){
        visited[z][i][j] = 0;
        dist[z][i][j] = INF;
    }
}

bool isOK(int z, int i, int j){
    if(z >= 0 && z < L && i >= 0 && i < R && j >= 0 && j < C){
        if(maze[z][i][j] != '#') return true;
    }
    return false;
}

int BFS(int z, int i, int j){
    init();
    queue < cell > q;
    int next_z,next_i,next_j;

    visited[z][i][j] = 1;
    dist[z][i][j] = 0;

    cell cur = cell(z,i,j);
    q.push(cur);

    while( !q.empty() ){
        //printf("len = %d\n",q.size());
        cur = q.front();
        q.pop();
        int tmpz = cur.z,tmpx = cur.x,tmpy = cur.y;

        for(int k = 0; k < 6; k++){
            next_z = tmpz + dz[k];
            next_i = tmpx + dx[k];
            next_j = tmpy + dy[k];
            if(isOK(next_z,next_i,next_j) && visited[next_z][next_i][next_j] == 0){
                dist[next_z][next_i][next_j] = dist[tmpz][tmpx][tmpy] + 1;
                //printf("%d\n",dist[next_z][next_i][next_j]);
                if(maze[next_z][next_i][next_j] == 'E') return dist[next_z][next_i][next_j];
                visited[next_z][next_i][next_j] = 1;

                cur.z = next_z, cur.x = next_i, cur.y = next_j;
                q.push(cur);
                //q.push(cell(next_z,next_i,next_j));
            }
        }

    }

    return -1;
}

int main()
{
    //freopen("input.txt","r",stdin);
    while(1){
        scanf("%d %d %d",&L,&R,&C);
        if(L == 0 && R == 0 && C == 0) break;
        for(int z = 0; z < L; z++){
            for(int i = 0; i < R; i++) scanf("%s",maze[z][i]);
        }

        for(int z = 0; z < L; z++)
        for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
        if(maze[z][i][j] == 'S'){
            int ans = BFS(z,i,j);
            if(ans == -1) printf("Trapped!\n");
            else printf("Escaped in %d minute(s).\n",ans);
            break;
        }

    }

    return 0;
}
