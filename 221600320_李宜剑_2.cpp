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

void systemTime()//����ϵͳ������ʱ�� 
{
	time_t Curtime = (time_t)0;//����ʱ����� ���ҵõ�����ʱ�� 
   	struct tm* Rettime = NULL;
   	time(&Curtime);
	Rettime=localtime(&Curtime); //�õ�ϵͳʱ�� 
	
	const char *week[]={"��","һ","��","��","��","��","��"};
	printf("\n\r��ǰ���ڡ�ʱ��:%04d-%02d-%02d (����%s) %02d:%02d:%02d",
		Rettime->tm_year + 1900,Rettime->tm_mon + 1,Rettime->tm_mday,week
		[Rettime->tm_wday],Rettime->tm_hour,Rettime->tm_min ,Rettime->tm_sec);
		
	Sleep(100);	
}

linkList intList(void)//��ʼ������  
{
	stu *p;
	if((p=(stu *)malloc(sizeof(stu)))==NULL)
	{
		printf("����ռ�ʧ��!\n");
		return NULL;
	}
	p->next = NULL;//��ʾ��β
	return p; 
}

int nodeCount(stu *head)//ͳ�ƽڵ���Ŀ
{
	int i=0;
	stu *p;
	for(p=head->next;p!=NULL;p=p->next)
		i++;
	return i;	
 } 

void classMenu()//����������� 
{
	printf("1.ѧ��             2.����         3.�Ա�             4.����      \n");
	printf("5.��������         6.����         7.����״��         8.������ò  \n");
	printf("9.���֤����       10.ѧ�����    11.ѧ����ѧ����    12.��ѧ��ʽ \n");
	printf("13.ѧԺ����        14.רҵ����    15.�꼶            16.ѧ��     \n");
	printf("17.�������        18.�༶        19.����Ա          20.�߿��ɼ� \n");
}

void menu()//�˵����� 
{
	systemTime();//��ʾ��ǰϵͳʱ�� 
	//��ʾ�Լ���Ȩ��Ϣ
	printf("\nCopyright 2016-2019 ���˽� 221600320 All Rights Reserved.\n");
	printf("***********************************************************\n");
	printf("**              ��Уѧ����Ϣϵͳ                         **\n");
	printf("**                                                       **\n");
	printf("**    1.¼��ѧ�����������Ϣ                             **\n");
	printf("**    2.��ѯѧ�����������Ϣ                             **\n");
	printf("**    3.�޸�ѧ�����������Ϣ                             **\n");
	printf("**    4.ɾ��ѧ�����������Ϣ                             **\n");
	printf("**    5.���ѧ�����������Ϣ                             **\n");
	printf("**    6.ͳ�ơ�����ѧ�����������Ϣ                       **\n");
	printf("**    7.����ѧ�Ż�����������ѧ�����������Ϣ             **\n");
	printf("**    8.���ѧ������Ϣ����Ļ��                           **\n");
	printf("**    9.���ѧ������Ϣ���ļ�                             **\n");
	printf("**    0.�˳�ϵͳ                                         **\n");
	printf("**                                                       **\n");
	printf("***********************************************************\n");
	
}

int inType()// ����ʱ�Ӽ���¼�� ���Ǵ��ļ�
{
	int a;
	int flag=1; 
	do{
		printf("1.�Ӽ�������ѧ������Ϣ\n");
		printf("2.���ļ�����ѧ������Ϣ\n");
		printf("��ѡ��:");
		scanf("%d",&a);
		if(a==1||a==2)
			flag=1;
		else
		{
			printf("�������������ѡ��:\n");
			flag=0;
		 } 	
	}while(!flag);
	
	return a;	
} 

int ifRight(int a,int b,int c)//�ж��Ƿ�Ϊ�Ϸ�����  �Ϸ����� 1 ���Ϸ����� 0
{
	if(b==2)//���ں��ж��·ݵ��������� Ҫ������ǲ�������  
	{	   //���������������29�� ������28��
		if( (a%4==0 && a%100!=0) || a%400==0 )
		{
			if( 1<=c && c<=29 )
				return 1; 
			else
				return 0;	
		}
		else 
		{
			if( 1<=c && c<=28 )
				return 1;
			else
				return 0;	
		}
	}
	
	if( b==1 || b==3 || b==5 || b==7 || b==8 || b==10 || b==12 ) 
	{	//�����·ݺ������ �Ƿ�Ϸ� ����2�·� �����·� ���� 31�� С�� 20��
		if( 1<=c && c<=31 )
			return 1;
		else
			return 0;	
	}
	else
	{
		if( 1<=c && c<=30 )
			return 1;
		else
			return 0;	
	}
}

int numCheck(char a[],stu *head,int count)//ѧ�ż��� 
{
	stu *p=NULL;
	int i,j,len=strlen(a),flag=0;
	if(len!=9)//�ж��ǲ���9���ַ� 
		return 0;
	if(len==9)
	{
		for(p=head->next,j=1;j<count;p=p->next,j++)//�������� 
		{
			if(strcmp(a,p->num )==0)//�ж����ѧ����֮ǰ�ǲ����Ѿ����ֹ���
			{
				return 0;
				break;
			}
		}
		for(i=0;i<len;i++)
		{
			if(!isdigit(a[i]))//�ж��ǲ������֣�ѧ��ֻ�������� 
			{
				return 0;
				break;
			}
		}
		return 1;
	}
}

int nameCheck(char a[])//���ּ��� 
{
	int i,n=strlen(a);
	for (i = 0; i < n; i++)
	{
		if(isalpha(a[i])||isdigit(a[i])||n<4||n>40||isdigit(a[i])) 
		{//����������������ĸ����С��2���ֻ��ߴ���20���� �ͷ���0
			return 0;
			break;
		}
		else 
			return 1;
	}
}

char *studentsNum(stu *head,stu *p,int count)//¼��ѧ��
{
	int flag=1;
	static char temp[10];//��ʱ�洢ѧ�� 
	do{
		if(flag==0)
			printf("\nѧ��������������������:"); 
		else 
			printf("\n������ѧ��%dѧ��:",count);
			scanf("%s",temp);
			getchar();
			flag=numCheck(temp,head,count); 
	}while(!flag);
	return temp;	
 } 

char *studetsName(stu *head,stu *p,int count)//¼������
{
	int flag=1;
	static char temp[40];
	do{ 
		if(flag==0)
			printf("\n����������������������:");
		else
			printf("\n������ѧ��%d����:",count);
			scanf("%s",temp);
			getchar();
			flag=nameCheck(temp);		 
	}while(!flag);
	
	return temp;	
 } 
 
char *studentsSex(int count)//¼��ѧ���Ա�
{
	int flag=1;
	static char tempSex[4];
	do{//�Ա��¼�� 
		int sex;
		printf("\n�����ѡ�������Ա�:\n");
		printf("\n1.�� 2.Ů");
		printf("\n�������Ա�:");
		scanf("%d",&sex);
		if(sex==1) 
		{
			strcpy(tempSex,"��");
			printf("ѧ��%d�Ա�:��\n",count);
			flag=1;
		}
		else if(sex==2)
		{
			strcpy(tempSex,"Ů");
			printf("ѧ��%d�Ա�:Ů\n",count);
			flag=1;
		}
		else if (sex!=1||sex!=2)
		{
			flag=0;
			printf("�Ա���������������ѡ��:");	
		}
	}while(!flag);
	printf("\n");	
	return tempSex;
} 

//��    �ܣ�����Ź��Ҵ��롢���ƶ��ձ���ļ���������country��
//��ڲ�����country��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
//��    �أ����Ҵ��롢���ƶ��ձ�ļ�¼����
int getCountryTable(struct Country country[]) {
    FILE *fp=fopen(FNAME1,"r");
    if (fp==NULL) {
        fprintf(stderr,"\a��Ź��Ҵ��롢���ƶ��ձ���ļ�[%s]�����ڣ�\n",FNAME1);
        exit(-1);
    }
    int n=0;
    while (fscanf(fp,"%d %s",&country[n].code1,country[n].name)==2)
        n++;
    fclose(fp);
    return n;
}

//��    �ܣ���ʾ���Ҵ��롢���ƶ��ձ�
//��ڲ�����country��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
//          n��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ���
void showCountryTable(struct Country country[],int n) {
    for (int i=0;i<n;i++) {
        printf("[%02d]",country[i].code1);
        printf("%-*s",MAX_COUNTRY_NAME_LEN+2,country[i].name);
        if((i+1)%3==0)
			printf("\n"); 
    }
}

//��    �ܣ�����(�û������)���Ҵ����Ӧ�������±�
//��ڲ�����country��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
//          n��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����ĳ���
//          code1(�û������)���жϵĹ��Ҵ���
//��    �أ����Ҵ�����ڷ������Ӧ���±꣬���򷵻�-1
int getIndexOfCode1(struct Country country[],int n,int code1) {
    for (int i=0;i<n;i++) {
        if (country[i].code1==code1) return i;
    }
    return -1;
}

//��    �ܣ���������ʣ��������ַ���<�س�>��
//��ڲ�������
//��    �أ���
void eatLine1(void) {
    while (getchar()!='\n')
        continue;
}

