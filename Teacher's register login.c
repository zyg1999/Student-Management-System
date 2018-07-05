#include"student.h"

void register_tea_menu()
{

	system("cls");
	kuang();
	goto_xy(55, 1);
	printf("教   师   注   册");
	goto_xy(55, 4);
	printf("*账户名请使用本人工号*");
	goto_xy(55, 5);
	printf("*密码长度须为6-15之间*");
	goto_xy(57, 6);
	printf("账户名：");
	goto_xy(57, 8);
	printf("密  码：");

	printf("\n\n\n\n\n");

}
//教师注册界面
void Login_tea_menu()
{

	system("cls");
	kuang();
	goto_xy(55, 1);
	printf("教    师   登    录");
	goto_xy(55, 4);
	printf("*账户名请使用本人工号*");
	goto_xy(57, 6);
	printf("账户名：");
	goto_xy(57, 8);
	printf("密  码：");

	printf("\n\n\n\n\n");

}
//教师登录界面
Account * register_tea(Account *pHead)
{

	int flag = 1, flag1 = 1, flag2 = 1;
	char ch;
	int i = 0;
	Account * pNew = (Account*)malloc(sizeof(Account));
	char secondps[20];
	pNew->next = NULL;
	while (flag)
	{
		register_tea_menu();
		goto_xy(65, 6);
		scanf("%s", pNew->name);

		if (judge_no(pNew->name, 8) == 0)//查用户名是否符合规范
		{
			goto_xy(50, 10);
			printf("工号必须为8位数字，请按任意键重输！\n");
			getch();
			continue;
		}

		if (Lookup_tea(pNew->name) == 1)//查重
		{
			goto_xy(50, 11);
			printf("该用户名已注册，请按任意键重新输入！");
			getch();
			continue;
		}
		else
			flag = 0;
	abc:while (flag1)
	{
		i = 0;
		goto_xy(65, 8);
		while ((ch = getch()) != '\r')
		{
			if (ch < 0)//排除上下左右键
			{
				getch();
				continue;
			}
			else if (ch == '\b'&&i>0)
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				i--;
			}
			else if (!isdigit(ch) && !isalpha(ch))
				continue;
			else if (i >= 15)
				continue;
			else
			{
				putchar('*');
				pNew->password[i++] = ch;
			}

		}
		pNew->password[i] = '\0';
		if (strlen(pNew->password) < 6)
		{
			goto_xy(60, 10);
			printf("密码必须大于6位！");
			goto_xy(65, 8);
			printf("                   ");
			goto_xy(65, 8);
			goto abc;
		}


			i = 0;
			goto_xy(55, 12);
			printf("请再次输入密码:");

			while ((ch = getch()) != '\r')
			{
					if (ch < 0)//排除上下左右键
					{
						getch();
						continue;
					}
					else if (ch == '\b'&&i>0)
					{
						putchar('\b');
						putchar(' ');
						putchar('\b');
						i--;
					}
					else if (!isdigit(ch) && !isalpha(ch))
						continue;
					else if (i >= 15)
						continue;
					else
					{
						putchar('*');
						secondps[i++] = ch;
					}

			}
			secondps[i] = '\0';
			if (strcmp(pNew->password, secondps) == 0)
				flag1 = 0;
			else
			{
				goto_xy(55, 13);
				printf("两次密码输入不一致，请重新输入！");
				goto_xy(55, 12);
				printf("请再次输入密码:");
				goto_xy(70, 12);
				printf("                     ");
				goto_xy(65, 8);
				printf("                     ");
			}

		}
		pNew->next = pHead->next;//头插
		pHead->next = pNew;
		goto_xy(55, 13);
		printf("                                    ");
		goto_xy(57, 14);
		printf("注册成功！");
		Sleep(1500);
		return pHead;
	}

}
//教师注册
void Save_register_tea(Account * pHead)
{
	FILE *fp = NULL;
	Account *pTemp;
	if (pHead == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("注册信息为空！按任意键继续！\n");
		Sleep(1500);
		getch();
	}
	fp = fopen("register_teacher.txt", "w+");
	if (fp == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("文件打开失败！按任意键继续！\n");
		Sleep(1500);
		getch();
	}
	pTemp = pHead;
	pTemp = pHead->next;
	while (pTemp != NULL)
	{

		fwrite(pTemp, sizeof(Account), 1, fp);
		pTemp = pTemp->next;
	}
	fflush(fp);
	fclose(fp);
	Sleep(1000);
	fp = NULL;
	return;
}
//保存教师注册信息
int Lookup_tea(char *stunum)
{
	FILE *fp;
	fp = fopen("register_teacher.txt", "r");

	while (!feof(fp))
	{
		Account *a;
		a = (Account*)malloc(sizeof(Account));
		fread(a, sizeof(Account), 1, fp);
		if (strcmp(a->name, stunum) == 0)
		{
			return 1;
			break;
		}
		else
			return 0;
	}
	fclose(fp);
}
//教师用户名查重
Account * Readteadate()
{
	FILE *fp;
	Account *pHead, *pEnd, *pNew = NULL;
	pHead = (Account *)malloc(sizeof(Account));
	pHead->next = NULL;
	pEnd = pHead;
	if ((fp = fopen("register_teacher.txt", "r")) == NULL)
	{
		fp = fopen("register_stu.txt", "w");
		getchar();
	}
	else
	{
		pNew = (Account*)malloc(sizeof(Account));
		while ((fread(pNew, sizeof(Account), 1, fp))>0)
		{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
			pNew = (Account*)malloc(sizeof(Account));
		}

	}
	free(pNew);
	fclose(fp);
	return pHead;

}
//读注册信息到链表
int Matching_tea(char *stunum, char*stupass)
{
	FILE *fp;
	fp = fopen("register_teacher.txt", "r");
	while (!feof(fp))
	{
		Account *a;
		a = (Account*)malloc(sizeof(Account));
		fread(a, sizeof(Account), 1, fp);
		if (strcmp(a->name, stunum) == 0)
		{
			if (strcmp(a->password, stupass) == 0)
			{
				return 1;
				break;
			}
			else
				return 0;
		}
		else
			continue;
	}
	fclose(fp);
}
//查找账户密码是否匹配
int Login_tea()
{
	char ch;
	int flag = 1;
	int num = 0;
	while (flag)
	{
		num++;
		Login_tea_menu();
		char namet[9];
		strcpy(namet, Getname());
		if (Lookup_tea(namet) == 0)
		{
			goto_xy(57, 10);
			printf("该用户未注册！请先注册！");
			Sleep(1000);
			firstselect();
		}
		else
		{
			goto_xy(65, 8);
			char key[20];
			int i = 0;

			while ((ch = getch()) != '\r')
			{
				if (ch < 0)//排除上下左右键
				{
					getch();
					continue;
				}
				else if (ch == '\b'&&i>0)
				{
					putchar('\b');
					putchar(' ');
					putchar('\b');
					i--;
				}
				else if (!isdigit(ch) && !isalpha(ch))
					continue;
				else if (i >= 15)
					continue;
				else
				{
					putchar('*');
					key[i++] = ch;
				}
			}
			key[i] = '\0';

			if (Matching_tea(namet, key) == 1)
			{
				goto_xy(57, 14);
				printf("登陆成功！");
				Sleep(1000);
				flag = 0;
				tea_select();
			}
			else
			{
				if (num < 3)
				{
					goto_xy(57, 14);
					printf("密码错误！按任意键重新登录！");
					getch();
					continue;
				}
				else
				{
					goto_xy(57, 14);
					printf("密码错误三次！按任意键退出！");//输错三次返回主菜单
					getch();
					firstselect();
				}
			}


		}

	}
}
//教师登录