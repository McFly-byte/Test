#ifndef PIGFARM_H
#define PIGFARM_H

#include <bits/stdc++.h>
using namespace std;

#define market_weight 100 //最低销售体重 
#define simulation_duration 360  //模拟时长 10年 

enum breed{ Black = 1 , White , Colorful }; //品种  

extern char datafile[50];
extern char dayfile[50];
extern char filename[50];
extern char illfile[50];
extern int a[100][10];			//a 用来模拟， sickPig用来记录真实数据 
extern int sickPig[100][10];    //病猪数组  准备深搜了 
extern int sickId[2];
extern ofstream fout;
extern int FarmTime;		//猪场时间 
extern double Expense; 		//总支出 
extern double Income; 		//总收入 
extern double Cost[4];		//购价 
extern double Price[4];		//售价 

typedef struct Pig * pig;
struct Pig{
	int ID;//编号 
	breed Breed;//品种 
	double Weight;//体重 
	int Time;//饲养时间 
	int LifeSpan;//是否生病/剩余生命 
};

typedef struct Pigsty * pigsty;
struct Pigsty{
	int ID;//猪圈编号 
	int amount[4];//0-总数，1-黑，2-白，3-花 
	Pig sty[10];//把猪放入 
	pigsty Next;
}; 

typedef struct Pigfarm * pigfarm;
struct Pigfarm{
	int Farm_Time;//农场时间,用于整体的操作，与个体无关 
	pigsty Head;//第零个猪圈前一个位置，虚指 
};

bool isQualified( pig obj );//判断是否达到出售标准 

void grow( pig obj );//一头猪的饲养时间（方便于查询）和体重增长。 

void gain( pigfarm p , int time = 1 );//整个养猪场增长 

void sellAndBuy( pigfarm p );//卖出并补入新猪 

double sellPig( pigsty sty , int pig_id );//卖一头猪 返回收益 

double buyPig( pigsty sty , int Id );//买一头猪，记录花费 

pigsty CreatePigsty( int id );//创建新的猪圈 

pigfarm CreatePigfarm();//创建新的场 

void printPig( pigfarm p , int Id1 , int Id2 );// 打印某头猪的状态信息

void printPig( pig obj , int Sty_Id );//同上 函数重载 

void printPigsty( pigfarm p , int Id );//打印某一猪圈的猪的数量和种类 

void printPigfarm( pigfarm p );//打印猪场每个品种猪的数量和体重分布情况 

void saveIofor( pigfarm p ); //将猪场信息存放到txt文件中 

void getSick(); //猪瘟爆发了

int simulation( int period );//模拟传染 period天后多少头猪被感染 

void Welcome_to_the_( pigfarm p ); //欢迎语 

void startTime( pigfarm p , int maxTime , int sickTime = 1000000 ); 

void method( pigfarm p , int sickTime );

#endif 