//��    �ܣ����(�û������)���Ҵ����Ӧ�������±�
//��ڲ�����country��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
//          n��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ��û�����Ĺ��Ҵ����ڹ��ұ��ж�Ӧ���±�
int getIndexOfChoice1(struct Country country[],int n) {
    int code=0;   //�û�����Ĺ��Ҵ���
    int index=-1; //�û�����Ĺ��Ҵ����ڹ��ұ��ж�Ӧ���±�
    while (1) {
        showCountryTable(country,n); //��ʾ���Ҵ��롢���ƶ��ձ�
        
        if (code==0) printf("\n��");
        else         printf("\a\n�������������");
        printf("������Ҵ����<�س�>:");
        code=getchar(); 
        if (code!='\n') {
            ungetc(code,stdin);   //����<�س�>���������˻����뻺����
            scanf("%d",&code);
            eatLine();            //��������ʣ��������ַ���<�س�>��
        }
        else                      //�û�ֱ�Ӱ�<�س�>���õ�Ĭ��ֵ���й�
            code=DEFAULT_CODE1;    //Ĭ�Ϲ��Ҵ���01���й���
        
        if ((index=getIndexOfCode1(country,n,code))!=-1)
            break;                //�Ϸ��Ĺ��Ҵ���
        
        //system("cls"); //����
        code=-1;
    }
    
    return index;
}

char *studentsCountry(int count)//¼�������Ϣ
{
	fflush(stdin);
    //��Ź��Ҵ��롢���ƶ��ձ��(�ṹ)����
    static struct Country country[MAX_COUNTRY_NUM];
    
    //����Ź��Ҵ��롢���ƶ��ձ���ļ���������country��
    //n=���Ҵ��롢���ƶ��ձ�ļ�¼����
    int n=getCountryTable(country);
    
    //�û�����(ѡ��)����(����)
    //index=�û�����Ĺ��Ҵ����ڹ��ұ��ж�Ӧ���±�
    int index=getIndexOfChoice1(country,n);	
    
    printf("�������(ѧ��%d)�Ĺ����ǣ�[%02d]",count,country[index].code1);
    printf("%s\n",country[index].name);
    return country[index].name;
	
 } 

//�������ڼ��� 
int birthCheck(int year,int month,int day)
{
	if(month<0||month>12||day<0||day>31)
		return 0;
	else if(ifRight(year,month,day))//�ж��Ƿ����ںϷ� 
		return 1;
	else 
		return 0;		
	
 } 
 
char *studentsBirth(int count)
{
	int flag=1;
	int year,month,day;//������ַ���������������� 
	static char temp[15];//��ʱ������ų������� 
	do{
		printf("\n����ѧ��%d�ĳ�������(��ذ��ո�ʽ:xxxx.xx.xx):",count);
		scanf("%s",temp);
		//�ַ����������ת���� int ����� 
		year=(temp[0]-'0')*1000+(temp[1]-'0')*100+(temp[2]-'0')*10+(temp[3]-'0');
		month=(temp[5]-'0')*10+(temp[6]-'0');
		day=(temp[8]-'0')*10+(temp[9]-'0');
		if(birthCheck(year,month,day))//���ڵļ���
		{
			printf("��������:%s\n",temp);
			flag=1;
		}
		else
		{
			printf("������󣨻��߲��Ϸ������ڣ�,����������:\n");
			flag=0;
		 } 
	}while(!flag);
	printf("\n");
	return temp;
}

//��    �ܣ������������롢���ƶ��ձ���ļ���������nation��
//��ڲ�����nation���������롢���ƶ��ձ��(�ṹ)����
//��    �أ�������롢���ƶ��ձ�ļ�¼����
int getNationTable(struct Nation nation[]) {
    FILE *fp=fopen(FNAME,"r");
    if (fp==NULL) {
        fprintf(stderr,"\a���������롢���ƶ��ձ���ļ�[%s]�����ڣ�\n",FNAME);
        exit(-1);
    }
    int n=0;
    while (fscanf(fp,"%d %s",&nation[n].code,nation[n].name)==2)
        n++;
    fclose(fp);
    return n;
}

//��    �ܣ���ʾ������롢���ƶ��ձ�
//��ڲ�����nation���������롢���ƶ��ձ��(�ṹ)����
//          n���������롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ���
void showNationTable(struct Nation nation[],int n) {
    for (int i=0;i<n;i++) {
        printf("[%02d]",nation[i].code);
        printf("%-*s",MAX_NATION_NAME_LEN+2,nation[i].name);
        if((i+1)%5==0)
			printf("\n"); 
    }
}

//��    �ܣ�����(�û������)��������Ӧ�������±�
//��ڲ�����nation���������롢���ƶ��ձ��(�ṹ)����
//          n���������롢���ƶ��ձ��(�ṹ)����ĳ���
//          code(�û������)���жϵ��������
//��    �أ����������ڷ������Ӧ���±꣬���򷵻�-1
int getIndexOfCode(struct Nation nation[],int n,int code) {
    for (int i=0;i<n;i++) {
        if (nation[i].code==code) return i;
    }
    return -1;
}

//��    �ܣ���������ʣ��������ַ���<�س�>��
//��ڲ�������
//��    �أ���
void eatLine(void) {
    while (getchar()!='\n')
        continue;
}

//��    �ܣ����(�û������)��������Ӧ�������±�
//��ڲ�����nation���������롢���ƶ��ձ��(�ṹ)����
//          n���������롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ��û���������������������ж�Ӧ���±�
int getIndexOfChoice(struct Nation nation[],int n) {
    int code=0;   //�û�������������
    int index=-1; //�û���������������������ж�Ӧ���±�
    while (1) {
        showNationTable(nation,n); //��ʾ������롢���ƶ��ձ�
        
        if (code==0) printf("\n��");
        else         printf("\a\n�������������");
        printf("��������<�س�>:");
        code=getchar(); 
        if (code!='\n') {
            ungetc(code,stdin);   //����<�س�>���������˻����뻺����
            scanf("%d",&code);
            eatLine();            //��������ʣ��������ַ���<�س�>��
        }
        else                      //�û�ֱ�Ӱ�<�س�>���õ�Ĭ��ֵ������
            code=DEFAULT_CODE;    //Ĭ���������01�����壩
        
        if ((index=getIndexOfCode(nation,n,code))!=-1)
            break;                //�Ϸ����������
        
        //system("cls"); //����
        code=-1;
    }
    
    return index;
}

char *studentsNation(int count)//¼��������Ϣ
{
	fflush(stdin);
    //���������롢���ƶ��ձ��(�ṹ)����
    static struct Nation nation[MAX_NATION_NUM];
    
    //�����������롢���ƶ��ձ���ļ���������nation��
    //n=������롢���ƶ��ձ�ļ�¼����
    int n=getNationTable(nation);
    
    //�û�����(ѡ��)����(����)
    //index=�û���������������������ж�Ӧ���±�
    int index=getIndexOfChoice(nation,n);	
    
    printf("�������(ѧ��%d)�������ǣ�[%02d]",count,nation[index].code);
    printf("%s\n",nation[index].name);
    return nation[index].name;
	
 } 
 
char *marType(int n)//���ػ������� 
{
	static char temp[4];
    char mar[6][6]={"0","δ��","�ѻ�","ɥż","���","����"};
    strcpy(temp,mar[n]);
    return temp;
}

int studentsMarriage(int count)//¼��ѧ������״��(����״������)
{
	int flag=1;
	int temp;
	do{//����״����¼�� 
		//fflush(stdin);
		char c;
		printf("\n");
		printf("������ѧ��%d�Ļ���״��(Ĭ��Ϊδ��):\n",count);
		printf("1.δ�� 2.�ѻ� 3.ɥż 4.��� 5.����\n");
		fflush(stdin);
		if((c=getchar())=='\n')
		{
		   temp=1;
			printf("����״��Ϊ:%s\n",marType(1));
			flag=1;
		}
		else if('c'-'0'>'0'&&'c'-'0'<='5')
		{
			temp =c-'0';
			printf("����״��Ϊ:%s\n",marType(c-'0'));
			flag=1;
		} 
		else
		{
		   printf("�����������������:\n");
		   flag=0;
		}
						
	}while(!flag);
	printf("\n");
	return temp;	
	
 } 
 
//��    �ܣ������������ò���롢���ƶ��ձ���ļ���������politic��
//��ڲ�����politi���������ò���롢���ƶ��ձ��(�ṹ)����
//��    �أ�������ò���롢���ƶ��ձ�ļ�¼����
int getPoliticsTable(struct Politics politics[]) {
    FILE *fp=fopen(FNAME2,"r");
    if (fp==NULL) {
        fprintf(stderr,"\a���������ò���롢���ƶ��ձ���ļ�[%s]�����ڣ�\n",FNAME2);
        exit(-1);
    }
    int n=0;
    while (fscanf(fp,"%d %s",&politics[n].code2,politics[n].name)==2)
        n++;
    fclose(fp);
    return n;
}

//��    �ܣ���ʾ������ò���롢���ƶ��ձ�
//��ڲ�����politics���������ò���롢���ƶ��ձ��(�ṹ)����
//          n���������ò���롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ���
void showPoliticsTable(struct Politics politics[],int n) {
	fflush(stdin);
    for (int i=0;i<n;i++) {
        printf("[%02d]",politics[i].code2);
        printf("%-*s",MAX_POLITICS_NAME_LEN+2,politics[i].name); 
        if((i+1)%2==0)
			printf("\n"); 
    }
}

//��    �ܣ�����(�û������)������ò�����Ӧ�������±�
//��ڲ�����politics���������ò���롢���ƶ��ձ��(�ṹ)����
//          n���������ò���롢���ƶ��ձ��(�ṹ)����ĳ���
//          code2(�û������)���жϵ�������ò����
//��    �أ�������ò������ڷ������Ӧ���±꣬���򷵻�-1
int getIndexOfCode2(struct Politics politics[],int n,int code2) {
    for (int i=0;i<n;i++) {
        if (politics[i].code2==code2) return i;
    }
    return -1;
}

