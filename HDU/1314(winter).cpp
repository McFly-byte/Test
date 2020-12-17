				//大大数计算，累死我了2020.12.15 17:29:24 
				//乘加法简单，减法之前涉及的少差一点，比较复杂的就是除，有了除法取余也就简了
				 
#include <iostream> 
#include <algorithm> 
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

string Mult( string a , string b )
{
	string ans(256,'0');
	reverse( a.begin(), a.end() );
	reverse( b.begin(), b.end() );
	int value, carry = 0, remainder = 0, i, j;
	int alen = a.length(), blen = b.length();
	for( i = 0 ; i < alen; i++ ){
		for( j = 0 ; j < blen; j++ ){
			value = (ans[i+j]-'0')+carry+(a[i]-'0')*(b[j]-'0');
			carry = value/10;
			ans[i+j] = value%10+'0';
		} 
		if( carry ){
			ans[i+j] = carry+'0';
			carry /= 10;
		}
	}
	reverse( ans.begin() , ans.end() );
	while ( ans[0] == '0' ) ans.erase(0,1);
	return ans;
}

string Add( string a , string b )
{
	reverse( a.begin() , a.end() );
	reverse( b.begin() , b.end() );
	string ans(256,'0');
	int value = 0 , carry = 0;
	int i , j , alen = a.length() , blen = b.length();
	if( alen < blen ){
		swap( a , b );
		swap( alen , blen ); //cout << a << b << endl;
	}
	for( i = 0 ; i < alen ; i++ ){
		if( i >= blen ){
			value = (a[i]-'0') + carry;
			carry = value / 10;
			ans[i] = value % 10 + '0';
			continue;
		}
		value = (a[i]-'0') + (b[i]-'0')+carry;
		carry = value/10;
		ans[i] = value % 10 + '0';
	}
	if( carry ){
		ans[i] = carry + '0';
	}
	reverse( ans.begin() , ans.end() );
	while ( ans[0] == '0' ) ans.erase( 0, 1 );
	return ans;
}

bool isEqual( string a , string b )
{
	if( a.length() == b.length() ){
		for( int i = 0 ; i < a.length(); i++ ){
			if( a[i] != b[i] ) return false;
		}
		return true;
	}
	return false;
}

bool frontIsBig( string a , string b )//a是否大于等于b 
{
	if( b.length() > a.length() ) return false;
	if( b.length() < a.length() ) return true;
	for( int i = 0 ; i < a.length(); i++ ){
		if( a[i] > b[i] ) return true;
		if( a[i] < b[i] ) return false;
	}
	return true;
}

string Minus( string a , string b ) // 大数减，默认a大于b 
{
	if( isEqual( a , b ) ){		//相同时为零，这个也很重要 
		return "0";
	}							
	 string ans(256 , '0' );
	 reverse( a.begin() , a.end() );
	 reverse( b.begin() , b.end() );
	int alen = a.length() ,blen = b.length(), carry = 0, i;
	for( i = 0 ; i < alen; i++ ){ 
		if( i >= blen ){
			ans[i] = a[i]+carry;
			carry = 0;				//carry用过后要归零 
			if( ans[i] < '0' ){
				ans[i] += 10;
				carry = -1;
			}
			continue;	
		}
		ans[i] = (a[i]-'0')-(b[i]-'0')+carry+'0';
		carry = 0;				//同理 
		if( ans[i] < '0' ){
			ans[i] += 10;
			carry = -1;		//0&26都对应z，遇到0要给前一位减一 
		}
	}
	reverse( ans.begin() , ans.end() );
	while( ans[0] == '0' ) ans.erase(0,1);
	return ans ;
}

string Divide( string a , string b )//默认a大于等于b 
{
	string ans = "0";
	if( !frontIsBig( a , b ) ){	//a小了返回零 
		return "0";
	}
	string base , carry; 
	int blen = b.length(), alen = a.length(), i = blen-1;
	while ( frontIsBig( a , b ) ){
		base = b;carry = "1";
		while( frontIsBig( a, Mult( base , "10" ) ) ){ //注意判断可行后 
			base = Mult( base , "10" );				  //才能给他乘上去 
			carry = Mult( carry , "10" );
		}
		a = Minus( a , base );
		ans = Add( ans , carry );
	}
	return ans;
}

string Mod( string a ,  int n )
{
	char stri[10];
	itoa( n , stri , 10 );
	string str = stri;
	string ans = Divide( a , str );
	return Minus( a , Mult( ans , str ) );
}

void PrintNum( string a ) //带'，'的大数字输出 
{
	int i = 0 , j = 0, alen = a.length();
	if( alen % 3 == 0 ){
		i = j = 0;
	} 
	else if( alen % 3 == 1 ){
		cout << a[0];
		if( alen > 1 ) cout << ',';
		i = j = 1;
	}
	else if( alen % 3 == 2 ){
		cout << a[0] << a[1];
		if( alen > 2 ) cout << ',';
		i = j = 2;
	}
	for( ; i < alen ; i++ ){
			cout << a[i];
			if( ( i - j ) % 3 == 2 && i != alen-1 ) cout << ',';
		}
	cout << endl;
}

string Pow1314( char a , int n )//把第n位字母转换为对应数字值 
{
	int value = a - 'a' + 1;
//	cout << "value: " << value << endl;
	char stri[23]; 
	itoa( value, stri, 10 );
	string str = stri;
	string base = "1";
	for( int i = 0; i < n ; i++ ){			
		base = Mult( base , "26" );
	}
	str = Mult( base , str );
	return str;
}

string AtoD( string a )//字母转换为数字  alpha to digit
{
	reverse( a.begin() , a.end() );
	int alen = a.length();
	string ans = "0";
	for( int i = 0; i < alen ; i++ ){
		ans = Add( ans , Pow1314( a[i] , i ) );
	} 
	return ans;
}

string DtoA( string a )
{
	string ans(256,'0');
	int i = 0;
	while( !isEqual( a , "0" ) ){
		string carry = Mod( a , 26 );
//		cout << "carry : " << carry << endl;
		int digit = atoi( carry.data() );
		if( digit == 0 ){
			digit += 26;
			a = Minus( a , "1" );
		}
		a = Divide( a , "26" );
//		cout << "a: " << a << endl;
		ans[i++] = 'a' + digit - 1; 
//		cout << "ans: " << ans << endl;
	}
	reverse( ans.begin() , ans.end() );
	while( ans[0] == '0' ) ans.erase( 0,1 );
	return ans;
}

int main()
{
	string a;
	while ( cin >> a && a != "*" ){
		if( isdigit( a[0] ) ){//输入的是数字，要得到对应英文序列 
			string str = DtoA( a );
			cout << std::left << setw(22) << str;
			PrintNum( a );
		}
		else if( isalpha( a[0] ) ){//输入的是英文，要得到数字 
			string str = AtoD( a );
			cout << std::left << setw(22) << a;
			PrintNum( str );
		}
	}
}
