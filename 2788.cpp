#include <cstdio>

int main()
{
    //freopen("input.txt","r",stdin);
    int m,n,ans;
    int start,_end;
    while(1){
        scanf("%d %d",&m,&n);
        if(m == 0 && n == 0) break;
        start = 2 * m, _end = 2*m + 1;
        ans = 1;
        while(_end <= n){
            ans = (ans+1)*2 - 1;
            start = 2*start;
            _end = 2*_end + 1;
        }
        if(n > _end) ans = ans + (_end - start) + 1;
        else if(n >= start) ans = ans + (n - start) + 1;
        printf("%d\n",ans);
    }
    return 0;
}