//��    �ܣ���������ʣ��������ַ���<�س�>��
//��ڲ�������
//��    �أ���
void eatLine2(void) {
    while (getchar()!='\n')
        continue;
}

//��    �ܣ����(�û������)������ò�����Ӧ�������±�
//��ڲ�����politics���������ò���롢���ƶ��ձ��(�ṹ)����
//          n���������ò���롢���ƶ��ձ��(�ṹ)����ĳ���
//��    �أ��û������������ò������������ò���ж�Ӧ���±�
int getIndexOfChoice2(struct Politics politics[],int n) {
    int code=0;   //�û������������ò����
    int index=-1; //�û������������ò������������ò���ж�Ӧ���±�
    while (1) {
        showPoliticsTable(politics,n); //��ʾ������ò���롢���ƶ��ձ�
        
        if (code==0) printf("\n��");
        else         printf("\a\n�������������");
        printf("��������<�س�>:");
        code=getchar(); 
        if (code!='\n') {
            ungetc(code,stdin);   //����<�س�>���������˻����뻺����
            scanf("%d",&code);
            eatLine();            //��������ʣ��������ַ���<�س�>��
        }
        else                      //�û�ֱ�Ӱ�<�س�>��
			code=DEFAULT_CODE2;	//�õ�Ĭ��ֵ���й��������干����Ա 
              				  //Ĭ��������ò����03 �й��������干����Ա
        
        if ((index=getIndexOfCode2(politics,n,code))!=-1)
            break;                //�Ϸ���������ò����
        
        //system("cls"); //����
        code=-1;
    }
    
    return index;
}

char *studentsPolitics(int count)//¼��������ò��Ϣ
{
	fflush(stdin);
    //���������ò���롢���ƶ��ձ��(�ṹ)����
    static struct Politics politics[MAX_POLITICS_NUM];
    
    //�����������ò���롢���ƶ��ձ���ļ�����politic������
    //n=������ò�����ƶ��ձ�ļ�¼����
    int n=getPoliticsTable(politics);
    
    //�û�����(ѡ��)������ò(����)
    //index=�û������������ò������������ò���ж�Ӧ���±�
    int index=getIndexOfChoice2(politics,n);	
    
    printf("�������(ѧ��%d)��������ò�ǣ�[%02d]",count,politics[index].code2);
    printf("%s",politics[index].name);
    printf("\n");
    return politics[index].name;
	
 }  
 
 
int idCheck3(char id[],stu *head,int count)//��֤�Ƿ����֤�����ظ�
{//Id[] ���֤���� count�Ѿ�¼���ѧ���� 
	stu *p=NULL;
	int j; 
	for(p=head->next,j=1;j<count;p=p->next,j++)//�������� 
	{
		if(strcmp(id,p->id)==0)//�ж�������֤����֮ǰ�ǲ����Ѿ����ֹ���
		{
			return 0;
			break;
		}
	}
	return 1;
}  
  
int idCheck2(char id[])//��֤���һλ���֤��У����
{
	int i,sum=0;
	int remain;//���� 
	int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//ǰ17λ�ֱ�Ҫ���Ե�ϵ�� 
	int b[12]={1,0,0,9,8,7,6,5,4,3,2}; 
	for(i=0;i<17;i++)
	{
		sum+=(id[i]-'0')*a[i];
	}
	remain=sum%11;
	if(remain==2)
	{
		if(id[17]!='x')
			return 0;
	}
	else if((id[17]-'0')!=b[remain])
		return 0;
	else
		return 1;	
}
//���֤������Ϣ
//�������� �Ա� ���һλУ���� 
int idCheck1(char id[],int count,int year,int month,int day,char s[])
{
	int i;
	int sum1,sum2,sum3;//�ַ���������·� 
	if(!strcmp(s,"��"))
	{
		if((id[16]-'0')%2==0)
			return 0;
	}
	else if(!strcmp(s,"Ů"))
	{
		if((id[16]-'0')%2!=0)
			return 0;
	} 
	if(strlen(id)!=18)
		return 0;
	else if(!idCheck2(id))//�������ú����������һλ������
		return 0;
	else
	{
		for(i=0;i<=17;i++)
		{
			if(!isdigit(id[i]))
			{
				return 0;
				break;
			}
		}
		if(isdigit(id[17])||id[17]=='x')
		{
			sum1=(id[6]-'0')*1000+(id[7]-'0')*100+(id[8]-'0')*10+id[9]-'0';
			sum2=(id[10]-'0')*10+id[11]-'0';
			sum3=(id[12]-'0')*10+id[13]-'0';
			while(sum1!=year)
			{
				return 0;
				break;
			}
			while(sum2!=month)
			{
				return 0;
				break;
			}
			while(sum3!=day)
			{
				return 0;
				break;
			}
		}
	}
	return 1;	
} 

char *studentsId(int count,stu *head,int m,char b[],char s[])//¼��ѧ�������֤��Ϣ
{//m ������� s[]�����Ա� count����ѧ���� 
	fflush(stdin); 
	static char tempId[19];//��ʱ����������ID 
	int year,month,day;
	int flag=1;
	do{//���֤��¼�� 
		if(m!=1)
			break;
		printf("\n����ѧ��%d���֤����:",count);
		fflush(stdin);
		scanf("%s",tempId);

	    year=(tempId[6]-'0')*1000+(tempId[7]-'0')*100+(tempId[8]-'0')*10+(tempId[9]-'0');
	    month=(tempId[10]-'0')*10+(tempId[11]-'0');
	    day=(tempId[12]-'0')*10+(tempId[13]-'0');		
		if(!idCheck3(tempId,head,count))//�������ú����������֤�Ƿ��ظ�
		{
			printf("���֤�����ظ�������������:");
			flag=0;
		}	
		else if(idCheck1(tempId,count,year,month,day,s))
		{
			 printf("ID��ǰ����Ϣ���ϣ�������ȷ\n");
			flag=1;
		}
		else 
		{
			printf("ID��ǰ����Ϣ�����ϣ���������\n");
			flag=0;
		}
	}while(!flag);	
	return tempId;
 } 

char *stuCategory(int n)//����ѧ����� 
{
	static char temp[4];
    char stuc[5][10]={"0","����Ӧ��","��������","ũ��Ӧ��","ũ������",};
    strcpy(temp,stuc[n]);
    return temp;
}

int studentsCategory(int count)//¼��ѧ�����
{
	int flag=1;
	int x=0;
	do{//ѧ������¼�� 
		//fflush(stdin); 
		printf("\n");
		printf("1.����Ӧ��    2.��������    3.ũ��Ӧ��    4.ũ������\n"); 
		printf("��ѡ��ѧ��%d���:",count);
		scanf("%d",&x);
		if(x==1||x==2||x==3||x==4)
		{
			printf("ѧ�����:%s\n",stuCategory(x));
			flag=1;
			return x;
		 } 
		else
		{
			printf("�������������ѡ��:\n");
			flag=0;

		}
				
	}while(!flag);
 } 

char *studentsEnterDay(int count,char num1[])//¼��ѧ����ѧ����
{
	int flag=1;
	int year1,month1,day1;
	static char stuEnter[15];
	int idYear=(num1[2]-'0')*10+(num1[3]-'0')+2000;//����ѧ���������ݣ�
											//Ϊ���������׼�� 
	do{
		printf("\n����ѧ��%d��ѧ����(xxxx.xx.xx)8<=�·�<=10:",count);
		fflush(stdin);
		scanf("%s",stuEnter);
		//�ַ����������ת���� int ����� 
		year1=(stuEnter[0]-'0')*1000+(stuEnter[1]-'0')*100+(stuEnter[2]-'0')*10
				+(stuEnter[3]-'0');
		month1=(stuEnter[5]-'0')*10+(stuEnter[6]-'0');
		day1=(stuEnter[8]-'0')*10+(stuEnter[9]-'0');
		if(!ifRight(year1,month1,day1))//���������Ƿ�Ϸ� 
		{
			printf("�������ڲ��Ϸ�������������\n");
			flag=0;		
		}
		else if(month1<8||month1>10)
		{
			printf("�·ݲ��Ϸ�������������\n");
			flag=0;
		}
		else if(idYear!=year1)
		{
			printf("������룬��ѧ����ݲ�һ�£�����������\n");
			flag=0;
		}
		else
		{
			printf("��ѧ����:%s\n",stuEnter);
			flag=1;
		}
		
	}while(!flag);
	return stuEnter;//�������� 
 } 

char *studentsTypeName(int n)//����ѧ����ѧ��ʽ���������� 
{
	static char tempTypes[20];
	char type[15][20]={"0","��ͨ��ѧ","��������","ר����","������",
	"������","������","��ˮƽ�˶���","������","�վ�רҵ"};
	strcpy(tempTypes,type[n]);
	return tempTypes;
 } 

int studentsType(int count)//����ѧ����ѧ��ʽ���� 
{//count����ǰ�ڼ�λѧ�� 

	int tempType;//��ѧ����ѧ��ʽ���� 
	int flag=1;
	do{//ѧ����ѧ��ʽ��¼�� 
		FILE *fp;
		char s[255];
		char c;
		if((fp=fopen("221600320_���˽�_StudentType.txt","r"))==NULL)//���ļ� 
		{
			printf("���ļ�ʧ��\n");
		}
		printf("\n");
		while(fgets(s,6,fp))
		{
			printf("%s",s);
		}
		fclose(fp);
		printf("\n������ѧ��%d����ѧ��ʽ:",count);
		fflush(stdin);
		if((c=getchar())=='\n')//����ǻس���Ĭ�� 
		{
			tempType=1;
			printf("\nѧ��%d��ѧ��ʽ��:%s\n",count,studentsTypeName(1));
			flag=1;
		}
		else if(c)
		{
			tempType=c-'0';
			printf("\nѧ��%d��ѧ��ʽ��:%s\n",count,studentsTypeName(tempType));
			flag=1;
		}
		else
		{
			printf("������������������\n");
			flag=0;
		}
				
	}while(!flag);
	printf("\n");
	return 	tempType;
	
}

