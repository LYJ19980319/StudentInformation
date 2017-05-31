/*#ifndef _221600320_李宜剑_TEACHER_H
#define _221600320_李宜剑_TEACHER_H*/

#include <stdlib.h> //函数system需要

#define MAX_TEACHER_NAME_LEN 10

#define MAX_TEACHER_NUM  5

#define FNAME5 "221600320_李宜剑_TeacherCodeName.txt"

struct Teacher{
	int code5;
	char name[MAX_TEACHER_NAME_LEN+1];
}; 

int getTeacherTable(struct Teacher teacher[]);

void showTeacherTable(struct Teacher teacher[],int n);

int getIndexOfCode5(struct Teacher teacher[],int n,int code5);

int getIndexOfchoice5(struct Teacher teacher[],int n);

//#endif
