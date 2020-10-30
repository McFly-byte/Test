#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 205;
int N , M , n = 0 , ans = -1;
char rooms[MAXN][MAXN];
bool isOn[17] ;	//标记灯是否亮 
int kind[][3][2] = {0,0,-1,0,0,1, 0,0,1,0,0,1, 0,0,1,0,0,-1, 0,0,-1,0,0,-1};

class Node {
	public:
	int x , y;
	Node( int _x , int _y ) : x(_x) , y(_y){}
	Node(){}
} node[17];

bool lighten( int x , int y )	//判断该房间可否被照亮 （是否脆弱） 
{
	if( rooms[x][y] == '.' ) return true;
	if( x < 0 || x >= N || y < 0 || y >= M )	return true;
	return false; 
} 

int find( int x , int y )	//根据node中点的坐标反推得到该点对应i值 
{
	for( int i = 0 ; i < n ; i++ )
		if( node[i].x == x && node[i].y == y )
			return i;
	return -1;
}

bool isMatch( int s , int dir )		//判断状态s是否能使条件满足 
{
	for( int i = 0 ; i < n  ; i++ )	//定位到特殊灯 （每个二进制位代表一盏） 
		if( ( 1 << i ) & s ){		//i是s状态下亮着的灯之一 
			int x = node[i].x , y = node[i].y;
			memset( isOn , false , sizeof( isOn ) ); 
			isOn[i] = true;	//莫忘赋值为true  
			
			if( !lighten( x+kind[dir][1][0],y+kind[dir][1][1] ) ||
				!lighten( x+kind[dir][2][0],y+kind[dir][2][1] ) ) continue;
			isOn[find(x+kind[dir][1][0],y+kind[dir][1][1])] = true;
			isOn[find(x+kind[dir][2][0],y+kind[dir][2][1])] = true;
			
			for( int j = 0; j < n ; j++ )
				if( j != i && ( ( 1 << j ) & s ) ){ 
				//j是s状态下且已确定特殊灯为i时其他被点亮的灯 
					isOn[j] = true; //定位之后莫忘赋值为true 
					x = node[j].x , y = node[j].y;
					if( !lighten( x-1, y ) || !lighten( x , y+1 ) ) break;
					isOn[find(x-1,y)] = true;
					isOn[find(x,y+1)] = true;
				}
				
			bool flag = true;
			for( int k = 0 ; k < n ; k++ )
				if( !isOn[k] ) flag = false;
			if( flag )	return true;
		}
	return false;
}

int main()
{
	while( cin >> N >> M && N + M ){
		n = 0; ans = -1;	//新一轮开始时要制初始化 
		
		for( int i = 0 ; i < N ; i++ ){
			cin >> rooms[i];
			for( int j = 0 ; j < M ; j++ ){
				if( rooms[i][j] == '.' )
					node[n++] = Node( i , j );
			}
		}
		
		if( !n ){
			cout << 0 << endl;
			continue;
		}
		
		for( int type = 0 ; type < ( 1 << n ) ; type++ ){ 
		//枚举灯可能的组合方式  共2^n种可能 
			for( int dir = 0 ; dir < 4 ; dir++ ){
				if( isMatch( type , dir ) ){
					int count = 0, X = type;
					while( X ){		//通过循环得到x的二进制数中有几位是1 
						X &= (X-1);
						count++;
					}
					ans = ( ans == -1 ? count : min( count , ans ) ); 
				}
			}
		}
		cout << ans << endl;
	}
}
