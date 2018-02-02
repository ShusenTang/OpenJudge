#include<cstdio>
#include<algorithm>

using namespace std;
#define MAXN 1030

int num[MAXN],n;

void reverse_num(int left, int right){
    int tmp;
    while(left < right){
       tmp = num[left];
       num[left++] = num[right];
       num[right--] = tmp;
    }
}

void swap_i_j(int i, int j){
    int tmp = num[i];
    num[i] = num[j];
    num[j] = tmp;
}

int find_min_max(int a, int i){
    int ans_i,min_max;
    min_max = MAXN;
    for(int j = i; j < n; j++){
       if(num[j] > a && min_max > num[j]){
            ans_i = j;
            min_max = num[j];
       }
    }
    return ans_i;
}

void next(){
    for(int i = n-1; i > 0; i--){
        if( num[i-1] < num[i] ){
            swap_i_j(i-1,find_min_max(num[i-1],i));
            sort(num+i,num+n);
            return;
        }
        if(i == 1) reverse_num(0,n-1);
    }

}

void print_num(){
    for(int i = 0; i < n; i++){
        printf("%d",num[i]);
        if(i == n-1) printf("\n");
        else printf(" ");
    }
}


int main(){
    //freopen("input.txt","r",stdin);
    int m,k;
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&n,&k);
        for(int i = 0; i < n; i++){
            scanf("%d",&num[i]);
        }
        while(k--){
            next();
            if(k == 0) print_num();
        }
    }

    return 0;
}
