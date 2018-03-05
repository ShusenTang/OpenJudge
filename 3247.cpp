#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector < int > ans;

int first_n_digit_num(int n){
    int ans = 1;
    while(--n) ans *= 10;
    return ans;
}


bool isprime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    //freopen("input.txt","r",stdin);

    int n,realnum;
    char l[10],mid,r[10],num[20];
    scanf("%d",&n);
    if(n == 1) {
        printf("4\n2 3 5 7\n");
        return 0;
    }

    //printf("%d\n",first_n_digit_num(n/2));
    for(int i = first_n_digit_num(n/2); i < first_n_digit_num(1 + n/2); i++){
        sprintf(l,"%d",i);
        strcpy(r,l);
        reverse(r,r+n/2);

        if(n%2 == 1){
            strcpy(num,l);
            int tmp;
            for(int i = 0; i < 10; i++){
                tmp = n/2;
                num[tmp++] = i + '0';
                for(int j = 0; j < n/2; j++) num[tmp++] = r[j];
                num[tmp] = '\0';
                sscanf(num,"%d",&realnum);
                if(isprime( realnum )) ans.push_back(realnum); //printf("%d\n",realnum);
                //printf("%s\n",num);
            }
        }
        else{
            strcpy(num,l);
            int tmp = n/2;
            for(int j = 0; j < n/2; j++) num[tmp++] = r[j];
            num[tmp] = '\0';
            sscanf(num,"%d",&realnum);
            if(isprime( realnum )) ans.push_back(realnum); //printf("%d\n",realnum);
                //printf("%s\n",num)
        }
        //printf("%s-%s\n",l,r);
    }

    printf("%d\n",ans.size());
    for(int i = 0; i < ans.size(); i++){
        printf("%d",ans[i]);
        if(i == ans.size()-1) printf("\n");
        else printf(" ");
    }
    return 0;
}
