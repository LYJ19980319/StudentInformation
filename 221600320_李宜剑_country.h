/*#ifndef _221600320_���˽�_COUNTRY_H_
#define _221600320_���˽�_COUNTRY_H_*/

#include <stdio.h>
#include <stdlib.h> //����system��Ҫ

//�������Ƶ���󳤶�
#define MAX_COUNTRY_NAME_LEN 20
//���������Ŀ
#define MAX_COUNTRY_NUM      12
//Ĭ�Ϲ��Ҵ���01���й���
#define DEFAULT_CODE1 01
//��Ź��Ҵ��롢���ƶ��ձ���ļ�
#define FNAME1 "221600320_���˽�_CountryCodeName.txt"

//��Ź��Ҵ���͹�������
struct Country {
    int code1;
    char name[MAX_COUNTRY_NAME_LEN+1];
};

//��    �ܣ�����Ź��Ҵ��롢���ƶ��ձ���ļ���������country��
//��ڲ�����country��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
//��    �أ����Ҵ��롢���ƶ��ձ�ļ�¼����
int getCountryTable(struct Country country[]);

//��    �ܣ���ʾ���Ҵ��롢���ƶ��ձ�
//��ڲ�����country��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
//          n��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ���
void showCountryTable(struct Country country[],int n);

//��    �ܣ�����(�û������)���Ҵ����Ӧ�������±�
//��ڲ�����country��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
//          n��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����ĳ���
//          code1(�û������)���жϵĹ��Ҵ���
//��    �أ����������ڷ������Ӧ���±꣬���򷵻�-1
int getIndexOfCode1(struct Country country[],int n,int code1);

//��    �ܣ���������ʣ��������ַ���<�س�>��
//��ڲ�������
//��    �أ���
void eatLine1(void);

//��    �ܣ����(�û������)���Ҵ����Ӧ�������±�
//��ڲ�����country��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
//          n��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ��û�����Ĺ��Ҵ����ڹ��ұ��ж�Ӧ���±�
int getIndexOfChoice1(struct Country country[],int n);

//#endif
