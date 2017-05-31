#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include<math.h>
#include<windows.h>
#include<ctype.h>
#include<conio.h>
#include "221600320_李宜剑_student.h"
#include "221600320_李宜剑_nation.h"
#include "221600320_李宜剑_country.h"
#include "221600320_李宜剑_politics.h"
#include "221600320_李宜剑_college.h"
#include "221600320_李宜剑_major.h" 
#include "221600320_李宜剑_teacher.h" 
#define N 2000

int main(void)
{
	stu *head;
	if((head=intList())==NULL)
	{
			return NULL; 
	}//没有足够的内存，申请空间失败
	int n;//输入的选择序号
	do{
		menu();
		printf("请选择相应的序号进行相关的功能操作:");
		scanf("%d",&n);
		if(n==0) break;
		switch(n)
		{
			case 1:
			{
				head=informationIn();//录入信息 
				break;
			}
			case 2:
			{
				referInformation(head);//查询信息
				break;
			}
			case 3:
			{
				 modifInformation(head);//修改学生信息
				 break;
			}
			case 4:
			{
				delInformation(head);//删除信息 
				break;	
			}
			case 5:
			{
				addInformation(head);//增加学生信息
				break; 
			}
			case 6:
			{
				analyzeInformation(head);//统计，分析信息 
				break;
			 } 
			case 7:
			{
				sortInformation(head);//排序学生信息
				break;	
			}
			case 8:
			{
				showInformation(head);//将学生信息输出到屏幕上 
				break;
			}
			case 9:
			{
				ToFileInformation(head);//将学生信息输入到文件中
				break;	
			}	
		}
		putchar('\n');
		system("PAUSE");
		system("cls");//清屏
	}while(n!=0);
	
	freeList(head);//释放链表
	printf("\n链表已释放\n"); 
	
	
}
