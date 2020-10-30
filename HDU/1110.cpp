#include <bits/stdc++.h>//1110 长方形可以斜着放！ 
using namespace std;

bool judge( double a, double b, double x, double y )
{
	if( y > x )	swap( x , y );
	if( b > a )	swap( a , b );
	
	if( a*b < x*y )	return false;
	if( x < a && y < b )	return true;
	if( b <= y )	return false;
	
	double z = sqrt( pow( x , 2 ) + pow( y , 2 ) );
	double therta = asin( b/z ) - asin( y/z );
	double virtual_length = x*cos(therta) + y*sin(therta);
	if( virtual_length < a )	return true;
	else 
		return false;
}

int main()
{
	int T;
	cin >> T;
	double a , b , x , y;
	while( T-- ){
		cin >> a >> b >> x >> y;
		if( judge( a , b , x , y ) )	
			cout << "Escape is possible." << endl;
		else 
			cout << "Box cannot be dropped." << endl;
	} 
	return 0;
}
