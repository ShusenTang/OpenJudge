# include <stdio.h>
# include <string.h>
# include <algorithm>
using std::sort; 

char in[105],out[105];
int count1[100] = {0};
int count2[100] = {0};

int main(){
	int len;
	freopen("input.txt","r",stdin);
	scanf("%s",in);
	scanf("%s",out);
	len = strlen(in);
	for(int i = 0; i<len; i++){
		count1[in[i]-'A']++;
		count2[out[i]-'A']++;
	}
	sort(count1,count1+26);
	sort(count2,count2+26);
//	for(int i = 0;i<26;i++){
//		printf("%d ",count1[i]);
//	}
//	printf("\n");
//	for(int i = 0;i<26;i++){
//		printf("%d ",count2[i]);
//	}
	int i,j;
	i = i = 0;
	while(i<26 && j<26){
		if(count1[i]!=count2[j]){
			printf("NO\n");
			return 0;
		}
		i++;
		j++;
	}
	printf("YES\n");			
	return 0; 
} 
