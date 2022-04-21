#include <stdio.h>
#include <string.h>
#define N  5
struct student
{
	int sno;
	char sname[10];
	int score[3];
};
void output(struct student s[]);
void sort_fun(struct student* p);
/*给定N个学生的数据，实现学生姓名按字典序列排序*/
int main()
{
	struct student s[N] = { {1001,"zhangzhi",{78,56,36}},{1002,"lihua",{75,86,58}},{1003,"xiaoming",{78,45,69}},
							{1004,"sunyu",{98,56,63}}, {1005,"laifu",{87,65,96}} };
	printf("-----the original data -----------------\n");
	output(s);
	sort_fun(s);
	printf("-----Retrieved data -----------------\n");
	output(s, N);
}
void output(struct student s[])
{
	printf(" sno     sname      Chinese    math   English\n");
	for (int i = 0;i <N ;i++)//输出成员的编号和姓名
	{
		printf("%5d    %-10s",s[i].sno,s[i].sname);
		for (int j = 0;j < 3;j++)//输出学生的成绩
		{
			printf("%7d", s[i].score[j]);
		}
		printf("\n");
	}
}
void sort_fun(struct student *p)
{
	struct student temp;
	for (int i = 0;i < N-1;i++)
	{
		for (int j = 0;j < N - 1 - i;j++)
		{
			if (strcmp(p[j].sname,p[j + 1].sname)>0)//比较字符串大小的函数  strcmp
//该函数的比较过程：逐个比较两个串中对应的字符，字符大小按照ASCII码值确定，从左向右比较，
//如果遇到不同字符，所遇第一对不同字符的大小关系就确定了两个字符串的大小关系，
//如果未遇到不同字符而某个字符串首先结束，那么这个字符串是较小的，否则两个字符串相等。
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

