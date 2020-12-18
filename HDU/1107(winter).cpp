/*******************************************************************************
	*时间：2020-12-19 4:21
	*作者：我
	*描述：从晚上十点打到凌晨四点，大模拟，不过如此。 
		   收获还是不少的：for、front,打完有一种百年孤独的感觉 
*******************************************************************************/ 

#include <bits/stdc++.h> 
using namespace std;

#define eps 10e-6
#define _for( k, l, r ) for( int k = (l); k < (r); k++ )
//不要写for，不知道为什么会编译错误 
#define _rep( k, l, r ) for( int k = (l); k <= (r); k++ )

class disciple;
class node{
	public:
		int pos[2];
		int E_num , W_num , S_num; //峨眉，武当，少林
		int E_ntmp, W_ntmp, S_ntmp; //
		vector<disciple> d[3];//0-E, 1-W, 2-S
		bool whetherFight( int num1 , int num2 , int num3 = 0 ); // 1是否可以攻击2
		void Combat(); //战备 
		void Fight( disciple * a, disciple * b ); //打斗掉血 
		void Move(); //前进！本格内走到该去的下一格里 
}world[13][13];

class disciple{
	public:
		bool dir; // false向下/右，true反之 
		int school; //武术派别 0-E, 1-W, 2-S
		double Qi, Force, Health; // 内力，武艺， 生命值
		int Attack; // 攻击力，时刻浮动
		void updateAttack();
		void beAttacked( int attack );
		bool isAlive();
		void Copy( disciple a );
		friend class node; 
}dis;

double w[3] = { 0.2 , 0.8 , 0.5 };
//bool flag0 = false, flag1 = false, flag2 = false;//有没有输入该派弟子 

void init(); //楚门的世界 
void simu(); //弟子们走到下一格、斗殴、死亡 
void move(); //全 部 移 动 
void printAns();

void test(){
	cout << "     E W S" << endl;
	_rep( i, 1, 12 ){
		_rep( j, 1, 12 ){
			cout << i << ':' << j << "  " << world[i][j].E_num << ' ' <<
				world[i][j].W_num << ' ' <<
				world[i][j].S_num << ' ' << endl;
		}
	}
} 

int main()
{
	int T, N;
	char sch;
	cin >> T;
	while ( T-- ){
		init();
		cin >> N;
		int i, j;
		while ( cin >> sch && sch != '0' ){
			cin >> i >> j; // 输入位置坐标 
			cin >> dis.Qi >> dis.Force >> dis.Health; 
			dis.dir = false; 
			if( sch == 'E' ){
				dis.school = 0;
				world[i][j].E_num++;
			} 
			else if ( sch == 'W' ) {
				dis.school = 1;
				world[i][j].W_num++; 
			} 
			else {
				dis.school = 2;
				world[i][j].S_num++;
			} 
			world[i][j].d[dis.school].push_back( dis );
		} 
		//test();
		while ( N-- ){
			simu();
			//test();
		}
		printAns();
	} 
}

void simu()
{
	_rep( i, 1, 12 ){
		_rep( j, 1, 12 ){
			world[i][j].Combat();
		}
	}
	move();
}
 
void move()
{
	_rep( i, 1, 12 ){ _rep( j, 1, 12 ){ world[i][j].Move(); } }
	_rep( i, 1, 12 ){ _rep( j, 1, 12 ){ 
		world[i][j].E_num = world[i][j].E_ntmp;
		world[i][j].W_num = world[i][j].W_ntmp;
		world[i][j].S_num = world[i][j].S_ntmp;
		world[i][j].W_ntmp = world[i][j].E_ntmp = world[i][j].S_ntmp = 0; } }
} 

void node::Move()
{
	int i = this->pos[0] , j = this->pos[1];
	int ii, jj;
	_for( k, 0, this->E_num ) {	//左上到右下  	
		dis.Copy( this->d[0].front() ); //!front返回的是引用！ 
		vector<disciple>::iterator tmp = this->d[0].begin();
		ii = i , jj = j;	//要在循环内部赋值，防止（12，1）（1，12）情况 
		//cout <<"@@@@@" << this->pos[0] << ' ' <<this->pos[1]<< endl;
		if( dis.dir ){
			if( i == 12 && j == 1 || i == 1 && j == 12 ){
				world[ii][jj].E_ntmp++;	//continue可能直接出循环，要在里面提前计数 
				continue;
				//cout << 1 << endl;
			}
			else if( i == 1 || j == 1){
				dis.dir = false;
				ii = i+1, jj = j+1;
			//	cout << 11 << endl;
			}
			else{
				ii = i-1 , jj = j-1;
				//cout << 111 << endl;
			}
		}
		else {
			if( i == 12 && j == 1 || i == 1 && j == 12 ){
				world[ii][jj].E_ntmp++;
				continue;
			//	cout << 2 << endl;
			}
			else if( i == 12 || j == 12 ){
				dis.dir = true;
				ii = i-1 , jj = j-1;
			//	cout << 22 << endl;
			}
			else{
				ii = i+1, jj = j+1;
			//	cout << 222 << endl;
			}
		}
		//cout << ii << "****************************" << jj << endl;
		world[ii][jj].d[0].push_back( dis );
		world[ii][jj].E_ntmp++;
		this->d[0].erase( tmp );
		//this->E_num--;
	}
	_for( k, 0, this->W_num ) { //横 
		dis = this->d[1].front();
		vector<disciple>::iterator tmp = this->d[1].begin();
		ii = i , jj = j;
		if( dis.dir ){
			if( j == 1 ){
				dis.dir = false;
				ii = i, jj = j+1;
			}
			else{
				ii = i, jj = j-1;
			}
		}
		else {
			if( j == 12 ){
				dis.dir = true;
				ii = i, jj = j-1;
			}
			else{
				ii = i, jj = j+1;
			}
		}
		world[ii][jj].d[1].push_back( dis );
		world[ii][jj].W_ntmp++;
		this->d[1].erase( tmp );
		//this->W_num--;
	}
	_for( k, 0, this->S_num ) { //竖 
		dis = this->d[2].front();
		vector<disciple>::iterator tmp = this->d[2].begin();
		ii = i , jj = j;
		if( dis.dir ){
			if( i == 1 ){
				dis.dir = false;
				ii = i+1, jj = j;
			}
			else{
				ii = i-1, jj = j;
			}
		}
		else {
			if( i == 12 ){
				dis.dir = true;
				ii = i-1 , jj = j;
			}
			else{
				ii = i+1, jj = j;
			}
		}
		world[ii][jj].d[2].push_back( dis );
		world[ii][jj].S_ntmp++;
		this->d[2].erase( tmp );
		//this->S_num--;
	}
} 

