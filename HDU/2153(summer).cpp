#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n , max_num , sum;
	while( cin >> n && n ){
		max_num = 4 * ( n - 1 );
		sum = max_num + n + 1;
		for( int i = 1 ; i <= n ; i++ )
			cout << setw(3) << i;
		cout << endl;
		for( int i = 0 ; i < n-2 ; i++ ){
			for( int j = 1 ; j < n ; j++ ){
				if( j == 1 ) cout << setw(3) << max_num - i;
				if( j == n-1 ) cout << setw(3) << sum - max_num + i;
				else cout << "   ";
			}
			cout << endl;
		}
		if( n != 1 ){
			for( int i = 1 ; i <= n ; i++ )
				cout << setw(3) << max_num-n+3-i;
			cout << endl;
		}
			
	}
 } 
