#include <iostream>
using namespace std;

int main()
{
	int n;
	char a[2];
	bool flag = false;
	while( cin >> n ){
		if( flag ) cout << endl;
		flag = true;//因为不知道什么时候文件结束，故空行应如此操作 
		if( n % 4 == 3 ) cin >> a[0] >> a[1] ;
		else if( n % 4 == 1 ) cin >> a[1] >> a[0];//a[1]永远存储第一行呀打印的元素 
		if( n == 1 ){//n=1的情形别疏忽了 
			cout << a[1] << endl;
			continue;
		} 
		for( int i = 1; i <= n; i++ ){
			if( i == 1 || i == n ){
				cout << ' ';
				for( int j = 1 ; j <= n-2 ; j++ )	cout << a[1] ;
				cout << ' ' << endl;//空格不能少 
			}
			else if( i == n/2+1 ){
				for( int j = 1 ; j <= n ; j++ )	cout << a[j%2]; 
				cout << endl;
			}
			else if( i > 1 && i <= n/2 ){
				for( int j = 1 ; j < i ; j++ )	cout << a[j%2];
				for( int k = 1 ; k <= 2+n-i*2 ; k++ ) cout << a[i%2];
				for( int j = i-1 ; j >= 1; j-- ) cout << a[j%2];
				cout << endl;
			} 
			else {//直接复制（1，n/2+1）的情况 
				int l = n-i+1;
				for( int j = 1 ; j < l ; j++ )	cout << a[j%2];
				for( int k = 1 ; k <= 2+n-l*2 ; k++ ) cout << a[l%2];
				for( int j = l-1 ; j >= 1; j-- ) cout << a[j%2];
				cout << endl;
			}
		}
	}
 } 
