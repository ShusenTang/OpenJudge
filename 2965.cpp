#include<cstdio>
#include<cstring>

//using namespace std;

char Haab_mon[19][10] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char Tzo_mon[20][10] ={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int find_haab_mon(char mon[]){
    for(int i = 0; i < 19; i++){
        if(strcmp(mon,Haab_mon[i]) == 0) return i;
    }
}

int main(){
    //freopen("input.txt","r",stdin);

    int n,date,year,days,mon_index;
    char mon[10];
    scanf("%d",&n);
    printf("%d\n",n);
    while(n--){
        scanf("%d. %s %d",&date,mon,&year);
        days = 0;
        days += 365*year;
        mon_index = find_haab_mon(mon);
        days += 20*mon_index;
        days += date;

        int T_date,T_year;
        T_year = days / 260;
        T_date = (days%260)%13 + 1;

        int tmp = (days%260)%20;
        printf("%d %s %d\n",T_date,Tzo_mon[tmp],T_year);

    }
    return 0;
}
