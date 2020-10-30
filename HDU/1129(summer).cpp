#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int k , len;
	string code , text;
	while( cin >> k ){
		if( !k ) break;
		cin >> code;
		len = code.length() ;
		for( int i = 0 ; i < len ; i++ ){
			if( code[i] == '.' ) code[i] = 27;
			else if( code[i] == '_') code[i] = 0;
			else code[i] = code[i] - 'a' + 1;
		}
		for( int j = 0; j < len ; j++ ){
			text[(j*k)%len] = ( code[j] + j ) % 28;
		}
		for( int j = 0 ; j < len ; j++ ){
			if( text[j] == 0 ) text[j] = '_';
			else if( text[j] == 27 ) text[j] = '.';
			else text[j] = 'a' + text[j] - 1; 
			cout << text[j] ; 
		}
		cout << endl;
	}
 } 
