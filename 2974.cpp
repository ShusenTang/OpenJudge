//2974:487-3279

#include <stdio.h>
#include<algorithm>
using namespace std; 

int char_to_int(char c[])
{
	int ans = 0;
	int i = 0;
	while(1){
		if(c[i]=='\0') break;
		if(c[i]>='0' && c[i]<='9')
		       ans = ans*10 + c[i]-'0';
		i++;
	}
	return ans;
}

void ABC_to_123(char c[])
{
	int j = -1;
	for(int i=0;i<100;i++){
		if(c[i]!='-'){
			if((j++)==7) break;
			if(c[i]>='A' && c[i]<='C') c[j] = '2';
			else  if(c[i]>='D' && c[i]<='F') c[j] = '3';
			else  if(c[i]>='G' && c[i]<='I') c[j] = '4';
			else  if(c[i]>='J' && c[i]<='L') c[j] = '5';
			else  if(c[i]>='M' && c[i]<='O') c[j] = '6';
			else  if(c[i]>='P' && c[i]<='S') c[j] = '7';
			else  if(c[i]>='T' && c[i]<='V') c[j] = '8';
			else  if(c[i]>='W' && c[i]<='Y') c[j] = '9';
		}	
	}
}

char ph_num[100];
int record[100000] = {0};

int main()
{
	int num,i,tmp;
	int j = 0;
	char c[2];
	freopen("input.txt","r",stdin);
	scanf("%d",&num);
	tmp = num;
	while(tmp){
        scanf("%s",ph_num);
        ABC_to_123(ph_num);
        record[j++] = char_to_int(ph_num);
        tmp--;

	}
	sort(record,record+num);
	int pre,count,tag;
	pre = record[0];
	count=1;
	tag = 0;
	for(i = 1;i<num;i++){
		if(record[i]==pre) count++;
		else if(count>1) {
			printf("%03d-%04d %d\n",record[i-1]/10000,record[i-1]%10000,count);
			pre = record[i];
			count = 1;
			tag = 1;			
		}
		else pre = record[i];
	}
	if(tag == 0) printf("No duplicates.\n");
	return 0;
} 

//int main()
//{
//	char c[8] = "ABCDEFG";
//	int n;
//	//for(int i=0;i<10;i++) printf("%d ",c[i]);
//	ABC_to_123(c);
//	printf("--%s--",c);
//	n = char_to_int(c);
//	printf("%d ",n);
//	return 0;
//}
