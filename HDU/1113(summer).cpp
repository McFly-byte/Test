#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>

using namespace std;

typedef struct Word *word;
struct Word{
	char S[10];
	word ThisKind;
};

typedef struct Dict * dict;
struct Dict{
	int length;
	dict NextKind;
	word ThisKind;
}; 


bool isSame( char * A , char * B );
dict CreateD( ); 
bool InsertD( char * S , dict D );
void Getem( char * str , dict D );

int main()
{
	char target[10] = {0};
	dict D = CreateD();
	while( cin >> target && strcmp( target , "XXXXXX" ) != 0 ){
		InsertD( target , D );
		memset( target , 0 , 10 );
	}
	while( cin >> target && strcmp( target , "XXXXXX" ) != 0 ){
		Getem( target , D );
		cout << "******" << endl;
		memset( target , 0 , 10 );
	}
} 
 
bool isSame( char * A , char * B , int len )
{
	char a[10];
	char b[10];
	strcpy( a , A ) , strcpy( b , B );
	sort( a , a + len ) , sort( b , b + len );
	if( !strcmp( a , b ) )	return true;
	return false;
}

dict CreateD()
{
	dict D = ( dict )malloc( sizeof( struct Dict ) );
	D->length = 0;
	D->NextKind = NULL;
	D->ThisKind = NULL;
	return D ;
}

bool InsertD( char * str , dict D )
{
	int len = strlen( str );
	dict tag = D;
	while( tag->NextKind != NULL ){
		if( len > tag->NextKind->length )	tag = tag->NextKind;
		else if( len == tag->NextKind->length ){
			tag = tag->NextKind;
			word temp = ( word )malloc( sizeof( struct Word ) );	
			temp->ThisKind = tag->ThisKind;
			word flag = temp;	
			bool button = false;
			while( flag->ThisKind ){
				if( strcmp( str , flag->ThisKind->S ) > 0 ){
					flag = flag->ThisKind;
					button = true;
				}
				else if( strcmp( str , flag->ThisKind->S ) < 0 ){
					word tmp = ( word )malloc( sizeof( struct Word ) );
					strcpy( tmp->S , str );
					tmp->ThisKind = flag->ThisKind;
					flag->ThisKind = tmp;
					if( !button ){
						tag->ThisKind = tmp;
						button = true;
					}
					free( temp );
					return true;
				}
			} 
			word tmp = ( word )malloc( sizeof( struct Word ) );
			strcpy( tmp->S , str );
			tmp->ThisKind = NULL;				
			flag->ThisKind = tmp;
			free( temp );
			return true;
		}
		else{
			dict temp1 = ( dict )malloc( sizeof( struct Dict ) );
			temp1->length = len;
			temp1->NextKind = tag->NextKind;
			tag->NextKind = temp1;
			word temp2 = ( word )malloc( sizeof( struct Word ) );
			strcpy( temp2->S , str );
			temp2->ThisKind = NULL;
			temp1->ThisKind = temp2;
			return true;
		}
	}	
	dict temp1 = ( dict )malloc( sizeof( struct Dict ) );
	temp1->length = len;
	temp1->NextKind = NULL;
	tag->NextKind = temp1;
	word temp2 = ( word )malloc( sizeof( struct Word ) );
	strcpy( temp2->S , str );
	temp2->ThisKind = NULL;
	temp1->ThisKind = temp2;
	return true;
}

void Getem( char * str , dict D )
{
	int slen = strlen( str );
	dict tag = D->NextKind ;
	while( tag ){
		if( tag->length < slen )	tag = tag->NextKind;
		else if( tag->length > slen ){
			cout << "NOT A VALID WORD" << endl;
			return ;
		}
		else{
			word flag = tag->ThisKind;
			bool isturn = false;
			while( flag ){
				if( isSame( str , flag->S , slen ) ){
					cout << flag->S << endl;
					isturn = true;
				}
				flag = flag->ThisKind;
			}
			if( !isturn ) cout << "NOT A VALID WORD" << endl;
			return ; 
		}
	}
	cout << "NOT A VALID WORD" << endl;
}
