#include <iostream>
#include <cstring>
using namespace std;

void PrintDigits( string , int );
void PrintLine( char ch, int row , int size );

int main()
{
	int size;
	string digits;
	bool flag = false;
	while( cin >> size ){
		cin >> digits;
		if( !size ) break;
		PrintDigits( digits , size );
		cout << endl;
	}
}

void PrintDigits( string str, int n )
{
	int Len = str.length() , Row = n*2+3;
	for( int i = 0 ; i  < Row ; i++ ){
		for( int k = 0 ; k < Len ; k++ ){
			PrintLine( str[k] , i , n );
			if( k != Len-1 )
				cout << ' ' ;
		}
		cout << endl;
	}
}

void PrintLine( char ch, int row , int n )
{
	int lie = n + 2 , obj = ch-'0';
	if( row == 0 ){
		if( obj != 1 && obj != 4 ){
			cout << ' ';
			for( int i = 1 ; i < n+1 ; i++ ){
				cout << '-';
			}
			cout << ' ';
		}				
		else{
			for( int i = 1 ; i <= n+2; i++ )	cout << ' '; 
		}				
	}
	else if( row > 0 && row < n+1 ){
		if( obj == 5 || obj == 6 ){
			cout << '|' ;
			for( int i = 1 ; i <= n+1 ; i++ )	cout << ' ';
		}
		else if( obj == 7 || obj >= 1 && obj <= 3 ){
			for( int i = 1 ; i <= n+1 ; i++ )	cout << ' ';
			cout << '|' ;
		}
		else{
			cout << '|' ;
			for( int i = 1 ; i <= n ; i++ )	cout << ' ' ;
			cout << '|' ; 
		}
	}
	else if( row == n+1 ){
		if( obj == 1 || obj == 7 || obj == 0 ){
			for( int i = 1 ; i <= n+2; i++ )	cout << ' '; 
		}
		else {
			cout << ' ';
			for( int i = 1 ; i < n+1 ; i++ ){
				cout << '-';
			}
			cout << ' ';
		}
	}
	else if( row > n+1 && row < n*2+2 ){
		if( obj == 6 || obj == 8 || obj == 0 ){
			cout << '|';
			for( int i = 0 ; i < n; i++ )	cout << ' ' ;
			cout << '|';
		}
		else if( obj == 2 ){
			cout << '|';
			for( int i = 0 ; i <= n ; i++ )	cout << ' ';
		}
		else {
			for( int i = 0 ; i <= n ; i++ )	cout << ' ';
			cout << '|';
		}
	}
	else if( row == n*2+2 ){
		if( obj == 1 || obj == 4 || obj == 7 ){
			for( int i = 1 ; i <= n+2; i++ )	cout << ' '; 
		}
		else {
			cout << ' ';
			for( int i = 1 ; i < n+1 ; i++ ){
				cout << '-';
			}
			cout << ' ';
		}
	}
	
}
