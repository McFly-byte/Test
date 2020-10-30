#include "PigFarm.h"

bool isQualified( pig obj ){//判断可否出售 
	return ( obj->Weight >= market_weight || obj->Time >= 300 );
}

void grow( pig obj ){//单头猪增长 
	obj->Time++; 
	srand((unsigned)time(NULL));
	obj->Weight += (double)(rand()%12)/10.0;
} 

void gain( pigfarm p , int time ){//整个养猪场增长 
	pigsty tmp = p->Head;
	for( int i = 0 ; i < 100 ; i++ ){
		tmp = tmp->Next;
		for( int j = 0 ; j < 10 ; j++ ){
			for( int k = 0 ; k < time ; k++ )
				grow( &tmp->sty[j] );
		}
	}
} 
 
pigsty CreatePigsty( int id ){
	pigsty newsty = (pigsty)malloc( sizeof( struct Pigsty ) );
	newsty->ID = id;
	for( int i = 0 ; i < 4 ; i++ )
		newsty->amount[i] = 0;
	bool isBlack = false;
	int random_num = rand()%3+1;
	if( random_num == 1 ) isBlack = true;
	for( int i = 0 ; i < 10 ; i++ ){
		newsty->sty[i].ID = i;
		newsty->sty[i].Time = 0;
		newsty->sty[i].Weight = (double)(rand()%31+20);
		
		if( isBlack ){
			newsty->sty[i].Breed = (breed)1;
			newsty->amount[1]++; 
		}
		else {
			random_num = rand()%2+2;
			newsty->sty[i].Breed = (breed)random_num;
			newsty->amount[random_num]++;		
		}	
	}
	newsty->amount[0] = 10;
	newsty->Next = NULL;
	return newsty;
}

pigfarm CreatePigfarm(){
	pigfarm pfarm = (pigfarm)malloc(sizeof( struct Pigfarm ) );
	pfarm->Farm_Time = 0;
	pfarm->Head = (pigsty)malloc( sizeof( struct Pigsty ) );
	pfarm->Head->Next = NULL;
	for( int i = 99 ; i >= 0 ; i-- ){//使得Head后面一个i==0 
		pigsty tmp = CreatePigsty( i );
		tmp->Next = pfarm->Head->Next;
		pfarm->Head->Next = tmp;
	}
	return pfarm; 
}

void printPig( pigfarm p , int Id1 , int Id2 ){
	pigsty tmp = p->Head;
	for( int i = 0 ; i <= Id1 ; i++ ){
		tmp = tmp->Next; 
	}
	fout << "(￣(oo)￣) 猪圈编号：" << tmp->ID << "	猪编号：" << Id2 
	<< "	品种：";
	if( tmp->sty[Id2].Breed == 1 ) fout << "黑猪";
	else if( tmp->sty[Id2].Breed == 2 ) fout << "白猪";
	else if( tmp->sty[Id2].Breed == 3 ) fout << "花猪";
	fout << "	饲养时间：" << tmp->sty[Id2].Time;
	fout << "	体重：" << tmp->sty[Id2].Weight << endl;	
}

void printPig( pig obj , int Sty_Id ){
	fout << "(￣(oo)￣) 猪圈编号：" << Sty_Id << "	猪编号：" 
		 << obj->ID << "	品种：";
	if( obj->Breed == 1 ) fout << "黑猪";
	else if( obj->Breed == 2 ) fout << "白猪";
	else if( obj->Breed == 3 ) fout << "花猪";
	fout << "	饲养时间：" << obj->Time;
	fout << "	体重：" << obj->Weight << endl;
}

