#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int integer;//����
float decimals;//С��
int num1, num2, min, max, flag1, flag2, isFile;
char oper[5], op;
int x = time(0);
int ran()
{
	x++;
	return x;
}
char opera(int num2, char oper[])//������������
{

	int A;
	srand(ran());
	A = rand() % num2 + 1;
	return oper[A];
}
void menu(int &num1, int &num2, int &min, int &max, char oper[], int &flag1, int &flag2)
{
	printf("���������ɵ���Ŀ������");
	scanf_s("%d", &num1);
	printf("�������������������Ŀ: ");
	scanf_s("%d", &num2);
	printf("���������������Ӧ���ࣺ");
	for (int i = 0; i <= num2; i++)
	{
		scanf_s("%c", &oper[i]);
	}
	printf("�������������ķ�Χ��");
	scanf_s("%d %d", &min, &max);
	printf("��ѡ���Ƿ�������[1/0]");
	scanf_s("%d", &flag1);
	printf("��ѡ���Ƿ���С��[1/0]");
	scanf_s("%d", &flag2);
	printf("��ѡ���Ƿ��ӡ���ļ�[1/0]");
	scanf_s("%d", &isFile);

}
void divide()
{
	if (op == '/')
	{
		if (flag2)
		{
			decimals += 1;
		}
		else
		{
			integer += 1;
		}
	}
	return;
}

void randData(int isDecimals, int min, int max, FILE *file)//isDecimals�Ƿ�����С����min�������Сֵ��max��������ֵ
{
	if (isDecimals == 0)
	{
		srand(ran());
		integer = rand() % (max - min + 1) + min;
		if (integer < 0)
		{
			if (isFile)
			{
				fprintf(file, "(%d)", integer);
			}
			printf("(%d)", integer);
		}
		else
		{
			divide();
			if (isFile)
			{
				fprintf(file, "%d", integer);
			}
			printf("%d", integer);
		}
		//Sleep(1000);
	}
	else
	{
		int r = rand() % 3 + 1;
		int i = 1;
		float j = 1;
		while (r != 0)
		{
			i = i * 10;
			j = j / 10;
			r--;
		}
		srand(ran());
		decimals = rand() % (max - min + 1) + min;
		decimals = decimals + rand() % i*j;
		if (decimals < 0)
		{
			if (isFile)
			{
				fprintf(file, "(%.3f)", decimals);
			}
			printf("(%.3f)", decimals);
		}
		else
		{
			divide();
			if (isFile)
			{
				fprintf(file, "%.3f", decimals);
			}
			printf("%.3f", decimals);
		}
		//Sleep(1000);
	}
}


int equation()//��������������ʽ
{
	int cs = 0;//���ڵ�Ԫ���ԣ�
	FILE *file;
	fopen_s( &file,"file.txt", "w");
	if (file == NULL)
	{
		printf("cannot open file");
		exit(0);
	}
	int lbracket = 0, rbracket = 0, data;
	int num = num1;
	while (num)
	{
		int i;
		int j = 0;
		i = rand() % 4 + 2;//2~5�����ݣ�
		if (flag1 == 1)
		{
			data = 2 * i;
			lbracket = rand() % ((data - 3) - 1 + 1) + 1;
			if (lbracket % 2 == 0)
			{
				lbracket++;
			}
			rbracket = rand() % (data - (lbracket + 3) + 1) + (lbracket + 3);
			if (rbracket % 2 != 0)
			{
				rbracket++;
			}
		}
		j++;
		if (j == lbracket)
		{
			if (isFile)
			{
				fprintf(file, "(");
			}
			printf("(");
		}
		randData(flag2, min, max, file);
		j++;
		i--;
		while (i)
		{
			op = opera(num2, oper);
			if (isFile)
			{
				fprintf(file, "%c", op);
			}
			printf("%c", op);
			j++;
			if (j == lbracket)
			{
				if (isFile)
				{
					fprintf(file, "(");
				}
				printf("(");
			}
			randData(flag2, min, max, file);
			if (flag2==1&&num == 1 && i == 1)
			{
				cs += 1;
			}
			j++;
			if (j == rbracket)
			{
				if (isFile)
				{
					fprintf(file, ")");
				}
				printf(")");
				if (num == 1)
				{
					cs += 3;
				}
			}
			i--;
		}
		if (isFile)
		{
			fprintf(file, "=\n");
			if (num == 1)
			{
				cs += 5;
			}
		}
		printf("=\n");
		num--;
	}
	printf("���ԣ�%d", cs);
	return cs;
}
int main()
{
	int cs;
	menu(num1, num2, min, max, oper, flag1, flag2);
	cs = equation();
	system("pause");
	return 0;
}