int getCollegeTable(struct College college[])
{
	FILE *fp=fopen(FNAME3,"r");
	if(fp==NULL)
	{
		fprintf(stderr,"\a���ѧԺ���롢���ƶ��ձ���ļ�[%s]������!\n",FNAME3);
		exit(-1); 
	 }
	 int n=0;
	 while(fscanf(fp,"%d %s",&college[n].code3,college[n].name)==2)
	 	n++;
	 fclose(fp);
	return n; 	
}

void showCollegeTable(struct College college[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("[%02d]",college[i].code3);
		printf("%-*s",MAX_COLLEGE_NAME_LEN+2,college[i].name);
		if((i+1)%2==0)
			printf("\n");
	}
}

int getIndexOfCode3(struct College college[],int n,int code3)
{
    for (int i=0;i<n;i++) {
        if (college[i].code3==code3) return i;
    }
    return -1;
}

int getIndexOfchoice3(struct College college[],int n)
{
	int code=0;
	int index=-1;
	while(1)
	{
		printf("\nѡ��ѧԺ(����ΪѧԺ���Ƹ�����):\n");
		showCollegeTable(college,n);
		if(code==0) printf("\n��");
		else		printf("\a\n�������������ѡ��");
		printf("��������<�س�>:");
		scanf("%d",&code);
		if ((index=getIndexOfCode3(college,n,code))!=-1)
			break;
		code=-1;	
	}
	return index;
}

char *studentsCollege(int count)//¼��ѧԺ��Ϣ
{
	fflush(stdin);
	static struct College college[MAX_COLLEGE_NUM];
	int n=getCollegeTable(college);
	int index=getIndexOfchoice3(college,n);
	
	printf("�������(ѧ��%d)��ѧԺ��:[%02d]",count,college[index].code3);
	printf("%s",college[index].name);
	printf("\n"); 
	return college[index].name;
	
 } 

int getMajorTable(struct Major major[])
{
	FILE *fp=fopen(FNAME4,"r");
	if(fp==NULL)
	{
		fprintf(stderr,"\a���רҵ���롢���ƶ��ձ���ļ�[%s]������!\n",FNAME4);
		exit(-1); 
	 }
	 int n=0;
	 while(fscanf(fp,"%d %s",&major[n].code4,major[n].name)==2)
	 	n++;
	 fclose(fp);
	return n; 	
}

void showMajorTable(struct Major major[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("[%02d]",major[i].code4);
		printf("%-*s",MAX_MAJOR_NAME_LEN+2,major[i].name);
		if((i+1)%2==0)
			printf("\n");
	}
}

int getIndexOfCode4(struct Major major[],int n,int code4)
{
    for (int i=0;i<n;i++) {
        if (major[i].code4==code4) return i;
    }
    return -1;
}

int getIndexOfchoice4(struct Major major[],int n)
{
	int code=0;
	int index=-1;
	while(1)
	{
		printf("\nѡ��רҵ(����Ϊרҵ���Ƹ�����):\n");
		showMajorTable(major,n);
		if(code==0) printf("\n��");
		else		printf("\a\n�������������ѡ��");
		printf("��������<�س�>:");
		scanf("%d",&code);
		if ((index=getIndexOfCode4(major,n,code))!=-1)
			break;
		code=-1;	
	}
	return index;
}

char *studentsMajor(int count)//¼��רҵ��Ϣ
{
	fflush(stdin);
	static struct Major major[MAX_MAJOR_NUM];
	int n=getMajorTable(major);
	int index=getIndexOfchoice4(major,n);
	
	printf("�������(ѧ��%d)��רҵ��:[%02d]",count,major[index].code4);
	printf("%s",major[index].name);
	printf("\n");
	return major[index].name;
	
 } 

int studentsGrade(int count,char nu[])//����ѧ������ѧ�꼶
{//count Ϊ��ǰ�ڼ�λѧ��  nu��ѧ����ѧ�� ���ڼ���
	int flag=1;
	int grad;//��ʾ�꼶 
	int m;//�����ѧ�ż���������꼶
	
	m=2000+(nu[2]-'0')*10+(nu[3]-'0');
	do{
		printf("\n������ѧ��%d���꼶:",count); 
		fflush(stdin);//������� 
		grad=getchar(); 
        if (grad!='\n') {
            ungetc(grad,stdin);  //����<�س�>���������˻����뻺����
            scanf("%d",&grad);
            eatLine();   //��������ʣ��������ַ���<�س�>��
            if(grad>2017||grad<2000)
            {
            	printf("����ʱ�������⣬����������\n");
            	flag=0;
			}
            else if(grad!=m)
            {
            	int x;
            	printf("\a�꼶%d��ѧ���ϵ��꼶��Ϣ��һ��\n",grad);
            	printf("1.ѡ�����������꼶��Ϣ\n2.���Ӳ�һ����Ϣ\n");
            	scanf("%d",&x);
            	if(x==1)
            		flag=0;
            	else
					flag=1;	
			}
			else if(grad==m)
			{
				printf("\n��ѧ����Ϣ����");
				flag=1;
			}
        }
        else //�û�ֱ�Ӱ�<�س�>���õ�Ĭ��ֵ��2000+��ѧ�š��ġ���ѧ��ݡ�
        {
        	grad=m;
        	printf("\nĬ���꼶Ϊ:%d\n",grad);
			flag=1;	
		}						
            		
	}while(!flag);
	
	return grad; 
} 

int studentsLength(int count)//¼��ѧ�� 
{
	int len;
	int flag=1;
	do{
		printf("\n\n");
		printf("������ѧ��%dѧ��(������Լ���רҵѧ��һ��) ��ʽ������:",count);
		fflush(stdin);//������� 
		len=getchar();
        if (len!='\n')
		{
            ungetc(len,stdin);  //����<�س�>���������˻����뻺����
            scanf("%d",&len);
            eatLine();   //��������ʣ��������ַ���<�س�>��
            printf("ѧ��Ϊ%d��\n",len);
            flag=1;
            
		}
		else //�û�ֱ�Ӱ�<�س�>���õ�Ĭ��ֵ��4�꣨ѧ�ƣ� 
        {
        	len=4; 
        	printf("\nĬ��ѧ��Ϊ:%d��\n",len);
			flag=1;	
		}		
			 
	}while(!flag);
	return len;
 } 

char *studentsTrainLevel(int count)//¼��ѧ�����������
{
	static char level[5];
	int flag=1;
	int lev;
	do{
		printf("\n��ѡ��ѧ��%d���������(Ĭ��Ϊ����):\n",count);
		printf("1.ר��  2.����  3.˶ʿ  4.��ʿ\n");
		fflush(stdin);//������� 
		lev=getchar();
		if(lev!='\n')
		{
			ungetc(lev,stdin);
			scanf("%d",&lev);
			eatLine();
			switch(lev)
			{
				case 1:
				{
					strcpy(level,"ר��");
					break; 
				}
				case 2:
				{
					strcpy(level,"����");
					break;
				}
				case 3:
				{
					strcpy(level,"˶ʿ");
					break;
				}
				case 4:
				{
					strcpy(level,"��ʿ"); 
					break;
				}
				default:
				{
					printf("�������\n");
					flag=0;
				 } 
			}
				
		}
		else
			strcpy(level,"����"); 
	}while(!flag);
	printf("ѡ����������Ϊ:%s\n",level);
	return level;
	
 } 

char *studentsClass(int count) //¼��ѧ���༶��01~10
{
	fflush(stdin); 
	static char tempClass[3];
	int flag=1;
	int c;
	do{
		printf("\n");
		printf("����ѧ��%d�İ༶��(01~10):",count);
		fflush(stdin);
		scanf("%s",tempClass);
		//printf("������༶Ϊ%s",tempClass);
		if(strlen(tempClass)!=2)
		{
			printf("\n������������������\n");
			flag=0;
		}
		else
		{
			c=(tempClass[0]-'0')*10+(tempClass[1]-'0');
			if(c>10||c<1)
			{
				printf("����Ϊ%d���ڷ�Χ��\n",c);
				printf("����������\n");
				flag=0;
			}
			else
			{
				printf("����Ϊ%d,��ȷ\n",c);
				flag=1;
			}
		}
	}while(!flag);
	return tempClass;	
 } 
 
int getTeacherTable(struct Teacher teacher[])
{
	FILE *fp=fopen(FNAME5,"r");
	if(fp==NULL)
	{
		fprintf(stderr,"\a��Ÿ���Ա���롢���ƶ��ձ���ļ�[%s]������!\n",FNAME5);
		exit(-1); 
	 }
	 int n=0;
	 while(fscanf(fp,"%d %s",&teacher[n].code5,teacher[n].name)==2)
	 	n++;
	 fclose(fp);
	return n; 	
}

void showTeacherTable(struct Teacher teacher[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("[%02d]",teacher[i].code5);
		printf("%-*s",MAX_TEACHER_NAME_LEN+2,teacher[i].name);
		if((i+1)%3==0)
			printf("\n");
	}
}

