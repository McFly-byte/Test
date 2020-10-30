#include <cstdio>
using namespace std;

struct Node{
	int problems;
	int time;
	int initnum;
	int grade;
};
typedef Node *Ptr;

void Sort( Ptr a , int size );
void Sort2( Ptr a , int size );
void Swap2( Node& a , Node& b );
void Print( Ptr a , int size );
void SetGrade( Ptr a , int size , int * num ); 
void PGrade( Ptr a , int size );

int main()
{
	int n;
	while( scanf("%d",&n) && n>=0 ){
		if( n == 0 ) continue;
		int a[6] = {0} ;	
		Node * mem = new Node[n];
		int prob,h,m,s;
		int i = 0;
		while( i<n ){		
			scanf("%d %d:%d:%d",&prob,&h,&m,&s);	
			mem[i].time = h*3600+m*60+s;
			mem[i].problems = prob;
			mem[i].initnum = i;
			a[prob]++;			
			i++;	
		}
		for( int i = 0 ; i < 6 ; i++ )
			a[i] /= 2;
		Sort( mem , n );
		SetGrade( mem , n , a );
		PGrade( mem , n );
	}
}

void Sort( Ptr a , int size )
{
	int max = 0, maxid = 0 , maxt = 0;
	for( int i = 0; i < size - 1; i++ )
	{
		max = a[i].problems;
		maxt = a[i].time;
		maxid = i;
		for( int j = i + 1 ; j < size ; j++ ){
			if( a[j].problems > max ){
				maxid = j;
				maxt = a[j].time;
				max = a[j].problems;		//min用来比较，minid用来准备交换 
			}
			else if( a[j].problems == max ){
				if( a[j].time < maxt ){
					maxid = j;
					maxt = a[j].time;
				}
			}
		}
		Swap2( a[i], a[maxid] );
	 } 
}

void Swap2( Node& a , Node& b )
{
	int pb = a.problems, tm = a.time , gd = a.grade , id = a.initnum;
	a.problems = b.problems;
	a.time = b.time;
	a.grade = b.grade;
	a.initnum = b.initnum;
	b.problems = pb;
	b.time = tm; 
	b.grade = gd;
	b.initnum = id;
} 

void Sort2( Ptr a , int size )
{
	for( int i = 0; i < size - 1; i++ )
	{
		for( int j = i+1 ; j < size ; j++ )
		{
			if( a[j].initnum == i ){
				Swap2( a[i] , a[j] );		
				break;
			}
		}
	}
}

void Print( Ptr a , int size )
{
	for( int i = 0 ; i < size ; i++ ){
		printf("%d %d\n",a[i].problems,a[i].time);
	}
}

void SetGrade( Ptr a , int size , int * num )
{
	for( int i = 0 ; i < size ; i++ ){
		if( a[i].problems == 5 ){
			a[i].grade = 100;
		}
		else if( a[i].problems == 0 ){
			a[i].grade = 50;
		}
		else{
			int grade = 50 + 10 * a[i].problems;
			if( num[a[i].problems] ){
				grade += 5;
				num[a[i].problems]--;
			}
			a[i].grade = grade;
		}
	}
}

void PGrade( Ptr a , int size )
{
	Sort2( a , size );
	for( int i = 0 ; i < size ; i++ ){
		printf("%d\n",a[i].grade);
	}
	printf("\n");
}
