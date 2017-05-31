/*#ifndef _221600320_���˽�_NATION_H
#define _221600320_���˽�_NATION_H*/

#include <stdio.h>
#include <stdlib.h> //����system��Ҫ

//�������Ƶ���󳤶�
#define MAX_NATION_NAME_LEN 10
//���������Ŀ
#define MAX_NATION_NUM      56+2
//Ĭ���������01�����壩
#define DEFAULT_CODE 01
//���������롢���ƶ��ձ���ļ�
#define FNAME "221600320_���˽�_NationCodeName.txt"

//�������������������
struct Nation {
    int code;
    char name[MAX_NATION_NAME_LEN+1];
};

//��    �ܣ������������롢���ƶ��ձ���ļ���������nation��
//��ڲ�����nation���������롢���ƶ��ձ��(�ṹ)����
//��    �أ�������롢���ƶ��ձ�ļ�¼����
int getNationTable(struct Nation nation[]);

//��    �ܣ���ʾ������롢���ƶ��ձ�
//��ڲ�����nation���������롢���ƶ��ձ��(�ṹ)����
//          n���������롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ���
void showNationTable(struct Nation nation[],int n);

//��    �ܣ�����(�û������)��������Ӧ�������±�
//��ڲ�����nation���������롢���ƶ��ձ��(�ṹ)����
//          n���������롢���ƶ��ձ��(�ṹ)����ĳ���
//          code(�û������)���жϵ��������
//��    �أ����������ڷ������Ӧ���±꣬���򷵻�-1
int getIndexOfCode(struct Nation nation[],int n,int code);

//��    �ܣ���������ʣ��������ַ���<�س�>��
//��ڲ�������
//��    �أ���
void eatLine(void);

//��    �ܣ����(�û������)��������Ӧ�������±�
//��ڲ�����nation���������롢���ƶ��ձ��(�ṹ)����
//          n���������롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ��û���������������������ж�Ӧ���±�
int getIndexOfChoice(struct Nation nation[],int n);

//#endif
