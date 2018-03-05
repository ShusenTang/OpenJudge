#include<stdio.h>
#include<string.h>

// a1x13+ a2x23= - ( a3x33+ a4x43+ a5x53  )
// 左边的范围肯定比右边的范围小，而二者又要相等，所以以左边的范围来确立hash数组的大小

const int maxn=25000000;//左边绝对值最大0^4*2，有正有负，故50^4*2*2
short hash[maxn];//注意定义为short类型，否则会超内存
int main()
{
    int a1,a2,a3,a4,a5;
    int i,j,k;
    int sum,temp;
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)!=EOF)
    {
        sum=0;
        //fill(hash,hash+maxn,0);
        memset(hash,0,sizeof(hash));//开始全部初始化为0
        for(i=-50;i<=50;i++)
            for(j=-50;j<=50;j++)
                if(i!=0 && j!=0){
                    temp=a1*i*i*i+a2*j*j*j;//从头开始枚举，把每一个结果都存入下标中，注意可能会有很多种情况temp一样，所以是hash[]++
                    hash[temp+maxn/2]++;   //加上maxn/2保证数组下标为正数，
                }

        for(i=-50;i<=50;i++)
            for(j=-50;j<=50;j++)
                for(k=-50;k<=50;k++)
                    if(i!=0 && j!=0 && k!=0){
                        temp=a3*i*i*i+a4*j*j*j+a5*k*k*k;
                        if(temp>=-maxn/2 && temp<=maxn/2)//注意判断范围，第二个范围较大，如果不判断，会溢出
                           sum+=hash[-temp+maxn/2];//因为前面已经枚举了所有的情况，所以后面加上没一个hash的下标所对应的值就行了，反正如果没有这种情况，下标对应的值也是0对结果没有影响。。。
                    }
        printf("%d\n",sum);
    }
    return 0;
}
