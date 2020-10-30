#include <bits/stdc++.h>//1006
/*注意时间是连续的，不能枚举每一秒
所有变量都是double，不然精度不够,但是这样定义的i,j,k不能用作数组迭代器 
三循环没有明确先后之分*/
using namespace std;

const int loop = 12*60*60;//define不加括号后面算百分比容易错
						//或者用const int 

double h = 1.0/120 , m = 1.0/10 , s = 6.0;
double mh = m - h , sm = s - m , sh = s - h;
double T_mh = 360.0/mh , T_sm = 360.0/sm , T_sh = 360.0/sh;

double Max( double , double , double ); 
double Min( double , double , double ); 

int main()
{
	int n;
	while( cin >> n && n >= 0 ){
		double ans = 0;
		double a[6] = {n/mh,n/sh,n/sm,(360-n)/mh,(360-n)/sh,(360-n)/sm};

		for( double i = 0 ; i <= 1.0*loop ; i += T_mh ){
			for( double j = 0 ; j <= 1.0*loop ; j += T_sh ){
				if( i+a[3] < j+a[1] )	break;
				if( j+a[4] < i+a[0] )	continue;
				for( double k = 0 ; k <= 1.0*loop ; k += T_sm ){
					if( k+a[2] > i+a[3] || k+a[2] > j+a[4] )	break;
					if( i+a[0] > k+a[5] || j+a[1] > k+a[5] )	continue;
					double start =  Max( i+a[0], j+a[1], k+a[2] );
					double stop = Min( i+a[3], j+a[4], k+a[5] );
					
					if( stop > start )	ans += stop-start;
				}
			}
		}
		cout << fixed << setprecision(3) << 100*ans/loop << endl;
	}
 } 
 
 double Max( double a, double b, double c )
 {
 	return max(max(a,b),c);
  } 
  
  double Min( double a, double b, double c )
 {
 	return min(min(a,b),c);
  } 
