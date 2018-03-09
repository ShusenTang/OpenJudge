#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

map < int , int > mp;
map < int , int > ::iterator it;
map < int , int > ::iterator pre_it;



int main()
{
    //freopen("input.txt","r",stdin);

    int n,id,power;
    mp[1000000000] = 1;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&id,&power);
        printf("%d ",id);

        it = mp.lower_bound(power);

        if(it != mp.begin()){
            pre_it = it;
            pre_it--;
            if(power - pre_it->first <= it->first - power) printf("%d\n",pre_it->second);
            else printf("%d\n",it->second);
        }
        else printf("%d\n",it->second);


        mp[power] = id;
    }

    return 0;
}
