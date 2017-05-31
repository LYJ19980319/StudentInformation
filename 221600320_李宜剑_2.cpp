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

void systemTime()//调用系统函数的时间 
{
	time_t Curtime = (time_t)0;//定义时间变量 并且得到日历时间 
   	struct tm* Rettime = NULL;
   	time(&Curtime);
	Rettime=localtime(&Curtime); //得到系统时间 
	
	const char *week[]={"日","一","二","三","四","五","六"};
	printf("\n\r当前日期、时间:%04d-%02d-%02d (星期%s) %02d:%02d:%02d",
		Rettime->tm_year + 1900,Rettime->tm_mon + 1,Rettime->tm_mday,week
		[Rettime->tm_wday],Rettime->tm_hour,Rettime->tm_min ,Rettime->tm_sec);
		
	Sleep(100);	
}

linkList intList(void)//初始化链表  
{
	stu *p;
	if((p=(stu *)malloc(sizeof(stu)))==NULL)
	{
		printf("申请空间失败!\n");
		return NULL;
	}
	p->next = NULL;//表示链尾
	return p; 
}

int nodeCount(stu *head)//统计节点数目
{
	int i=0;
	stu *p;
	for(p=head->next;p!=NULL;p=p->next)
		i++;
	return i;	
 } 

void classMenu()//类里面的内容 
{
	printf("1.学号             2.姓名         3.性别             4.国家      \n");
	printf("5.出生日期         6.民族         7.婚姻状况         8.政治面貌  \n");
	printf("9.身份证号码       10.学生类别    11.学生入学日期    12.入学方式 \n");
	printf("13.学院名称        14.专业名称    15.年级            16.学制     \n");
	printf("17.培养层次        18.班级        19.辅导员          20.高考成绩 \n");
}

void menu()//菜单界面 
{
	systemTime();//显示当前系统时间 
	//显示自己版权信息
	printf("\nCopyright 2016-2019 李宜剑 221600320 All Rights Reserved.\n");
	printf("***********************************************************\n");
	printf("**              高校学生信息系统                         **\n");
	printf("**                                                       **\n");
	printf("**    1.录入学生个人相关信息                             **\n");
	printf("**    2.查询学生个人相关信息                             **\n");
	printf("**    3.修改学生个人相关信息                             **\n");
	printf("**    4.删除学生个人相关信息                             **\n");
	printf("**    5.添加学生个人相关信息                             **\n");
	printf("**    6.统计、分析学生个人相关信息                       **\n");
	printf("**    7.按照学号或者年龄排序学生个人相关信息             **\n");
	printf("**    8.输出学生的信息到屏幕上                           **\n");
	printf("**    9.输出学生的信息到文件                             **\n");
	printf("**    0.退出系统                                         **\n");
	printf("**                                                       **\n");
	printf("***********************************************************\n");
	
}

int inType()// 返回时从键盘录入 还是从文件
{
	int a;
	int flag=1; 
	do{
		printf("1.从键盘输入学生的信息\n");
		printf("2.从文件读入学生的信息\n");
		printf("请选择:");
		scanf("%d",&a);
		if(a==1||a==2)
			flag=1;
		else
		{
			printf("输入错误，请重新选择:\n");
			flag=0;
		 } 	
	}while(!flag);
	
	return a;	
} 

