#include <iostream>

using namespace std;

struct balloon{
	string color;
	int count;	
};

int main()
{
	int T;
	while ( cin >> T && T ){
		balloon a[T];
		int len = 0;
		string tmp;
		bool flag;
		for ( int i = 0 ; i < T ; i++ ){
			cin >> tmp;
			flag = false;
			for( int j = 0 ; j < len ; j++ ){
				if( a[j].color == tmp ){
					a[j].count++;
					flag = true;
				}
			}
			if( !flag ){
				a[len].color = tmp;
				a[len++].count = 1;
			}
		}
		int max = a[0].count , maxid = 0;
		for( int i = 1 ; i < len ; i++ ){
			if( a[i].count > max ) {
				max = a[i].count;
				maxid = i;
			}
		}
		cout << a[maxid].color << endl;
	}
}
