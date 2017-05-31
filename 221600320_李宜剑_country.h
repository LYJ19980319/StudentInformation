/*#ifndef _221600320_李宜剑_COUNTRY_H_
#define _221600320_李宜剑_COUNTRY_H_*/

#include <stdio.h>
#include <stdlib.h> //函数system需要

//国家名称的最大长度
#define MAX_COUNTRY_NAME_LEN 20
//国家最大数目
#define MAX_COUNTRY_NUM      12
//默认国家代码01（中国）
#define DEFAULT_CODE1 01
//存放国家代码、名称对照表的文件
#define FNAME1 "221600320_李宜剑_CountryCodeName.txt"

//存放国家代码和国家名称
struct Country {
    int code1;
    char name[MAX_COUNTRY_NAME_LEN+1];
};

//功    能：将存放国家代码、名称对照表的文件读入数组country中
//入口参数：country存放国家代码、名称对照表的(结构)数组
//返    回：国家代码、名称对照表的记录条数
int getCountryTable(struct Country country[]);

//功    能：显示国家代码、名称对照表
//入口参数：country存放国家代码、名称对照表的(结构)数组
//          n存放国家代码、名称对照表的(结构)数组的长度
//返    回：无
void showCountryTable(struct Country country[],int n);

//功    能：返回(用户输入的)国家代码对应的数组下标
//入口参数：country存放国家代码、名称对照表的(结构)数组
//          n存放国家代码、名称对照表的(结构)数组的长度
//          code1(用户输入的)待判断的国家代码
//返    回：民族代码存在返回其对应的下标，否则返回-1
int getIndexOfCode1(struct Country country[],int n,int code1);

//功    能：跳过本行剩余的其他字符和<回车>键
//入口参数：无
//返    回：无
void eatLine1(void);

//功    能：获得(用户输入的)国家代码对应的数组下标
//入口参数：country存放国家代码、名称对照表的(结构)数组
//          n存放国家代码、名称对照表的(结构)数组的长度
//返    回：用户输入的国家代码在国家表中对应的下标
int getIndexOfChoice1(struct Country country[],int n);

//#endif