void printPigsty( pigfarm p , int Id )
{
	pigsty tmp = p->Head;
	for( int i = 0 ; i <= Id ; i++ )
		tmp = tmp->Next;
	fout << "第" << Id << "个猪圈，当前总数：" << tmp->amount[0];
	if( tmp->amount[1] ) fout << " 黑猪数量：" << tmp->amount[1] << endl;
	else fout << " 白猪数量：" << tmp->amount[2] << " 花猪数量：" << tmp->amount[3] << endl;
	fout << "可被出售(编号)：";
	bool isNone = true;
	for( int i = 0 ; i < 10 ; i++ )
		if( isQualified( &tmp->sty[i] ) ){
			fout << i << ' ';
			isNone = false;
		} 
	if( isNone ) fout << "无" ; 
	fout << endl ;
}

void printPigfarm( pigfarm p )//打印体重分布图  等 
{
	pigsty tmp = p->Head;
	int t_num = 0 , b_num = 0 , w_num = 0 , c_num = 0; 
	int count[11] = {0} , position = 0; 
	int sup_count[5] = {0} , sup_position = 0;// 0-90 90-180 180-270 270-360 360-
	for( int i = 0 ; i < 100 ; i++ ){//猪圈的循环 
		tmp = tmp->Next;
		t_num += tmp->amount[0];
		b_num += tmp->amount[1];
		w_num += tmp->amount[2];
		c_num += tmp->amount[3];
		for( int j = 0 ; j < 9 ; j++ ){//每圈内猪的循环 
		//体重分布 
			position = (int)(tmp->sty[j].Weight)/10 - 2 ;
			if( position > 10 ) position = 10 ;
			count[position]++;
		//时间分布
			sup_position = tmp->sty[j].Time/90;
			if( sup_position > 4 ) sup_position = 4;//不会超过360天 
			sup_count[sup_position]++; 
		}
	}
	fout << "猪场现有猪数目 总数：" << t_num << ",黑猪数量：" << b_num 
	<< ",白猪数量：" << w_num << ",花猪数量：" << c_num << endl;
	//打印体重分布图 
	fout << "猪的体重分布：" << endl;
	for( int i = 0 ; i < 11 ; i++ )
		if( count[i] ) count[i] = sqrt(count[i]);
	int height = count[0];
	for( int i = 1 ; i < 11 ; i++ )
		if( count[i] > height ) height = count[i];
	
	for( int i = height ; i > 0 ; i-- ){
		fout << ' ';
		for( int j = 0 ; j < 11 ; j++ ){
			if( count[j] >= i ) fout << setw(4) << '*';
			else fout << "    ";  
		}
		fout << endl;
	}
	for( int k = 20 ; k <= 120 ; k += 10)
		fout << setw(4) << k ;
	fout << " ...(体重区间,左闭右开)" << endl;
	//打印时间分布图
	fout << "猪的饲养时间分布：" << endl;
	for( int i = 0 ; i < 5 ; i++ )
		if( sup_count[i] ) sup_count[i] = sqrt(sup_count[i]);
	//找到最大值
	int sup_height = sup_count[0];
	for( int i = 1 ; i < 5 ; i++ )
		if( sup_count[i] > sup_height ) sup_height = sup_count[i];
	for( int i = sup_height ; i > 0 ; i-- ){
		fout << ' ';
		for( int j = 0 ; j < 5 ; j++ ){
			if( sup_count[j] >= i ) fout << setw(4) << '*';
			else fout << "    ";  
		}
		fout << endl;
	}
	for( int k = 0 ; k <= 360 ; k += 90)
		fout << setw(4) << k ;
	fout << " ...(饲养时间区间,左闭右开)" << endl;
}

double sellPig( pigsty psty , int pig_id )
{
	pig obj = &psty->sty[pig_id];
	printPig( obj , psty->ID ); //存入文件暂时没实现，先把信息都输出 
	double price = obj->Weight * Price[obj->Breed];
	fout << "卖猪得到" << price << "元(" 
	     << Price[obj->Breed] << "元/千克)\n";  
	obj->Time = 0;	obj->Weight = 0.0;
	//保留breed 后面买猪若黑则同否则任意 
	psty->amount[0]--; 
	psty->amount[obj->Breed]--;
	return price; 
}

