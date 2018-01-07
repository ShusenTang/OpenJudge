#include <stdio.h>
#include <string.h>

int n;
char str[105][105];

void myrev(char *c){    //·­×ª×Ö·û´® 
	int high = strlen(c)-1;
	int low = 0;
	char tmp;
	while(low<high){
		tmp = c[low];
		c[low] = c[high];
		c[high] = tmp;
		low++;
		high--;
	}	
}



int maxstrlen(char *min_str)
{
	int substrlen = strlen(min_str);
	int min_str_len = strlen(min_str);
	char substr[105],resubstr[105];
	bool find;
	
	while(substrlen>0){
		for (int i = 0; i<= min_str_len-substrlen; i++){
			strncpy(substr,min_str+i,substrlen);
			strncpy(resubstr,min_str+i,substrlen);
			substr[substrlen] = resubstr[substrlen] = '\0';
			myrev(resubstr);
			find = true;
			for(int j = 0;j<n;j++)
				if(strstr(str[j],substr)==NULL && strstr(str[j],resubstr)==NULL){
					find = false;
					break;								
			}
			if(find) return substrlen;		  		
	    }
	    substrlen--;	
    }
	return 0;		
}


int main()
{
	int t,minstrlen;
	char minstr[105];
	
	//freopen("input.txt","r",stdin);
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		minstrlen = 100;
		for(int k = 0;k<n;k++){
			scanf("%s",str[k]);
			if(strlen(str[k]) <= minstrlen){
				strcpy(minstr,str[k]);
				minstrlen = strlen(minstr);
			}		
		}
		printf("%d\n",maxstrlen(minstr));		
	}	
	return 0;
} 
