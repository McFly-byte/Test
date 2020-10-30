#include <iostream>
#include <cstring>

using namespace std;

struct submit{
	int amount;
	int time ;
	int id;
};

void Sort( submit * , int );
void Swap( submit & , submit & );

int main()
{
	int N , G , S , C , M;
	while (scanf("%d%d%d%d%d", &N, &G, &S, &C, &M),N!=0&&G!=0&&S!=0&&C!=0&&M!=0){
		submit a[N];
		int hour , min , sec;
		for( int i = 0 ; i < N ; i++ ){
			scanf( "%d %d:%d:%d" , &a[i].amount , &hour , &min , &sec );
			a[i].id = i+1;
			a[i].time = hour * 3600 + min * 60 + sec;
		}
		Sort( a , N );
		for( int i = 0 ; i < N ; i++ ){
			if( a[i].id == M ){
				if( i < G ){
					printf( "Accepted today? I've got a golden medal :)\n" );
						break;
					}
				else if( i < G+S ){
					printf( "Accepted today? I've got a silver medal :)\n" );
						break;
					}
				else if( i < G+S+C ){
					printf( "Accepted today? I've got a copper medal :)\n");
						break;
					}		
				else {
					printf( "Accepted today? I've got an honor mentioned :)\n" );
						break;
					}	
			}
		}
	}
}

void Swap( submit & a , submit & b )
{
	swap( a.amount , b.amount );
	swap( a.id , b.id );
	swap( a.time , b.time );
} 

void Sort( submit * a , int N )
{
	int amount , time , id;
	for( int i = 0 ; i < N-1 ; i++ ){
		amount = a[i].amount;
		time = a[i].time;
		id = i;
		for( int j = i+1 ; j < N ; j++ ){
			if( a[j].amount > amount || ( a[j].amount == amount && a[j].time < time ) ) {
				id = j;
				amount = a[j].amount , time = a[j].time;
			}
		} 
		Swap( a[i] , a[id] );
	}
}
