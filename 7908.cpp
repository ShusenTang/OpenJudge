//7908:奖学金，2017研究生复试第一题

#include <stdio.h>
#include <stdlib.h> 
#include<algorithm> 
using namespace std; 

#define MAXNUM 25

struct Student{
	int ID,s1,s2,s3,sum;
	
	//结构体内部操作符重载，效率比外部高不少
	bool operator < (const Student a)const{  //注意两个const 
		if(a.sum!=sum) return sum > a.sum;
		else if(a.s1!=s1) return s1 > a.s1;
		else return a.ID > ID;
	}
	
	
}stu[MAXNUM];

//bool operator < (Student a,Student b)
//{
//	if(a.sum!=b.sum) return b.sum<a.sum;
//	else if(a.s1!=b.s1) return b.s1<a.s1;
//	else return a.ID < b.ID;	
//}

//bool mycmp(const Student &a,const Student &b)  //for sort 
//{
//	if(a.sum!=b.sum) return b.sum<a.sum;
//	else if(a.s1!=b.s1) return b.s1<a.s1;
//	else return a.ID < b.ID;
//}

//int mycmp(const void *c,const void *d) //for qsort
//{
//	struct Student *a = (Student *)c;
//	struct Student *b = (Student *)d;
//	
//	if(a->sum!=b->sum) return b->sum-a->sum;
//	else if(a->s1!=b->s1) return b->s1-a->s1;
//	else return a->ID - b->ID;
//}

int main()
{
	freopen("input.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d %d",&stu[i].s1,&stu[i].s2,&stu[i].s3);
		stu[i].sum = stu[i].s1 + stu[i].s2 + stu[i].s3;
		stu[i].ID = i+1;
		
	}
	sort(stu,stu + n)	;
	for (int i = 0;i<5;i++)
		printf("%d %d\n",stu[i].ID,stu[i].sum);	
	fclose(stdin);
	return 0;	
} 
