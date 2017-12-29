//2972：确定进制
//注意此题书上要求输入多组数据而网站上只用输入一组数据 
 
#include <stdio.h>

int pow(int num,int e) //计算num^e
{
	int ans=1;
	for(int i=0;i<e;i++) ans = ans*num;
	return ans;
}

void int_to_str(int num,char *str)//整数转字符 
{
	int i,l,tmp;
	i=l=0;
	while(num/10){
		str[i] = num%10 + '0';
		num = num/10;
		i++;
	}
	str[i] = num + '0';
	str[i+1] = '\0'; 
	while(l<i){
		tmp = str[l];
		str[l] = str[i];
		str[i] = tmp;
		i--;
		l++;
	}
}
 

int n_to_10(char num[],int n)//用字符型表示的n进制数转成10进制int 
{
	int len=0;
	for(int i = 0;;i++) {
		if(num[i]=='\0') break;
		len++;
	}
	int ans=0;
	for(int i = 0;i<len;i++) ans = ans + pow(n,len-i-1)*(num[i]-'0');
	return ans;
	
}

int main()
    {
        int num[3];
        char c[3][25];
        int n1,n2,n3;
        
        int count,ans,maxbit;
        //freopen("input.txt", "r", stdin);
        //scanf("%d",&count);
        count = 1;
        while(count){
            ans = maxbit =0;
            scanf("%d %d %d",&num[0],&num[1],&num[2]);
            for(int i = 0;i<3;i++) {
                int_to_str(num[i],c[i]);
                for (int j = 0; j < 25; j++) {
                    if(c[i][j]> maxbit) maxbit = c[i][j]; 
                    if(c[i][j]=='\0') break;
                }
            } 
            
            for(int i = 1 + maxbit - '0';i<17;i++){//n进制数里面出现的数字最大为n-1
                n1 = n_to_10(c[0],i);
                n2 = n_to_10(c[1],i);
                n3 = n_to_10(c[2],i);
                if(n1*n2==n3){
                    ans = i;
                    break;
                }
            }
            printf("%d\n",ans);
            count--;
        }
        
        //printf("%d",pow(2,10)) ;
        //fclose(stdin);
        
        return 0;
    }
