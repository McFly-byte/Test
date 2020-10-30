#include <bits/stdc++.h>
using namespace std;

int main()
{
	double H , U , D , F , height;
	int i;
	while( cin >> H >> U >> D >> F && H ){
		height = 0;
		i = 0;
		F = U * F / 100.0; 
		while( 1 ){
			i++;
			height += U;
			if( height > H ) break;
			height -= D;
			if( height < 0 ) break;
			U -= F;
			if( U <= 0 ) U = 0;
		}
		if( height < 0 ) cout << "failure on day " << i << endl;
		else cout << "success on day " << i << endl; 
	}
 } 
