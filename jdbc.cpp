#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int integer;//整数
float decimals;//小数
int num1, num2, min, max, flag1, flag2, isFile;
char oper[5], op;
int x = time(0);
int ran()
{
	x++;
	return x;
}
char opera(int num2, char oper[])//随机产生运算符
{

	int A;
	srand(ran());
	A = rand() % num2 + 1;
	return oper[A];
}
void menu(int &num1, int &num2, int &min, int &max, char oper[], int &flag1, int &flag2)
{
	printf("请输入生成的题目数量：");
	scanf_s("%d", &num1);
	printf("请输入运算符的种类数目: ");
	scanf_s("%d", &num2);
	printf("请输入运算符的相应种类：");
	for (int i = 0; i <= num2; i++)
	{
		scanf_s("%c", &oper[i]);
	}
	printf("请输入运算数的范围：");
	scanf_s("%d %d", &min, &max);
	printf("请选择是否有括号[1/0]");
	scanf_s("%d", &flag1);
	printf("请选择是否有小数[1/0]");
	scanf_s("%d", &flag2);
	printf("请选择是否打印到文件[1/0]");
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

void randData(int isDecimals, int min, int max, FILE *file)//isDecimals是否生成小数，min随机数最小值，max随机数最大值
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


int equation()//生成四则运算表达式
{
	int cs = 0;//用于单元测试；
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
		i = rand() % 4 + 2;//2~5个数据；
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
	printf("测试：%d", cs);
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