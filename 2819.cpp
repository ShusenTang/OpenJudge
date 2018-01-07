#include <stdio.h>
#include <string.h>

char str[105];
int posi[3][105];
int i[3],k[3];

void mysort(){
	i[0] = i[1] = i[2] = 0;
	for(int j=0; j<100; j++){
		if(str[j]=='\0') break;
		if(str[j]>='a' && str[j]<='i') posi[0][i[0]++] = j;
		else if(str[j]>='j' && str[j]<='r') posi[1][i[1]++] = j;
		else if( (str[j]=='_') || (str[j]>='s' && str[j]<='z'))posi[2][i[2]++] = j;	
	}
}

void reverse_all(int tag){
	if(i[tag]==0) return;
	int low = 0;
	int high = i[tag]-1;
	char tmp;
	while(low<high){    //·­×ªstr 
		tmp = str[posi[tag][low]];
		str[posi[tag][low]] = str[posi[tag][high]];
		str[posi[tag][high]] = tmp;
		low++;
		high--;
	}
}

void reverse(int tag){
	if(i[tag]==0) return;
	int low1,high1,low2,high2,t;
	low1 = 0;	
	t = k[tag]%i[tag];	
	high1 = t-1;
	low2 = t;
	char tmp;
	
	high2 = i[tag]-1;
	while(low1<high1){
		tmp = str[posi[tag][low1]];
		str[posi[tag][low1]] = str[posi[tag][high1]];
		str[posi[tag][high1]] = tmp;
		low1++;
		high1--;
	}
	while(low2<high2){
		tmp = str[posi[tag][low2]];
		str[posi[tag][low2]] = str[posi[tag][high2]];
		str[posi[tag][high2]] = tmp;
		low2++;
		high2--;
	}	
}

int main()
{
	int low,high;
	char tmp;
	freopen("input.txt","r",stdin);
	while(1){
		scanf("%d%d%d",&k[0],&k[1],&k[2]);
		if( ! (k[0]||k[1]||k[2]) ) break;
		getchar();
		scanf("%s",str);
		
	    mysort();	
	    reverse_all(0);
	    reverse_all(1);	    
	    reverse_all(2);
	    
	    mysort();	    
	    reverse(0);
	    reverse(1);	    
	    reverse(2);
	
		printf("%s\n",str);
	}
	return 0;	
}
