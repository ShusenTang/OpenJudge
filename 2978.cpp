#include<cstdio>
#include<algorithm>

#define MAX 20005
#define INFTIME 100000000
#define LEFT 0
#define RIGHT 1
using namespace std;

int n,maxh;

struct platform{
    int h,x1,x2;
}p[1005];
int mytime[1005][2];  //mytime[21][0]、mytime[21][1]分别代表从第21块板子最左侧和最右侧开始的最小时间
void initialtime(){
    for(int i = 0; i < n+2; i++){
        mytime[i][LEFT] = mytime[i][RIGHT] = 0;
    }
}

bool cmp(platform a, platform b){
    return a.h > b.h;
}

int mintime(int pos,int i){
    if(i == n+1) return 0;

    int leftmintime,rightmintime;
    if(mytime[i][LEFT] == 0){
        int left_platform = i+1;
        while(1){
            if(p[left_platform].x1 <= p[i].x1 && p[left_platform].x2 >= p[i].x1) break;
            left_platform++;
        }
        if( (p[i].h - p[left_platform].h) > maxh) mytime[i][LEFT] = INFTIME;
        else mytime[i][LEFT] = p[i].h - p[left_platform].h + mintime(p[i].x1,left_platform);
    }
    leftmintime = pos - p[i].x1 + mytime[i][LEFT];

    if(mytime[i][RIGHT] == 0){
        int right_platform = i+1;
        while(1){
            if(p[right_platform].x1 <= p[i].x2 && p[right_platform].x2 >= p[i].x2) break;
            right_platform++;
        }
        if( (p[i].h - p[right_platform].h) > maxh) mytime[i][RIGHT] = INFTIME;
        else mytime[i][RIGHT] = p[i].h - p[right_platform].h + mintime(p[i].x2,right_platform);
    }
    rightmintime = p[i].x2 - pos + mytime[i][RIGHT];

    if(leftmintime > rightmintime) return rightmintime;
    else return leftmintime;

}

int main(){
    //freopen("input.txt","r",stdin);
    int t,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&n,&x,&y,&maxh);
        p[0].h = y;
        p[0].x1 = p[0].x2 = x;
        for(int i = 1; i <= n; i++)
            scanf("%d %d %d",&p[i].x1,&p[i].x2,&p[i].h);
        p[n+1].h = 0;
        p[n+1].x1 = (-1)*MAX;
        p[n+1].x2 = MAX;

        sort(p,p+n+2,cmp);
        initialtime();
        printf("%d\n",mintime(x,0));
    }
    return 0;
}
