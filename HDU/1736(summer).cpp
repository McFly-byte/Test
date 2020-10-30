#include <bits/stdc++.h>//中文字符一个占两字节 
using namespace std;	//出现"”或“"要小心 
						//中文引号的ascii第一位为负值，第二位左引号-80右引号-79 
						//输入时有空格
						//同样是多组输入 
int main()
{
	string str;
	while( getline(cin,str) ){
	
	int len = str.length();
	bool flag = 1;
	for( int i = 0 ; i < len ; i++ ){
	
		if( str[i] == ',' ) cout << "，";
		else if( str[i] == '.' ) cout << "。";
		else if( str[i] == '?' ) cout << "？";
		else if( str[i] == '!' ) cout << "！"; 
		else if( str[i] == '"' ){
			if( flag ){
				 cout << "“";
				 flag = 0;
			}
			else {
				cout << "”";
				flag = 1; 
			}
		}
		else if( str[i] == '<' && str[i+1] == '<' ){
			cout << "《";
			i++; 
		}
		else if( str[i] == '>' && str[i+1] == '>' ){
			cout << "》";
			i++; 
		} 
		else cout << str[i];
		if( str[i] < 0 && str[i+1] == -80 ) flag = 0;
		if( str[i] < 0 && str[i+1] == -79 ) flag = 1;
	}
	cout << endl;
	}
 } 
