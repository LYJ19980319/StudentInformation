/*#ifndef _221600320_李宜剑_MAJOR_H_
#define _221600320_李宜剑_MAJOR_H_*/

#include <stdlib.h> //函数system需要

#define MAX_MAJOR_NAME_LEN 20

#define MAX_MAJOR_NUM  7

#define FNAME4 "221600320_李宜剑_MajorCodeName.txt"

struct Major{
	int code4;
	char name[MAX_MAJOR_NAME_LEN+1];
}; 

int getMajorTable(struct Major major[]);

void showMajorTable(struct Major major[],int n);

int getIndexOfCode4(struct Major major[],int n,int code4);

int getIndexOfchoice4(struct Major major[],int n);

//#endif
