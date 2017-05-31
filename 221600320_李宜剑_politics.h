/*#ifndef _221600320_���˽�_POLITICS_H
#define _221600320_���˽�_POLITICS_H*/

#include <stdio.h>
#include <stdlib.h> //����system��Ҫ

//������ò���Ƶ���󳤶�
#define MAX_POLITICS_NAME_LEN 25
//������ò�����Ŀ
#define MAX_POLITICS_NUM      13
//Ĭ��������ò����01��������Ա��
#define DEFAULT_CODE2 01
//���������ò���롢���ƶ��ձ���ļ�
#define FNAME2 "221600320_���˽�_PoliticsCodeName.txt"

//���������ò�����������ò����
struct Politics{
    int code2;
    char name[MAX_POLITICS_NAME_LEN+1];
};

//��    �ܣ������������ò���롢���ƶ��ձ���ļ���������politics��
//��ڲ�����politics���������ò���롢���ƶ��ձ��(�ṹ)����
//��    �أ�������ò���롢���ƶ��ձ�ļ�¼����
int getPoliticsTable(struct Politics politics[]);

//��    �ܣ���ʾ������ò���롢���ƶ��ձ�
//��ڲ�����politics���������ò���롢���ƶ��ձ��(�ṹ)����
//          n���������ò���롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ���
void showPoliticsTable(struct Politics politics[],int n);

//��    �ܣ�����(�û������)������ò�����Ӧ�������±�
//��ڲ�����politics���������ò���롢���ƶ��ձ��(�ṹ)����
//          n���������ò���롢���ƶ��ձ��(�ṹ)����ĳ���
//          code2(�û������)���жϵ�������ò����
//��    �أ�������ò������ڷ������Ӧ���±꣬���򷵻�-1
int getIndexOfCode2(struct Politics politics[],int n,int code2);

//��    �ܣ���������ʣ��������ַ���<�س�>��
//��ڲ�������
//��    �أ���
void eatLine2(void);

//��    �ܣ����(�û������)������ò�����Ӧ�������±�
//��ڲ�����politics���������ò���롢���ƶ��ձ��(�ṹ)����
//          n���������ò���롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ��û������������ò������������ò���ж�Ӧ���±�
int getIndexOfChoice2(struct Politics politics[],int n);

//#endif