int ifRight(int a,int b,int c)//判断是否为合法日期  合法返回 1 不合法返回 0
{
	if(b==2)//对于含有二月份的日期数据 要检查它是不是闰年  
	{	   //如果是闰年它就有29天 否则是28天
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
	{	//检验月份后面的日 是否合法 除了2月份 其他月份 大月 31天 小月 20天
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

int numCheck(char a[],stu *head,int count)//学号检验 
{
	stu *p=NULL;
	int i,j,len=strlen(a),flag=0;
	if(len!=9)//判断是不是9个字符 
		return 0;
	if(len==9)
	{
		for(p=head->next,j=1;j<count;p=p->next,j++)//遍历链表 
		{
			if(strcmp(a,p->num )==0)//判断这个学号在之前是不是已经出现过了
			{
				return 0;
				break;
			}
		}
		for(i=0;i<len;i++)
		{
			if(!isdigit(a[i]))//判断是不是数字，学号只能是数字 
			{
				return 0;
				break;
			}
		}
		return 1;
	}
}

int nameCheck(char a[])//名字检验 
{
	int i,n=strlen(a);
	for (i = 0; i < n; i++)
	{
		if(isalpha(a[i])||isdigit(a[i])||n<4||n>40||isdigit(a[i])) 
		{//如果名字输入的是字母或者小于2个字或者大于20个字 就返回0
			return 0;
			break;
		}
		else 
			return 1;
	}
}

char *studentsNum(stu *head,stu *p,int count)//录入学号
{
	int flag=1;
	static char temp[10];//临时存储学号 
	do{
		if(flag==0)
			printf("\n学号输入有误，请重新输入:"); 
		else 
			printf("\n请输入学生%d学号:",count);
			scanf("%s",temp);
			getchar();
			flag=numCheck(temp,head,count); 
	}while(!flag);
	return temp;	
 } 

char *studetsName(stu *head,stu *p,int count)//录入姓名
{
	int flag=1;
	static char temp[40];
	do{ 
		if(flag==0)
			printf("\n姓名输入有误，请重新输入:");
		else
			printf("\n请输入学生%d姓名:",count);
			scanf("%s",temp);
			getchar();
			flag=nameCheck(temp);		 
	}while(!flag);
	
	return temp;	
 } 
 
char *studentsSex(int count)//录入学生性别
{
	int flag=1;
	static char tempSex[4];
	do{//性别的录入 
		int sex;
		printf("\n请根据选项输入性别:\n");
		printf("\n1.男 2.女");
		printf("\n请输入性别:");
		scanf("%d",&sex);
		if(sex==1) 
		{
			strcpy(tempSex,"男");
			printf("学生%d性别:男\n",count);
			flag=1;
		}
		else if(sex==2)
		{
			strcpy(tempSex,"女");
			printf("学生%d性别:女\n",count);
			flag=1;
		}
		else if (sex!=1||sex!=2)
		{
			flag=0;
			printf("性别输入有误，请重新选择:");	
		}
	}while(!flag);
	printf("\n");	
	return tempSex;
} 

//功    能：将存放国家代码、名称对照表的文件读入数组country中
//入口参数：country存放国家代码、名称对照表的(结构)数组
//返    回：国家代码、名称对照表的记录条数
int getCountryTable(struct Country country[]) {
    FILE *fp=fopen(FNAME1,"r");
    if (fp==NULL) {
        fprintf(stderr,"\a存放国家代码、名称对照表的文件[%s]不存在！\n",FNAME1);
        exit(-1);
    }
    int n=0;
    while (fscanf(fp,"%d %s",&country[n].code1,country[n].name)==2)
        n++;
    fclose(fp);
    return n;
}

//功    能：显示国家代码、名称对照表
//入口参数：country存放国家代码、名称对照表的(结构)数组
//          n存放国家代码、名称对照表的(结构)数组的长度
//返    回：无
void showCountryTable(struct Country country[],int n) {
    for (int i=0;i<n;i++) {
        printf("[%02d]",country[i].code1);
        printf("%-*s",MAX_COUNTRY_NAME_LEN+2,country[i].name);
        if((i+1)%3==0)
			printf("\n"); 
    }
}

//功    能：返回(用户输入的)国家代码对应的数组下标
//入口参数：country存放国家代码、名称对照表的(结构)数组
//          n存放国家代码、名称对照表的(结构)数组的长度
//          code1(用户输入的)待判断的国家代码
//返    回：国家代码存在返回其对应的下标，否则返回-1
int getIndexOfCode1(struct Country country[],int n,int code1) {
    for (int i=0;i<n;i++) {
        if (country[i].code1==code1) return i;
    }
    return -1;
}

//功    能：跳过本行剩余的其他字符和<回车>键
//入口参数：无
//返    回：无
void eatLine1(void) {
    while (getchar()!='\n')
        continue;
}

//功    能：获得(用户输入的)国家代码对应的数组下标
//入口参数：country存放国家代码、名称对照表的(结构)数组
//          n存放国家代码、名称对照表的(结构)数组的长度
//返    回：用户输入的国家代码在国家表中对应的下标
int getIndexOfChoice1(struct Country country[],int n) {
    int code=0;   //用户输入的国家代码
    int index=-1; //用户输入的国家代码在国家表中对应的下标
    while (1) {
        showCountryTable(country,n); //显示国家代码、名称对照表
        
        if (code==0) printf("\n请");
        else         printf("\a\n输入错误，请重新");
        printf("输入国家代码和<回车>:");
        code=getchar(); 
        if (code!='\n') {
            ungetc(code,stdin);   //不是<回车>，将按键退回输入缓冲区
            scanf("%d",&code);
            eatLine();            //跳过本行剩余的其他字符和<回车>键
        }
        else                      //用户直接按<回车>，得到默认值：中国
            code=DEFAULT_CODE1;    //默认国家代码01（中国）
        
        if ((index=getIndexOfCode1(country,n,code))!=-1)
            break;                //合法的国家代码
        
        //system("cls"); //清屏
        code=-1;
    }
    
    return index;
}

char *studentsCountry(int count)//录入国家信息
{
	fflush(stdin);
    //存放国家代码、名称对照表的(结构)数组
    static struct Country country[MAX_COUNTRY_NUM];
    
    //将存放国家代码、名称对照表的文件读入数组country中
    //n=国家代码、名称对照表的记录条数
    int n=getCountryTable(country);
    
    //用户输入(选择)国家(代码)
    //index=用户输入的国家代码在国家表中对应的下标
    int index=getIndexOfChoice1(country,n);	
    
    printf("你刚输入(学生%d)的国家是：[%02d]",count,country[index].code1);
    printf("%s\n",country[index].name);
    return country[index].name;
	
 } 

//出生日期检验 
int birthCheck(int year,int month,int day)
{
	if(month<0||month>12||day<0||day>31)
		return 0;
	else if(ifRight(year,month,day))//判定是否日期合法 
		return 1;
	else 
		return 0;		
	
 } 
 
char *studentsBirth(int count)
{
	int flag=1;
	int year,month,day;//存放由字符串分离出来的日期 
	static char temp[15];//临时变量存放出生日期 
	do{
		printf("\n输入学生%d的出生日期(务必按照格式:xxxx.xx.xx):",count);
		scanf("%s",temp);
		//字符串里的日期转换成 int 即求和 
		year=(temp[0]-'0')*1000+(temp[1]-'0')*100+(temp[2]-'0')*10+(temp[3]-'0');
		month=(temp[5]-'0')*10+(temp[6]-'0');
		day=(temp[8]-'0')*10+(temp[9]-'0');
		if(birthCheck(year,month,day))//日期的检验
		{
			printf("出生日期:%s\n",temp);
			flag=1;
		}
		else
		{
			printf("输入错误（或者不合法的日期）,请重新输入:\n");
			flag=0;
		 } 
	}while(!flag);
	printf("\n");
	return temp;
}

//功    能：将存放民族代码、名称对照表的文件读入数组nation中
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//返    回：民族代码、名称对照表的记录条数
int getNationTable(struct Nation nation[]) {
    FILE *fp=fopen(FNAME,"r");
    if (fp==NULL) {
        fprintf(stderr,"\a存放民族代码、名称对照表的文件[%s]不存在！\n",FNAME);
        exit(-1);
    }
    int n=0;
    while (fscanf(fp,"%d %s",&nation[n].code,nation[n].name)==2)
        n++;
    fclose(fp);
    return n;
}

//功    能：显示民族代码、名称对照表
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//返    回：无
void showNationTable(struct Nation nation[],int n) {
    for (int i=0;i<n;i++) {
        printf("[%02d]",nation[i].code);
        printf("%-*s",MAX_NATION_NAME_LEN+2,nation[i].name);
        if((i+1)%5==0)
			printf("\n"); 
    }
}

//功    能：返回(用户输入的)民族代码对应的数组下标
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//          code(用户输入的)待判断的民族代码
//返    回：民族代码存在返回其对应的下标，否则返回-1
int getIndexOfCode(struct Nation nation[],int n,int code) {
    for (int i=0;i<n;i++) {
        if (nation[i].code==code) return i;
    }
    return -1;
}

//功    能：跳过本行剩余的其他字符和<回车>键
//入口参数：无
//返    回：无
void eatLine(void) {
    while (getchar()!='\n')
        continue;
}

//功    能：获得(用户输入的)民族代码对应的数组下标
//入口参数：nation存放民族代码、名称对照表的(结构)数组
//          n存放民族代码、名称对照表的(结构)数组的长度
//返    回：用户输入的民族代码在民族表中对应的下标
int getIndexOfChoice(struct Nation nation[],int n) {
    int code=0;   //用户输入的民族代码
    int index=-1; //用户输入的民族代码在民族表中对应的下标
    while (1) {
        showNationTable(nation,n); //显示民族代码、名称对照表
        
        if (code==0) printf("\n请");
        else         printf("\a\n输入错误，请重新");
        printf("输入代码和<回车>:");
        code=getchar(); 
        if (code!='\n') {
            ungetc(code,stdin);   //不是<回车>，将按键退回输入缓冲区
            scanf("%d",&code);
            eatLine();            //跳过本行剩余的其他字符和<回车>键
        }
        else                      //用户直接按<回车>，得到默认值：汉族
            code=DEFAULT_CODE;    //默认民族代码01（汉族）
        
        if ((index=getIndexOfCode(nation,n,code))!=-1)
            break;                //合法的民族代码
        
        //system("cls"); //清屏
        code=-1;
    }
    
    return index;
}

char *studentsNation(int count)//录入民族信息
{
	fflush(stdin);
    //存放民族代码、名称对照表的(结构)数组
    static struct Nation nation[MAX_NATION_NUM];
    
    //将存放民族代码、名称对照表的文件读入数组nation中
    //n=民族代码、名称对照表的记录条数
    int n=getNationTable(nation);
    
    //用户输入(选择)民族(代码)
    //index=用户输入的民族代码在民族表中对应的下标
    int index=getIndexOfChoice(nation,n);	
    
    printf("你刚输入(学生%d)的民族是：[%02d]",count,nation[index].code);
    printf("%s\n",nation[index].name);
    return nation[index].name;
	
 } 
 
char *marType(int n)//返回婚姻类型 
{
	static char temp[4];
    char mar[6][6]={"0","未婚","已婚","丧偶","离婚","其他"};
    strcpy(temp,mar[n]);
    return temp;
}

int studentsMarriage(int count)//录入学生婚姻状况(婚姻状况代码)
{
	int flag=1;
	int temp;
	do{//婚姻状况的录入 
		//fflush(stdin);
		char c;
		printf("\n");
		printf("请输入学生%d的婚姻状况(默认为未婚):\n",count);
		printf("1.未婚 2.已婚 3.丧偶 4.离婚 5.其他\n");
		fflush(stdin);
		if((c=getchar())=='\n')
		{
		   temp=1;
			printf("婚姻状况为:%s\n",marType(1));
			flag=1;
		}
		else if('c'-'0'>'0'&&'c'-'0'<='5')
		{
			temp =c-'0';
			printf("婚姻状况为:%s\n",marType(c-'0'));
			flag=1;
		} 
		else
		{
		   printf("输入错误，请重新输入:\n");
		   flag=0;
		}
						
	}while(!flag);
	printf("\n");
	return temp;	
	
 } 
 
//功    能：将存放政治面貌代码、名称对照表的文件读入数组politic中
//入口参数：politi存放政治面貌代码、名称对照表的(结构)数组
//返    回：政治面貌代码、名称对照表的记录条数
int getPoliticsTable(struct Politics politics[]) {
    FILE *fp=fopen(FNAME2,"r");
    if (fp==NULL) {
        fprintf(stderr,"\a存放政治面貌代码、名称对照表的文件[%s]不存在！\n",FNAME2);
        exit(-1);
    }
    int n=0;
    while (fscanf(fp,"%d %s",&politics[n].code2,politics[n].name)==2)
        n++;
    fclose(fp);
    return n;
}

//功    能：显示政治面貌代码、名称对照表
//入口参数：politics存放政治面貌代码、名称对照表的(结构)数组
//          n存放政治面貌代码、名称对照表的(结构)数组的长度
//返    回：无
void showPoliticsTable(struct Politics politics[],int n) {
	fflush(stdin);
    for (int i=0;i<n;i++) {
        printf("[%02d]",politics[i].code2);
        printf("%-*s",MAX_POLITICS_NAME_LEN+2,politics[i].name); 
        if((i+1)%2==0)
			printf("\n"); 
    }
}

//功    能：返回(用户输入的)政治面貌代码对应的数组下标
//入口参数：politics存放政治面貌代码、名称对照表的(结构)数组
//          n存放政治面貌代码、名称对照表的(结构)数组的长度
//          code2(用户输入的)待判断的政治面貌代码
//返    回：政治面貌代码存在返回其对应的下标，否则返回-1
int getIndexOfCode2(struct Politics politics[],int n,int code2) {
    for (int i=0;i<n;i++) {
        if (politics[i].code2==code2) return i;
    }
    return -1;
}

//功    能：跳过本行剩余的其他字符和<回车>键
//入口参数：无
//返    回：无
void eatLine2(void) {
    while (getchar()!='\n')
        continue;
}

//功    能：获得(用户输入的)政治面貌代码对应的数组下标
//入口参数：politics存放政治面貌代码、名称对照表的(结构)数组
//          n存放政治面貌代码、名称对照表的(结构)数组的长度
//返    回：用户输入的政治面貌代码在政治面貌表中对应的下标
int getIndexOfChoice2(struct Politics politics[],int n) {
    int code=0;   //用户输入的政治面貌代码
    int index=-1; //用户输入的政治面貌代码在政治面貌表中对应的下标
    while (1) {
        showPoliticsTable(politics,n); //显示政治面貌代码、名称对照表
        
        if (code==0) printf("\n请");
        else         printf("\a\n输入错误，请重新");
        printf("输入代码和<回车>:");
        code=getchar(); 
        if (code!='\n') {
            ungetc(code,stdin);   //不是<回车>，将按键退回输入缓冲区
            scanf("%d",&code);
            eatLine();            //跳过本行剩余的其他字符和<回车>键
        }
        else                      //用户直接按<回车>，
			code=DEFAULT_CODE2;	//得到默认值：中国共产主义共青团员 
              				  //默认政治面貌代码03 中国共产主义共青团员
        
        if ((index=getIndexOfCode2(politics,n,code))!=-1)
            break;                //合法的政治面貌代码
        
        //system("cls"); //清屏
        code=-1;
    }
    
    return index;
}

char *studentsPolitics(int count)//录入政治面貌信息
{
	fflush(stdin);
    //存放政治面貌代码、名称对照表的(结构)数组
    static struct Politics politics[MAX_POLITICS_NUM];
    
    //将存放政治面貌代码、名称对照表的文件读入politic数组中
    //n=政治面貌、名称对照表的记录条数
    int n=getPoliticsTable(politics);
    
    //用户输入(选择)政治面貌(代码)
    //index=用户输入的政治面貌代码在政治面貌表中对应的下标
    int index=getIndexOfChoice2(politics,n);	
    
    printf("你刚输入(学生%d)的政治面貌是：[%02d]",count,politics[index].code2);
    printf("%s",politics[index].name);
    printf("\n");
    return politics[index].name;
	
 }  
 
 
int idCheck3(char id[],stu *head,int count)//验证是否身份证号码重复
{//Id[] 身份证号码 count已经录入的学生数 
	stu *p=NULL;
	int j; 
	for(p=head->next,j=1;j<count;p=p->next,j++)//遍历链表 
	{
		if(strcmp(id,p->id)==0)//判断这个身份证号在之前是不是已经出现过了
		{
			return 0;
			break;
		}
	}
	return 1;
}  
  
int idCheck2(char id[])//验证最后一位身份证的校验码
{
	int i,sum=0;
	int remain;//余数 
	int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//前17位分别要乘以的系数 
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
//身份证检验信息
//对年月日 性别 最后一位校验码 
int idCheck1(char id[],int count,int year,int month,int day,char s[])
{
	int i;
	int sum1,sum2,sum3;//字符算求和年月份 
	if(!strcmp(s,"男"))
	{
		if((id[16]-'0')%2==0)
			return 0;
	}
	else if(!strcmp(s,"女"))
	{
		if((id[16]-'0')%2!=0)
			return 0;
	} 
	if(strlen(id)!=18)
		return 0;
	else if(!idCheck2(id))//单独调用函数检验最后一位检验码
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

char *studentsId(int count,stu *head,int m,char b[],char s[])//录入学生的身份证信息
{//m 代表国籍 s[]代表性别 count代表学生数 
	fflush(stdin); 
	static char tempId[19];//临时变量存放身份ID 
	int year,month,day;
	int flag=1;
	do{//身份证的录入 
		if(m!=1)
			break;
		printf("\n输入学生%d身份证号码:",count);
		fflush(stdin);
		scanf("%s",tempId);

	    year=(tempId[6]-'0')*1000+(tempId[7]-'0')*100+(tempId[8]-'0')*10+(tempId[9]-'0');
	    month=(tempId[10]-'0')*10+(tempId[11]-'0');
	    day=(tempId[12]-'0')*10+(tempId[13]-'0');		
		if(!idCheck3(tempId,head,count))//单独调用函数检验身份证是否重复
		{
			printf("身份证号码重复，请重新输入:");
			flag=0;
		}	
		else if(idCheck1(tempId,count,year,month,day,s))
		{
			 printf("ID与前面信息符合，输入正确\n");
			flag=1;
		}
		else 
		{
			printf("ID与前面信息不符合，重新输入\n");
			flag=0;
		}
	}while(!flag);	
	return tempId;
 } 

char *stuCategory(int n)//返回学生类别 
{
	static char temp[4];
    char stuc[5][10]={"0","城镇应届","城镇往届","农村应届","农村往届",};
    strcpy(temp,stuc[n]);
    return temp;
}

int studentsCategory(int count)//录入学生类别
{
	int flag=1;
	int x=0;
	do{//学生类别的录入 
		//fflush(stdin); 
		printf("\n");
		printf("1.城镇应届    2.城镇往届    3.农村应届    4.农村往届\n"); 
		printf("请选择学生%d类别:",count);
		scanf("%d",&x);
		if(x==1||x==2||x==3||x==4)
		{
			printf("学生类别:%s\n",stuCategory(x));
			flag=1;
			return x;
		 } 
		else
		{
			printf("输入错误，请重新选择:\n");
			flag=0;

		}
				
	}while(!flag);
 } 

char *studentsEnterDay(int count,char num1[])//录入学生入学日期
{
	int flag=1;
	int year1,month1,day1;
	static char stuEnter[15];
	int idYear=(num1[2]-'0')*10+(num1[3]-'0')+2000;//计算学号里面的年份，
											//为后面检验做准备 
	do{
		printf("\n输入学生%d入学日期(xxxx.xx.xx)8<=月份<=10:",count);
		fflush(stdin);
		scanf("%s",stuEnter);
		//字符串里的日期转换成 int 即求和 
		year1=(stuEnter[0]-'0')*1000+(stuEnter[1]-'0')*100+(stuEnter[2]-'0')*10
				+(stuEnter[3]-'0');
		month1=(stuEnter[5]-'0')*10+(stuEnter[6]-'0');
		day1=(stuEnter[8]-'0')*10+(stuEnter[9]-'0');
		if(!ifRight(year1,month1,day1))//检验日期是否合法 
		{
			printf("输入日期不合法，请重新输入\n");
			flag=0;		
		}
		else if(month1<8||month1>10)
		{
			printf("月份不合法，请重新输入\n");
			flag=0;
		}
		else if(idYear!=year1)
		{
			printf("年份输入，与学号年份不一致，请重新输入\n");
			flag=0;
		}
		else
		{
			printf("入学日期:%s\n",stuEnter);
			flag=1;
		}
		
	}while(!flag);
	return stuEnter;//返回日期 
 } 

char *studentsTypeName(int n)//返回学生入学方式的类型名称 
{
	static char tempTypes[20];
	char type[15][20]={"0","普通入学","自主招生","专项生","保送生",
	"艺术类","体育类","高水平运动队","体育类","空军专业"};
	strcpy(tempTypes,type[n]);
	return tempTypes;
 } 

int studentsType(int count)//返回学生入学方式代号 
{//count代表当前第几位学生 

	int tempType;//存学生入学方式代号 
	int flag=1;
	do{//学生入学方式的录入 
		FILE *fp;
		char s[255];
		char c;
		if((fp=fopen("221600320_李宜剑_StudentType.txt","r"))==NULL)//打开文件 
		{
			printf("打开文件失败\n");
		}
		printf("\n");
		while(fgets(s,6,fp))
		{
			printf("%s",s);
		}
		fclose(fp);
		printf("\n请输入学生%d的入学方式:",count);
		fflush(stdin);
		if((c=getchar())=='\n')//如果是回车即默认 
		{
			tempType=1;
			printf("\n学生%d入学方式是:%s\n",count,studentsTypeName(1));
			flag=1;
		}
		else if(c)
		{
			tempType=c-'0';
			printf("\n学生%d入学方式是:%s\n",count,studentsTypeName(tempType));
			flag=1;
		}
		else
		{
			printf("输入有误，请重新输入\n");
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
		fprintf(stderr,"\a存放学院代码、名称对照表的文件[%s]不存在!\n",FNAME3);
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
		printf("\n选择学院(以下为学院名称跟代码):\n");
		showCollegeTable(college,n);
		if(code==0) printf("\n请");
		else		printf("\a\n输入错误，请重新选择");
		printf("输入代码和<回车>:");
		scanf("%d",&code);
		if ((index=getIndexOfCode3(college,n,code))!=-1)
			break;
		code=-1;	
	}
	return index;
}

char *studentsCollege(int count)//录入学院信息
{
	fflush(stdin);
	static struct College college[MAX_COLLEGE_NUM];
	int n=getCollegeTable(college);
	int index=getIndexOfchoice3(college,n);
	
	printf("你刚输入(学生%d)的学院是:[%02d]",count,college[index].code3);
	printf("%s",college[index].name);
	printf("\n"); 
	return college[index].name;
	
 } 

int getMajorTable(struct Major major[])
{
	FILE *fp=fopen(FNAME4,"r");
	if(fp==NULL)
	{
		fprintf(stderr,"\a存放专业代码、名称对照表的文件[%s]不存在!\n",FNAME4);
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
		printf("\n选择专业(以下为专业名称跟代码):\n");
		showMajorTable(major,n);
		if(code==0) printf("\n请");
		else		printf("\a\n输入错误，请重新选择");
		printf("输入代码和<回车>:");
		scanf("%d",&code);
		if ((index=getIndexOfCode4(major,n,code))!=-1)
			break;
		code=-1;	
	}
	return index;
}

char *studentsMajor(int count)//录入专业信息
{
	fflush(stdin);
	static struct Major major[MAX_MAJOR_NUM];
	int n=getMajorTable(major);
	int index=getIndexOfchoice4(major,n);
	
	printf("你刚输入(学生%d)的专业是:[%02d]",count,major[index].code4);
	printf("%s",major[index].name);
	printf("\n");
	return major[index].name;
	
 } 

int studentsGrade(int count,char nu[])//返回学生的入学年级
{//count 为当前第几位学生  nu存学生的学号 用于检验
	int flag=1;
	int grad;//表示年级 
	int m;//存放由学号计算出来的年级
	
	m=2000+(nu[2]-'0')*10+(nu[3]-'0');
	do{
		printf("\n请输入学生%d的年级:",count); 
		fflush(stdin);//清楚缓冲 
		grad=getchar(); 
        if (grad!='\n') {
            ungetc(grad,stdin);  //不是<回车>，将按键退回输入缓冲区
            scanf("%d",&grad);
            eatLine();   //跳过本行剩余的其他字符和<回车>键
            if(grad>2017||grad<2000)
            {
            	printf("输入时间有问题，请重新输入\n");
            	flag=0;
			}
            else if(grad!=m)
            {
            	int x;
            	printf("\a年级%d与学号上的年级信息不一致\n",grad);
            	printf("1.选择重新输入年级信息\n2.忽视不一致信息\n");
            	scanf("%d",&x);
            	if(x==1)
            		flag=0;
            	else
					flag=1;	
			}
			else if(grad==m)
			{
				printf("\n与学号信息符合");
				flag=1;
			}
        }
        else //用户直接按<回车>，得到默认值：2000+“学号”的“入学年份”
        {
        	grad=m;
        	printf("\n默认年级为:%d\n",grad);
			flag=1;	
		}						
            		
	}while(!flag);
	
	return grad; 
} 

int studentsLength(int count)//录入学制 
{
	int len;
	int flag=1;
	do{
		printf("\n\n");
		printf("请输入学生%d学制(必须和自己的专业学制一样) 格式：数字:",count);
		fflush(stdin);//清楚缓冲 
		len=getchar();
        if (len!='\n')
		{
            ungetc(len,stdin);  //不是<回车>，将按键退回输入缓冲区
            scanf("%d",&len);
            eatLine();   //跳过本行剩余的其他字符和<回车>键
            printf("学制为%d年\n",len);
            flag=1;
            
		}
		else //用户直接按<回车>，得到默认值：4年（学制） 
        {
        	len=4; 
        	printf("\n默认学制为:%d年\n",len);
			flag=1;	
		}		
			 
	}while(!flag);
	return len;
 } 

char *studentsTrainLevel(int count)//录入学生的培养层次
{
	static char level[5];
	int flag=1;
	int lev;
	do{
		printf("\n请选择学生%d的培养层次(默认为本科):\n",count);
		printf("1.专科  2.本科  3.硕士  4.博士\n");
		fflush(stdin);//清楚缓冲 
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
					strcpy(level,"专科");
					break; 
				}
				case 2:
				{
					strcpy(level,"本科");
					break;
				}
				case 3:
				{
					strcpy(level,"硕士");
					break;
				}
				case 4:
				{
					strcpy(level,"博士"); 
					break;
				}
				default:
				{
					printf("输入错误\n");
					flag=0;
				 } 
			}
				
		}
		else
			strcpy(level,"本科"); 
	}while(!flag);
	printf("选择的培养层次为:%s\n",level);
	return level;
	
 } 

char *studentsClass(int count) //录入学生班级号01~10
{
	fflush(stdin); 
	static char tempClass[3];
	int flag=1;
	int c;
	do{
		printf("\n");
		printf("输入学生%d的班级号(01~10):",count);
		fflush(stdin);
		scanf("%s",tempClass);
		//printf("你输入班级为%s",tempClass);
		if(strlen(tempClass)!=2)
		{
			printf("\n输入有误，请重新输入\n");
			flag=0;
		}
		else
		{
			c=(tempClass[0]-'0')*10+(tempClass[1]-'0');
			if(c>10||c<1)
			{
				printf("输入为%d不在范围内\n",c);
				printf("请重新输入\n");
				flag=0;
			}
			else
			{
				printf("输入为%d,正确\n",c);
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
		fprintf(stderr,"\a存放辅导员代码、名称对照表的文件[%s]不存在!\n",FNAME5);
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
		printf("\n选择辅导员(以下为辅导员名字跟代码):\n");
		showTeacherTable(teacher,n);
		if(code==0) printf("\n请");
		else		printf("\a\n输入错误，请重新选择");
		printf("输入代码和<回车>:");
		scanf("%d",&code);
		if ((index=getIndexOfCode5(teacher,n,code))!=-1)
			break;
		code=-1;	
	}
	return index;
}

char *studentsTeacher(int count)//录入辅导员信息 
{
	fflush(stdin);
	static struct Teacher teacher[MAX_TEACHER_NUM];
	int n=getTeacherTable(teacher);
	int index=getIndexOfchoice5(teacher,n);
	
	printf("你刚输入的(学生%d)辅导员是:[%02d]",count,teacher[index].code5);
	printf("%s",teacher[index].name);
	printf("\n");
	return teacher[index].name;
	
 }  
 
int studentsExam(int count)//录入高考成绩  
{
	int flag=1;
	int score;
	do{
		fflush(stdin);
		printf("\n输入学生%d的高考成绩(格式:正整数(0<分数<750)):",count);
		scanf("%d",&score);
		
		if(score<0||score>750)
		{
			printf("\n成绩不在范围内，请重新输入\n");
			flag=0;
		}
		else
		{
			printf("\n学生%d高考成绩是%d\n",count,score);
			flag=1;
		}
	}while(!flag);
	return score;
	
 } 
 
linkList informationIn()//录入学生信息
{
	int x,count=1;//count统计学生数 x为选择从键盘录入还是文件 
	int m=1;//m为是否继续输入信息的标志 
	int flag1=0;//做为输入是否错误的标志
	stu temp;//声明一个临时结构体变量 
	stu *head;
	stu *r; 
	head=(stu *)malloc(sizeof(stu));//申请头结点空间 
	head->next=NULL;//初始化一个空链表
	r=head;
	FILE *pRead ;
	char anac[20]; 
	x=inType(); 
	if(x==1)//键盘录入信息 
	{
		printf("开始录入信息:\n");
		while(m!=0)
		{
			stu *p;
			p=(stu *)malloc(sizeof(stu));//申请新的结点
			p->
			strcpy(p->num,studentsNum(head,p,count));//学号信息 
			
			strcpy(p->name,studetsName(head,p,count));//姓名信息
			
			strcpy(p->sex,studentsSex(count));//学生性别
			
			strcpy(p->countryName,studentsCountry(count));//录入国家信息 
			
			strcpy(p->birth,studentsBirth(count));//学生出生日期
			
			strcpy(p->nationName,studentsNation(count));//录入学生民族信息 
			
			p->marriage =studentsMarriage(count);//录入学生婚姻状况
			
			strcpy(p->politicsName,studentsPolitics(count));//录入政治面貌 
			
			fflush(stdin);
			strcpy(anac,p->countryName) ;
			
			if(strcmp(anac,"中国")!=1)
			{
				strcpy(p->id,"111111111111111111");
			}
			else
			strcpy(p->id,studentsId(count,head,p->marriage,p->birth,p->sex));
			//录入学生的身份证信息	 参数marriage,birth sex 用于检验 
			//专业 学院未录入 暂缺 
			p->studentCategory=studentsCategory(count);//学生类别代号
			
			strcpy(p->enterDay,studentsEnterDay(count,p->num));//学生入学时间 
															//参数学号进行验证					
			p->studentType=studentsType(count); //录入学生入学方式 
			
			strcpy(p->collegeName,studentsCollege(count));//录入学院
			
			strcpy(p->majorName,studentsMajor(count));//录入专业 
			
			p->grade =studentsGrade(count,p->num);//录入年级 学号用于检验
			
			p->studyLength=studentsLength(count);//录入学制 
			
			strcpy(p->trainLevel,studentsTrainLevel(count));//录入学生的培养层次 
			
			strcpy(p->classNum,studentsClass(count));//录入学生的班级号 
			
			strcpy(p->teaacherName,studentsTeacher(count));//录入辅导员信息
			
			p->score=studentsExam(count);//录入高考成绩 
				
			//getchar();
		 	r->next =p;//将结点插到表头
			r=p; 
			printf("\n输入0停止录入信息,输入1继续录入信息:");
			scanf("%d",&m);
			++count;//统计完一个学生信息，加一个学生数			
		}
	} 
	else if(x==2)//从文件读入信息 
	{
		int stu1=0;
		int temps;
		printf("文件要读入几个学生信息:");
		scanf("%d",&temps);
		printf("文件要读入%d个学生信息\n",temps);
		pRead=fopen("221600320_李宜剑_studentInformation.txt","r");
		if(pRead==NULL)
		{
			printf("打开文件失败");
		}
		else
		{
			while(stu1<temps)
			{
				stu *p;
				p=(stu *)malloc(sizeof(stu));//申请新的结点
				
				fscanf(pRead,"%s %s %s %s %s %s %d %s %s %d %d %s %s %s %d %d %s %s %s %d",
				p->num ,p->name ,p->sex ,p->countryName ,p->nationName ,p->birth ,
				&p->marriage ,p->politicsName ,p->id ,&p->studentCategory ,&p->studentType ,
				p->enterDay ,p->collegeName ,p->majorName ,&p->grade ,&p->studyLength ,p->trainLevel ,p->classNum ,
				p->teaacherName ,&p->score );
				
				r->next =p;//将结点插到表头
					r=p; 
				stu1++;	
					/*printf("\n输入0停止录入信息,输入1继续录入信息:");
					scanf("%d",&m);
					++count;//统计完一个学生信息，加一个学生数	*/
							
			}	
			printf("已读入学生数据\n");
			
		}
		
	 } 
	r->next=NULL;
	return head;	
 } 
 
void ShowMainInformation(stu *head)//展示主要信息 就是学生序号以及名字 
{
	stu *p;
	int i=1;
	for(p=head->next;p!=NULL;p=p->next,i++)
	{
		printf("学生%d:\n",i);
		printf("姓名:%s\n",p->name);
	}
}
 
 
void DecideoutInformation(int n,stu *head,int count)//根据选择输出用户需要的东西
{													//count代表学生
	int i=1; 
	stu *p;
	for(p=head->next;p!=NULL&&i!=count;p=p->next,i++);//遍历链表输出信息
	
	if(n==1) printf("学号:%s\n",p->num);
	if(n==2) printf("姓名:%s\n",p->name);
	if(n==3) printf("性别:%s\n",p->sex);
	if(n==4) printf("国家:%s\n",p->countryName); 
	if(n==5) printf("出生日期:%s\n",p->birth);
	if(n==6) printf("民族:%s\n",p->nationName);
	if(n==7) printf("婚姻状况:%s\n",marType(p->marriage));
	if(n==8) printf("政治面貌:%s\n",p->politicsName); 
	if(n==9) printf("身份证号码:%s\n",p->id);
	if(n==10) printf("学生类别:%s\n",stuCategory(p->studentCategory)); 
	if(n==11) printf("学生入学日期:%s\n",p->enterDay);
	if(n==12) printf("入学方式:%s\n",studentsTypeName(p->studentType));
	if(n==13) printf("学院名称:%s\n",p->collegeName);
	if(n==14) printf("专业名称:%s\n",p->majorName); 
	if(n==15) printf("年级:%d\n",p->grade);
	if(n==16) printf("学制:%d年\n",p->studyLength);
	if(n==17) printf("培养层次:%2s\n",p->trainLevel);
	if(n==18) printf("班级:%2s\n",p->classNum);
	if(n==19) printf("辅导员:%s\n",p->teaacherName);
	if(n==20) printf("高考成绩:%d\n",p->score);
	
	
 } 
 
void referInformation(stu *head)//查询信息
{
	stu *p;
	int flag=1;//是否继续查询的标志 
	int n,i,j;//n为单独跟组合查询的变量 count是单独查询里面学生序号 
	int a[20];//存放组合查询的选项 
	int s=countList(head);//计算学生数 
	if(head->next==NULL)
	{
		printf("无学生信息\n");
	}
	else
	{
		while(flag)
		{
			int count=1;
			printf("1.单独查询  2.组合查询 \n");
			scanf("%d",&n);
			if(n==1)
			{
				int m;//单独查询时候要查询的选项 
				printf("你选择单独查询(1与2不能选，本身会输出):\n");
				classMenu();//输出结构体里面的内容 
				printf("选择你要查询的选项:");
				scanf("%d",&m);
				printf("\n");
				while(m<3||m>20)
				{
					printf("选择不在科选范围内，请重新输入\n");
					scanf("%d",&m);
				}
				for(p=head->next;p!=NULL;p=p->next)//遍历链表输出信息 
				{
					printf("学生%d.\n",count);
					printf("姓名:%s\n",p->name);
					DecideoutInformation(m,head,count);//输出用户所选择的的信息 
					count++;
				}
			}
			else
			{
				int sum;//要查询多少项 
				printf("你选择组合查询，请输入你要查询多少个选项(1~18):");
				scanf("%d",&sum);
				while(sum<0||sum>18)
				{
					printf("所选择超过范围，请重新输入:");
					scanf("%d",sum);
				}
				printf("你选择查询%d项数据\n",sum);
				classMenu();//输出结构体里面的内容
				printf("输入你要选择查询的选项，1,2，不必选，本身会输出");
				printf("数字之间加空格");
				for(i=1;i<=sum;i++)
				{
					scanf("%d",&a[i]);
				}
				printf("你选择查询"); 
				for(i=1;i<=sum;i++)
				{
					printf("%d ",a[i]);
				}
				printf("这几项信息");
				printf("\n");
				for(i=1;i<=s;i++)
				{
					int k=1;
					printf("学生%d.\n",count);
					for(p=head->next;p!=NULL&&k!=count;p=p->next,k++);
					printf("姓名:%s\n",p->name);
					for(j=1;j<=sum;j++)
					{
						
						DecideoutInformation(a[j],head,count);//后面输出所要查询的东西 	
					}
					count++;	
				}
				
			} 
			printf("\n");
			printf("1.继续查询 0.退出\n");
			printf("请输入你的选择:");
			scanf("%d",&flag);
			printf("\n");
		} 
	
	}
	
 } 

int delType()//返回删除学生信息的方式
{
	int x;
	int flag=1;
	do{
		printf("1.删除单个学生的信息\n");
		//printf("2.整个专业+年级学生信息全部删除\n");
		printf("输入选择:");
		scanf("%d",&x);
		if(x==1)
		{
			printf("你选择删除单个学生信息\n");
			return 1;
		}
		/*else if(x==2)
		{
			printf("你选择整个专业+年级学生信息全部删除\n");
			return 1;
		}*/
		else
		{
			printf("输入错误，请重新输入\n");
			flag=0;
		}		
	}while(!flag);
 } 

int countList(stu *head)//统计链表里面的结点数目 
{
	int count=0;//计数器 计算总结点数 
	for(stu *p=head->next ;p!=NULL;p=p->next )//链表的遍历 
		count++;
	return count;	
}

linkList delSingleStuents(stu *head)//删除单个学生信息 
{
	int sum=countList(head);//统计已录入录入学生数 
	int count=1;
	int x;//输入的选择
	int flag=1;//判断是否删除的是合理 
	do{
		ShowMainInformation(head);
		printf("\n请输入你要删除的第几个学生:");
		scanf("%d",&x);
		if(x<0||x>sum)
		{
			printf("输入错误，不在录入学生数范围，请重新输入\n");
			flag=0;
		}
		else
		{
			stu *p,*pre=head;
			p=head->next;
			count=1;
			while(count!=x)//循环到要删除的第x个学生 
			{
				pre=pre->next;
				p=p->next;
				count++;
			}
			pre->next=p->next;//删除操作，将前驱节点后继 
			free(p);//释放节点 
			return head;
		}
			
	}while(!flag);		
}

/*linkList delMajorGrade(head)//删除专业+年级的学生信息
{
	fflush(stdin); 
	char delMaj[10];//存放要删除的专业名称
	int delGra;//要删除的年级
	printf("\n输入你要删除的专业名称") 
	
} */

linkList  delInformation(stu *head)//删除学生信息
{
	if(head->next==NULL)
	{
		printf("无学生信息\n");
	}
	else
	{
		int m=delType();//返回删除学生信息的方式
		if(m==1)
		{
			delSingleStuents(head);//删除单个学生信息 
			printf("已删除所选学生信息\n");
		}
		/*else if(m==2)
		{
			delMajorGrade(head);//删除专业+年级的学生信息
			printf("已删除所选学生信息\n"); 
		}*/
	}

 } 

linkList modifInformation(stu *head)//修改学生信息
{
	int x,count,s; 
	int flag=1;
	int m=1;//做为是否继续修改学生信息的标志 
	int sum=nodeCount(head);//统计已录入学生数 
	stu *p;
	if(head->next==NULL)
	{
		printf("无学生信息\n");
	}
	else
	{
		while(m)
		{
			
			do{ 
				ShowMainInformation(head);
				printf("选择你要修改的学生:");
				scanf("%d",&s);
				while(s>sum||s<1)
				{
					printf("无这个学生信息，请重新输入\n");
					scanf("%d",&s);
				 } 
				printf("你要修改第%d个学生的信息:\n",s); 
				classMenu();
				printf("选择你要修改的选项:");
				scanf("%d",&x);
				if(x<1||x>20)
				{
					printf("没有这个选项，请重新输入\n");
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
							
					if(x==1) strcpy(p->num,studentsNum(head,p,count));//学号信息 
					
					if(x==2) strcpy(p->name,studetsName(head,p,count));//姓名信息
				
					if(x==3) strcpy(p->sex,studentsSex(count));//学生性别
				
					if(x==4) strcpy(p->countryName,studentsCountry(count));//录入国家信息 
					
					if(x==5) strcpy(p->birth,studentsBirth(count));//学生出生日期
					
					if(x==6) strcpy(p->nationName,studentsNation(count));//录入学生民族信息 
					
					if(x==7) p->marriage =studentsMarriage(count);//录入学生婚姻状况
					
					if(x==8) strcpy(p->politicsName,studentsPolitics(count));//录入政治面貌 
				 
					if(x==9) strcpy(p->id,studentsId(count,head,p->marriage,p->birth,p->sex));
						//录入学生的身份证信息	 参数marriage,birth sex 用于检验 
						//专业 学院未录入 暂缺 
					if(x==10)p->studentCategory=studentsCategory(count);//学生类别代号
					
					if(x==11)strcpy(p->enterDay,studentsEnterDay(count,p->num));//学生入学时间 
																	//参数学号进行验证					
					if(x==12)p->studentType=studentsType(count); //录入学生入学方式 
					
					if(x==13)strcpy(p->collegeName,studentsCollege(count));//录入学院
					
					if(x==14)strcpy(p->majorName,studentsMajor(count));//录入专业 
					
					if(x==15)p->grade =studentsGrade(count,p->num);//录入年级 学号用于检验
					
				    if(x==16)p->studyLength=studentsLength(count);//录入学制 
					
					if(x==17)strcpy(p->trainLevel,studentsTrainLevel(count));//录入学生的培养层次 
					
					if(x==18)strcpy(p->classNum,studentsClass(count));//录入学生的班级号 
						
					if(x==19)strcpy(p->teaacherName,studentsTeacher(count));//录入辅导员信息
					
					if(x==20)p->score=studentsExam(count);//录入高考成绩 
	
				}
				
			}while(!flag);
			
			printf("你已修改一项信息\n");
			printf("1.继续修改 0.退出\n");				
			printf("请输入你的选择");
			scanf("%d",&m); 
	   }
	}	 
	return head;
}
	
linkList addInformation(stu *head)
{
	int m=0,i=0;
	int sum=nodeCount(head);//记录结点数目 
	int count=sum+1;//表示接下去是第count个学生 
	char strcountry[6]={"中国"} ;
	if(head->next==NULL)
		printf("现在无学生信息，你可以进行添加\n");
	else
	{
		ShowMainInformation(head);
		printf("已存在学生信息如上\n");
	}
	printf("1.选择添加学生信息  0.退出\n");
	scanf("%d",&m);
	while(m)
	{
		stu *pre;
		for(pre=head;i<sum;i++,pre=pre->next);
		printf("开始添加学生信息\n");
		
			stu *p;
			p=(stu *)malloc(sizeof(stu));//申请新的结点
			
			strcpy(p->num,studentsNum(head,p,count));//学号信息 
			
			strcpy(p->name,studetsName(head,p,count));//姓名信息
			
			strcpy(p->sex,studentsSex(count));//学生性别
			
			strcpy(p->countryName,studentsCountry(count));//录入国家信息 
			
			strcpy(p->birth,studentsBirth(count));//学生出生日期
			
			strcpy(p->nationName,studentsNation(count));//录入学生民族信息 
			
			p->marriage =studentsMarriage(count);//录入学生婚姻状况
			
			strcpy(p->politicsName,studentsPolitics(count));//录入政治面貌 
			
			if(strcmp(p->countryName ,strcountry)!=1)
			{
				strcpy(p->id,"111111111111111111");
			}
			else
			strcpy(p->id,studentsId(count,head,p->marriage,p->birth,p->sex));
			//录入学生的身份证信息	 参数marriage,birth sex 用于检验 
			//专业 学院未录入 暂缺 
			p->studentCategory=studentsCategory(count);//学生类别代号
			
			strcpy(p->enterDay,studentsEnterDay(count,p->num));//学生入学时间 
															//参数学号进行验证					
			p->studentType=studentsType(count); //录入学生入学方式 
			
			strcpy(p->collegeName,studentsCollege(count));//录入学院
			
			strcpy(p->majorName,studentsMajor(count));//录入专业 
			
			p->grade =studentsGrade(count,p->num);//录入年级 学号用于检验
			
			p->studyLength=studentsLength(count);//录入学制 
			
			strcpy(p->trainLevel,studentsTrainLevel(count));//录入学生的培养层次 
			
			strcpy(p->classNum,studentsClass(count));//录入学生的班级号 
			
			strcpy(p->teaacherName,studentsTeacher(count));//录入辅导员信息
			
			p->score=studentsExam(count);//录入高考成绩 
				
			p->next=pre->next;
			pre->next=p;	
		printf("1.继续添加信息 0.退出\n");
		printf("请输入你的选择:");
		scanf("%d",&m);
	} 		
}

int anaylyzeType()//返回分析学生信息的方式
{
	int flag=1;
	int m;
	do{
		printf("1.按照国家分析信息 2.按照民族分析信息\n");
		printf("请输入你的选择:");
		scanf("%d",&m);
		if(m==1)
		{
			printf("你选择按照国家分析信息\n");
			return 1;
		}
		else if(m==2)
		{
			printf("你选择按照民族分析信息\n");
			return 2;
		}
		else
		{
			printf("输入错误，请重新输入\n");
			flag=0;
		}
	}while(!flag);
 } 

void analyzeCountry(stu *head)//按照国家分析 
{
	char strcountry[20]; 
	stu *p;
	int count1=0;//来统计多少是中国学生 
	int count2=0;//其他国家学生 
	int flag1=0,flag2=0;
	for(p=head->next;p!=NULL;p=p->next)
	{
		strcpy(strcountry,p->countryName); 
		if(strcmp(strcountry ,"中国")==1)//如果是中国学生
		{
			printf("姓名:%s\n",p->name);
			count1++;
			flag1=1;
		 } 
	}
	if(flag1) printf("以上%d个学生来自中国\n",count1);
	//如果有是中国的学生，就输出个数 
	for(p=head->next;p!=NULL;p=p->next)
	{
		strcpy(strcountry,p->countryName);
		if(strcmp(strcountry,"中国")!=1)//如果不是中国学生
		{
			printf("姓名:%s\n",p->name);
			count2++;
			flag2=1;
		 } 
	}
	if(flag2) printf("以上%d个学来自外国\n",count2);
	
 } 
 
void analyzeNation(stu *head)//按照民族分析 
{
	stu *p; 
	int count1=0;//来统计多少是汉族学生 
	int count2=0;//其他民族学生 
	int flag1=0,flag2=0;
	char strnation[20]; 
	for(p=head->next;p!=NULL;p=p->next)
	{
		strcpy(strnation,p->nationName);
		if(strcmp(strnation,"汉族")==0)//如果是汉族学生
		{
			printf("姓名:%s\n",p->name);
			count1++;
			flag1=1;
		 } 
	}
	if(flag1) printf("以上%d个学生的民族是汉族\n",count1);
	//如果有是汉族的学生，就输出个数 
	for(p=head->next;p!=NULL;p=p->next)
	{
		strcpy(strnation,p->nationName);
		if(strcmp(strnation,"汉族")!=0)//如果是少数民族 
		{
			printf("姓名:%s\n",p->name);
			count2++;
			flag2=1;
		 } 
	}
	if(flag2) printf("以上%d个学生是少数民族或是外国血统\n",count2);
	
		
 } 

void analyzeInformation(stu *head)//统计，分析信息
{
	if(head->next==NULL)
	{
		printf("无学生信息\n");
	}
	else
	{
		int m1=anaylyzeType();//接收返回的分析学生信息的方式
		if(m1==1)
		{
			analyzeCountry(head);//按照国家分析 
		 } 
		else if(m1==2)
		{
			analyzeNation(head);//按照民族分析 
		}
		
	}

 } 


int sortType()//返回学生信息排序方式
{
	int t;
	int flag=1;
	do{
		printf("\n1.根据学号大小进行排序    2.根据年龄大小进行排序    3.根据高考成绩进行排序\n");
		printf("请选择排序方式\n");
		scanf("%d",&t);

		if(t==1)
		{
			printf("你选择根据学号大小进行排序\n");
			return 1;
		}
		else if(t==2)
		{
			printf("你选择根据年龄大小进行排序\n");
			return 2;
		}
		else if(t==3)
		{
			printf("你选择根据高考成绩进行排序\n");
			return 3;
		 } 
		 else
		 {
		 	printf("输入错误，请重新输入\n");
		 	flag=0;
		 }
		
	}while(!flag);
	
 } 

/*linkList sortNum(stu *head)//学号排序
{
//采用选择排序算法 交换结点进行成绩排序
	stu *first;  //排列后有序链的表头指针
	stu *tail;   //排列后有序链的表尾指针
	stu *p_min;  //保留键值更小的结点的前驱节点的指针
	stu *min;   //存储最小结点 
	stu *p;   //当前比较的结点
	stu *head1;
	head1=head->next;
	first=NULL;
	while(head!=NULL)//在链表中值最小的结点 
	{
		//for语句就是体现选择排序思想
		for(p=head1,min=head1;p->next!=NULL;p=p->next)
		{//循环遍历链表中的节点，找出此时最小的节点。
			if(strcmp(p->next->num,min->num)<0)//找到一个比当前min小的节点
			{
				p_min=p;//保存找到节点的前驱节点：显然p->next的前驱节点是p
				min=p->next;//保存值更小的节点
			}
		}	
			/*上面for语句结束后，就要做两件事；
            一是把它放入有序链表中；
            二是根据相应的条件判断，安排它离开原来的链表
			*/	
			//第一件事
		/*if(first==NULL)//如果链表目前还是空链表
		{
			first=min;//第一次找到值最小的结点
			tail=min;//尾指针让它指向最后的结点 
		 } 
		 else//如果链表已经有结点
		 {
		 	tail->next=min;//把刚刚找到的最小结点放到最后 
			 				//即让尾指针的next指向它 
			 tail=min;//尾指针也要指向它				
		 }
		 //第二件事
		 if(min==head1)//如果找到的最小结点就是第一个结点
		 {
		 	head1=head1->next;
		  } 
		 else//如果不是第一个节点
		 {
		 	p_min->next=min->next;//前次最小节点的next指向当前min的next,
		                 	//这样就让min离开了原链表
		  }  
	}
	if(first!=NULL)//循环得到有序链表first
	{
		tail->next=NULL;//单向链表的最后一个节点next应该指向NULL 
	}
	head->next=first;
	return head; 	
	
 }*/ 
 
linkList sortNum(stu *head)//学号排序
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
 
linkList sortAge(stu *head)//根据年龄大小排序 
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
//linkList sortAge(stu *head)//年龄大小排序
//{
////采用选择排序算法 交换结点进行成绩排序
//	stu *first;  //排列后有序链的表头指针
//	stu *tail;   //排列后有序链的表尾指针
//	stu *p_min;  //保留键值更小的结点的前驱节点的指针
//	stu *min;   //存储最小结点 
//	stu *p;   //当前比较的结点
//	first=NULL;
//	int flag = 1;
//	while(head!=NULL)//在链表中值最小的结点 
//	{
//		//for语句就是体现选择排序思想
//		for(p=head,min=head->next;p->next!=NULL;p=p->next)
//		{//循环遍历链表中的节点，找出此时最小的节点。=
//			flag = 1;
//			{
//				p_min=p;//保存找x//保存值更小的节点
//				flag = 0; 
//			}
//		}	
//			/*上面for语句结束后，就要做两件事；
//            一是把它放入有序链表中；
//            二是根据相应的条件判断，安排它离开原来的链表
//			*/	
			//第一件事
//		if(first==NULL)//如果链表目前还是空链表
//		{
//			first->next=min;//第一次找到值最小的结点
//			tail->next=min;//尾指针让它指向最后的结点 
//		 } 
//		 else//如果链表已经有结点
//		 {
//		 	tail->next=min;//把刚刚找到的最小结点放到最后 
//			 				//即让尾指针的next指向它 
//			 tail=min;//尾指针也要指向它				
//		 }
//		 //第二件事
//		 if(min==head)//如果找到的最小结点就是第一个结点
//		 {
//		 	head=head->next;
//		  } 
//		 else//如果不是第一个节点
//		 {
//		 	p_min->next=min->next;//前次最小节点的next指向当前min的next,
//		                 	//这样就让min离开了原链表
//		  }  
//	}
//	if(first!=NULL)//循环得到有序链表first
//	{
//		tail->next=NULL;//单向链表的最后一个节点next应该指向NULL 
//	}
//	head = first;
//	return head;	
//	
//} 
 
linkList sortScore(stu *head)//高考成绩排序
{
//采用选择排序算法 交换结点进行成绩排序
	stu *first;  //排列后有序链的表头指针
	stu *tail;   //排列后有序链的表尾指针
	stu *p_min;  //保留键值更小的结点的前驱节点的指针
	stu *min;   //存储最小结点 
	stu *p;   //当前比较的结点
	first=NULL;
	while(head!=NULL)//在链表中值最小的结点 
	{
		//for语句就是体现选择排序思想
		for(p=head,min=head;p->next!=NULL;p=p->next)
		{//循环遍历链表中的节点，找出此时最小的节点。
			if(p->next->score < min->score)//找到一个比当前min小的节点
			{
				p_min=p;//保存找到节点的前驱节点：显然p->next的前驱节点是p
				min=p->next;//保存值更小的节点
			}
		}	
			/*上面for语句结束后，就要做两件事；
            一是把它放入有序链表中；
            二是根据相应的条件判断，安排它离开原来的链表
			*/	
			//第一件事
		if(first==NULL)//如果链表目前还是空链表
		{
			first=min;//第一次找到值最小的结点
			tail=min;//尾指针让它指向最后的结点 
		 } 
		 else//如果链表已经有结点
		 {
		 	tail->next=min;//把刚刚找到的最小结点放到最后 
			 				//即让尾指针的next指向它 
			 tail=min;//尾指针也要指向它				
		 }
		 //第二件事
		 if(min==head)//如果找到的最小结点就是第一个结点
		 {
		 	head=head->next;
		  } 
		 else//如果不是第一个节点
		 {
		 	p_min->next=min->next;//前次最小节点的next指向当前min的next,
		                 	//这样就让min离开了原链表
		  }  
	}
	if(first!=NULL)//循环得到有序链表first
	{
		tail->next=NULL;//单向链表的最后一个节点next应该指向NULL 
	}
	head=first;
	return head;	
 }

linkList sortInformation(stu *head)//排序学生信息
{
	int t;
	if(head->next==NULL)
	{
		printf("无学生信息\n");
	}
	else
	{
		t=sortType();
		switch(t)
		{
			case 1:
			{
				sortNum(head);//学号大小进行排序 
				printf("\n排序成功");
				break;
			}
			case 2:
			{
				sortAge(head);//年龄大小进行排序 
				printf("\n排序成功");
				break;
			}
			case 3:
			{
				sortScore(head);//高考成绩进行排序
				printf("\n排序成功");
				break;	
			}	
		}
	}
}

void showInformation(stu *head)//将学生信息输出到屏幕上 
{
	int count=1;
	int n;
	stu *p=NULL;
	if(head->next==NULL)
	{
		printf("无学生信息\n");
	}
	else
	{
		for(p=head->next;p!=NULL;p=p->next)//遍历链表输出信息 
		{
			fflush(stdin);
			printf("学生%d.\n",count);
			printf("学号:%s\n",p->num);
			printf("姓名:%s\n",p->name);
			printf("性别:%s\n",p->sex);
			printf("国家:%s\n",p->countryName); 
			printf("出生日期:%s\n",p->birth);
			printf("民族:%s\n",p->nationName);
			printf("婚姻状况:%s\n",marType(p->marriage));
			printf("政治面貌:%s\n",p->politicsName);
			printf("身份证号码:%s\n",p->id); 
			printf("学生类别:%s\n",stuCategory(p->studentCategory)); 
			printf("学生入学日期:%s\n",p->enterDay);
			printf("入学方式:%s\n",studentsTypeName(p->studentType));
			printf("学院名称:%s\n",p->collegeName);
			printf("专业名称:%s\n",p->majorName); 
			printf("年级:%d\n",p->grade);
			printf("学制:%d年\n",p->studyLength);
			printf("培养层次:%s",p->trainLevel);
			printf("\n");
			printf("班级:%s\n",p->classNum);
			printf("辅导员:%s\n",p->teaacherName);
			printf("高考成绩:%d\n",p->score);
			printf("\n");
			count++;
		}		
	}
}

void ToFileInformation(stu *head)//将学生信息输入到文件中
{
	int count=1;
	stu *p=NULL;
	FILE *pwrite;
	pwrite=fopen("information.txt","w");
	if(pwrite==NULL)
		return ;
	if(head->next ==NULL)
		printf("无学生信息\n");
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
												//写入数据到文件中  
			printf("\n");//一个学生的信息跟另外一个学生信息之间要空一行									
			++count;
			//if(count%5==0)
			//	fprintf(pwrite,"\r\n");
		}
		fclose(pwrite);//关闭文件 
	}
	
	if(countList(head))//如果链表为空自然没有数据可以存入文件中	 	
		printf("已将%d个学生信息读入到文件\"221600320_李宜剑_information.txt\"中\n",countList(head));	
}

void freeList(stu *head)//释放链表
{
	stu *p=head;// 一开始p指向哨兵  
	while(p!=NULL)//开始遍历链表 
	{
		p=head->next;//当前结点的下一个结点赋给p 
		free(head);//释放掉当前结点 
		head=p;//当前结点指向下一个 
	 } 
 }   
