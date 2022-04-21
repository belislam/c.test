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
/*����N��ѧ�������ݣ�ʵ��ѧ���������ֵ���������*/
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
	for (int i = 0;i <N ;i++)//�����Ա�ı�ź�����
	{
		printf("%5d    %-10s",s[i].sno,s[i].sname);
		for (int j = 0;j < 3;j++)//���ѧ���ĳɼ�
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
			if (strcmp(p[j].sname,p[j + 1].sname)>0)//�Ƚ��ַ�����С�ĺ���  strcmp
//�ú����ıȽϹ��̣�����Ƚ��������ж�Ӧ���ַ����ַ���С����ASCII��ֵȷ�����������ұȽϣ�
//���������ͬ�ַ���������һ�Բ�ͬ�ַ��Ĵ�С��ϵ��ȷ���������ַ����Ĵ�С��ϵ��
//���δ������ͬ�ַ���ĳ���ַ������Ƚ�������ô����ַ����ǽ�С�ģ����������ַ�����ȡ�
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

