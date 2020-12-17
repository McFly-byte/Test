#include <iostream>
using namespace std;

int cet6[5] = { 15, 7, 4, 2, 1 };

int main()
{
	int n;
	while( cin >> n ){
		for( int i = 0 ; i < 5 ; i++ ){
			if( n-cet6[i] < 1 ) continue;
			else cout << n-cet6[i];
			if( i != 4 ) cout << ' ';
		}
		cout << endl;
	}
 } 
