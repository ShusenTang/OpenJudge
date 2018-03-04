#include<stdio.h>

int visited[60][60],castle[60][60];
int m,n,num,max_room,room;

void visit(int i, int j){
    if(visited[i][j]) return;
    visited[i][j] = 1;
    room++;

    int tmp = castle[i][j];
    if(tmp % 2 == 0) //无西墙
        visit(i,j-1);

    tmp /= 2;
    if(tmp % 2 == 0) //无北墙
        visit(i-1,j);

    tmp /= 2;
    if(tmp % 2 == 0) //无东墙
        visit(i,j+1);

    tmp /= 2;
    if(tmp % 2 == 0) //无南墙
        visit(i+1,j);
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) scanf("%d",&castle[i][j]);

    num = 0;
    max_room = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++){
        if(visited[i][j] == 0){
            room = 0;
            num++;
            visit(i,j);
            if(room > max_room) max_room = room;
        }
    }
    printf("%d\n%d\n",num,max_room);
    return 0;
}
