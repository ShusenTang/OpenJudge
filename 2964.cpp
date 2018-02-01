#include<cstdio>
#include<math.h>

using namespace std;

int one_mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char week[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

bool is366(int year){
    if(year%100 == 0 && year%400 != 0) return false;
    if(year%4 == 0) return true;
    return false;
}

int one_year_days(int year){
    if(is366(year)) return 366;
    else return 365;
}

void cpt_mon_day(int days,int year,int &mon, int &day){
    if(is366(year)) one_mon[1] += 1;

    int i,sum = 0;
    for(i = 0; i < 12; i++){
       if(sum+one_mon[i] >= days) break;
       sum += one_mon[i];
    }
    mon = i + 1;
    day = days - sum;

    if(is366(year)) one_mon[1] -= 1;
}



int main(){
    freopen("input.txt","r",stdin);

    int days;
    while(1){
        scanf("%d",&days);
        if(days == -1) break;
        days += 1;

        int i,sum,mon,day;
        sum = 0;
        for(i = 2000;i < 10000; i++){
            if(sum+one_year_days(i) >= days) break;
            sum += one_year_days(i);
        }
        printf("%d-",i);
        cpt_mon_day(days-sum,i,mon,day);
        printf("%02d-%02d ",mon,day);
        printf("%s\n",week[(days-1)%7]);
    }


    return 0;
}
