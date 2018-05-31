#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#ifndef STUDENT_H
#define STUDENT_H

struct date
{
	int year;
	int month;
	int day;
};
typedef struct information
{
	char num[9];
	char name[21];
	char sex[6];
	struct date birthday;
	float score[3];
	double sum;

}Node;
typedef struct student
{
	Node node;
	struct student * next;
}List;
typedef struct ACCOUNT
{
	char name[9];
	char password[15];
	struct ACCOUNT * next;

}Account;

Account * register_stu(Account *pHead);//学生注册
Account * register_tea(Account *pHead);//教师注册
int Lookup_stu(char *);//查重
int Lookup_tea(char *);//查重
char * Getname();//获取用户名
int Matching_stu(char *stunum, char*stupass);//用户名和密码匹配
int Matching_tea(char *stunum, char*stupass);//用户名和密码匹配
int Judge_password(char ch);//判断密码是否符合
void goto_xy(int x, int y);//光标移动
void kuang();
void login_stu();//学生登录
void second_stu();//学生二级菜单
void login_tea();//教师登录
void second_tea();//教师二级菜单
int judge_no(char num[], int len);//判断学号输入是否正确
List * Input_stu();//录入
List * Increase_stu(List * pHead);  //增加
List * Delete_stu_bynum(List * pHead);//删除
List * Modify(List *pHead); //修改
void  Query(List * pHead);//查询
List * Sort_by_sum(List * pHead);//学号升序排序
List * Sort_by_sum(List * pHead);
int Lookup_stu_date(char *stunum);//学生数据查重


#endif
