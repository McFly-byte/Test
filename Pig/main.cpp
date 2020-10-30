#include <iostream> 
#include "PigFarm.h"
using namespace std;

char filename[50] = "information.txt";	//存放猪场扩展信息 
char datafile[50] = "data.txt";			//存放猪场全部属性 
char dayfile[50] = "Day.txt";			//存放猪场相对日期 
char illfile[50] = "illness.txt";		//存放猪瘟模拟信息
int a[100][10] = {0}; 
int sickPig[100][10] = {0}; 			//生病的猪对应的数组 
int sickId[2];
ofstream fout( filename , ios::app );
int FarmTime = 0;
double Expense = 0;
double Income = 0;
double Cost[4] = { 0.0 , 9.0 , 4.0 , 2.0 };
double Price[4] = { 0.0 , 15.0 , 7.0 , 6.0 };

int main() 
{
	srand((unsigned)time(NULL));			//时间种子 
	pigfarm pig_farm = CreatePigfarm();		//创建一个猪场 
	Welcome_to_the_(pig_farm); 				//对此猪场的一系列描述 
	fout.close();							//关闭全局文件 
	return 0;
}
