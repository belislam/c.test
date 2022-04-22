#include <stdio.h>
# define N 10
struct student
{
	int ID;
	char name[20];
	int score;
};
void output(struct student s[]);
void sort(struct student s[]);
int main()
{
	struct student s[N] = { {1001,"zhangsan",79},{1002,"zhanglin",89} ,{1003,"zhangzhi",36} ,{1004,"lisi",58},
							{1005,"sunzhi",98},{1006,"sunyu",68} ,{1007,"sunyun",39} ,{1008,"lishi",78},
							{1009,"sunzhe",99} ,{1010,"liheng",70} };
	printf("---the original data-------\n");
	output(s);
	sort(s);
	printf("---the data of after sort-------\n");
	output(s);
}
void output(struct student s[])
{
	for (int i = 0;i < N;i++)
	{
		printf("%5d  %-8s%5d\n",s[i].ID, s[i].name, s[i].score);
	}
}
void sort(struct student s[])
{
	struct student temp;
	for (int i = 0;i < N - 1;i++)
	{
		for (int j = 0;j < N - 1 - i;j++)
		{
			if (s[j].score < s[j + 1].score)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}