int getIndexOfCode5(struct Teacher teacher[],int n,int code5)
{
    for (int i=0;i<n;i++) {
        if (teacher[i].code5==code5) return i;
    }
    return -1;
}

int getIndexOfchoice5(struct Teacher teacher[],int n)
{
	int code=0;
	int index=-1;
	while(1)
	{
		printf("\nѡ�񸨵�Ա(����Ϊ����Ա���ָ�����):\n");
		showTeacherTable(teacher,n);
		if(code==0) printf("\n��");
		else		printf("\a\n�������������ѡ��");
		printf("��������<�س�>:");
		scanf("%d",&code);
		if ((index=getIndexOfCode5(teacher,n,code))!=-1)
			break;
		code=-1;	
	}
	return index;
}

char *studentsTeacher(int count)//¼�븨��Ա��Ϣ 
{
	fflush(stdin);
	static struct Teacher teacher[MAX_TEACHER_NUM];
	int n=getTeacherTable(teacher);
	int index=getIndexOfchoice5(teacher,n);
	
	printf("��������(ѧ��%d)����Ա��:[%02d]",count,teacher[index].code5);
	printf("%s",teacher[index].name);
	printf("\n");
	return teacher[index].name;
	
 }  
 
int studentsExam(int count)//¼��߿��ɼ�  
{
	int flag=1;
	int score;
	do{
		fflush(stdin);
		printf("\n����ѧ��%d�ĸ߿��ɼ�(��ʽ:������(0<����<750)):",count);
		scanf("%d",&score);
		
		if(score<0||score>750)
		{
			printf("\n�ɼ����ڷ�Χ�ڣ�����������\n");
			flag=0;
		}
		else
		{
			printf("\nѧ��%d�߿��ɼ���%d\n",count,score);
			flag=1;
		}
	}while(!flag);
	return score;
	
 } 
 
linkList informationIn()//¼��ѧ����Ϣ
{
	int x,count=1;//countͳ��ѧ���� xΪѡ��Ӽ���¼�뻹���ļ� 
	int m=1;//mΪ�Ƿ����������Ϣ�ı�־ 
	int flag1=0;//��Ϊ�����Ƿ����ı�־
	stu temp;//����һ����ʱ�ṹ����� 
	stu *head;
	stu *r; 
	head=(stu *)malloc(sizeof(stu));//����ͷ���ռ� 
	head->next=NULL;//��ʼ��һ��������
	r=head;
	FILE *pRead ;
	char anac[20]; 
	x=inType(); 
	if(x==1)//����¼����Ϣ 
	{
		printf("��ʼ¼����Ϣ:\n");
		while(m!=0)
		{
			stu *p;
			p=(stu *)malloc(sizeof(stu));//�����µĽ��
			p->
			strcpy(p->num,studentsNum(head,p,count));//ѧ����Ϣ 
			
			strcpy(p->name,studetsName(head,p,count));//������Ϣ
			
			strcpy(p->sex,studentsSex(count));//ѧ���Ա�
			
			strcpy(p->countryName,studentsCountry(count));//¼�������Ϣ 
			
			strcpy(p->birth,studentsBirth(count));//ѧ����������
			
			strcpy(p->nationName,studentsNation(count));//¼��ѧ��������Ϣ 
			
			p->marriage =studentsMarriage(count);//¼��ѧ������״��
			
			strcpy(p->politicsName,studentsPolitics(count));//¼��������ò 
			
			fflush(stdin);
			strcpy(anac,p->countryName) ;
			
			if(strcmp(anac,"�й�")!=1)
			{
				strcpy(p->id,"111111111111111111");
			}
			else
			strcpy(p->id,studentsId(count,head,p->marriage,p->birth,p->sex));
			//¼��ѧ�������֤��Ϣ	 ����marriage,birth sex ���ڼ��� 
			//רҵ ѧԺδ¼�� ��ȱ 
			p->studentCategory=studentsCategory(count);//ѧ��������
			
			strcpy(p->enterDay,studentsEnterDay(count,p->num));//ѧ����ѧʱ�� 
															//����ѧ�Ž�����֤					
			p->studentType=studentsType(count); //¼��ѧ����ѧ��ʽ 
			
			strcpy(p->collegeName,studentsCollege(count));//¼��ѧԺ
			
			strcpy(p->majorName,studentsMajor(count));//¼��רҵ 
			
			p->grade =studentsGrade(count,p->num);//¼���꼶 ѧ�����ڼ���
			
			p->studyLength=studentsLength(count);//¼��ѧ�� 
			
			strcpy(p->trainLevel,studentsTrainLevel(count));//¼��ѧ����������� 
			
			strcpy(p->classNum,studentsClass(count));//¼��ѧ���İ༶�� 
			
			strcpy(p->teaacherName,studentsTeacher(count));//¼�븨��Ա��Ϣ
			
			p->score=studentsExam(count);//¼��߿��ɼ� 
				
			//getchar();
		 	r->next =p;//�����嵽��ͷ
			r=p; 
			printf("\n����0ֹͣ¼����Ϣ,����1����¼����Ϣ:");
			scanf("%d",&m);
			++count;//ͳ����һ��ѧ����Ϣ����һ��ѧ����			
		}
	} 
	else if(x==2)//���ļ�������Ϣ 
	{
		int stu1=0;
		int temps;
		printf("�ļ�Ҫ���뼸��ѧ����Ϣ:");
		scanf("%d",&temps);
		printf("�ļ�Ҫ����%d��ѧ����Ϣ\n",temps);
		pRead=fopen("221600320_���˽�_studentInformation.txt","r");
		if(pRead==NULL)
		{
			printf("���ļ�ʧ��");
		}
		else
		{
			while(stu1<temps)
			{
				stu *p;
				p=(stu *)malloc(sizeof(stu));//�����µĽ��
				
				fscanf(pRead,"%s %s %s %s %s %s %d %s %s %d %d %s %s %s %d %d %s %s %s %d",
				p->num ,p->name ,p->sex ,p->countryName ,p->nationName ,p->birth ,
				&p->marriage ,p->politicsName ,p->id ,&p->studentCategory ,&p->studentType ,
				p->enterDay ,p->collegeName ,p->majorName ,&p->grade ,&p->studyLength ,p->trainLevel ,p->classNum ,
				p->teaacherName ,&p->score );
				
				r->next =p;//�����嵽��ͷ
					r=p; 
				stu1++;	
					/*printf("\n����0ֹͣ¼����Ϣ,����1����¼����Ϣ:");
					scanf("%d",&m);
					++count;//ͳ����һ��ѧ����Ϣ����һ��ѧ����	*/
							
			}	
			printf("�Ѷ���ѧ������\n");
			
		}
		
	 } 
	r->next=NULL;
	return head;	
 } 
 
void ShowMainInformation(stu *head)//չʾ��Ҫ��Ϣ ����ѧ������Լ����� 
{
	stu *p;
	int i=1;
	for(p=head->next;p!=NULL;p=p->next,i++)
	{
		printf("ѧ��%d:\n",i);
		printf("����:%s\n",p->name);
	}
}
 
 
void DecideoutInformation(int n,stu *head,int count)//����ѡ������û���Ҫ�Ķ���
{													//count����ѧ��
	int i=1; 
	stu *p;
	for(p=head->next;p!=NULL&&i!=count;p=p->next,i++);//�������������Ϣ
	
	if(n==1) printf("ѧ��:%s\n",p->num);
	if(n==2) printf("����:%s\n",p->name);
	if(n==3) printf("�Ա�:%s\n",p->sex);
	if(n==4) printf("����:%s\n",p->countryName); 
	if(n==5) printf("��������:%s\n",p->birth);
	if(n==6) printf("����:%s\n",p->nationName);
	if(n==7) printf("����״��:%s\n",marType(p->marriage));
	if(n==8) printf("������ò:%s\n",p->politicsName); 
	if(n==9) printf("���֤����:%s\n",p->id);
	if(n==10) printf("ѧ�����:%s\n",stuCategory(p->studentCategory)); 
	if(n==11) printf("ѧ����ѧ����:%s\n",p->enterDay);
	if(n==12) printf("��ѧ��ʽ:%s\n",studentsTypeName(p->studentType));
	if(n==13) printf("ѧԺ����:%s\n",p->collegeName);
	if(n==14) printf("רҵ����:%s\n",p->majorName); 
	if(n==15) printf("�꼶:%d\n",p->grade);
	if(n==16) printf("ѧ��:%d��\n",p->studyLength);
	if(n==17) printf("�������:%2s\n",p->trainLevel);
	if(n==18) printf("�༶:%2s\n",p->classNum);
	if(n==19) printf("����Ա:%s\n",p->teaacherName);
	if(n==20) printf("�߿��ɼ�:%d\n",p->score);
	
	
 } 
 
