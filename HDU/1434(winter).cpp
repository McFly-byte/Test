//模拟队列
/*
	一开始没有用优先队列，纯手打。结果没注意多组输入，一直WA.
	第二天尝试换个做法，照着CSDN的猫画的，结果还不过，这才注意到多组。
	但是之前手打那份超内存，心累不看了。
	queue熟练度++。 
*/ 
#include <iostream>
#include <queue>
using namespace std;

struct node {
	int RP;
	string Name;
	friend bool operator<( node a , node b ){
		if( a.RP == b.RP ) return a.Name < b.Name;
		return a.RP > b.RP;
	}
}tmp;

int main()
{
	int n, m;
	while ( cin >> n >> m ){
		
	priority_queue<node> q[n+1];
	for( int i = 1 ; i <= n ; i++ ){
		int t;
		cin >> t;
		while( t-- ){
			cin >> tmp.Name >> tmp.RP;
			q[i].push( tmp );
		}
	}	
	string command;
	while( m-- ){
		cin >> command;
		if( command == "GETON" ){
			int id;
			cin >>id;
			cin >> tmp.Name >> tmp.RP;
			q[id].push( tmp );
		}
		else if( command == "JOIN" ){
			int i , j;
			cin >> i >> j;
			while( !q[j].empty() ){
				tmp = q[j].top();
				q[i].push( tmp );
				q[j].pop();
			}
		}
		else if( command == "GETOUT" ){
			int id;
			cin >> id;
			tmp = q[id].top();
			cout << tmp.Name << endl;
			q[id].pop();
		}
	}
}
} 

//---------------------------------以下是初次纯手打---------------------
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdlib.h>
using namespace std;

class guest{
	public:
		string name;
		int RP;	
		guest * Next;
		void init( int n );
		void addNew( string str , int a );
		void merge( guest g );
		void getout();
};

bool cmp( guest a , guest b )
{
	if( a.RP == b.RP ){
		return a.name < b.name; 
	}
	return a.RP > b.RP;
}

int main()
{
	int n, m, arg;
	while ( cin >> n >> m ){
		
	guest a[n+1];
	for( int i = 1 ; i <= n ; i++ ){
		cin >> arg;
		a[i].init( arg );
	/*	guest * flag = &a[i];
		while( flag )*/
	}
	string command;
	while ( m-- ){
		cin >> command;
		if ( command == "GETON" ){
			int id;
			cin >> id;
			string str;
			int b;
			cin >> str >> b;
			a[id].addNew( str , b );
		}
		else if ( command == "JOIN" ){
			int id1 , id2;
			cin >> id1 >> id2;
			a[id1].merge( a[id2] );
		}
		else if ( command == "GETOUT" ){
			int id;
			cin >> id;
			a[id].getout();
		}
	}
}
}

void guest::getout()
{
	if( !this->Next ) return ;
	guest * flag = this;
	guest * min = flag->Next;
	int minRP = flag->Next->RP;
	string maxName = flag->Next->name;
		
	while ( flag->Next ){
		flag = flag->Next;
		if( flag->RP < minRP || flag->RP == minRP && flag->name > maxName ){
			min = flag; 
			minRP = flag->RP;
			maxName = flag->name;
		}
	}
	cout << min->name << endl;
	flag = this;
	while( flag->Next != min ){
		flag = flag->Next;
	}
	flag->Next = min->Next;
	delete min;
}

void guest::merge( guest g )
{
	guest * flag = g.Next;
	guest * tmp;
	while ( flag ){
		this->addNew( flag->name , flag->RP );
		tmp = flag;
		flag = flag->Next;
		delete tmp;
	}	
}

void guest::addNew( string str , int a )
{
	guest * flag = new guest;
	flag->name = str;
	flag->RP = a;
	flag->Next = this->Next;
	this->Next = flag;
	/*while( flag->Next ){
		flag = flag->Next;
		cout << flag->RP << ' ' << flag->name << endl;
	}*/
}

void guest::init( int n )
{
	guest * flag = this;
	this->Next = NULL; 
	string nm;
	int rp;
	for( int i = 0; i < n; i++ ){
		cin >> nm >> rp;
		flag->Next = new guest;
		flag = flag->Next;
		flag->name = nm;
		flag->RP = rp;
		flag->Next = NULL;	
	}
	flag = this;
/*	while( flag->Next ){
		flag = flag->Next; 
		cout << flag->RP << "  " << flag->name << endl;
		
	}*/
}
