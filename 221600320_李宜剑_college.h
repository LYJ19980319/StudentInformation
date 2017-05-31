/*#ifndef _221600320_李宜剑_COLLEGE_H
#define _221600320_李宜剑_COLLEGE_H*/

#include <stdio.h>
#include <stdlib.h> //函数system需要

#define MAX_COLLEGE_NAME_LEN 30

#define MAX_COLLEGE_NUM  23

#define FNAME3 "221600320_李宜剑_CollegeCodeName.txt"

struct College{
	int code3;
	char name[MAX_COLLEGE_NAME_LEN+1];
}; 

int getCollegeTable(struct College college[]);

void showCollegeTable(struct College college[],int n);

int getIndexOfCode3(struct College college[],int n,int code3);


int getIndexOfchoice3(struct College college[],int n);

//#endif
