#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

char space[7] = "|     ";

string str;
int cnt = 1;

bool print(int level,int isroot){
    vector < string > file;
    //if(isroot) cout << "ROOT" << endl;
    //vector < string > dir;
    while(1){
        //scanf("%s",str);
        cin >> str;
        if(str[0] == '#') return false;
        //if(level == 0 && isroot) cout << "ROOT" << endl;
        else if(str[0] == '*' || str[0] == ']') break;
        if(level == 0 && isroot){
            if(cnt > 1) cout << endl;
            cout << "DATA SET " << cnt++ << ":" << endl;
            cout << "ROOT" << endl;
        }
        isroot  = 0;

        if(str[0] == 'f') file.push_back(str);
        else if(str[0] == 'd'){
            for(int i = 0; i <= level; i++) cout << space;
            cout << str << endl;
            print(level+1,0);
        }
    }

    sort(file.begin(),file.end());

    for(int i = 0; i < file.size(); i++){
        for(int i = 0; i < level; i++) cout << space;
        cout << file[i] << endl;
    }
    return true;
}

int main(){
    while(1){
        if( ! print(0,1)) break;
    }
    return 0;
}