void referInformation(stu *head)//��ѯ��Ϣ
{
	stu *p;
	int flag=1;//�Ƿ������ѯ�ı�־ 
	int n,i,j;//nΪ��������ϲ�ѯ�ı��� count�ǵ�����ѯ����ѧ����� 
	int a[20];//�����ϲ�ѯ��ѡ�� 
	int s=countList(head);//����ѧ���� 
	if(head->next==NULL)
	{
		printf("��ѧ����Ϣ\n");
	}
	else
	{
		while(flag)
		{
			int count=1;
			printf("1.������ѯ  2.��ϲ�ѯ \n");
			scanf("%d",&n);
			if(n==1)
			{
				int m;//������ѯʱ��Ҫ��ѯ��ѡ�� 
				printf("��ѡ�񵥶���ѯ(1��2����ѡ����������):\n");
				classMenu();//����ṹ����������� 
				printf("ѡ����Ҫ��ѯ��ѡ��:");
				scanf("%d",&m);
				printf("\n");
				while(m<3||m>20)
				{
					printf("ѡ���ڿ�ѡ��Χ�ڣ�����������\n");
					scanf("%d",&m);
				}
				for(p=head->next;p!=NULL;p=p->next)//�������������Ϣ 
				{
					printf("ѧ��%d.\n",count);
					printf("����:%s\n",p->name);
					DecideoutInformation(m,head,count);//����û���ѡ��ĵ���Ϣ 
					count++;
				}
			}
			else
			{
				int sum;//Ҫ��ѯ������ 
				printf("��ѡ����ϲ�ѯ����������Ҫ��ѯ���ٸ�ѡ��(1~18):");
				scanf("%d",&sum);
				while(sum<0||sum>18)
				{
					printf("��ѡ�񳬹���Χ������������:");
					scanf("%d",sum);
				}
				printf("��ѡ���ѯ%d������\n",sum);
				classMenu();//����ṹ�����������
				printf("������Ҫѡ���ѯ��ѡ�1,2������ѡ����������");
				printf("����֮��ӿո�");
				for(i=1;i<=sum;i++)
				{
					scanf("%d",&a[i]);
				}
				printf("��ѡ���ѯ"); 
				for(i=1;i<=sum;i++)
				{
					printf("%d ",a[i]);
				}
				printf("�⼸����Ϣ");
				printf("\n");
				for(i=1;i<=s;i++)
				{
					int k=1;
					printf("ѧ��%d.\n",count);
					for(p=head->next;p!=NULL&&k!=count;p=p->next,k++);
					printf("����:%s\n",p->name);
					for(j=1;j<=sum;j++)
					{
						
						DecideoutInformation(a[j],head,count);//���������Ҫ��ѯ�Ķ��� 	
					}
					count++;	
				}
				
			} 
			printf("\n");
			printf("1.������ѯ 0.�˳�\n");
			printf("���������ѡ��:");
			scanf("%d",&flag);
			printf("\n");
		} 
	
	}
	
 } 

int delType()//����ɾ��ѧ����Ϣ�ķ�ʽ
{
	int x;
	int flag=1;
	do{
		printf("1.ɾ������ѧ������Ϣ\n");
		//printf("2.����רҵ+�꼶ѧ����Ϣȫ��ɾ��\n");
		printf("����ѡ��:");
		scanf("%d",&x);
		if(x==1)
		{
			printf("��ѡ��ɾ������ѧ����Ϣ\n");
			return 1;
		}
		/*else if(x==2)
		{
			printf("��ѡ������רҵ+�꼶ѧ����Ϣȫ��ɾ��\n");
			return 1;
		}*/
		else
		{
			printf("�����������������\n");
			flag=0;
		}		
	}while(!flag);
 } 

int countList(stu *head)//ͳ����������Ľ����Ŀ 
{
	int count=0;//������ �����ܽ���� 
	for(stu *p=head->next ;p!=NULL;p=p->next )//����ı��� 
		count++;
	return count;	
}

linkList delSingleStuents(stu *head)//ɾ������ѧ����Ϣ 
{
	int sum=countList(head);//ͳ����¼��¼��ѧ���� 
	int count=1;
	int x;//�����ѡ��
	int flag=1;//�ж��Ƿ�ɾ�����Ǻ��� 
	do{
		ShowMainInformation(head);
		printf("\n��������Ҫɾ���ĵڼ���ѧ��:");
		scanf("%d",&x);
		if(x<0||x>sum)
		{
			printf("������󣬲���¼��ѧ������Χ������������\n");
			flag=0;
		}
		else
		{
			stu *p,*pre=head;
			p=head->next;
			count=1;
			while(count!=x)//ѭ����Ҫɾ���ĵ�x��ѧ�� 
			{
				pre=pre->next;
				p=p->next;
				count++;
			}
			pre->next=p->next;//ɾ����������ǰ���ڵ��� 
			free(p);//�ͷŽڵ� 
			return head;
		}
			
	}while(!flag);		
}

/*linkList delMajorGrade(head)//ɾ��רҵ+�꼶��ѧ����Ϣ
{
	fflush(stdin); 
	char delMaj[10];//���Ҫɾ����רҵ����
	int delGra;//Ҫɾ�����꼶
	printf("\n������Ҫɾ����רҵ����") 
	
} */

linkList  delInformation(stu *head)//ɾ��ѧ����Ϣ
{
	if(head->next==NULL)
	{
		printf("��ѧ����Ϣ\n");
	}
	else
	{
		int m=delType();//����ɾ��ѧ����Ϣ�ķ�ʽ
		if(m==1)
		{
			delSingleStuents(head);//ɾ������ѧ����Ϣ 
			printf("��ɾ����ѡѧ����Ϣ\n");
		}
		/*else if(m==2)
		{
			delMajorGrade(head);//ɾ��רҵ+�꼶��ѧ����Ϣ
			printf("��ɾ����ѡѧ����Ϣ\n"); 
		}*/
	}

 } 

linkList modifInformation(stu *head)//�޸�ѧ����Ϣ
{
	int x,count,s; 
	int flag=1;
	int m=1;//��Ϊ�Ƿ�����޸�ѧ����Ϣ�ı�־ 
	int sum=nodeCount(head);//ͳ����¼��ѧ���� 
	stu *p;
	if(head->next==NULL)
	{
		printf("��ѧ����Ϣ\n");
	}
	else
	{
		while(m)
		{
			
			do{ 
				ShowMainInformation(head);
				printf("ѡ����Ҫ�޸ĵ�ѧ��:");
				scanf("%d",&s);
				while(s>sum||s<1)
				{
					printf("�����ѧ����Ϣ������������\n");
					scanf("%d",&s);
				 } 
				printf("��Ҫ�޸ĵ�%d��ѧ������Ϣ:\n",s); 
				classMenu();
				printf("ѡ����Ҫ�޸ĵ�ѡ��:");
				scanf("%d",&x);
				if(x<1||x>20)
				{
					printf("û�����ѡ�����������\n");
					flag=0;
				}
				else
				{
					count=1;
					stu *p;
					p=head->next;
					while(count!=s)
					{
						p=p->next; 
						count++;
					}
							
					if(x==1) strcpy(p->num,studentsNum(head,p,count));//ѧ����Ϣ 
					
					if(x==2) strcpy(p->name,studetsName(head,p,count));//������Ϣ
				
					if(x==3) strcpy(p->sex,studentsSex(count));//ѧ���Ա�
				
					if(x==4) strcpy(p->countryName,studentsCountry(count));//¼�������Ϣ 
					
					if(x==5) strcpy(p->birth,studentsBirth(count));//ѧ����������
					
					if(x==6) strcpy(p->nationName,studentsNation(count));//¼��ѧ��������Ϣ 
					
					if(x==7) p->marriage =studentsMarriage(count);//¼��ѧ������״��
					
					if(x==8) strcpy(p->politicsName,studentsPolitics(count));//¼��������ò 
				 
					if(x==9) strcpy(p->id,studentsId(count,head,p->marriage,p->birth,p->sex));
						//¼��ѧ�������֤��Ϣ	 ����marriage,birth sex ���ڼ��� 
						//רҵ ѧԺδ¼�� ��ȱ 
					if(x==10)p->studentCategory=studentsCategory(count);//ѧ��������
					
					if(x==11)strcpy(p->enterDay,studentsEnterDay(count,p->num));//ѧ����ѧʱ�� 
																	//����ѧ�Ž�����֤					
					if(x==12)p->studentType=studentsType(count); //¼��ѧ����ѧ��ʽ 
					
					if(x==13)strcpy(p->collegeName,studentsCollege(count));//¼��ѧԺ
					
					if(x==14)strcpy(p->majorName,studentsMajor(count));//¼��רҵ 
					
					if(x==15)p->grade =studentsGrade(count,p->num);//¼���꼶 ѧ�����ڼ���
					
				    if(x==16)p->studyLength=studentsLength(count);//¼��ѧ�� 
					
					if(x==17)strcpy(p->trainLevel,studentsTrainLevel(count));//¼��ѧ����������� 
					
					if(x==18)strcpy(p->classNum,studentsClass(count));//¼��ѧ���İ༶�� 
						
					if(x==19)strcpy(p->teaacherName,studentsTeacher(count));//¼�븨��Ա��Ϣ
					
					if(x==20)p->score=studentsExam(count);//¼��߿��ɼ� 
	
				}
				
			}while(!flag);
			
			printf("�����޸�һ����Ϣ\n");
			printf("1.�����޸� 0.�˳�\n");				
			printf("���������ѡ��");
			scanf("%d",&m); 
	   }
	}	 
	return head;
}
	
