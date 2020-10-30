#include <iostream>

using namespace std;

int main()
{
	int N , flag = 1 , n , sheet , pageid;
	while( cin >> N && N ){
		if( N == 1 ){
			cout << "Printing order for 1 pages:\nSheet 1, front: Blank, 1\n";
			continue;
		}
		
		cout << "Printing order for " << N << " pages:" << endl;
		
		if( N % 4 == 0 ) n = N+1;
		else n = N + 5 - ( N % 4 );
		sheet = n / 4;
		pageid = n-1;
		
		for( int i = 2 ; i < sheet*2+2; i++ ){
			
			cout << "Sheet " << i/2 ;
			if( i % 2 ) cout << ", back : ";
			else cout << ", front: ";
			
			if ( pageid > N ) cout << "Blank, ";
			else cout << pageid << ", ";
			if ( ( n-pageid > N ) ) cout <<"Blank" << endl;
			else cout << n-pageid <<endl;
			
			if( i % 2 ) pageid = n - pageid - 1;
			else pageid = n - pageid + 1;
		}
	}
} 
