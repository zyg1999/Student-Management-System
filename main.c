#include"student.h"
#define time 40

void menu()
{
	kuang();
	goto_xy(50, 1);
	printf("欢 ");
	Sleep(time);
	printf("迎 ");
	Sleep(time);
	printf("使 ");
	Sleep(time);
	printf("用 ");
	Sleep(time);
	printf("学 ");
	Sleep(time);
	printf("籍 ");
	Sleep(time);
	printf("管 ");
	Sleep(time);
	printf("理 ");
	Sleep(time);
	printf("系 ");
	Sleep(time);
	printf("统");
	goto_xy(57, 6);
	printf("1.学  生  注  册");
	goto_xy(57, 7);
	printf("2.学  生  登  录");
	goto_xy(57, 8);
	printf("3.教  师  注  册");
	goto_xy(57, 9);
	printf("4.教  师  登  录");
	goto_xy(57, 10);
	printf("5.管 理 员 登 录");
	goto_xy(57, 15);
	printf("0.退          出");
	printf("\n\n\n\n\n\n");
}
//菜单框
void firstselect()
{
	
	Account *pHead = NULL;
	char a[100];
	do {
		system("cls");
		menu();
		goto_xy(50, 12);
		printf("请输入您的选择：");
		scanf("%s", a);
		Sleep(1000);
		if (strcmp("1", a) == 0)
		{
			pHead = Readstudate();
			pHead = register_stu(pHead);
			Save_register_stu(pHead);
			Sleep(1000);
		}
		else if (strcmp("2", a) == 0)
		{

			Login_stu();
			getch();
		}
		else if (strcmp("3", a) == 0)
		{
			pHead = Readteadate();
			pHead = register_tea(pHead);
			Save_register_tea(pHead);
			Sleep(1000);
		}
		else if (strcmp("4", a) == 0)
		{
			Login_tea();
			getch();
		}
		else if (strcmp("5", a) == 0)
		{
			char *p;
			p = Read_manps();
			Login_man(p);
			man_select();
		}
		else if (strcmp("0", a) == 0)
		{
			system("cls");
			goto_xy(50, 10);
			printf("正在退出系统！");
			Exit();
			system("cls");
			exit(1);
		}
		else
		{
			goto_xy(50, 13);
			printf("输入错误，请重新输入！");
			Sleep(1000);
		}
	} while (strcmp(a, "0"));

}
//一级菜单
int main(void)
{
	firstselect();
}