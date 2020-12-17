/*感觉像深搜，写不出来了 
2 2 2 1
aa
a
3 3 3 3
aaa
ba
bba
3 3 3 1
aaa
ba
bba
3 3 3 3
aaa
Ea
aab
*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

char a[102][102];

int isDetonate( int h , int w );

int main()
{
	int H, W, h, w;
	while ( cin >> H >> W >> h >> w ){
		memset( a , 0 , sizeof( a ) );
		string str;
		for( int i = 1 ; i <= H ; i++ ){
			cin >> str;
			strcpy( a[i] , str.data() );
		}
		int num = 0, count = isDetonate( h , w );
		if( count < 3 ){
			cout << num << endl;
			continue;
		}
		else {
			
		}
	}
} 

int isDetonate( int h , int w )
{
	char ch = a[h][w];
	int count = 1;
	if( a[h-1][w] == ch ){
		count++;
		a[h-1][w] = 'E';
	} 
	if( a[h-1][w-1] == ch ){
		count++;
		a[h-1][w-1] = 'E';
	} 
	if( a[h][w-1] == ch ){
		count++;
		a[h][w-1] = 'E';
	} 
	if( a[h+1][w-1] == ch ) {
		count++;
		a[h+1][w-1] = 'E';
	} 
	if( a[h+1][w] == ch ) {
		count++;
		a[h+1][w] = 'E';
	} 
	if( a[h+1][w+1] == ch ) {
		count++;
		a[h+1][w+1] = 'E';
	} 
	return count;
}
