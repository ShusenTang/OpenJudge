#include<cstdio>
#include<algorithm>

using namespace std;

int press[5][6],mybackup[5][6],tmp[6];

int mynot(int a){
    if(a) return 0;
    return 1;
}

void presslight(int i, int j,int button){
    if(button){
        mybackup[i][j] = mynot( mybackup[i][j] );
        if(i > 0) mybackup[i-1][j] = mynot(mybackup[i-1][j]);
        if(j > 0) mybackup[i][j-1] = mynot(mybackup[i][j-1]);
        if(i < 4) mybackup[i+1][j] = mynot(mybackup[i+1][j]);
        if(j < 5) mybackup[i][j+1] = mynot(mybackup[i][j+1]);
    }
}

bool isOK(){
    for(int i = 0; i < 6; i++) presslight(0,i,tmp[i]);

    for(int i = 1; i < 5; i++){
        for(int j = 0; j < 6; j++)
            presslight(i,j,mybackup[i-1][j]);
    }

    for(int j = 0; j < 6; j++)
        if(mybackup[4][j] == 1) return false;

    return true;
}

void backup(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 6; j++)
            mybackup[i][j] = press[i][j];
}

int main(){
    //freopen("input.txt","r",stdin);

    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j < 6; j++){
            scanf("%d",&press[i][j]);
            mybackup[i][j] = press[i][j];
        }
    }
    for(int i1 = 0; i1 < 2; i1++)
        for(int i2 = 0; i2 < 2; i2++)
            for(int i3 = 0; i3 < 2; i3++)
                for(int i4 = 0; i4 < 2; i4++)
                    for(int i5 = 0; i5 < 2; i5++)
                        for(int i6 = 0; i6 < 2; i6++){
                            tmp[0] = i1;
                            tmp[1] = i2;
                            tmp[2] = i3;
                            tmp[3] = i4;
                            tmp[4] = i5;
                            tmp[5] = i6;
                            if(isOK()){
                                backup();
                                for(int k = 0; k < 5; k++) printf("%d ",tmp[k]);
                                printf("%d\n",tmp[5]);

                                for(int k = 0; k < 6; k++) presslight(0,k,tmp[k]);

                                for(int k = 1; k < 5; k++)
                                    for(int t = 0; t < 6; t++){
                                        printf("%d",mybackup[k-1][t]);
                                        if(t == 5) printf("\n");
                                        else printf(" ");
                                        presslight(k,t,mybackup[k-1][t]);
                                    }
                                return 0;
                            }
                            backup();
                        }

    return 0;
}
