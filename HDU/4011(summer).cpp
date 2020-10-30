#include <cstdio>
using namespace std;

int main()
{
	int N,num,id=1,pay;
	long long int fee,cost;
	scanf( "%d",&N );
	while( N-- ){
		scanf( "%d%I64d%d",&num,&fee,&pay );
		//重要事件的数量、从北京到上海或上海到北京的单次航班费用
		//以及在北京停留一天的工资 
		long long int thisday=0, lastday=0, remaindays=1;
		scanf("%I64d",&lastday);
		cost = 0;//总费用 
		for( int i = 1 ; i < num ; i++ ){	//printf("%d\n",cost);
			scanf( "%I64d",&thisday );
			if( ( thisday - lastday  ) * pay > fee * 2 ){
				cost += ( remaindays*pay + fee*2 );	//printf("%d\n",remaindays);
				remaindays = 1;
			}
			else
				remaindays += ( thisday - lastday );
			lastday = thisday;
		}//printf("%I64d\n",remaindays);
		cost += ( remaindays*pay + fee*2 );//最后一次去BJ没有被计入 
		printf( "Case #%d: %I64d\n",id++,cost );
	}
} 
