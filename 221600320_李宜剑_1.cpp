#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include<math.h>
#include<windows.h>
#include<ctype.h>
#include<conio.h>
#include "221600320_���˽�_student.h"
#include "221600320_���˽�_nation.h"
#include "221600320_���˽�_country.h"
#include "221600320_���˽�_politics.h"
#include "221600320_���˽�_college.h"
#include "221600320_���˽�_major.h" 
#include "221600320_���˽�_teacher.h" 
#define N 2000

int main(void)
{
	stu *head;
	if((head=intList())==NULL)
	{
			return NULL; 
	}//û���㹻���ڴ棬����ռ�ʧ��
	int n;//�����ѡ�����
	do{
		menu();
		printf("��ѡ����Ӧ����Ž�����صĹ��ܲ���:");
		scanf("%d",&n);
		if(n==0) break;
		switch(n)
		{
			case 1:
			{
				head=informationIn();//¼����Ϣ 
				break;
			}
			case 2:
			{
				referInformation(head);//��ѯ��Ϣ
				break;
			}
			case 3:
			{
				 modifInformation(head);//�޸�ѧ����Ϣ
				 break;
			}
			case 4:
			{
				delInformation(head);//ɾ����Ϣ 
				break;	
			}
			case 5:
			{
				addInformation(head);//����ѧ����Ϣ
				break; 
			}
			case 6:
			{
				analyzeInformation(head);//ͳ�ƣ�������Ϣ 
				break;
			 } 
			case 7:
			{
				sortInformation(head);//����ѧ����Ϣ
				break;	
			}
			case 8:
			{
				showInformation(head);//��ѧ����Ϣ�������Ļ�� 
				break;
			}
			case 9:
			{
				ToFileInformation(head);//��ѧ����Ϣ���뵽�ļ���
				break;	
			}	
		}
		putchar('\n');
		system("PAUSE");
		system("cls");//����
	}while(n!=0);
	
	freeList(head);//�ͷ�����
	printf("\n�������ͷ�\n"); 
	
	
}
