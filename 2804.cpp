# include <stdio.h>
# include <string.h>
# include <algorithm>
using namespace std;

struct Dic{
	char str1[30];  // Ӣ�� 
	char str2[30];  //���� 
	
}dic[101000];

int dic_num;  //�ֵ��е������� 

bool mycmp(const Dic &a, const Dic &b){   // �ṹ�尴��str2�Ƚϴ�С 
	if(strcmp(b.str2,a.str2)>0) return true;
	else return false;
	//else return strcmp(b.str2,a.str2);
}

void myfind(char str[],int low,int high){    //���ֲ��� 
	if(low > high) {
		printf("eh\n");
		return;
	}
	int mid = (low+high)/2;
	int tmp = strcmp(str,dic[mid].str2);
	if(tmp < 0) myfind(str,low,mid-1); //str��С 
	else if(tmp > 0) myfind(str,mid+1,high);
	else printf("%s\n",dic[mid].str1);
}
 

int main(){
	freopen("input.txt","r",stdin);
	int i = 0;
	while(1){
		gets(dic[i].str1);
		if(dic[i].str1[0]=='\0') break;
		
		int j=0;
		while(1){
		   if(dic[i].str1[j]==' ') break;
		   j++;
		}
		dic[i].str1[j++]='\0';
		int k=0;
		while(1){
			dic[i].str2[k] = dic[i].str1[j];
			if(dic[i].str1[j]=='\0')  break;
			j++;
			k++;
		}		
		i++;				
	}
	dic_num = i;
	sort(dic,dic + dic_num,mycmp); //��str2���ӵ�˳������ 
	char doc[15];
	while(scanf("%s",doc)!=EOF){
		myfind(doc,0,dic_num-1);
    }	
	fclose(stdin);
	return 0;
}
