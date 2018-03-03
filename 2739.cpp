#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2200
using namespace std;

char a[MAXN],b[MAXN],pow_a_x[MAXN];
void init_process(){ //a,b翻转并补0
    int len1 = strlen(a);
    int len2 = strlen(b);
    reverse(a,a+len1);
    reverse(b,b+len2);
    for(int i = len1; i < MAXN-1; i++) a[i] = '0';
    for(int i = len2; i < MAXN-1; i++) b[i] = '0';
    a[MAXN-1] = '\0';
    b[MAXN-1] = '\0';
}

int tmp[MAXN];
void mul_a(){
    fill(tmp,tmp+MAXN,0);
    for(int i = 0; pow_a_x[i] != '\0'; i++)
    for(int j = 0; a[j] != '\0'; j++){
        if(i+j >= MAXN) break;
        tmp[i+j] += (pow_a_x[i]-'0') * (a[j] - '0');
    }


    int mul,cin = 0;
    for(int i = 0; pow_a_x[i] != '\0'; i++){
        mul = cin + tmp[i];
        pow_a_x[i] = mul % 10 + '0';
        cin = mul / 10;
    }

}

bool cmp(){ //b < a^x 时返回true
   for(int i = MAXN-2; i >= 0; i--){
        if(b[i] == pow_a_x[i]) continue;
        else if(b[i] < pow_a_x[i]) return true;
        else return false;
   }
   return false;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%s",a);
    scanf("%s",b);
    init_process();
    strcpy(pow_a_x,a);

    int x = 0;
    while(1){
        if(cmp()) break;
        else{
            x++;
            mul_a();
        }
    }
    printf("%d",x);
    return 0;
}

