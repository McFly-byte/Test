#include <iostream>
using namespace std;

int main()
{
	string s;
	int count = 0;
	while( getline( cin , s ) ){
		int len = s.size();//不用len会出错？ 
		for( int i = 0 ; i < len-3 ; i++ ){
			if( ( s[i] == 'D' || s[i] == 'd') && 
				( s[i+1] == 'O' || s[i+1] == 'o' ) &&
				( s[i+2] == 'G' || s[i+2] == 'g' ) &&
				( s[i+3] == 'E' || s[i+3] == 'e' ) ){
					count++;
				}
		}
	}
	cout << count << endl;;
 } 
