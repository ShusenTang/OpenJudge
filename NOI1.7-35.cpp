#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string str;
int p1,p2,p3;

int main()
{
    //freopen("input.txt","r",stdin);
    char in[200];

    cin >> p1 >> p2 >> p3;
    cin >> str;
    for(int i = 1; i < str.size()-1; i++){
        if(str[i] != '-' || str[i-1] >= str[i+1] || str[i-1] == '-' || str[i+1] == '-') continue;
        if( (str[i+1] - str[i-1]) > 30) continue;

        str.erase(str.begin()+i);
        if(str[i] == 1+str[i-1]) continue;


        int num = str[i] - str[i-1] - 1;
        if(p1 == 2 && str[i-1] >= 'a'){
            for(int k = 0; k < num; k++)
                for(int j = 0; j < p2; j++) in[p2*k + j] = str[i-1]+k+1-'a'+'A';
        }
        else if(p1 == 1 || (p1 == 2 && str[i-1] < 'a') ){
            for(int k = 0; k < num; k++)
                for(int j = 0; j < p2; j++)  in[p2*k + j] = str[i-1]+k+1;
        }
        else{
            for(int k = 0; k < num; k++)
                for(int j = 0; j < p2; j++)  in[p2*k + j] = '*';
        }

        in[p2*num] = '\0';
        if(p3 == 2) reverse(in,in+p2*num);
        //printf("%s\n",in);
        str.insert(i,in);
    }
    cout << str << endl;

    //cout << (int)'z' <<endl;
    return 0;
}
