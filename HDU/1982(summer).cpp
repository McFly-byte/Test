#include <iostream>//小心---###-的情况，会PE 
#include <cstring>//不能用strtok，遇到上述情形不知该输出多少空格 
#include <stdlib.h>
using namespace std;

char code[10001];

int main()
{
	int T , len , digit;
	cin >> T;
	while( T-- ){
		memset( code , 0 , 10001 );
		cin >> code ;
		len = strlen( code );
		for( int i = 0 ; i < len ; i++ ){
			if( code[i] == '#' )	cout << ' ';
			else if( code[i] == '-' )	continue;
			else if( isdigit( code[i] ) && isdigit( code[i+1] ) ){
				digit = (code[i] - '0')*10 + (code[i+1] - '0');
				cout << char( 64 + digit );
				i++;
			}
			else  cout << char( 64 + (code[i] - '0') );
		}
		cout << endl;
	}
 } 
/* 
int main()
{							
	int T , value , len;
	cin >> T;
	char * operate;
	//getchar(); 
	while( T-- ){
		memset(code,0,10001);
		cin >> code ;//system("pause");
		operate = strtok( code , "#" );//	system("pause");
		while( operate != NULL ){	
			len = strlen( operate );	//system("pause");
			for( int i = 0 ; i < len ; i++ ){
				if( operate[i] == '-' )	continue;
				else if( isdigit( operate[i] ) ){
					if( isdigit( operate[i+1] ) ){
						value = ( operate[i] - '0' )*10 + ( operate[i+1] - '0');
						i++;	
					}
					else 
						value = operate[i] - '0';
					cout << char( 64 + value ) ;	
				}
			}	//system("pause");
			operate = strtok( NULL , "#" );
			if( operate != NULL )
				cout << ' ';
		}
		cout << endl;
	} 
}*/ 