double buyPig( pigsty psty , int Id )
{
	pig obj = &psty->sty[Id];
	obj->Time = 0;
	obj->Weight = (double)(rand()%31+20);
	if( obj->Breed != 1 ){
		obj->Breed = (breed)(rand()%2+2); 
	}
	psty->amount[obj->Breed]++;
	psty->amount[0]++; 
	printPig( obj , psty->ID );
	double price = Cost[obj->Breed] * obj->Weight;
	fout << "购猪花费" << price << "元(" 
	     << Price[obj->Breed] << "元/千克)\n"; 
	return price;
}

void sellAndBuy( pigfarm p )
{
	pigsty tmp = p->Head;
	for( int i = 0 ; i < 100 ; i++ ){
		tmp = tmp->Next;
		for( int j = 0; j < 10 ; j++ ){
			if( isQualified( &tmp->sty[j] ) ){
				Income += sellPig( tmp , j );
				Expense += buyPig( tmp , j ); 
			}	
		} 
	}
}

void startTime( pigfarm p , int maxTime , int sickTime )
{
	while( ++FarmTime && FarmTime <= maxTime ){
			if( FarmTime%90 == 0 && sickTime > FarmTime ){
				if( FarmTime%360 == 0 ) fout << "第" << FarmTime/360 + 1 << "年销售记录" << endl; 
				fout << "第" << FarmTime << "天销售情况：" << endl;
				cout << "第 " << FarmTime << " 天 : 正常" << endl; 
				gain( p , 90 ); //猪场自增长 
				printPigfarm( p ); //打印猪场信息 
				sellAndBuy( p );	//不卖对的 只卖贵的 
				cout << "总收入：" << Income << ' ' << "总支出：" << Expense << endl; 
			}	
			if( sickTime == FarmTime ){ //开始猪瘟 
				cout << "	第" << FarmTime << "天，猪瘟爆发了！" << endl; 
				getSick();
				int tm = 0; 
				while( simulation(5) < 1000 ) tm += 5; //爆发开始的第tm天 
				cout << "若不采取措施，大约" << tm << "天后所有的猪都会感染" << endl;
				fout << "大约" << tm << "天后，猪圈将覆灭！" << endl; 
				fout << "模拟数据见" << illfile << endl; 
				ofstream fill( illfile , ios::app );
				fill << "模拟数据: (数字对应该猪第几天被感染)" << endl; 
				for( int j = 0 ; j < 10 ; j++ ){
					for( int i = 0; i < 100 ; i++ ){
						fill << a[i][j] << ' ';
						a[i][j] = sickPig[i][j];//a只是模拟，完成后要复原 
					}
					fill << endl;
				}
				fill << endl;				 
			}
			else if( sickTime < FarmTime ){ //模拟传染 ， 所有猪都被传染时农场无 
				cout << "	瘟疫爆发第" << FarmTime-sickTime+1 << "天" << endl;
				cout << "	是否采取措施？" ;
				int tag;
				cin >> tag;
				if( tag ){
					cout << "	采取隔离措施" << endl;
					method(p,sickTime);
					sickTime = 1000000;
				}
				else{
					int num;
					num = simulation(1); 
					ofstream fill( illfile , ios::app );
					fill << "瘟疫爆发第" << FarmTime-sickTime+1 << "天" << endl;
					for( int j = 0 ; j < 10 ; j++ ){
						for( int i = 0; i < 100 ; i++ ){
							fill << a[i][j] << ' ';
							sickPig[i][j] = a[i][j];//a只是模拟，完成后要复原 
						}
						fill << endl;
					}
					fill << endl;
					if( num > 100 && num < 200 )
						cout << "	黑猪在哀嚎,白猪在哭泣,你怎么这么狠心/(ㄒoㄒ)/~~" << endl;
					else if( num >= 200 && num < 300 )
						cout << "	养猪唯唯诺诺，吃肉重拳出击？" << endl;
					else if( num >= 300 && num < 400 )
						cout << "	我淋过最大的雨，就是你对猪场的视而不见。" << endl;
					else if( num >= 400 && num < 500 )
						cout << "	死亡和庸俗是猪场仅有的无法逃避的东西。" << endl;
					else if( num >= 500 && num < 600 )
						cout << "	如果猪假装失忆，会被多少人趁机抛弃。" << endl;
					else if( num >= 600 && num < 700 )
						cout << "	世事一场大梦，猪生几度悲凉。" << endl;
					else if( num >= 700 && num < 800 )
						cout << "	终有弱水替猪场，再无相思寄巫山" << endl; 
					else if( num >= 800 ){					 
						cout << "猪场环境十分恶劣，已被查封，再见！" << endl;
						break; 
					} 
				}
			}
		}
}

