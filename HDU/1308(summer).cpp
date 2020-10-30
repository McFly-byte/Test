#include <iostream>
#include <cstring>
using namespace std;

bool isLeap( int Year );
bool isIllegal( int Year , int Mon , int Day );
int Weekday( int Year , int Mon , int Day );

string mon[13] = { "\0" , "January" , "February" , "March" , "April" , "May" , "June" ,
				"July" , "August" , "September" , "October" , "November" , "December" };
string wkday[7] = { "Monday" , "Tuesday" , "Wednesday" , "Thursday" , 
					"Friday" , "Saturday" , "Sunday" };

int main()
{
	int year , month , day , wkd;
	while( cin >> month >> day >> year && ( year+month+day ) ){
		if( isIllegal( year,month,day ) ) {
			cout << month << '/' << day << '/' << year << " is an invalid date." << endl;
			continue;
		}
		//system("pause");
		wkd = Weekday( year , month , day );
		//system("pause");
		cout << mon[month] << ' ' << day << ", " << year << " is a " << wkday[wkd] << endl;
	}
	return 0;
 } 
 
bool isLeap( int Year )
{	
	return ( Year % 400 == 0 ) || ( Year % 4 == 0 && Year % 100 != 0 );
}

bool isIllegal( int Year , int Mon , int Day )
{
	if( Year < 0 || Mon < 1 || Mon > 12 || Day < 1 || Day > 31 )
		return true;
	if( Year == 1752 && Mon == 9 && ( Day > 2 && Day < 14 ) )
		return true;
	if( Mon == 4 || Mon == 6 || Mon == 9 || Mon == 11 ){
		if( Day > 30 ) return true;
	}
	else if( Mon == 2 ){
		if( isLeap( Year ) && Day > 29 || !isLeap( Year ) && Day > 28 )
			return true;
	}
	return false;
}

int Weekday( int Year , int Mon , int Day )//基姆拉尔森计算公式 
{
	if( Mon == 1 || Mon == 2 ) {//遇到1，2月视为上一年的13，14月 
		Mon += 12;
		Year--;
	}
	if( Year > 1752 || Year == 1752 && Mon > 9 || Year == 1752 && Mon == 9 && Day >= 14 )
		return (Year + Year /4 + Year / 400 - Year / 100 + 2 * Mon + 3 * (Mon + 1)/5 + Day) % 7;
	else 
		return (4 + Year + Year /4 + Year / 400 - Year / 100 + 2 * Mon + 3 * (Mon + 1)/5 + Day) % 7; 	
}
