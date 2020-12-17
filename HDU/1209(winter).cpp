#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

//21:00 15:00 09:00 06:00 03:00 
//小心角度一样时的比较哦 
class Angle{
	public:
		double ang;
		int id;
	friend class Time;
}; 

class Time{
	public:
		string t;
		int hh , mm;
		Angle angle;
		void getAngle();
};

void Time::getAngle( ){
	int h = hh%12, m = mm;
	double h_angle = h*30+m*0.5, m_angle = m*6;
	double result = abs( h_angle - m_angle );
	if( result > 180 ) result = 360 - result;
	this->angle.ang = result;
}

/*bool cmp( Time a , Time b ){
	if( a.angle.ang > b.angle.ang ) return true;
	return false;
}*/

int main()
{
	int T;
	cin >> T;
	while ( T-- ){
		char s[10];
		Time a[5];
		for( int i = 0 ; i < 5 ; i++ ){
			cin >> s;
			a[i].t = s;//可以直接赋值 
			a[i].hh = atoi( strtok( s,":") );//字符串操作 
			a[i].mm = atoi( strtok( NULL,":" ) );
			a[i].getAngle();
			a[i].angle.id = i;
		}
		//system( "pause" );
		for( int i = 0 ; i < 4 ; i++ ){
			for( int j = 4; j > i; j-- ){
				if( a[j].angle.ang < a[j-1].angle.ang )
				{
					swap( a[j].angle.ang , a[j-1].angle.ang );
					swap( a[j].mm , a[j-1].mm );
					swap( a[j].hh , a[j-1].hh );
					swap( a[j].t , a[j-1].t );
					//swap( a[j].angle.id , a[j-1].angle.id );
				}
				else if( a[j].angle.ang == a[j-1].angle.ang ){
					if( a[j].hh < a[j-1].hh || 
					    a[j].hh == a[j-1].hh && a[j].mm < a[j-1].mm )
					{
						swap( a[j].angle.ang , a[j-1].angle.ang );
						swap( a[j].mm , a[j-1].mm );
						swap( a[j].hh , a[j-1].hh );
						swap( a[j].t , a[j-1].t );
						//swap( a[j].angle.id , a[j-1].angle.id );
					}
				}
			}
		}
		//system( "pause" );
		cout << a[2].t << endl;
	}
}