void getSick(){ //猪瘟爆发了 爆发当天为第1天 
	int id1 , id2;
	id1 = rand()%100;
	id2 = rand()%10;
	sickPig[id1][id2] = 1; 
	a[id1][id2] = 1; 
	fout << "猪瘟爆发！" << endl; 
	fout << "源头是" << id1 << "号猪圈的第" << id2 << "头猪！" << endl;
	cout << "源头是" << id1 << "号猪圈的第" << id2 << "头猪！" << endl;
	sickId[0] = id1 , sickId[1] = id2;
} 

int simulation( int period )//从a数组对应的当前天开始，再向后数tm天 
{ 
	int nowaday = 1 , ans = 0;
	//找到数组中最大值，也既瘟疫爆发天数 
	for( int i = 0 ; i < 100 ; i++ ){
		for( int j = 0;  j < 10 ; j++ ){
			if( a[i][j] > nowaday ) nowaday = a[i][j]; 
		}
	}
	int ran1 , ran2; //传染几率 1-同圈 2-邻圈 
	nowaday++;
	for( int t = nowaday; t < period+nowaday ; t++ ){
		for( int i = 0 ; i < 100 ; i++ ){
			for( int j = 0 ; j < 10 ; j++ ){
				if( a[i][j] < t && a[i][j] != 0 ){
					for( int k = 0 ; k < 10 ; k++ ){
						if( a[i][k] == 0 ){
							ran1 = rand()%2;
							if( ran1 ) a[i][k] = t;
						}
						if( i>=1 && a[i-1][k] == 0 ){
							ran2 = rand()%20;
							if( ran2 < 3 ) a[i-1][k] = t;
						}
						if( i<99 && a[i+1][k] == 0 ){
							ran2 = rand()%20;
							if( ran2 < 3 ) a[i+1][k] = t;
						}
					}	
				}
			}
		}	
	}
	ans=0;
	//ofstream fill( illfile , ios::app );
	for( int j = 0 ; j < 10 ; j++ )
		for( int i = 0 ; i < 100 ;i ++ )
			if( a[i][j] ) ans++;
	//fill.close();
	return ans;
}

void method( pigfarm p , int sickTime )
{
	//ofstream fill( illfile , ios::app );
	pigsty tmp = p->Head;
	int num = 0;
	for( int i = 0 ; i < 100 ; i++ ){
		tmp = tmp->Next;
		bool isInfected = false;
		for( int j = 0 ; j < 10 ; j++ ){
			if( sickPig[i][j] ){
				isInfected = true;
				Expense += buyPig( tmp , j );
				Expense += tmp->sty[j].Weight * (FarmTime-sickTime+1);
				fout << "猪圈编号：" << i << " 猪编号：" << j << " 已被处理" << endl;
			}
		}
		if( isInfected ){
			num++;
			Expense += 5000; 
			fout << "猪圈编号：" << i << " 已被处理" << endl;
		}
	}
}