void node::Combat()
{
	if( this->whetherFight( E_num , S_num , W_num) ){
		this->Fight( &this->d[0][0] , &this->d[2][0] );
		//cout << "SUcceed" << endl;
	}
	if( this->whetherFight( E_num , W_num , S_num) ){
		this->Fight( &this->d[0][0] , &this->d[1][0] );
		//cout << "SUcceed" << endl;
	}
	if( this->whetherFight( W_num , S_num ,E_num ) ){
		this->Fight( &this->d[1][0] , &this->d[2][0] );
		//cout << "SUcceed" << endl;
	}
	for( int k = 0 ; k < 3 ; k++ ){
		vector <disciple>::iterator iter = this->d[k].begin();
	 	for ( ; iter != this->d[k].end(); ){
	 		if( !(*iter).isAlive() ) {
	 			iter = this->d[k].erase(iter);
	 			if( k == 0 ) this->E_num--;
	 			else if( k == 1 ) this->W_num--;
	 			else if( k == 2 ) this->S_num--;
			 }		//弟子死了数量也要减少 
	 		else iter++;
		}
	}
 } 

bool node::whetherFight( int num1 , int num2 , int num3 ) // 1是否可以攻击2
{
	if( num1 == num2 && num2 == num3 && num3 == 1 ) return false;
	if( num1 == 1 && num2 == 1 ) return true;
	return false; 
} 
 
void node::Fight( disciple * a, disciple * b )
{
	//cout << "succeed" << endl;
	a->updateAttack();
	b->updateAttack();
	a->beAttacked( b->Attack );
	b->beAttacked( a->Attack ); 
//	cout << ' ' << a->Attack << ' ' << b->Attack << endl;
	//cout << ' ' << a->Health << ' ' << b->Health << endl;
}

void disciple::updateAttack()
{
	this->Attack = ( w[this->school]*this->Qi + 
	 (1-w[this->school])*this->Force ) * ( this->Health + 10 ) / 100; //忘了是1-了 
}

void disciple::beAttacked( int attack )
{
	this->Health -= attack;
}

void disciple::Copy( disciple a )
{
	this->Attack = a.Attack;
	this->dir = a.dir;
	this->Force = a.Force;
	this->Health = a.Health;
	this->Qi = a.Qi;
	this->school = a.school;
 } 

bool disciple::isAlive()
{
	if( this->Health - 0.0 > eps ) return true;
	this->Health = 0;
	return false;
}

void init()
{ 	//rep&for分不清楚害死人！ 
	_rep( i, 1, 12 ){
		_rep( j, 1, 12 ){
			world[i][j].E_num = 0; world[i][j].W_num = 0; world[i][j].S_num = 0;
			world[i][j].E_ntmp = 0; world[i][j].W_ntmp = 0; world[i][j].S_ntmp = 0;
			world[i][j].pos[0] = i;
			world[i][j].pos[1] = j;
			for( int k = 0 ; k < 3 ; k++ ){
				vector <disciple>::iterator iter = world[i][j].d[k].begin();
		   	 	for ( ; iter != world[i][j].d[k].end(); )
		    	    iter = world[i][j].d[k].erase(iter);
			}
		}
	}
}

void printAns( )
{
	int En = 0, Wn = 0, Sn = 0;
	double Eh = 0, Wh = 0, Sh = 0;
	_rep( i, 1, 12 ){
		_rep( j, 1, 12 ){
			En += world[i][j].E_num;
			Wn += world[i][j].W_num;
			Sn += world[i][j].S_num;
			for ( int k = 0 ; k < world[i][j].E_num; k++ )
				Eh += world[i][j].d[0][k].Health; 
			for ( int k = 0 ; k < world[i][j].W_num; k++ )
				Wh += world[i][j].d[1][k].Health;
			for ( int k = 0 ; k < world[i][j].S_num; k++ )
				Sh += world[i][j].d[2][k].Health; 
		}
	}
	cout << Sn << ' ' << Sh << endl; 
	cout << Wn << ' ' << Wh << endl;
	cout << En << ' ' << Eh << endl;
	cout << "***" << endl; 		
}
