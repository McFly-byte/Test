#include <bits/stdc++.h>
using namespace std;

struct Node{
	char msg[1005];
	int parameter , priority , right;//参数，优先级值，权值
									//（用于优先级值相等时的判断先后）
	bool operator<(const Node &A) const//运算符重载，两个const不可或缺，会报错 
	{
		if( priority == A.priority )	return right > A.right;
		return priority > A.priority;
	}
} tmp;

int main()
{
	priority_queue<Node> Q; //优先队列 
	string str;
	int right = 0;//权值 
	while( cin >> str ){
		if( str == "GET" ){
			if( Q.empty() ) cout << "EMPTY QUEUE!" << endl;
			else {
				tmp = Q.top() ;
				Q.pop() ;
				cout << tmp.msg << ' ' << tmp.parameter << endl;
			}
		}
		else if( str == "PUT" ){
			Node temp;
			cin >> temp.msg >> temp.parameter >> temp.priority;
			temp.right = right++;
			Q.push( temp ); 
		}
	}
 } 