linkList addInformation(stu *head)
{
	int m=0,i=0;
	int sum=nodeCount(head);//��¼�����Ŀ 
	int count=sum+1;//��ʾ����ȥ�ǵ�count��ѧ�� 
	char strcountry[6]={"�й�"} ;
	if(head->next==NULL)
		printf("������ѧ����Ϣ������Խ������\n");
	else
	{
		ShowMainInformation(head);
		printf("�Ѵ���ѧ����Ϣ����\n");
	}
	printf("1.ѡ�����ѧ����Ϣ  0.�˳�\n");
	scanf("%d",&m);
	while(m)
	{
		stu *pre;
		for(pre=head;i<sum;i++,pre=pre->next);
		printf("��ʼ���ѧ����Ϣ\n");
		
			stu *p;
			p=(stu *)malloc(sizeof(stu));//�����µĽ��
			
			strcpy(p->num,studentsNum(head,p,count));//ѧ����Ϣ 
			
			strcpy(p->name,studetsName(head,p,count));//������Ϣ
			
			strcpy(p->sex,studentsSex(count));//ѧ���Ա�
			
			strcpy(p->countryName,studentsCountry(count));//¼�������Ϣ 
			
			strcpy(p->birth,studentsBirth(count));//ѧ����������
			
			strcpy(p->nationName,studentsNation(count));//¼��ѧ��������Ϣ 
			
			p->marriage =studentsMarriage(count);//¼��ѧ������״��
			
			strcpy(p->politicsName,studentsPolitics(count));//¼��������ò 
			
			if(strcmp(p->countryName ,strcountry)!=1)
			{
				strcpy(p->id,"111111111111111111");
			}
			else
			strcpy(p->id,studentsId(count,head,p->marriage,p->birth,p->sex));
			//¼��ѧ�������֤��Ϣ	 ����marriage,birth sex ���ڼ��� 
			//רҵ ѧԺδ¼�� ��ȱ 
			p->studentCategory=studentsCategory(count);//ѧ��������
			
			strcpy(p->enterDay,studentsEnterDay(count,p->num));//ѧ����ѧʱ�� 
															//����ѧ�Ž�����֤					
			p->studentType=studentsType(count); //¼��ѧ����ѧ��ʽ 
			
			strcpy(p->collegeName,studentsCollege(count));//¼��ѧԺ
			
			strcpy(p->majorName,studentsMajor(count));//¼��רҵ 
			
			p->grade =studentsGrade(count,p->num);//¼���꼶 ѧ�����ڼ���
			
			p->studyLength=studentsLength(count);//¼��ѧ�� 
			
			strcpy(p->trainLevel,studentsTrainLevel(count));//¼��ѧ����������� 
			
			strcpy(p->classNum,studentsClass(count));//¼��ѧ���İ༶�� 
			
			strcpy(p->teaacherName,studentsTeacher(count));//¼�븨��Ա��Ϣ
			
			p->score=studentsExam(count);//¼��߿��ɼ� 
				
			p->next=pre->next;
			pre->next=p;	
		printf("1.���������Ϣ 0.�˳�\n");
		printf("���������ѡ��:");
		scanf("%d",&m);
	} 		
}

int anaylyzeType()//���ط���ѧ����Ϣ�ķ�ʽ
{
	int flag=1;
	int m;
	do{
		printf("1.���չ��ҷ�����Ϣ 2.�������������Ϣ\n");
		printf("���������ѡ��:");
		scanf("%d",&m);
		if(m==1)
		{
			printf("��ѡ���չ��ҷ�����Ϣ\n");
			return 1;
		}
		else if(m==2)
		{
			printf("��ѡ�������������Ϣ\n");
			return 2;
		}
		else
		{
			printf("�����������������\n");
			flag=0;
		}
	}while(!flag);
 } 

void analyzeCountry(stu *head)//���չ��ҷ��� 
{
	char strcountry[20]; 
	stu *p;
	int count1=0;//��ͳ�ƶ������й�ѧ�� 
	int count2=0;//��������ѧ�� 
	int flag1=0,flag2=0;
	for(p=head->next;p!=NULL;p=p->next)
	{
		strcpy(strcountry,p->countryName); 
		if(strcmp(strcountry ,"�й�")==1)//������й�ѧ��
		{
			printf("����:%s\n",p->name);
			count1++;
			flag1=1;
		 } 
	}
	if(flag1) printf("����%d��ѧ�������й�\n",count1);
	//��������й���ѧ������������� 
	for(p=head->next;p!=NULL;p=p->next)
	{
		strcpy(strcountry,p->countryName);
		if(strcmp(strcountry,"�й�")!=1)//��������й�ѧ��
		{
			printf("����:%s\n",p->name);
			count2++;
			flag2=1;
		 } 
	}
	if(flag2) printf("����%d��ѧ�������\n",count2);
	
 } 
 
void analyzeNation(stu *head)//����������� 
{
	stu *p; 
	int count1=0;//��ͳ�ƶ����Ǻ���ѧ�� 
	int count2=0;//��������ѧ�� 
	int flag1=0,flag2=0;
	char strnation[20]; 
	for(p=head->next;p!=NULL;p=p->next)
	{
		strcpy(strnation,p->nationName);
		if(strcmp(strnation,"����")==0)//����Ǻ���ѧ��
		{
			printf("����:%s\n",p->name);
			count1++;
			flag1=1;
		 } 
	}
	if(flag1) printf("����%d��ѧ���������Ǻ���\n",count1);
	//������Ǻ����ѧ������������� 
	for(p=head->next;p!=NULL;p=p->next)
	{
		strcpy(strnation,p->nationName);
		if(strcmp(strnation,"����")!=0)//������������� 
		{
			printf("����:%s\n",p->name);
			count2++;
			flag2=1;
		 } 
	}
	if(flag2) printf("����%d��ѧ������������������Ѫͳ\n",count2);
	
		
 } 

void analyzeInformation(stu *head)//ͳ�ƣ�������Ϣ
{
	if(head->next==NULL)
	{
		printf("��ѧ����Ϣ\n");
	}
	else
	{
		int m1=anaylyzeType();//���շ��صķ���ѧ����Ϣ�ķ�ʽ
		if(m1==1)
		{
			analyzeCountry(head);//���չ��ҷ��� 
		 } 
		else if(m1==2)
		{
			analyzeNation(head);//����������� 
		}
		
	}

 } 


int sortType()//����ѧ����Ϣ����ʽ
{
	int t;
	int flag=1;
	do{
		printf("\n1.����ѧ�Ŵ�С��������    2.���������С��������    3.���ݸ߿��ɼ���������\n");
		printf("��ѡ������ʽ\n");
		scanf("%d",&t);

		if(t==1)
		{
			printf("��ѡ�����ѧ�Ŵ�С��������\n");
			return 1;
		}
		else if(t==2)
		{
			printf("��ѡ����������С��������\n");
			return 2;
		}
		else if(t==3)
		{
			printf("��ѡ����ݸ߿��ɼ���������\n");
			return 3;
		 } 
		 else
		 {
		 	printf("�����������������\n");
		 	flag=0;
		 }
		
	}while(!flag);
	
 } 

/*linkList sortNum(stu *head)//ѧ������
{
//����ѡ�������㷨 ���������гɼ�����
	stu *first;  //���к��������ı�ͷָ��
	stu *tail;   //���к��������ı�βָ��
	stu *p_min;  //������ֵ��С�Ľ���ǰ���ڵ��ָ��
	stu *min;   //�洢��С��� 
	stu *p;   //��ǰ�ȽϵĽ��
	stu *head1;
	head1=head->next;
	first=NULL;
	while(head!=NULL)//��������ֵ��С�Ľ�� 
	{
		//for����������ѡ������˼��
		for(p=head1,min=head1;p->next!=NULL;p=p->next)
		{//ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣
			if(strcmp(p->next->num,min->num)<0)//�ҵ�һ���ȵ�ǰminС�Ľڵ�
			{
				p_min=p;//�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p
				min=p->next;//����ֵ��С�Ľڵ�
			}
		}	
			/*����for�������󣬾�Ҫ�������£�
            һ�ǰ����������������У�
            ���Ǹ�����Ӧ�������жϣ��������뿪ԭ��������
			*/	
			//��һ����
		/*if(first==NULL)//�������Ŀǰ���ǿ�����
		{
			first=min;//��һ���ҵ�ֵ��С�Ľ��
			tail=min;//βָ������ָ�����Ľ�� 
		 } 
		 else//��������Ѿ��н��
		 {
		 	tail->next=min;//�Ѹո��ҵ�����С���ŵ���� 
			 				//����βָ���nextָ���� 
			 tail=min;//βָ��ҲҪָ����				
		 }
		 //�ڶ�����
		 if(min==head1)//����ҵ�����С�����ǵ�һ�����
		 {
		 	head1=head1->next;
		  } 
		 else//������ǵ�һ���ڵ�
		 {
		 	p_min->next=min->next;//ǰ����С�ڵ��nextָ��ǰmin��next,
		                 	//��������min�뿪��ԭ����
		  }  
	}
	if(first!=NULL)//ѭ���õ���������first
	{
		tail->next=NULL;//������������һ���ڵ�nextӦ��ָ��NULL 
	}
	head->next=first;
	return head; 	
	
 }*/ 
 
linkList sortNum(stu *head)//ѧ������
{
	stu * headNew = new stu;
	stu * p = new stu;
	stu * pre = new stu;
	int i;
	stu * a = new stu;
	a->next = head;
	stu * fp;
	for(i = 0,fp = head->next;fp!=NULL;fp = fp->next)
	{
		i++;
	}
	if(i == 0)
	{
		return head;
	}
	else if(i==1)
	{
		return head;
	}
	int flag = 1;
	
	headNew = head;
	pre = head->next;
	for(p = pre->next; p!=NULL; headNew = headNew->next, pre = pre->next, p = p->next)
	{
		flag = 1;
		if(strcmp(pre->num,p->num)>0)
		{
			flag = 0;
		}
		if(flag == 0)
		{
			pre->next = p->next; //headNew	->    	pre->	p->next  		->p
			p->next = pre;		//headNew	->     p	->	pre	->	p	->	next 
			headNew->next = p;
			headNew = a;
			pre = a->next;
			p = pre->next;
		}
	}
	return head;	
	
 } 
 
