#include<iostream>

using namespace std;

int main()
{
	long long a;
	while( cin>>a ){
		if( ( a - 2 ) % 4 == 0 )
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
