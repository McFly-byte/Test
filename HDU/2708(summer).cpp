#include <iostream>//水题 通过率低是有原因的 根本没说有多组输入 
#include <cstring>
using namespace std;

int num[27]; 

int find_max_rowid( int * a , int maxn );

int main()
{
	string str1 , str2 , str3 , str4 , str;
	while( getline(cin,str1)&&getline(cin,str2)&&
		   getline(cin,str3)&&getline(cin,str4) ){		//system("pause");
		memset( num , 0 , 27*sizeof( int) );
		str = str1 + str2 + str3 + str4;
		for( int i = 0 ; i < str.length() ; i++ ){
			if( str[i] >='A' && str[i] <= 'Z' )	num[str[i]-'A'+1]++;
		}
	
	int maxn = num[1];
	for( int i = 2 ; i <= 26 ; i++ ){
		if( num[i] > maxn )	maxn = num[i];
	}
	for( int i = maxn ; i > 0 ; i-- ){
		int maxid = find_max_rowid( num, i );
		for( int j = 1 ; j <= maxid ; j++ ){
			if( num[j] >= i ) cout << '*';
			else cout << ' ';
			if( j != maxid ) cout << ' ';
		}
		cout << endl;
	}
	for( int i = 0 ; i < 26 ; i++ ){
		if( i ) cout << ' ';
		cout << char( 65 + i ) ;
	}
	cout << endl;
	}
}

int find_max_rowid( int * a , int maxn )
{
	int maxid = 1;
	for( int i = 1 ; i <= 26 ; i++ ){
		if( a[i] >= maxn ) maxid = i;
	}
	return maxid;
 } 
