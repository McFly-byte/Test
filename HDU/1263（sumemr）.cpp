#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

typedef struct Detail *detail;
struct Detail{
	char * production_place;
	char * fruit;
	int amount ;
	detail Next;
};//依次存放产地、水果品种、数量、下一种水果信息的指针 

int T； 
detail CreateNew();//关键是插入 
detail Insert( char * , char * , int , detail );
void Print( detail );

int main()
{
	int N , Amount;
	char f[81] , p[81];
	cin >> T;
	while( T-- ){
		detail H = CreateNew();
		cin >> N;
		while( N-- ){
			memset( f , 0 , 81 );
			memset( p , 0 , 81 );
			cin >> f >> p >> Amount;
			H = Insert( p, f, Amount, H ); 
		}
		Print( H );
	} 
}

detail CreateNew()
{
	detail Head = (detail)malloc( sizeof( struct Detail ) ); 
	Head->amount = 0;
	Head->Next = NULL;
	return Head;
}

detail Insert( char * place, char * kind, int amnt , detail Head )
{
	detail head = Head , rear = Head->Next;
	while( rear ){
		if( strcmp(rear->production_place,place) < 0 ){
			head = rear;
			rear = rear->Next;
		}
		else if( !strcmp( rear->production_place , place ) ){
			if( !strcmp(rear->fruit,kind) ){
				rear->amount += amnt;
				return Head;
			}
			else if( strcmp( rear->fruit , kind ) < 0 ){
				head = rear;
				rear = rear->Next;
			}
			else break;
		}
		else
			break;
	}
	detail tmp = ( detail )malloc( sizeof( struct Detail ) );
	tmp->production_place = (char *)malloc((strlen( place )+10) * sizeof(char));
	tmp->fruit = (char *)malloc( ( strlen( kind ) + 10 ) * sizeof( char ) );
	strcpy( tmp->production_place , place );
	strcpy( tmp->fruit , kind );
	tmp->amount = amnt;
	tmp->Next = rear;
	head->Next = tmp;
	return Head;
}

void Print( detail H )
{
	if( !H->Next ) return ;
	detail tag = H;
	char tmp[81] = "Hello World!";
	while( tag->Next ){
		tag = tag->Next; 
		if( strcmp( tag->production_place , tmp ) != 0 ){
			memset( tmp , 0 , 81 );
			strcpy( tmp , tag->production_place );
			cout << tmp << endl;
		}
		cout << "   |----" << tag->fruit << '(' << tag->amount << ')' << endl;
	}
	if( T ) cout << endl;
}
