/*#ifndef _221600320_���˽�_TEACHER_H
#define _221600320_���˽�_TEACHER_H*/

#include <stdlib.h> //����system��Ҫ

#define MAX_TEACHER_NAME_LEN 10

#define MAX_TEACHER_NUM  5

#define FNAME5 "221600320_���˽�_TeacherCodeName.txt"

struct Teacher{
	int code5;
	char name[MAX_TEACHER_NAME_LEN+1];
}; 

int getTeacherTable(struct Teacher teacher[]);

void showTeacherTable(struct Teacher teacher[],int n);

int getIndexOfCode5(struct Teacher teacher[],int n,int code5);

int getIndexOfchoice5(struct Teacher teacher[],int n);

//#endif
