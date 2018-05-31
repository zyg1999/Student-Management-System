#include"student.h"

void Login_man_menu()
{

	system("cls");
	kuang();
	goto_xy(55, 1);
	printf("管   理   员   登    录");
	goto_xy(57, 6);
	printf("账户名：Manager");
	goto_xy(57, 8);
	printf("密  码：");

	printf("\n\n\n\n\n");

}
//管理员登录界面
void second_manger()
{
	system("cls");
	printf("				 ------------------------------------------------------------\n");
	printf("				 ·                     管 理 员 端                        ·\n");
	printf("				 ------------------------------------------------------------\n");
	printf("				 ·                   1.修改学生密码                       ·\n");
	printf("				 ·                   2.修改教师密码                       ·\n");
	printf("				 ·                   3.删除学生注册信息                   ·\n");
	printf("				 ·                   4.删除教师注册信息                   ·\n");
	printf("				 ·                   5.查询学生账户信息                   ·\n");
	printf("				 ·                   6.查询教师账户信息                   ·\n");
	printf("				 ·                   7.修改管理员密码                     ·\n");
	printf("				 ·                   8.初始化管理员密码                   ·\n");
	printf("				 ·                   9.退  出  登  录                     ·\n");
	printf("				 ·                   0.退  出  系  统                     ·\n");
	printf("				 ------------------------------------------------------------\n");
}
//管理员二级菜单
void Login_man(char * p)
{
	char ch;
	int flag = 1;
	while (flag)
	{
		Login_man_menu();
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

		if (strcmp(p, key) == 0)
		{
			goto_xy(57, 14);
			printf("登陆成功！");
			Sleep(1000);
			flag = 0;
		}
		else
		{
			goto_xy(57, 14);
			printf("密码错误！请重新登录！");
			Sleep(1000);
			continue;
		}


	}


}
//管理员登录
Account *Read_stureg()
{
	FILE *fp;;
	Account *pHead, *pEnd, *pNew = NULL;

	pHead = (Account *)malloc(sizeof(Account));
	pHead->next = NULL;
	pEnd = pHead;
	if ((fp = fopen("register_stu.txt", "r")) == NULL)
	{
		printf("\t\t\t\t打开文件失败！\n");
		getch();
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
//读学生账户信息到链表
Account *Read_teareg()
{
	FILE *fp;;
	Account *pHead, *pEnd, *pNew = NULL;

	pHead = (Account *)malloc(sizeof(Account));
	pHead->next = NULL;
	pEnd = pHead;
	if ((fp = fopen("register_teacher.txt", "r")) == NULL)
	{
		printf("\t\t\t\t打开文件失败！\n");
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
//读教师账户信息到链表
Account * Modify_reg(Account *pHead)
{
	Account * ptemp = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t         密码修改\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t请输入用户名：");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t用户名必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->name, n) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		return 0;
	}
	else
	{
		char psw[15];
		printf("\t\t\t\t请输入新密码：");
		scanf("%s", psw);
		strcpy(ptemp->password, psw);
		printf("\t\t\t\t修改成功！\n");	
	}
	return pHead;
}
//修改密码
Account *Delete_reg(Account*pHead)
{
	Account * ptemp = pHead, *ptemp1 = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        用户信息删除\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t请输入用户名：");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t用户名必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->name, n) != 0)
	{
		ptemp1 = ptemp;
		ptemp = ptemp->next;
	}
	if (ptemp == NULL)
	{
		printf("\t\t\t\t无该用户的信息！\n");
		return NULL;
	}
	else
	{
		ptemp1->next = ptemp->next;
		free(ptemp);
		printf("\t\t\t\t删除成功！\n");
	}
	return pHead;
}
//删除账户及密码
void *Query_reg(Account*pHead)
{
	Account * ptemp = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        账户信息查询\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t请输入用户名：");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t用户名必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->name, n) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t无该用户的信息\n");
		Sleep(1000);
		return 0;
	}
	else
	{
		printf("\t\t\t\t----------------------------\n");
		printf("\t\t\t\t    用户名:%s\n", ptemp->name);
		printf("\t\t\t\t    密  码:%s\n", ptemp->password);
		printf("\t\t\t\t----------------------------\n");
	}

}
//查询账户及密码
void Save_reg_stu(Account * pHead)
{
	FILE *fp = NULL;
	Account * pTemp;
	if (pHead == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("无该用户信息！按任意键继续\n");
		getch();
		return;
	}
	fp = fopen("register_stu.txt", "w+");
	if (fp == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("文件打开失败！按任意键继续！\n");
		Sleep(1500);
		getch();
	}
	pTemp = pHead->next;
	while (pTemp != NULL)
	{

		fwrite(pTemp, sizeof(Account), 1, fp);
		pTemp = pTemp->next;
	}
	printf("\t\t\t\t保存成功!\n");
	fflush(fp);
	fclose(fp);
	Sleep(1000);
	fp = NULL;
	return;
}
//保存数据到学生注册文件(复写)
void Save_reg_tea(Account * pHead)
{
	FILE *fp = NULL;
	Account * pTemp;
	if (pHead == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("无该用户信息！按任意键继续\n");
		getch();
		return;
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
	pTemp = pHead->next;
	while (pTemp != NULL)
	{

		fwrite(pTemp, sizeof(Account), 1, fp);
		pTemp = pTemp->next;
	}
	fflush(fp);
	fclose(fp);
	printf("\t\t\t\t保存成功!\n");
	Sleep(1000);
	fp = NULL;
	return;
}
//保存数据到教师注册文件(复写)
char * Read_manps()
{
	FILE * fp;
	static char a[20];
	if ((fp = fopen("register_man.txt", "r")) ,fp == NULL)
	{
		printf("\t\t\t\t打开文件失败！\n");
		getchar();
	}
	else
	{
		fread(a, sizeof(a), 1, fp);
	}
	fclose(fp);
	return a;
}
//读取管理员密码
void chushi_man()
{
	FILE *fp;
	fp = fopen("register_man.txt", "w+");
	char a[20] = "1234567";
	fwrite(a, sizeof(a), 1, fp);
	fclose(fp);	
}
//管理员密码初始化
void Modify_man()
{
	FILE *fp;
	fp = fopen("register_man.txt", "w+");
	if (fp == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("文件打开失败！按任意键继续！\n");
		Sleep(1500);
		getch();
	}
	else
	{
		char a[20];
		printf("\t\t\t\t---------------------------\n");
		printf("\t\t\t\t请输入管理员新密码：");
		scanf("%s", a);
		printf("\t\t\t\t---------------------------\n");
		fwrite(a, sizeof(a), 1, fp);
		printf("\t\t\t\t修改成功！\n");
	}
	fclose(fp);
}
//修改管理员密码
void man_select()
{
	Account *pHead;
	char a[100];
	do {
		system("cls");
		second_manger();
		goto_xy(50, 14);
		printf("请输入您的选择：");
		scanf("%s", a);
		Sleep(1000);
		if (strcmp("1", a) == 0)
		{
			pHead=Read_stureg();
			pHead=Modify_reg(pHead);
			Save_reg_stu(pHead);	
		}
		else if (strcmp("2", a) == 0)
		{
			pHead = Read_teareg();
			pHead = Modify_reg(pHead);
			Save_reg_tea(pHead);
		}
		else if (strcmp("3", a) == 0)
		{
			pHead = Read_stureg();
			pHead = Delete_reg(pHead);
			Save_reg_stu(pHead);
			
		}
		else if (strcmp("4", a) == 0)
		{
			pHead = Read_teareg();
			pHead = Delete_reg(pHead);
			Save_reg_tea(pHead);
		}
		else if (strcmp("5", a) == 0)
		{
			pHead = Read_stureg();
			Query_reg(pHead);
			printf("\t\t\t\t继续请按任意键\n");
			getch();
			
		}
		else if (strcmp("6", a) == 0)
		{
			pHead = Read_teareg();
			Query_reg(pHead);
			printf("\t\t\t\t继续请按任意键\n");
			getch();
		}
		else if (strcmp("7", a) == 0)
		{
			Modify_man();
			printf("\t\t\t\t继续请按任意键\n");
			getch();
		}
		else if (strcmp("8", a) == 0)
		{
			chushi_man();
			printf("\t\t\t\t继续请按任意键\n");
			getch();
		}
		else if (strcmp("9", a) == 0)
		{
			firstselect();
		}
		else if (strcmp("0", a) == 0)
		{
			system("cls");
			goto_xy(50, 10);
			printf("正在退出系统！");
			Exit();
			Sleep(500);
			system("cls");
			exit(1);
		}
		else
		{
			goto_xy(50, 13);
			printf("输入错误，请重新输入！");
			goto_xy(66, 12);
			printf("              ");
			goto_xy(66, 12);
		}
	} while (strcmp(a, "0"));


}
//管理员二级菜单