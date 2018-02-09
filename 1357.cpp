#include<cstdio>
#include<algorithm>
#include<stdlib.h>

#define INFCOST 1000000005

using namespace std;
int L[3],C[3],station[10005]; // station[i]表示第i个车站到第0个车站距离
int cost_to_des[10005] = {0}; // cost_to_des[i]表示第i个车站到des车站最小花费
int n,start,des;

int compute_cost(int start_station){
    if(start_station == des) return 0;
    if(cost_to_des[start_station] != 0)  return cost_to_des[start_station];

    int cost[3] = {0}; //有三种票故三种方案，cost[i]表示第一张票是第i种票时的总花费
    for(int i = 0; i < 3; i++){
        if(station[start_station]  < station[start_station + 1]-L[i]) cost[i] = INFCOST;// 连最近的车站都到不了，花费为无穷
        else{
            int next_station = start_station; //next_station是第一张票尽可能远的目的地
            while(station[start_station] >= station[next_station + 1] - L[i]){
                next_station++;
                if(next_station == des) break;
            }
            cost[i] = C[i] + compute_cost(next_station); //总费用=第一张票的费用+接下来的费用
        }
    }
    cost_to_des[start_station] = min(cost[0],min(cost[1],cost[2])); //取三种方案的最小值并写入数组
    return cost_to_des[start_station];
}


int main()
{
    //freopen("input.txt","r",stdin);

    scanf("%d %d %d %d %d %d",&L[0],&L[1],&L[2],&C[0],&C[1],&C[2]);
    scanf("%d",&n);
    scanf("%d %d",&start,&des);
    if(start > des){ // 题目没说start一定小于des
        int tmp = start;
        start = des;
        des = tmp;
    }
    start--;  //题目从1开始的，故减一
    des--;
    station[0] = 0; // 第0个站到第0个站距离为0
    for(int i = 1; i < n; i++) scanf("%d",&station[i]);
    printf("%d\n",compute_cost(start));
    return 0;
}
