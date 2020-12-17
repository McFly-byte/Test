#include <iostream>
#include <queue>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct node{
	string name;
	int num , time;
	friend operator < ( node a , node b ){
		if( a.num == b.num && a.time == b.time ) return a.name > b.name;
		if( a.num == b.num ) return a.time > b.time;
		return a.num < b.num;
	}
}stu;

int main()
{
	int n, m;
	cin >> n >> m;
	priority_queue<node> q;
	string grade;
	int tm;
	while( cin >> stu.name ){
		stu.num = 0;
		stu.time = 0;
		for( int i = 0 ; i < n ; i++ ){
			cin >> grade;
			tm = 0; 
			if( grade.find( '(' ) != grade.npos ){
				int foul = 0;
				for( int j = grade.find('(')+1 ; j < grade.find(')') ; j++ ){
					foul *= 10;
					foul += grade[j]-'0';
				}
				for( int j = 0 ; j < grade.find('('); j++ ){
					tm *= 10;
					tm += grade[j]-'0';
				}
				stu.time += ( tm + foul*m );
				stu.num++;
			}		
			else {
				tm = atoi( grade.data() );
				//cout << "tm: " << tm << endl;
				if( tm <= 0 ) continue;
				else {
					stu.time += tm;
					stu.num++; 
				}
			}
			//cout << "name " << stu.name << " num: " << stu.num << " time: " << stu.time << endl;
		}
		q.push( stu );
	}
	while ( !q.empty() ){
		stu = q.top();
		cout <<  std::left << setw( 10 ) << stu.name << ' ';
		cout << std::right << setw( 2 ) << stu.num << ' ' << setw( 4 ) << stu.time << endl;
		q.pop();
	}
 } 
 
 //8 20 Smitm -1 -16 8 0 0 120 39 0
 //去掉tab ， 重新提交一下
 //总结一下itoa find的用法
 //为什么tab复制过来再粘贴就消失了？
/* 
8 20
Smith -1 -16 8 0 0 120 39 0
John 116 -2 11 0 0 82 55(1) 0
Josephus 72(3) 126 10 -3 0 47 21(2) -2
Bush 0 -1 -8 0 0 0 0 0
Alice -2 67(2) 13 -1 0 133 79(1) -1
Bob 0 0 57(5) 0 0 168 -7 0
*/ 
