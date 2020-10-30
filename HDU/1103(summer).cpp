#include <iostream>//第一遍写题意都理解错了，之后又过了好久才用队列写出来。
				  //还有好多值得改进的地方，心力交瘁不写了 
#include <queue>
using namespace std;

int tb2, tb4, tb6;//可以用数组 每种桌子数目 
int diners; 
queue<int> a,b,c;//也可用数组
				// 配合上边table_amount:tb2/4/6,循环可以省很多代码空间 

void Judge( int dnr_n , int arv_tm );//diners'number && arrival time

int main()
{
	while( ( cin >> tb2 >> tb4 >> tb6 ) &&  ( tb2+tb4+tb6 ) != 0 ){
		while( !a.empty() ) a.pop();
		while( !b.empty() ) b.pop(); 
		while( !c.empty() ) c.pop();//队列初始为零 还没想到好办法200906 
		diners = 0; //可在餐厅吃饭的人数 
		string time;//到达时间|开始用餐时间 
		int tm_min , dnr_num;
		while( cin >> time && time[0] != '#' ){
			cin >> dnr_num;
			tm_min = ((time[0]-'0')*10+(time[1]-'0'))*60
					+((time[3]-'0')*10+(time[4]-'0'));	
				//对时间的转变也没想到好办法 
			Judge( dnr_num , tm_min );
		}
		cout << diners << endl;
	}
}

void Judge( int dnr_n , int arv_tm )
{
	//先处理tb2的，其他桌类似 
	if( dnr_n == 1 || dnr_n == 2 ){
		if( a.size() < tb2 ){//如果size为0 a.front()就RE了 不能直接用a.front() 
			a.push ( arv_tm );
			diners += dnr_n; 
		}
		else if( a.size() == tb2 ){
			if( arv_tm >= a.front() && arv_tm <= a.front() + 30 ){
				arv_tm = a.front() + 30;
				a.pop();
				a.push(arv_tm); 
				diners += dnr_n; 
			}
			else if( arv_tm > a.front() + 30 ){
				a.pop();
				a.push(arv_tm);
				diners += dnr_n; 
			}
		} 
	}
	else if( dnr_n == 3 || dnr_n == 4 ){
		if( b.size() < tb4 ){//如果size为0 a.front()就RE了 
			b.push ( arv_tm );
			diners += dnr_n; //cout << '\t' << diners << ' ' << arv_tm << endl;
		}
		else if( b.size() == tb4 ){	//cout << endl;
			if( arv_tm >= b.front() && arv_tm <= b.front() + 30 ){
				arv_tm = b.front() + 30;
				b.pop();
				b.push(arv_tm); 
				diners += dnr_n;  //cout << ' ' << diners << ' ' << arv_tm << endl;
			}
			else if( arv_tm > b.front() + 30 ){
				b.pop();
				b.push(arv_tm);
				diners += dnr_n;  //cout << ' ' << diners << ' ' << arv_tm << endl;
			}
		} 
	}
	else if( dnr_n == 5 || dnr_n == 6 ){
		if( c.size() < tb6 ){//如果size为0 a.front()就RE了 
			c.push ( arv_tm );
			diners += dnr_n; 
		}
		else if( c.size() == tb6 ){
			if( arv_tm >= c.front() && arv_tm <= c.front() + 30 ){
				arv_tm = c.front() + 30;
				c.pop();
				c.push(arv_tm); 
				diners += dnr_n; 
			}
			else if( arv_tm > c.front() + 30 ){
				c.pop();
				c.push(arv_tm);
				diners += dnr_n; 
			}
		}
	}
}
