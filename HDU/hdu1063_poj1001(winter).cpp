#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int cut( string & R );//去掉没用的零，返回小数部分有几位，并将R转变成可直接参加乘法的形式 
string mult( string r , string relay );
string power( string R , int n ); 

int main()
{
	string R;
	int N;
	while ( cin >> R >> N ){
		int dot = N * cut( R ); // 最终结果有dot位小数 
		string ans = power( R , N );
		while( ans.length() < dot ) ans.insert( 0, "0" );
		if( dot )
			ans.insert( ans.length()-dot,".");
		cout << ans << endl; 
	}
} 

int cut( string & R )
{
	int dot = 0;
	while ( R[0] == '0' ) R.erase(0,1);
	if( R.find('.') != string::npos ) 
	{
		for( int j = R.length()-1 ; R[j] == '0' ; j-- ) R.erase( j , 1 );
		for( int j = R.length()-1 ; R[j] != '.' ; j-- ) dot++;
	} 
	if( R[0] == '.' ){
		R.erase( 0 , 1 );
		while( R[0] == '0' ) R.erase(0,1); 
	} 
	else {
		for( int j = 0 ; j < R.length() ; j++ )
			if( R[j] == '.' ){
				R.erase( j , 1 );
				break;
			} 
	}
	return dot;
}

string mult( string r , string relay )
{
	string result = string( 150 , '0');
	int remainder = 0 , carry = 0 , value = 0;
	int alen = r.length() , blen = relay.length();
	int i , j;
	reverse( r.begin() , r.end() );
	reverse( relay.begin() , relay.end() );
	for( int i = 0 ; i < alen ; i++ ){
		for( j = 0 ; j < blen ; j++ ){
			value = (result[i+j]-'0') + (r[i]-'0')*(relay[j]-'0') + carry;
			remainder = value%10;
			carry = value/10;
			result[i+j] = remainder+'0'; 
		}
		if( carry ){
			result[i+j] = carry+'0';
			carry /= 10;
		}
	} 
	i = result.length()-1;
	while ( result[i] == '0' ) result.erase(i--,1);
	reverse( result.begin() , result.end()); 
	return result;
}

string power( string R , int n )
{
	if( n == 1 ) return R;
	string ans = R;
	for( int i = 1 ; i < n ; i++ ){
		ans = mult( R , ans );
	} 
	return ans;
}