linkList sortAge(stu *head)//���������С���� 
{	
	stu * headNew = new stu;
	stu * p = new stu;
	stu * pre = new stu;
	int i;
	stu * a = new stu;
	a->next = head;
	stu * fp;
	for(i = 0,fp = head->next;fp!=NULL;fp = fp->next)
	{
		i++;
	}
	if(i == 0)
	{
		return head;
	}
	else if(i==1)
	{
		return head;
	}
	int flag = 1;
	
	headNew = head;
	pre = head->next;
	for(p = pre->next; p!=NULL; headNew = headNew->next, pre = pre->next, p = p->next)
	{
		flag = 1;
		if(strcmp(pre->birth,p->birth)>0)
		{
			flag = 0;
		}
		if(flag == 0)
		{
			pre->next = p->next; //headNew	->    	pre->	p->next  		->p
			p->next = pre;		//headNew	->     p	->	pre	->	p	->	next 
			headNew->next = p;
			headNew = a;
			pre = a->next;
			p = pre->next;
		}
	}
	return head;	
}
//linkList sortAge(stu *head)//�����С����
//{
////����ѡ�������㷨 ���������гɼ�����
//	stu *first;  //���к��������ı�ͷָ��
//	stu *tail;   //���к��������ı�βָ��
//	stu *p_min;  //������ֵ��С�Ľ���ǰ���ڵ��ָ��
//	stu *min;   //�洢��С��� 
//	stu *p;   //��ǰ�ȽϵĽ��
//	first=NULL;
//	int flag = 1;
//	while(head!=NULL)//��������ֵ��С�Ľ�� 
//	{
//		//for����������ѡ������˼��
//		for(p=head,min=head->next;p->next!=NULL;p=p->next)
//		{//ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣=
//			flag = 1;
//			{
//				p_min=p;//������x//����ֵ��С�Ľڵ�
//				flag = 0; 
//			}
//		}	
//			/*����for�������󣬾�Ҫ�������£�
//            һ�ǰ����������������У�
//            ���Ǹ�����Ӧ�������жϣ��������뿪ԭ��������
//			*/	
			//��һ����
//		if(first==NULL)//�������Ŀǰ���ǿ�����
//		{
//			first->next=min;//��һ���ҵ�ֵ��С�Ľ��
//			tail->next=min;//βָ������ָ�����Ľ�� 
//		 } 
//		 else//��������Ѿ��н��
//		 {
//		 	tail->next=min;//�Ѹո��ҵ�����С���ŵ���� 
//			 				//����βָ���nextָ���� 
//			 tail=min;//βָ��ҲҪָ����				
//		 }
//		 //�ڶ�����
//		 if(min==head)//����ҵ�����С�����ǵ�һ�����
//		 {
//		 	head=head->next;
//		  } 
//		 else//������ǵ�һ���ڵ�
//		 {
//		 	p_min->next=min->next;//ǰ����С�ڵ��nextָ��ǰmin��next,
//		                 	//��������min�뿪��ԭ����
//		  }  
//	}
//	if(first!=NULL)//ѭ���õ���������first
//	{
//		tail->next=NULL;//������������һ���ڵ�nextӦ��ָ��NULL 
//	}
//	head = first;
//	return head;	
//	
//} 
 
linkList sortScore(stu *head)//�߿��ɼ�����
{
//����ѡ�������㷨 ���������гɼ�����
	stu *first;  //���к��������ı�ͷָ��
	stu *tail;   //���к��������ı�βָ��
	stu *p_min;  //������ֵ��С�Ľ���ǰ���ڵ��ָ��
	stu *min;   //�洢��С��� 
	stu *p;   //��ǰ�ȽϵĽ��
	first=NULL;
	while(head!=NULL)//��������ֵ��С�Ľ�� 
	{
		//for����������ѡ������˼��
		for(p=head,min=head;p->next!=NULL;p=p->next)
		{//ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣
			if(p->next->score < min->score)//�ҵ�һ���ȵ�ǰminС�Ľڵ�
			{
				p_min=p;//�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p
				min=p->next;//����ֵ��С�Ľڵ�
			}
		}	
			/*����for�������󣬾�Ҫ�������£�
            һ�ǰ����������������У�
            ���Ǹ�����Ӧ�������жϣ��������뿪ԭ��������
			*/	
			//��һ����
		if(first==NULL)//�������Ŀǰ���ǿ�����
		{
			first=min;//��һ���ҵ�ֵ��С�Ľ��
			tail=min;//βָ������ָ�����Ľ�� 
		 } 
		 else//��������Ѿ��н��
		 {
		 	tail->next=min;//�Ѹո��ҵ�����С���ŵ���� 
			 				//����βָ���nextָ���� 
			 tail=min;//βָ��ҲҪָ����				
		 }
		 //�ڶ�����
		 if(min==head)//����ҵ�����С�����ǵ�һ�����
		 {
		 	head=head->next;
		  } 
		 else//������ǵ�һ���ڵ�
		 {
		 	p_min->next=min->next;//ǰ����С�ڵ��nextָ��ǰmin��next,
		                 	//��������min�뿪��ԭ����
		  }  
	}
	if(first!=NULL)//ѭ���õ���������first
	{
		tail->next=NULL;//������������һ���ڵ�nextӦ��ָ��NULL 
	}
	head=first;
	return head;	
 }

linkList sortInformation(stu *head)//����ѧ����Ϣ
{
	int t;
	if(head->next==NULL)
	{
		printf("��ѧ����Ϣ\n");
	}
	else
	{
		t=sortType();
		switch(t)
		{
			case 1:
			{
				sortNum(head);//ѧ�Ŵ�С�������� 
				printf("\n����ɹ�");
				break;
			}
			case 2:
			{
				sortAge(head);//�����С�������� 
				printf("\n����ɹ�");
				break;
			}
			case 3:
			{
				sortScore(head);//�߿��ɼ���������
				printf("\n����ɹ�");
				break;	
			}	
		}
	}
}

void showInformation(stu *head)//��ѧ����Ϣ�������Ļ�� 
{
	int count=1;
	int n;
	stu *p=NULL;
	if(head->next==NULL)
	{
		printf("��ѧ����Ϣ\n");
	}
	else
	{
		for(p=head->next;p!=NULL;p=p->next)//�������������Ϣ 
		{
			fflush(stdin);
			printf("ѧ��%d.\n",count);
			printf("ѧ��:%s\n",p->num);
			printf("����:%s\n",p->name);
			printf("�Ա�:%s\n",p->sex);
			printf("����:%s\n",p->countryName); 
			printf("��������:%s\n",p->birth);
			printf("����:%s\n",p->nationName);
			printf("����״��:%s\n",marType(p->marriage));
			printf("������ò:%s\n",p->politicsName);
			printf("���֤����:%s\n",p->id); 
			printf("ѧ�����:%s\n",stuCategory(p->studentCategory)); 
			printf("ѧ����ѧ����:%s\n",p->enterDay);
			printf("��ѧ��ʽ:%s\n",studentsTypeName(p->studentType));
			printf("ѧԺ����:%s\n",p->collegeName);
			printf("רҵ����:%s\n",p->majorName); 
			printf("�꼶:%d\n",p->grade);
			printf("ѧ��:%d��\n",p->studyLength);
			printf("�������:%s",p->trainLevel);
			printf("\n");
			printf("�༶:%s\n",p->classNum);
			printf("����Ա:%s\n",p->teaacherName);
			printf("�߿��ɼ�:%d\n",p->score);
			printf("\n");
			count++;
		}		
	}
}

void ToFileInformation(stu *head)//��ѧ����Ϣ���뵽�ļ���
{
	int count=1;
	stu *p=NULL;
	FILE *pwrite;
	pwrite=fopen("information.txt","w");
	if(pwrite==NULL)
		return ;
	if(head->next ==NULL)
		printf("��ѧ����Ϣ\n");
	else
	{
		for(p=head->next;p!=NULL;p=p->next)
		{	
			fprintf(pwrite,"%d\n%s\n%s\n%s\n%s\n%s\n",
			count,p->num,p->name,p->sex,p->countryName,p->nationName);
			fprintf(pwrite,"%s\n%d\n%s\n",p->birth,p->marriage,p->politicsName);
			fprintf(pwrite,"%s\n%d\n%d\n",p->id,p->studentCategory,p->studentType);
			fprintf(pwrite,"%s\n%s\n%s\n",p->enterDay,p->collegeName,p->majorName);
			fprintf(pwrite,"%d\n%d\n%s\n",p->grade,p->studyLength,p->trainLevel);
			fprintf(pwrite,"%s\n%s\n%d\n",p->classNum,p->teaacherName,p->score);
												//д�����ݵ��ļ���  
			printf("\n");//һ��ѧ������Ϣ������һ��ѧ����Ϣ֮��Ҫ��һ��									
			++count;
			//if(count%5==0)
			//	fprintf(pwrite,"\r\n");
		}
		fclose(pwrite);//�ر��ļ� 
	}
	
	if(countList(head))//�������Ϊ����Ȼû�����ݿ��Դ����ļ���	 	
		printf("�ѽ�%d��ѧ����Ϣ���뵽�ļ�\"221600320_���˽�_information.txt\"��\n",countList(head));	
}

void freeList(stu *head)//�ͷ�����
{
	stu *p=head;// һ��ʼpָ���ڱ�  
	while(p!=NULL)//��ʼ�������� 
	{
		p=head->next;//��ǰ������һ����㸳��p 
		free(head);//�ͷŵ���ǰ��� 
		head=p;//��ǰ���ָ����һ�� 
	 } 
 }   
