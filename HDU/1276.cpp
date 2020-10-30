#include<iostream>

using namespace std;

int n;
int amount;
int a[5001] = {0};

bool is2end(int a[],int amount)
{
	int leftSoldier = 0;
	for(int i=1,j=0;i<=amount;i++)
	{
		if(a[i]==-1)
			continue;
		else
			j++;
		if((j%2)==0){
			a[i]=-1;
		}		
		else
			leftSoldier++;
	}
	if(leftSoldier<=3)
		return true;
	return false;
		
}

bool is3end(int a[],int amount)
{
	int leftSoldier = 0;
	for(int i=1,j=0;i<=amount;i++)
	{
		if(a[i]==-1)
			continue;
		else 
			j++;
		if(j%3==0){
			a[i]=-1;
		}		
		else
			leftSoldier++;
	}
	if(leftSoldier<=3)
		return true;
	return false;
}

int main()
{
	cin>>n; 
	while(n--){

		cin>>amount;
		for( int i = 1; i <= amount; i++ )
			a[i] = 0;
			
		bool flag = false;
		int turn = 1;
		while( flag == false ){
		if( turn % 2 )	
			flag = is2end(a,amount);
		else
			flag = is3end(a,amount);
		turn++ ;	
		}
		
		for( int i = 1; i <= amount; i++ ){
			if(a[i]!=-1)
			{
				if(i==1)
					cout<<i;
				else
					cout<<' '<<i;
			}
		}
		cout<<endl;
		amount = 0;
	}
	return 0;
 } 
