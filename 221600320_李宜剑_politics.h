/*#ifndef _221600320_李宜剑_POLITICS_H
#define _221600320_李宜剑_POLITICS_H*/

#include <stdio.h>
#include <stdlib.h> //函数system需要

//政治面貌名称的最大长度
#define MAX_POLITICS_NAME_LEN 25
//政治面貌最大数目
#define MAX_POLITICS_NUM      13
//默认政治面貌代码01（共青团员）
#define DEFAULT_CODE2 01
//存放政治面貌代码、名称对照表的文件
#define FNAME2 "221600320_李宜剑_PoliticsCodeName.txt"

//存放政治面貌代码和政治面貌名称
struct Politics{
    int code2;
    char name[MAX_POLITICS_NAME_LEN+1];
};

//功    能：将存放政治面貌代码、名称对照表的文件读入数组politics中
//入口参数：politics存放政治面貌代码、名称对照表的(结构)数组
//返    回：政治面貌代码、名称对照表的记录条数
int getPoliticsTable(struct Politics politics[]);

//功    能：显示政治面貌代码、名称对照表
//入口参数：politics存放政治面貌代码、名称对照表的(结构)数组
//          n存放政治面貌代码、名称对照表的(结构)数组的长度
//返    回：无
void showPoliticsTable(struct Politics politics[],int n);

//功    能：返回(用户输入的)政治面貌代码对应的数组下标
//入口参数：politics存放政治面貌代码、名称对照表的(结构)数组
//          n存放政治面貌代码、名称对照表的(结构)数组的长度
//          code2(用户输入的)待判断的政治面貌代码
//返    回：政治面貌代码存在返回其对应的下标，否则返回-1
int getIndexOfCode2(struct Politics politics[],int n,int code2);

//功    能：跳过本行剩余的其他字符和<回车>键
//入口参数：无
//返    回：无
void eatLine2(void);

//功    能：获得(用户输入的)政治面貌代码对应的数组下标
//入口参数：politics存放政治面貌代码、名称对照表的(结构)数组
//          n存放政治面貌代码、名称对照表的(结构)数组的长度
//返    回：用户输入的政治面貌代码在政治面貌表中对应的下标
int getIndexOfChoice2(struct Politics politics[],int n);

//#endif
