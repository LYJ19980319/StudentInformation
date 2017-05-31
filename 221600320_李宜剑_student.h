#ifndef _221600320_李宜剑_STUDENT_H
#define _221600320_李宜剑_STUDENT_H

#include <stdio.h>
#include <stdlib.h> //函数system需要

typedef struct student{
	char num[10];//学号 学院编码（2位）+入学年份（2位）+数字编码（5位）
	char name[50];//姓名 必须进行必要的数据检验
	char sex[4]; //性别 2选1
	char countryName[20];//枚举让用户选择国家的名称 
	char nationName[10];//存放民族名字 
	char birth[15];//出生日期
	int marriage;//枚举让用户选择婚姻状况  婚姻状况 
	char politicsName[25];//枚举让用户选择政治面貌
	char id[19];//身份证号码 
	int studentCategory;//学生类别 代号 
	int studentType;//枚举让用户选择学生入学方式 
	char enterDay[15];//入学日期 
	char collegeName[30];//学院名称 
	char majorName[20];//专业名称及学制 
	int grade;//年级
	int studyLength;//学制
	char trainLevel[5];//培养层次
	char classNum[3];//班级号 01~10
	char teaacherName[10];//辅导员名字
	int score;//学生高考成绩
	struct student *next;
}stu,*linkList;

void systemTime();//调用系统函数的时间 

linkList intList(void);//初始化链表

int nodeCount(stu *head);//统计链表里面的节点数 

void classMenu();//类里面的内容   

void menu();//菜单界面 

int inType();// 返回时从键盘录入 还是从文件

int ifRight(int a,int b,int c);//判断是否为合法日期  合法返回 1 不合法返回 0

int numCheck(char a[],stu *head,int count);//学号检验

int nameCheck(char a[]);//名字检验 

char *studentsNum(stu *head,stu *p,int count);//录入学号

char *studetsName(stu *head,stu *p,int count);//录入姓名

char *studentsSex(int count);//录入学生性别

char *studentsCountry(int count);//录入国家信息

int birthCheck(int year,int month,int day);//出生日期的检验 

char *studentsNation(int count);//录入民族信息

char *marType(int n);//返回婚姻类型 

int studentsMarriage(int count);//录入学生婚姻状况(婚姻状况代码)

char *studentsPolitics(int count);//录入政治面貌信息

int idCheck(char id[],stu *head);//验证身份证是否重复 

int idCheck2(char id[]);////验证最后一位身份证的校验码

int idCheck1(char id[],int n,int year,int month,int day,char s[]);//身份验证 性别 出生日期 

char *stuCategory(int n);//返回学生类别

int studentsCategory(int count);//录入学生类别

char *studentsEnterDay(int count,char num1[]);//录入学生入学日期

char *studentsTypeName(int n);//返回学生入学方式的类型名称 

int studentsType(int count);//返回学生入学方式代号 

char *studentsId(int count,stu *head,int m,char b[],char s[]);//录入学生的身份证信息

char *studentsCollege(int count);//录入学院信息

char *studentsMajor(int count);//录入专业和学制信息

int studentsGrade(int count,char nu[]);//返回学生的入学年级

int studentsLength(int count);//录入学制  

char *studentsTrainLevel(int count);//录入学生的培养层次 

char *studentsClass(int count);//录入学生班级号01~10

char *studentsTeacher(int count);//录入辅导员信息 

int studentsExam(int count);//录入高考成绩 

linkList informationIn();//录入学生信息

void ShowMainInformation(stu *head);//展示主要信息 就是学生序号以及名字 

void DecideoutInformation(int n,stu *head,int count);//根据选择输出用户需要的东西

void referInformation(stu *head);//查询信息

int delType();//返回删除学生信息的方式

int countList(stu *head);//统计链表里面的结点数目 

linkList delSingleStuents(stu *head);//删除单个学生信息 

//linkList delMajorGrade(stu *head);//删除专业+年级的学生信息

linkList  delInformation(stu *head);//删除学生信息 

linkList modifInformation(stu *head);//修改学生信息

linkList addInformation(stu *head);//增加学生信息

int anaylyzeType();//返回分析学生信息的方式

void analyzeCountry(stu *head);//按照国家分析 

void analyzeNation(stu *head);//按照民族分析 

void analyzeInformation(stu *head);//统计，分析信息 
 
linkList sortNum(stu *head);//学号排序

linkList sortAge(stu *head);//年龄大小排序

linkList sortAge(stu *head,int type);//高考成绩排序
 
linkList sortInformation(stu *head);//排序学生信息

void showInformation(stu *head);//全部信息输出到屏幕 

void ToFileInformation(stu *head);//将学生信息输入到文件中

void freeList(stu *head);//释放链表

#endif


