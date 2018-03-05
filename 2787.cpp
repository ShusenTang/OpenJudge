#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#define MIL 1e-6
using namespace std;
char op[4]={'+','-','*','/'}; 
int numback[4];
double cas(double a,int opnum,double b){
	switch(op[opnum]){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}

bool calculator(double a,double b,double c,double d,int opnum1,int opnum2,int opnum3){
	if(fabs(cas(cas(a,opnum1,b),opnum2,cas(c,opnum3,d))-24.0)<MIL){

		//cout<<"("<<a<<op[opnum1]<<b<<")"<<op[opnum2]<<"("<<c<<op[opnum3]<<d<<")"<<endl;
		return 1;
			}
	else if(fabs(cas(cas(cas(a,opnum1,b),opnum2,c),opnum3,d)-24.0)<MIL){
		//cout<<"(("<<a<<op[opnum1]<<b<<")"<<op[opnum2]<<c<<")"<<op[opnum3]<<d<<endl;	
		return 1;
			}
	else if(fabs(cas(cas(a,opnum1,cas(b,opnum2,c)),opnum3,d)-24.0)<MIL){
		//cout<<"("<<a<<op[opnum1]<<"("<<b<<op[opnum2]<<c<<"))"<<op[opnum3]<<d<<endl;	
		return 1;
			}
	else if(fabs(cas(a,opnum1,cas(cas(b,opnum2,c),opnum3,d))-24.0)<MIL){
		//cout<<a<<op[opnum1]<<"(("<<b<<op[opnum2]<<c<<")"<<op[opnum3]<<d<<")"<<endl;	
		return 1;
			}
	else if(fabs(cas(a,opnum1,cas(b,opnum2,cas(c,opnum3,d)))-24.0)<MIL){
		//cout<<a<<op[opnum1]<<"("<<b<<op[opnum2]<<"("<<c<<op[opnum3]<<d<<"))"<<endl;	
		return 1;
			}
	else 
	return 0;
}

int main(){
	int flag,tmp[4];
	//freopen("devinput.txt","r",stdin);
//		freopen("out24.txt","wb",stdout);
	while(1){
        scanf("%d %d %d %d",&numback[0],&numback[1],&numback[2],&numback[3]);
        if(numback[0] == 0 && numback[1] == 0 && numback[2] == 0 && numback[3] == 0) break;
        
        for(int i = 0; i < 4; i++) tmp[i] = i;

        flag = 1;
        
        while(1){
        	for(int i=0;i<4 && flag;i++)
			for(int j=0;j<4 && flag;j++)
			for(int k=0;k<4 && flag;k++)
				if( calculator(numback[tmp[0]],numback[tmp[1]],numback[tmp[2]],numback[tmp[3]],i,j,k) ) {
					flag = 0;
					printf("YES\n");
					break;	
				}
        	
        	if(next_permutation(tmp,tmp+4) == false) break;
        } 
		if(flag) printf("NO\n");  

	}
}
