#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10005;

string tel[MAXN];
int t,n;

bool isqianzhui(int tel_i, int tel_j){
    int len1 = tel[tel_i].size();
    int len2 = tel[tel_j].size();
    int i = 0, j = 0;
    while(i < len1 && j < len2){
        if(tel[tel_i][i] != tel[tel_j][j]) return false;
        i++;
        j++;
    }
    return true;
}



int main()
{
    //freopen("input.txt","r",stdin);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> tel[i];

        sort(tel,tel+n);

        int flag = 1;
        for(int i = 1; i < n; i++){
            if(isqianzhui(i-1,i)){
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
    }

    return 0;
}
