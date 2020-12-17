#include <iostream>
using namespace std;

int A,B;
int a[52];
/*
int f( int n ){
	if( n == 1 || n == 2 ) return 1;
	return ( A*f(n-1) ) + ( B*f(n-2) ) % 7 ; 
}
//(A * f(n - 1) + B * f(n - 2)) mod 7.

int main()
{
	int N;
	while ( cin >> A >> B >> N , ( A || B || N ) ){
		cout << f( N%49 ) << endl;
	}
}*/

int main()
{
	int N;
	while ( cin >> A >> B >> N , ( A || B || N ) ){
		int i;
		a[1] = a[2] = 1; 
		for( i = 3 ; i < 52 ; i++ ){
			a[i] = ( A*a[i-1] + B*a[i-2] ) % 7;
			if( a[i] == 1 && a[i-1] == 1 ) break;
		}
		a[0] = a[i-2];
		cout << a[N%(i-2)] << endl;
	}
}
