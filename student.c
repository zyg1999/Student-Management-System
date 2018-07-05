#include"student.h"

void second_tea()
{
	system("cls");
	printf("				 ------------------------------------------------------------\n");
	printf("				 ·                     教  师  端                         ·\n");
	printf("				 ------------------------------------------------------------\n");
	printf("				 ·                   1.录入学生信息                       ·\n");
	printf("				 ·                   2.增加学生信息                       ·\n");
	printf("				 ·                   3.删除学生信息                       ·\n");
	printf("				 ·                   4.修改学生信息                       ·\n");
	printf("				 ·                   5.查询学生信息                       ·\n");
	printf("				 ·                   6.输出学生信息                       ·\n");
	printf("				 ·                   7.成 绩 分 析                        ·\n");
	printf("				 ·                   8.外部导入信息                       ·\n");
	printf("				 ·                   9.退 出 登 录                        ·\n");
	printf("				 ·                   0.退 出 系 统                        ·\n");
	printf("				 ------------------------------------------------------------\n");
}
//教师端菜单
void second_stu()
{
	system("cls");
	printf("\t\t\t\t----------------------------------------------------------------------\n");
	printf("\t\t\t\t·                           学  生  端                             · \n");
	printf("\t\t\t\t----------------------------------------------------------------------\n");
	printf("\t\t\t\t·                                                                  · \n");
	printf("\t\t\t\t·                        1.信  息  查  询                          · \n");
	printf("\t\t\t\t·                                                                  · \n");
	printf("\t\t\t\t·                                                                  · \n");
	printf("\t\t\t\t·                        2.成  绩  分  析                          · \n");
	printf("\t\t\t\t·                                                                  · \n");
	printf("\t\t\t\t·                                                                  · \n");
	printf("\t\t\t\t·                        3.退  出  登  录                          · \n");
	printf("\t\t\t\t·                                                                  · \n");
	printf("\t\t\t\t·                                                                  · \n");
	printf("\t\t\t\t·                        0.退  出  系  统                          · \n");
	printf("\t\t\t\t----------------------------------------------------------------------\n");
}
//学生端菜单
int Lookup_stu_date(char *stunum)
{
	List *a;
	a = (List*)malloc(sizeof(List));
	FILE *fp;
	fp = fopen("stu_date.txt", "r");
	while (!feof(fp))
	{

		fread(a, sizeof(List), 1, fp);
		if (strcmp(a->node.num,stunum) == 0)
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;

}
//学生信息学号查重
List * Input_stu(List*pHead)
{
	float a, b, c;
	int flag = 1;
	List *pNew;
	pNew = (List *)malloc(sizeof(List));
	pNew->next = NULL;
	printf("\t\t\t\t*******************************\n");
	printf("\t\t\t\t        学生信息录入\n");
	printf("\t\t\t\t*******************************\n");
	printf("\t\t\t\t请输入学生学号（输入0结束）：");
	scanf("%s", pNew->node.num);
	while (strcmp(pNew->node.num, "0") != 0)
	{
		if (judge_no(pNew->node.num, 8) == 0)
		{
			printf("\t\t\t\t学号必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			printf("\t\t\t\t*******************************\n");
			printf("\t\t\t\t        学生信息录入\n");
			printf("\t\t\t\t*******************************\n");
			printf("\t\t\t\t请输入学生学号（输入0结束）：");
			scanf("%s", pNew->node.num);
			continue;
		}
		while (1)
		{
			if (Lookup_stu_date(pNew->node.num) == 0)
			{
				break; 
			}
			else
			{
				printf("\t\t\t\t该学生已存在，请重新输入！\n");
				printf("\t\t\t\t请输入学生的学号：");
				scanf("%s", pNew->node.num);
			}
		}

		printf("\t\t\t\t请输入学生姓名：");
		scanf("%s", pNew->node.name);
		printf("\t\t\t\t请输入学生性别：");
		scanf("%s", &pNew->node.sex);
		printf("\t\t\t\t请输入学生出生日期，空格隔开：");
		scanf("%d %d %d", &pNew->node.birthday.year, &pNew->node.birthday.month, &pNew->node.birthday.day);
		while (1)
		{
			printf("\t\t\t\t请输入学生的三门课成绩，空格隔开：");
			scanf("%f %f %f", &a, &b, &c);
			if (a < 0 || b < 0 || c < 0)
				printf("\t\t\t\t输入信息有误，请重新输入!\n");
			else
			{
				pNew->node.score[0] = a;
				pNew->node.score[1] = b;
				pNew->node.score[2] = c;
				break;
			}
		}
		pNew->node.sum = pNew->node.score[0] + pNew->node.score[1] + pNew->node.score[2];//计算总成绩

		pNew->next = pHead->next;
		pHead->next = pNew;

		pNew = (List *)malloc(sizeof(List));
		printf("\n");
		printf("\t\t\t\t请输入学号(输入0结束)：");
		scanf("%s", pNew->node.num);
	}
	free(pNew);
	return pHead;
}
//录入
List *  Increase_stu(List * pHead)
{
	List * ptemp = pHead, *pNew;
	float a, b, c;
	char n[9];
	int flag = 1;
	while (flag)
	{
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        学生信息增加\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t请输入要增加到哪位同学后：");
		scanf("%s", n);
	
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t学号必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			continue;
		}
		while (ptemp&&strcmp(ptemp->node.num, n) != 0)
			ptemp = ptemp->next;
		if (ptemp == NULL)
		{
			printf("\t\t\t\t无该学生！请重输\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;


		pNew = (List*)malloc(sizeof(List));
		printf("\t\t\t\t请输入插入学生的学号(结束输0)：");
		scanf("%s", pNew->node.num);
		while (strcmp(pNew->node.num, "0") != 0)
		{
				if (judge_no(n, 8) == 0)
				{
					printf("\t\t\t\t学号必须为8位数字！请重输\n");
					Sleep(1000);
					system("cls");
					continue;
				}
				while (1)
				{
					if ((Lookup_stu_date(pNew->node.num)) == 0)
					{
						
						break;
					}
					else
					{
						printf("\t\t\t\t该学生已存在，请重新输入！\n");
						printf("\t\t\t\t请输入插入学生的学号：");
						scanf_s("%s", pNew->node.num, 9);
					}
				}
				printf("\t\t\t\t请输入学生姓名：");
				scanf("%s", pNew->node.name);
				printf("\t\t\t\t请输入学生性别：");
				scanf("%s", &pNew->node.sex);
				printf("\t\t\t\t请输入学生出生日期，空格隔开：");
				scanf("%d %d %d", &pNew->node.birthday.year, &pNew->node.birthday.month, &pNew->node.birthday.day);
				while (1)
				{
					printf("\t\t\t\t请输入学生的三门课成绩，空格隔开：");
					scanf("%f %f %f", &a, &b, &c);
					if (a < 0 || b < 0 || c < 0)
						printf("\t\t\t\t输入信息有误，请重新输入!\n");
					else
					{
						pNew->node.score[0] = a;
						pNew->node.score[1] = b;
						pNew->node.score[2] = c;
						break;
					}
				}
				pNew->node.sum = pNew->node.score[0] + pNew->node.score[1] + pNew->node.score[2];//计算总成绩

				pNew->next = ptemp->next;
				ptemp->next = pNew;


				pNew = (List*)malloc(sizeof(List));
				printf("\n");
				printf("\t\t\t\t请输入插入学生的学号(结束输0)：");
				scanf("%s", pNew->node.num);
		}
		
	}
	free(pNew);
	return pHead;
}
//增加到指定位置
List *Readdate()
{
	FILE *fp;;

	List *pHead, *pEnd, *pNew = NULL;

	pHead = (List *)malloc(sizeof(List));
	pHead->next = NULL;
	pEnd = pHead;
	if ((fp = fopen("stu_date.txt", "r")) == NULL)
	{
		fp = fopen("stu_date.txt", "w");
		getchar();

	}
	else
	{
		pNew = (List*)malloc(sizeof(List));
		while ((fread(pNew, sizeof(List), 1, fp))>0)
		{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
			pNew = (List*)malloc(sizeof(List));
		}

	}
	free(pNew);
	fclose(fp);
	return pHead;

}
//读取学生数据到链表
void Save_date_stu(List * pHead)
{
	FILE *fp = NULL;
	List * pTemp;
	if (pHead == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("注册信息为空！按任意键继续！\n");
		getch();
		return 0;
	}
	fp = fopen("stu_date.txt", "w+");
	if (fp == NULL)
	{
		system("cls");
		kuang();
		goto_xy(57, 9);
		printf("文件打开失败！按任意键继续！\n");
		getch();
	}
	pTemp = pHead->next;
	while (pTemp != NULL)
	{

		fwrite(pTemp, sizeof(List), 1, fp);
		pTemp = pTemp->next;
	}
	fflush(fp);
	fclose(fp);
	printf("\t\t\t\t保存成功!按任意键继续！\n");
	getch();
	return;
}
//保存数据到文件
void  Query(List * pHead)
{
	List * ptemp = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        学生信息查询\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t请输入学生学号：");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t学号必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->node.num, n) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t无该学生的信息\n");
		Sleep(500);
		return NULL;
	}
	else
	{
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t学号：%s\n", ptemp->node.num);
		printf("\t\t\t\t姓名：%s\n", ptemp->node.name);
		printf("\t\t\t\t性别：%s\n", ptemp->node.sex);
		printf("\t\t\t\t出生日期：%d %d %d\n", ptemp->node.birthday.year, ptemp->node.birthday.month, ptemp->node.birthday.day);
		printf("\t\t\t\t科目一%.2f 科目二%.2f 科目三%.2f\n", ptemp->node.score[0], ptemp->node.score[1], ptemp->node.score[2]);
		printf("\t\t\t\t总成绩：%.2f\n", ptemp->node.sum);
		printf("\t\t\t\t------------------------------------\n");
	}
}
//教师端查询按学号
List* Delete_stu_bynum(List * pHead)
{
	List * ptemp = pHead, *ptemp1 = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        学生信息删除\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t请输入学生学号：");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t学号必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->node.num, n) != 0)
	{
		ptemp1 = ptemp;
		ptemp = ptemp->next;
	}
	if (ptemp == NULL)
	{
		printf("\t\t\t\t无该学生的信息！\n");
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
//删除
List * Modify(List *pHead)
{
	List * ptemp = pHead;
	char n[9];
	int flag = 1;
	while (flag)
	{

		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        学生信息修改\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t请输入学生学号：");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t学号必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else
			flag = 0;
	}
	while (ptemp&&strcmp(ptemp->node.num, n) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t无该学生的信息\n");
		getch();
		return NULL;
	}
	else
	{
		char c[20];
		int flag1 = 1;
		do
		{
			printf("\t\t\t\t1-姓名  2-性别  3-出生日期   4-科目一  5-科目二  6-科目三  0-返回上一层\n");
			printf("\t\t\t\t请输入想要修改的信息类别:");
			scanf("%s", c);
			if (!strcmp(c, "1"))
			{
				printf("\t\t\t\t请输入新姓名：");
				scanf("%s", ptemp->node.name);
			}
			else if (!strcmp(c, "2"))
			{
				printf("\t\t\t\t请输入新性别：");
				scanf("%s", &ptemp->node.sex);
			}
			else if (!strcmp(c, "3"))
			{
				printf("\t\t\t\t请输入新出生日期(如：2018 5 12)：");
				scanf("%d %d %d", &ptemp->node.birthday.year, &ptemp->node.birthday.month, &ptemp->node.birthday.day);
			}
			else if (!strcmp(c, "4"))
			{
				float a;
				while (1)
				{
					printf("\t\t\t\t请输入新科目一成绩：");
					scanf("%f", &a);
					if (a > 0)
					{
						ptemp->node.score[0] = a;
						break;
					}
					else
					{
						printf("\t\t\t\t输入信息有误！\n");
						continue;

					}
				}
				
			}
			else if (!strcmp(c, "5"))
			{
				float a;
				while (1)
				{
					printf("\t\t\t\t请输入新科目二成绩：");
					scanf("%f", &a);
					if (a > 0)
					{
						ptemp->node.score[1] = a;
						break;
					}
					else
					{
						printf("\t\t\t\t输入信息有误！\n");
						continue;

					}
				}
			}
			 else if (!strcmp(c, "6"))
			{
				float a;
				while (1)
				{
					printf("\t\t\t\t请输入新科目三成绩：");
					scanf("%f", &a);
					if (a > 0)
					{
						ptemp->node.score[2] = a;
						break;
					}
					else
					{
						printf("\t\t\t\t输入信息有误！\n");
						continue;

					}
				}
			}
			else  if (!strcmp(c, "0"))
			{
				break;
			}
			else
			{
				printf("\t\t\t\t输入错误，请重新输入！");
			}
		} while (strcmp(c, "0"));
	}
	return pHead;
}
//修改
void  Query_nameandnum(List * pHead)
{
	List * ptemp = pHead;
	char name[20];
	char n[9];
	int flag = 1;
	while (flag) {
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t        学生信息查询\n");
		printf("\t\t\t\t*******************************\n");
		printf("\t\t\t\t请输入学生学号：");
		scanf("%s", n);
		if (judge_no(n, 8) == 0)
		{
			printf("\t\t\t\t学号必须为8位数字！请重输\n");
			Sleep(1000);
			system("cls");
			second_tea();
			continue;
		}
		else {
			flag = 0;
			printf("\t\t\t\t请输入学生姓名：");
			scanf("%s",name);
		}
	}
	
	while (ptemp&&strcmp(ptemp->node.num, n)&& strcmp(ptemp->node.name, name) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t无该学生的信息\n");
		Sleep(500);
		return NULL;
	}
	else
	{
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t学号：%s\n", ptemp->node.num);
		printf("\t\t\t\t姓名：%s\n", ptemp->node.name);
		printf("\t\t\t\t性别：%s\n", ptemp->node.sex);
		printf("\t\t\t\t出生日期：%d %d %d\n", ptemp->node.birthday.year, ptemp->node.birthday.month, ptemp->node.birthday.day);
		printf("\t\t\t\t科目一%.2f 科目二%.2f 科目三%.2f\n", ptemp->node.score[0], ptemp->node.score[1], ptemp->node.score[2]);
		printf("\t\t\t\t总成绩：%.2f\n", ptemp->node.sum);
		printf("\t\t\t\t------------------------------------\n");
	}
}
//教师端查询按姓名和学号
List * Sort_by_sum(List* pHead)
{
	List *p, *q;
	int n=0, i, j;
	p = pHead;
	while (p)
	{
		n++;
		p = p->next;
	}
	for (i = 0; i<n - 2; i++)
	{
		p = pHead;
		q = p->next;
		for (j = 0; j<n - i - 2; j++)
		{
			if (q->node.sum<(q->next->node.sum))
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
	}


	return pHead;
}
//总成绩降序排序
List * Sort_by_num(List* pHead)
{
	List *p, *q;
	int n = 0, i, j;
	p = pHead;
	while (p)
	{
		n++;
		p = p->next;
	}
	for (i = 0; i<n - 2; i++)
	{
		p = pHead;
		q = p->next;
		for (j = 0; j<n - i - 2; j++)
		{
			if (strcmp(q->node.num,q->next->node.num)>0)
			{
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
			}
			p = p->next;
			q = p->next;
		}
	}

	return pHead;
}
//学号升序排序
int judge_no(char num[], int len)
{
	int i;

	if (strlen(num) != len)
	{
		return 0;
	}
	for (i = 0; i<len; i++)
	{
		if (num[i] >= '0' && num[i] <= '9');
		else  break;
	}
	if (i == len) 
		return (1);
	else
	{
		return 0;
	}
}
//判断学号输入是否正确
void Analyzescore(List*pHead)
{
	List *p;
	int sum1 = 0, sum2 = 0, sum3 = 0;
	p = pHead->next;
	if (p == NULL)
	{
		printf("\t\t\t\t暂无数据!按任意键继续\n");
		getch();
		return 0;
	}
	while (p)
	{
		if (p->node.score[0] < 60)
			sum1++;
		if (p->node.score[1] < 60)
			sum2++;
		if (p->node.score[2] < 60)
			sum3++;
		p = p->next;
	}
	printf("\t\t\t\t----------------------------------------------\n");
	printf("\t\t\t\t                 成绩分析\n");
	printf("\t\t\t\t----------------------------------------------\n");
	printf("\t\t\t\t             科目一不及格人数：%d人\n", sum1);
	printf("\t\t\t\t             科目二不及格人数：%d人\n", sum2);
	printf("\t\t\t\t             科目三不及格人数：%d人\n", sum3);
	printf("\t\t\t\t----------------------------------------------\n");
	printf("\t\t\t\t按任意键继续！");
	getch();
}
//成绩分析
void Printf_list(List *pHead)
{
	int num = 1;
	List * p = pHead->next;
	if (p == NULL)
	{
		printf("\t\t\t\t暂无数据!按任意键继续\n");
		getch();
		return 0;
	}
	while (p != NULL)
	{
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t总成绩排名：%d\n", num);
		printf("\t\t\t\t学号：%s\n", p->node.num);
		printf("\t\t\t\t姓名：%s\n", p->node.name);
		printf("\t\t\t\t性别：%s\n", p->node.sex);
		printf("\t\t\t\t出生日期：%d %d %d\n", p->node.birthday.year, p->node.birthday.month, p->node.birthday.day);
		printf("\t\t\t\t科目一%.2f 科目二%.2f 科目三%.2f\n", p->node.score[0], p->node.score[1], p->node.score[2]);
		printf("\t\t\t\t总成绩：%.2f\n", p->node.sum);
		printf("\t\t\t\t------------------------------------\n");
		p = p->next;
		num++;
	}
}
//打印排名链表信息
void Printf_numlist(List *pHead)
{
	List * p = pHead->next;
	if (p == NULL)
	{
		printf("\t\t\t\t暂无数据!按任意键继续\n");
		getch();
		return 0;
	}
	while (p != NULL)
	{
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t学号：%s\n", p->node.num);
		printf("\t\t\t\t姓名：%s\n", p->node.name);
		printf("\t\t\t\t性别：%s\n", p->node.sex);
		printf("\t\t\t\t出生日期：%d %d %d\n", p->node.birthday.year, p->node.birthday.month, p->node.birthday.day);
		printf("\t\t\t\t科目一%.2f 科目二%.2f 科目三%.2f\n", p->node.score[0], p->node.score[1], p->node.score[2]);
		printf("\t\t\t\t总成绩：%.2f\n", p->node.sum);
		printf("\t\t\t\t------------------------------------\n");
		p = p->next;
	}
}
//打印学号排序信息
void Query_stu(List *pHead,char *p)
{
	List * ptemp = pHead;
	int flag = 1;
	while (ptemp&&strcmp(ptemp->node.num, p) != 0)
		 ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t信息暂未录入\n");
		Sleep(500);
		return NULL;
	}
	else
	{
		printf(" \n");
		printf(" \n");
		printf("\t\t\t\t------------------------------------\n");
		printf("\t\t\t\t学号：%s\n", ptemp->node.num);
		printf("\t\t\t\t姓名：%s\n", ptemp->node.name);
		printf("\t\t\t\t性别：%s\n", ptemp->node.sex);
		printf("\t\t\t\t出生日期：%d %d %d\n", ptemp->node.birthday.year, ptemp->node.birthday.month, ptemp->node.birthday.day);
		printf("\t\t\t\t科目一%.2f 科目二%.2f 科目三%.2f\n", ptemp->node.score[0], ptemp->node.score[1], ptemp->node.score[2]);
		printf("\t\t\t\t总成绩：%.2f\n", ptemp->node.sum);
		printf("\t\t\t\t------------------------------------\n");
	}
}
//登录用户的个人信息
void Analy_stu(List *pHead, char *p)
{
	List * ptemp = pHead;
	int flag = 1;
	while (ptemp&&strcmp(ptemp->node.num, p) != 0)
		ptemp = ptemp->next;
	if (ptemp == NULL)
	{
		printf("\t\t\t\t信息暂未录入\n");
		Sleep(500);
		return NULL;
	}
	else
	{
		int flag = 0;
		printf(" \n");
		printf(" \n");
		printf("\t\t\t\t------------------------------------\n");
		if (ptemp->node.score[0] < 60)
		{
			flag = 1;
			printf("\t\t\t\t科目一不合格\n");
		}
		if (ptemp->node.score[1] < 60)
		{
			flag = 1;
			printf("\t\t\t\t科目二不合格\n");
		}
			
		if (ptemp->node.score[2] < 60)
		{
			flag = 1;
			printf("\t\t\t\t科目三不合格\n");
		}
		if (flag == 1)
			printf("\t\t\t\t潜心学习，分析试卷，加油！\n");
		else if (flag == 0)
			printf("\t\t\t\t全部合格，不忘初心，奋力向前！\n");
		printf("\t\t\t\t------------------------------------\n");
	}
}
//分析登录用户单个成绩
void Exit()
{
	int i;
	goto_xy(50,8);
	for (i = 0; i < 5; i++)
	{
		printf("■ ");
		Sleep(200);
	}
}
//退出
List * outsidefile(char *p)
{
	FILE *fp;
	List *pNew, *pHead;
	pHead = (List *)malloc(sizeof(List));
	pHead->next = NULL;
	pNew = (List *)malloc(sizeof(List));
	
	if (fp = fopen(p, "r") ,fp== NULL)
	{
		printf("\t\t\t\t文件不存在！");
		return NULL;
	}

	while (!feof(fp))
	{

		fscanf(fp, "%s %s %s %d %d %d %f %f %f %lf", pNew->node.num, pNew->node.name, pNew->node.sex, &pNew->node.birthday.year, &pNew->node.birthday.month, &pNew->node.birthday.day, &pNew->node.score[0], &pNew->node.score[1], &pNew->node.score[2], &pNew->node.sum);
		pNew->next = NULL;
		pNew->next = pHead->next;
		pHead->next = pNew;

		pNew = (List *)malloc(sizeof(List));
	}
	free(pNew);
	fclose(fp);
	return pHead;
}
//外部导入学生信息
void stu_select(char * p)
{
	List * pHead;
	char a[100];
	do {
		system("cls");
		second_stu();
		goto_xy(50, 15);
		printf("请输入您的选择：");
		scanf("%s", a);
		Sleep(1000);
		if (strcmp("1", a) == 0)
		{
			pHead=Readdate();
			Query_stu(pHead,p);
			printf("\t\t\t\t按任意键继续\n");
			getch();
		}
		else if (strcmp("2", a) == 0)
		{
			pHead = Readdate();
			Analy_stu(pHead, p);
			printf("\t\t\t\t按任意键继续\n");
			getch();
		}

		else if (strcmp("3", a) == 0)
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
//学生
void tea_select()
{
	List * pHead = NULL;
	char a[100];
	do {
		system("cls");
		second_tea();
		goto_xy(50, 14);
		printf("请输入您的选择：");
		scanf("%s", a);
		Sleep(1000);
		if (strcmp("1", a) == 0)
		{
			pHead = Readdate();
			pHead = Input_stu(pHead);
			Save_date_stu(pHead);	
		}
		else if (strcmp("2", a) == 0)
		{

			pHead = Readdate();
			pHead = Increase_stu(pHead);
			Save_date_stu(pHead);
		}
		else if (strcmp("3", a) == 0)
		{
			pHead = Readdate();
			pHead = Delete_stu_bynum(pHead);
			Save_date_stu(pHead);
		}
		else if (strcmp("4", a) == 0)
		{
			pHead = Readdate();
			pHead = Modify(pHead);
			Save_date_stu(pHead);
			
		}
		else if (strcmp("5", a) == 0)
		{
			int n;
			printf("\t\t\t\t请选择查询方式  1.按学号查询  2.学号加名字查询：");
			scanf("%d", &n);
			pHead = Readdate();
			if (n == 1) {
				Query(pHead);
			}
			else if(n==2){
				Query_nameandnum(pHead);
			}
			printf("\t\t\t\t按任意键继续！\n");
			getch();
		}
		else if (strcmp("6", a) == 0)
		{
			pHead = Readdate();
			int n;
			printf("\t\t\t\t请选择查询方式  1.按成绩降序输出  2.按学号升序输出：");
			scanf("%d", &n);
			if (n == 1) {
				pHead = Sort_by_sum(pHead);
				Printf_list(pHead);
			}
			else if (n == 2) {
				pHead=Sort_by_num(pHead);
				Printf_numlist(pHead);
			}
			printf("\t\t\t\t按任意键继续！\n");
			getch();
		}
		else if (strcmp("7", a) == 0)
		{
			pHead = Readdate();
			Analyzescore(pHead);
		}
		else if (strcmp("8", a) == 0)
		{
			char filename[50];
			printf("\t\t\t\t请输入导入文件文件的绝对路径：");
			scanf("%s", filename);
			if (pHead=outsidefile(filename),pHead == NULL)
			{
				printf("\t\t\t\t该路径下文件不存在！按任意键继续！");
				getch();
			}
			else
			{
				Save_date_stu(pHead);
			}
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
//教师