void Welcome_to_the_( pigfarm p )
{
	ifstream fin(filename, ios::ate);
	long location = fin.tellg();
	if( location == 0 ){
		//一些废话 
		cout << "欢迎初次来到猪场模拟，你不需要做任何事就可以得到一批形而上的猪。" << endl;
		cout << "猪场上日期会自动增长，每90天自动出售一批符合要求的猪（届时会有信息提示）" << endl;
		cout << "各项信息都会被记录，开始吧" << endl;
		for( int i = 0 ; i < 100 ; i++ ) cout << '_' ;
		cout << endl; 
		system("pause"); 
		//输出猪场初始信息 
		cout << "最初的猪场信息已被记录进文本文件“information.txt”中" << endl;
		fout << "猪场初始信息" << endl; 
		for( int i = 0 ; i < 100 ; i++ ){
			printPigsty( p , i );
			for( int k = 0 ; k < 10 ; k++ ){
				printPig(p,i,k);		
			}
		}
		printPigfarm( p );
		//时间启动，自动买卖开始 
		cout << "第一次来到猪场，自动进行" << simulation_duration <<"天的增长，以后你可以自己定义时长" << endl; 
		startTime( p , simulation_duration );
		//将当前时间保存，以便于下次打开 
		ofstream dayout( dayfile , ios::out );
		dayout << FarmTime;
		//将当前猪场各猪圈/猪信息保存，以便于下次打开 
		pigsty ps = p->Head;
		ofstream dataOut( datafile , ios::out );
		for( int i = 0 ; i < 100 ; i++ ){
			ps = ps->Next;
			dataOut << ps->ID << ' ';
			for( int j  = 0 ; j < 4 ; j++ ) dataOut << ps->amount[j] << ' ';
			for( int k = 0 ; k < 10 ; k++ ){
				dataOut << ps->sty[k].ID << ' ';
				dataOut << (int)ps->sty[k].Breed << ' ';
				dataOut << ps->sty[k].Time << ' ';
				dataOut << ps->sty[k].Weight <<' ';
			}
		} 
		//把打开的文件统统关闭 
		dataOut.close();
		dayout.close();
	}
	else {
		//一些废话 
		cout << "欢迎再次回到猪场" << endl; 
		//导入时间 
		ifstream dayin( dayfile , ios::in );
		dayin >> FarmTime;
		cout << "现在是猪场上第" << FarmTime << "天" << endl; 
		//导入猪场/猪圈/猪的信息 
		ifstream dataIn( datafile , ios::in );
		pigsty ps = p->Head;
		int temp;//breed类型不可直接输入 
		for( int i = 0 ; i < 100 ; i++ ){
			ps = ps->Next;
			dataIn >> ps->ID;
			for( int j  = 0 ; j < 4 ; j++ ) dataIn >> ps->amount[j];
			for( int k = 0 ; k < 10 ; k++ ){
				dataIn >> ps->sty[k].ID ;
				dataIn >> temp;
				ps->sty[k].Breed = breed(temp);
				dataIn >> ps->sty[k].Time ;
				dataIn >> ps->sty[k].Weight ;
			}
		} 
		//把刚才导入的信息输出 到information.txt 
		cout << "当前猪场信息已被记录进文本文件“information.txt”中" << endl;
		fout << "当前猪场信息" << endl; 
		for( int i = 0 ; i < 100 ; i++ ){
			printPigsty( p , i );
			for( int k = 0 ; k < 10 ; k++ ){
				printPig(p,i,k);		
			}
		}
		printPigfarm( p );
		//输入一个时间，让猪场再跑起来
		int maxT;
		cout << "现在,输入猪场继续运作的最大天数：";
		cin >>  maxT;
		int ran_day = rand()%(maxT-360)+360; cout << ran_day << endl;
		cout << "在某一天，猪场可能会出现猪瘟！" << endl;
		startTime( p , maxT , ran_day );
		//将当前时间保存，以便于下次打开 
		ofstream dayout( dayfile , ios::out );
		dayout << FarmTime;
		//统统关闭 
		dayout.close();
		dataIn.close();
		dayin.close();
	}
	fin.close();
}
