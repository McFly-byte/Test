#include <iostream>
using namespace std;

int main()
{
	int T , n;
	cin >> T;
	while( T-- ){
		cin >> n;
		for( int i = 1 ; i <= n ; i++ ){//注意不要打多余的空格 
			for( int j = 1 ; j <= i || j <= n-i+1 ; j++ ){
				if( j == i || j == n - i + 1 ) cout << 'X';
				else cout << ' ' ;
			}
			cout << endl;
		}
		cout << endl;
	}
 } 
