#ifndef _221600320_���˽�_STUDENT_H
#define _221600320_���˽�_STUDENT_H

#include <stdio.h>
#include <stdlib.h> //����system��Ҫ

typedef struct student{
	char num[10];//ѧ�� ѧԺ���루2λ��+��ѧ��ݣ�2λ��+���ֱ��루5λ��
	char name[50];//���� ������б�Ҫ�����ݼ���
	char sex[4]; //�Ա� 2ѡ1
	char countryName[20];//ö�����û�ѡ����ҵ����� 
	char nationName[10];//����������� 
	char birth[15];//��������
	int marriage;//ö�����û�ѡ�����״��  ����״�� 
	char politicsName[25];//ö�����û�ѡ��������ò
	char id[19];//���֤���� 
	int studentCategory;//ѧ����� ���� 
	int studentType;//ö�����û�ѡ��ѧ����ѧ��ʽ 
	char enterDay[15];//��ѧ���� 
	char collegeName[30];//ѧԺ���� 
	char majorName[20];//רҵ���Ƽ�ѧ�� 
	int grade;//�꼶
	int studyLength;//ѧ��
	char trainLevel[5];//�������
	char classNum[3];//�༶�� 01~10
	char teaacherName[10];//����Ա����
	int score;//ѧ���߿��ɼ�
	struct student *next;
}stu,*linkList;

void systemTime();//����ϵͳ������ʱ�� 

linkList intList(void);//��ʼ������

int nodeCount(stu *head);//ͳ����������Ľڵ��� 

void classMenu();//�����������   

void menu();//�˵����� 

int inType();// ����ʱ�Ӽ���¼�� ���Ǵ��ļ�

int ifRight(int a,int b,int c);//�ж��Ƿ�Ϊ�Ϸ�����  �Ϸ����� 1 ���Ϸ����� 0

int numCheck(char a[],stu *head,int count);//ѧ�ż���

int nameCheck(char a[]);//���ּ��� 

char *studentsNum(stu *head,stu *p,int count);//¼��ѧ��

char *studetsName(stu *head,stu *p,int count);//¼������

char *studentsSex(int count);//¼��ѧ���Ա�

char *studentsCountry(int count);//¼�������Ϣ

int birthCheck(int year,int month,int day);//�������ڵļ��� 

char *studentsNation(int count);//¼��������Ϣ

char *marType(int n);//���ػ������� 

int studentsMarriage(int count);//¼��ѧ������״��(����״������)

char *studentsPolitics(int count);//¼��������ò��Ϣ

int idCheck(char id[],stu *head);//��֤���֤�Ƿ��ظ� 

int idCheck2(char id[]);////��֤���һλ���֤��У����

int idCheck1(char id[],int n,int year,int month,int day,char s[]);//�����֤ �Ա� �������� 

char *stuCategory(int n);//����ѧ�����

int studentsCategory(int count);//¼��ѧ�����

char *studentsEnterDay(int count,char num1[]);//¼��ѧ����ѧ����

char *studentsTypeName(int n);//����ѧ����ѧ��ʽ���������� 

int studentsType(int count);//����ѧ����ѧ��ʽ���� 

char *studentsId(int count,stu *head,int m,char b[],char s[]);//¼��ѧ�������֤��Ϣ

char *studentsCollege(int count);//¼��ѧԺ��Ϣ

char *studentsMajor(int count);//¼��רҵ��ѧ����Ϣ

int studentsGrade(int count,char nu[]);//����ѧ������ѧ�꼶

int studentsLength(int count);//¼��ѧ��  

char *studentsTrainLevel(int count);//¼��ѧ����������� 

char *studentsClass(int count);//¼��ѧ���༶��01~10

char *studentsTeacher(int count);//¼�븨��Ա��Ϣ 

int studentsExam(int count);//¼��߿��ɼ� 

linkList informationIn();//¼��ѧ����Ϣ

void ShowMainInformation(stu *head);//չʾ��Ҫ��Ϣ ����ѧ������Լ����� 

void DecideoutInformation(int n,stu *head,int count);//����ѡ������û���Ҫ�Ķ���

void referInformation(stu *head);//��ѯ��Ϣ

int delType();//����ɾ��ѧ����Ϣ�ķ�ʽ

int countList(stu *head);//ͳ����������Ľ����Ŀ 

linkList delSingleStuents(stu *head);//ɾ������ѧ����Ϣ 

//linkList delMajorGrade(stu *head);//ɾ��רҵ+�꼶��ѧ����Ϣ

linkList  delInformation(stu *head);//ɾ��ѧ����Ϣ 

linkList modifInformation(stu *head);//�޸�ѧ����Ϣ

linkList addInformation(stu *head);//����ѧ����Ϣ

int anaylyzeType();//���ط���ѧ����Ϣ�ķ�ʽ

void analyzeCountry(stu *head);//���չ��ҷ��� 

void analyzeNation(stu *head);//����������� 

void analyzeInformation(stu *head);//ͳ�ƣ�������Ϣ 
 
linkList sortNum(stu *head);//ѧ������

linkList sortAge(stu *head);//�����С����

linkList sortAge(stu *head,int type);//�߿��ɼ�����
 
linkList sortInformation(stu *head);//����ѧ����Ϣ

void showInformation(stu *head);//ȫ����Ϣ�������Ļ 

void ToFileInformation(stu *head);//��ѧ����Ϣ���뵽�ļ���

void freeList(stu *head);//�ͷ�����

#endif


